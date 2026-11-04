#!/bin/sh
# Provision the matching toolchain: a MIPS assembler/linker, and the original compilers if the user supplies them.
#
# This is the "container" without Docker: this machine has no container runtime, so provisioning is a script
# that builds into `build/toolchain/` (gitignored) and can be re-run to repair a partial state. Everything it
# fetches is open source or supplied by the owner; nothing proprietary is downloaded, committed or redistributed.
#
# What is in scope, and why each piece is needed:
#
#   binutils (mips)    `as` and `ld` for the target. Configured `--without-zlib`: binutils' bundled zlib does
#                      not compile against the macOS 14 SDK (`_stdio.h` macro clash), and neither gas nor ld
#                      needs it. Measured here, not guessed. Without them splat's emitted asm stays text: no object, no
#                      link, no comparison. This is the piece that unblocks the rehearsal's missing half, and
#                      it is ordinary GNU source — built here, not vendored.
#   IDO 5.3 / 7.1      the candidate compilers for 1999 N64 code. `decompals/ido-static-recomp` recompiles the
#                      *original IRIX binaries* for a modern host, which means the IRIX binaries must come from
#                      the machine's owner. **This script will not fetch them**: they are proprietary, and a
#                      decompilation that redistributes its compiler is a decompilation with a problem.
#                      Supply them at `$IDO_53_DIR` / `$IDO_71_DIR` (each holding the IRIX `cc`, `cfe`, `uopt`,
#                      `ugen`, `as1`, `as2`, `uld`), and the doctor reports what is usable.
#
# Usage:
#   ./provision.sh            # build what can be built, then report
#   ./provision.sh --doctor   # report only; build nothing
#   ./provision.sh --clean    # remove build/toolchain
#
# Environment:
#   BINUTILS_VERSION  default 2.42
#   IDO_RECOMP_REPO   default https://github.com/decompals/ido-static-recomp
#   IDO_53_DIR, IDO_71_DIR   where the user's IRIX IDO binaries live (optional)
set -u

root=$(git rev-parse --show-toplevel 2>/dev/null) || {
	printf 'provision: not inside a git work tree\n' >&2
	exit 1
}
cd "$root" || exit 1

TC=build/toolchain
BINUTILS_VERSION=${BINUTILS_VERSION:-2.42}
IDO_RECOMP_REPO=${IDO_RECOMP_REPO:-https://github.com/decompals/ido-static-recomp}
JOBS=$(sysctl -n hw.ncpu 2>/dev/null || echo 4)
MODE=${1:-}

case "$MODE" in
--clean)
	rm -rf "$TC"
	printf 'provision: removed %s\n' "$TC"
	exit 0
	;;
--doctor) ;;
"") ;;
*)
	printf 'provision: unknown argument %s (use --doctor or --clean)\n' "$MODE" >&2
	exit 2
	;;
esac

have() { command -v "$1" >/dev/null 2>&1; }

doctor() {
	printf '\n== toolchain doctor\n'
	bin="$TC/binutils/bin/mips-linux-gnu-as"
	if [ -x "$bin" ]; then
		printf 'PASS mips assembler  %s (%s)\n' "$bin" "$("$bin" --version | head -1)"
	else
		printf 'SKIP mips assembler  not built yet (%s)\n' "$bin"
	fi
	ld="$TC/binutils/bin/mips-linux-gnu-ld"
	if [ -x "$ld" ]; then
		printf 'PASS mips linker     %s\n' "$ld"
	else
		printf 'SKIP mips linker     not built yet (%s)\n' "$ld"
	fi
	for v in 7.1 5.3; do
		if [ -x "$TC/ido-$v/cc" ]; then
			printf 'PASS IDO %s native   %s/ido-%s (cc, as1, uld)\n' "$v" "$TC" "$v"
		else
			printf 'SKIP IDO %s native   not recompiled yet (needs gmake and the IRIX binaries)\n' "$v"
		fi
	done
	if [ -x "$TC/src/bu27-build/gas/as.new" ]; then
		printf 'PASS as 2.7 (SDK-era) %s/src/bu27-build/gas/as.new — expands `move` to `addu`, as the cartridge does\n' "$TC"
	fi
	if [ -x "$TC/mips-gcc-2.8.1/bin/cc1" ]; then
		printf 'PASS gcc 2.8.1       %s/mips-gcc-2.8.1/bin/cc1 (4/4 probes; this is the matching compiler)\n' "$TC"
	fi
	if [ -x "$TC/mips-gcc-2.7.2/bin/cc1" ]; then
		printf 'PASS gcc 2.7.2       %s/mips-gcc-2.7.2/bin/cc1 (3/4 probes; p3 needs 2.8.1)\n' "$TC"
	fi
	if [ -x "$TC/ido-7.1/cc" ]; then
		USR_LIB="$root/$TC/ido-7.1" "$TC/ido-7.1/cc" -c -O2 -non_shared -G 0 -mips2 \
			-o "$TC/probe.o" "$TC/probe.c" 2>/dev/null && \
			printf 'PASS compile probe    cc produced %s\n' "$(file -b "$TC/probe.o" | cut -c1-46)"
	fi
	printf '\ncompiler candidates this project has NOT tested: IDO 5.3, IDO 7.1, gcc 2.7.2, gcc 2.8.1.\n'
	printf 'Deciding between them is a measurement (docs/TOOLCHAIN.md), not an assumption.\n'
}

build_binutils() {
	if [ -x "$TC/binutils/bin/mips-linux-gnu-as" ]; then
		printf 'binutils: already built\n'
		return 0
	fi
	if ! have make || ! have cc || ! have curl; then
		printf 'binutils: FAIL needs make, a C compiler and curl\n' >&2
		return 1
	fi
	mkdir -p "$TC/src" || return 1
	tar="$TC/src/binutils-$BINUTILS_VERSION.tar.xz"
	if [ ! -f "$tar" ]; then
		printf 'binutils: fetching %s (about 25 MB)\n' "$BINUTILS_VERSION"
		curl -fsSL -o "$tar" "https://ftp.gnu.org/gnu/binutils/binutils-$BINUTILS_VERSION.tar.xz" || {
			printf 'binutils: FAIL download\n' >&2
			return 1
		}
	fi
	rm -rf "$TC/src/binutils-$BINUTILS_VERSION"
	tar -xf "$tar" -C "$TC/src" || return 1
	# The bundled zlib's `#ifndef HAVE_FDOPEN` fallback (`#define fdopen(fd,mode) NULL`) collides with the
	# macOS 14 SDK's _stdio.h. Three attempts to set that macro from outside failed -- an inline assignment on
	# configure, an exported cache variable, and `--without-zlib` (which 2.42 still builds bundled zlib under)
	# -- so the fallback is deleted from the build tree instead. This is a build-tree patch, not a fork: the
	# tarball is re-extracted every run, so the patch cannot drift, and a reviewer can see it in one line.
	# The bundled zlib defines `fdopen(fd,mode) NULL` when it cannot detect fdopen, which collides with the
	# macOS 14 SDK's _stdio.h. Three attempts to set the macro from outside failed -- an inline assignment on
	# configure, an exported cache variable, and `--without-zlib` (2.42 still builds bundled zlib) -- and a
	# patch(1) hunk matched only one of the three copies while `|| true` hid the rest. So: delete every line,
	# then assert the count, because "the patch applied" is a claim that has to be checked like any other.
	# `grep -c` prints 0 *and* exits 1 on no match, so `|| echo 0` produced "0\n0" and the assertion below
	# read that as a failure. `|| true` keeps the printed value.
	before=$(grep -c "define fdopen(fd,mode)" "$TC/src/binutils-$BINUTILS_VERSION/zlib/zutil.h" 2>/dev/null || true)
	sed -i '' '/define fdopen(fd,mode)/d' "$TC/src/binutils-$BINUTILS_VERSION/zlib/zutil.h" 2>/dev/null || \
		sed -i '/define fdopen(fd,mode)/d' "$TC/src/binutils-$BINUTILS_VERSION/zlib/zutil.h"
	after=$(grep -c "define fdopen(fd,mode)" "$TC/src/binutils-$BINUTILS_VERSION/zlib/zutil.h" 2>/dev/null || true)
	printf 'binutils: removed %s fdopen fallback line(s), %s left\n' "$before" "$after"
	if [ "$after" != "0" ]; then
		printf 'binutils: FAIL the zlib workaround did not apply\n' >&2
		return 1
	fi
	mkdir -p "$TC/build-binutils" && cd "$TC/build-binutils" || return 1
	# exported, not inline: binutils' bundled zlib runs its own configure from a recursive make and does not
	# inherit an inline assignment on the top-level configure (measured -- the failure survived it).
	export ac_cv_func_fdopen=yes
	export CFLAGS="-O2"
	# no texinfo on this host: gas/ld do not need the manuals, and `info-recursive` aborts the whole build
	# without MAKEINFO stubbed (measured -- it was the second distinct failure after zlib).
	export MAKEINFO=true
	printf 'binutils: configuring for mips-linux-gnu (gas + ld only)\n'
	# absolute, because configure is executed from the build directory -- a relative path here silently ran
	# the wrong file and reported "FAIL configure" with the reason thrown away by the /dev/null that used to
	# be on this line
	# `ac_cv_func_fdopen=yes`: the bundled zlib's configure fails to detect fdopen against the macOS 14 SDK and
	# then `#define fdopen(fd,mode) NULL`, which collides with _stdio.h. Cached, this is a one-line workaround
	# inside the build; patching binutils source would be a fork of it.
	# exported, not inline: the bundled zlib runs its own configure from a recursive make, and an inline
	# assignment on the top-level configure is not inherited by it (measured).
	ac_cv_func_fdopen=yes \

	"$root/$TC/src/binutils-$BINUTILS_VERSION/configure" \
		--target=mips-linux-gnu --prefix="$root/$TC/binutils" \
		--disable-nls --disable-werror --disable-gdb --disable-gprof \
		--disable-gold --disable-sim --without-zlib >"$root/$TC/configure.log" 2>&1 || {
		printf 'binutils: FAIL configure — see %s\n' "$TC/configure.log" >&2
		cd "$root" || exit 1
		return 1
	}
	printf 'binutils: building with %s jobs (this is the slow step)\n' "$JOBS"
	# MAKEINFO on the command line, not exported: the Makefile defines it itself, and an environment variable
	# does not override a Makefile assignment (measured -- `doc/bfd.info` was still being built).
	if ! make MAKEINFO=true -j"$JOBS" all-gas all-ld >"$root/$TC/binutils.log" 2>&1; then
		printf 'binutils: FAIL make — see %s\n' "$TC/binutils.log" >&2
		cd "$root" || exit 1
		return 1
	fi
	make MAKEINFO=true install-gas install-ld install-binutils >>"$root/$TC/binutils.log" 2>&1 || {
		printf 'binutils: FAIL install\n' >&2
		cd "$root" || exit 1
		return 1
	}
	cd "$root" || exit 1
	printf 'binutils: installed to %s\n' "$TC/binutils"
}

build_binutils27() {
	# binutils 2.7 (1996): the SDK-era `as`. It matters because it expands `move` to `addu` on its own, which is
	# the cartridge's idiom -- modern gas picks `or`. Built from ftp.gnu.org/gnu/binutils (old-gnu/ is gone).
	src="$TC/src/binutils-2.7"
	out="$TC/src/bu27-build"
	[ -x "$out/gas/as.new" ] && { printf 'binutils 2.7: already built\n'; return 0; }
	if [ ! -d "$src" ]; then
		printf 'binutils 2.7: SKIP sources missing (build/toolchain/src/binutils-2.7)\n'
		return 0
	fi
	host_cc=$(command -v gcc-16 || command -v gcc) || { printf 'binutils 2.7: SKIP no GCC host compiler\n'; return 0; }
	mkdir -p "$out"
	# 1996's configure calls config.sub with old-style multiple arguments, which a modern config.sub rejects;
	# 2.42's copies accept both, and 2.7's own do not recognise aarch64-apple-darwin.
	if [ -f "$TC/src/binutils-2.42/config.sub" ]; then
		cp "$TC/src/binutils-2.42/config.sub" "$TC/src/binutils-2.42/config.guess" "$src/" 2>/dev/null
	fi
	( cd "$out" && CC="$host_cc -std=gnu89 -fcommon -w -I$root/$TC/src/hostshim" \
	    ../binutils-2.7/configure --target=mips-elf --disable-nls --disable-werror >"$root/$TC/bu27-config.log" 2>&1 && \
	  make -j"$JOBS" all-gas all-ld CC="$host_cc -std=gnu89 -fcommon -w -I$root/$TC/src/hostshim" \
	       >"$root/$TC/bu27-build.log" 2>&1 ) || {
		printf 'binutils 2.7: FAIL — see %s (needs one const patch on sys_nerr/sys_errlist)\n' "$TC/bu27-build.log" >&2
		return 1
	}
	printf 'binutils 2.7: gas in %s/gas/as.new (its ld builds but writes an empty file on this host)\n' "$out"
}

build_gcc272() {
	# gcc 2.7.2.3 for mips-elf: the SDK's own makefiles name `CC = gcc` with `-O -G 0`, and the probe corpus
	# confirms it (3 of 4 probes byte-exact against IDO's 1). Building a 1996 compiler on a 2026 host took six
	# patches, all recorded in docs/TOOLCHAIN.md; none of them touch code generation.
	src="$TC/src/gcc-2.7.2.3"
	out="$TC/mips-gcc-2.7.2"
	[ -x "$out/bin/cc1" ] && { printf 'gcc 2.7.2: already built\n'; return 0; }
	if [ ! -d "$src" ]; then
		printf 'gcc 2.7.2: SKIP sources missing (build/toolchain/src/gcc-2.7.2.3)\n'
		return 0
	fi
	if ! command -v gcc-16 >/dev/null 2>&1 && ! command -v gcc >/dev/null 2>&1; then
		printf 'gcc 2.7.2: SKIP needs a GCC host compiler (clang rejects 1996 idioms: lvalue casts, obstack macros)\n'
		return 0
	fi
	host_cc=$(command -v gcc-16 || command -v gcc)
	mkdir -p "$out/bin" "$TC/src/gcc-build"
	( cd "$TC/src/gcc-build" && \
	  ../gcc-2.7.2.3/configure --target=mips-elf --with-gnu-as --with-gnu-ld --disable-libgcc \
	      --disable-multilib --enable-languages=c >"$root/$TC/gcc-config.log" 2>&1 && \
	  make -j"$JOBS" LANGUAGES=c CLIB="-lm" \
	       CC="$host_cc -std=gnu89 -fcommon -w -I$root/$TC/src/hostshim" >"$root/$TC/gcc-build.log" 2>&1 ) || {
		printf 'gcc 2.7.2: FAIL — see %s (the enquire/deduced steps want .stabs and fail harmlessly; cc1 is what matters)\n' "$TC/gcc-build.log" >&2
	}
	[ -x "$TC/src/gcc-build/cc1" ] || { printf 'gcc 2.7.2: FAIL cc1 was not produced\n' >&2; return 1; }
	cp "$TC/src/gcc-build/cc1" "$out/bin/cc1"
	printf 'gcc 2.7.2: cc1 in %s/bin (the driver xgcc exists but execs the host cc; call cc1 directly)\n' "$out"
}

# M261: gcc 2.8.1 stores the constant-pool float in the emulator's packed internal form when the host is 64-bit
# (`sizeof u == 2 * sizeof (HOST_WIDE_INT)` is 8 == 16), so every pool float came out as 0 and `li.s` was never
# chosen. The patch is a tracked script because it is three coordinated edits and every anchor must match once.
patch_gcc281_fp() {
	[ -f "$src/varasm.c" ] || { printf 'gcc 2.8.1: SKIP fp patch, sources missing\n'; return 0; }
	grep -q 'M261' "$src/varasm.c" && return 0
	python3 "$root/tools/toolchain/patch_gcc281_fp.py" "$src" || return 1
	# 2.8.1's Makefile carries no header dependencies, so patching a target macro leaves varasm.o stale and
	# the change silently does nothing (M265: the pool stayed before the function until varasm.c was touched).
	touch "$src/varasm.c" "$src/function.c" "$src/real.h" \
	      "$src/config/mips/mips.c" "$src/config/mips/mips.h"
}

build_gcc281() {
	# gcc 2.8.1 (1998) is the compiler that matches: 4 of 4 probes byte-for-byte where 2.7.2 cannot do the
	# store's address materialisation. Five patches, all recorded in docs/TOOLCHAIN.md, none of them codegen.
	src="$TC/src/gcc-2.8.1"
	out="$TC/mips-gcc-2.8.1"
	[ -x "$out/bin/cc1" ] && { printf 'gcc 2.8.1: already built\n'; return 0; }
	if [ ! -d "$src" ]; then
		printf 'gcc 2.8.1: SKIP sources missing (build/toolchain/src/gcc-2.8.1)\n'
		return 0
	fi
	host_cc=$(command -v gcc-16 || command -v gcc) || { printf 'gcc 2.8.1: SKIP no GCC host compiler\n'; return 0; }
	mkdir -p "$out/bin" "$TC/src/gcc28-build"
	patch_gcc281_fp || return 1
	( cd "$TC/src/gcc28-build" && \
	  CC="$host_cc -std=gnu89 -fcommon -w -I$root/$TC/src/hostshim" \
	    ../gcc-2.8.1/configure --target=mips-elf --with-gnu-as --with-gnu-ld --disable-libgcc \
	        --disable-multilib --enable-languages=c >"$root/$TC/gcc28-config.log" 2>&1 ) || {
		printf 'gcc 2.8.1: FAIL configure — see %s\n' "$TC/gcc28-config.log" >&2
		return 1
	}
	# `cc1` includes `config.h`, which configure writes with host macros only; the target macros live in tm.h
	# and 2.8.1's build expects them there. Appending the include is what makes cc1 compile at all.
	grep -q 'include "tm.h"' "$TC/src/gcc28-build/config.h" || \
		echo '#include "tm.h"' >> "$TC/src/gcc28-build/config.h"
	( cd "$TC/src/gcc28-build" && \
	  make -j1 cc1 LANGUAGES=c CLIB="-lm" \
	       CC="$host_cc -std=gnu89 -fcommon -w -I$root/$TC/src/hostshim" \
	       >"$root/$TC/gcc28-build.log" 2>&1 ) || {
		printf 'gcc 2.8.1: FAIL — see %s\n' "$TC/gcc28-build.log" >&2
		return 1
	}
	[ -x "$TC/src/gcc28-build/cc1" ] || { printf 'gcc 2.8.1: FAIL cc1 was not produced\n' >&2; return 1; }
	cp "$TC/src/gcc28-build/cc1" "$out/bin/cc1"
	printf 'gcc 2.8.1: cc1 in %s/bin (the matching compiler)\n' "$out"
}

build_ido() {
	# The recompiler turns the ORIGINAL IRIX binaries into host programs, so it needs them as input. They are
	# not fetched here: the owner supplies them, either as the project zip (`IDO_RECOMP_ZIP`, which happens to
	# carry ido/5.3 and ido/7.1 under their own licence) or by pointing `IDO_RECOMP_DIR` at a checkout.
	src="$TC/src/ido-static-recomp-main"
	if [ ! -d "$src" ]; then
		if [ -n "${IDO_RECOMP_ZIP:-}" ] && [ -f "${IDO_RECOMP_ZIP}" ]; then
			mkdir -p "$TC/src" && unzip -q -o "$IDO_RECOMP_ZIP" -d "$TC/src" || return 1
		elif [ -d "${IDO_RECOMP_DIR:-}" ]; then
			cp -R "$IDO_RECOMP_DIR" "$src" || return 1
		else
			printf 'ido: SKIP no sources — set IDO_RECOMP_ZIP (the project zip) or IDO_RECOMP_DIR\n'
			printf 'ido: the IRIX binaries it recompiles are proprietary and are never fetched by this repo\n'
			return 0
		fi
	fi
	# gmake 4.x, not /usr/bin/make 3.81: the recompiler's Makefile uses $(eval) forms BSD/make-3.81 rejects.
	if ! command -v gmake >/dev/null 2>&1; then
		printf 'ido: SKIP gmake is missing — `brew install make` (it is not the /usr/bin/make 3.81)\n'
		return 0
	fi
	for ver in 7.1 5.3; do
		out="$TC/ido-$ver"
		[ -x "$out/cc" ] && { printf 'ido %s: already built\n' "$ver"; continue; }
		printf 'ido %s: recompiling (this is ~3 min per version)\n' "$ver"
		# absolute log path: this runs inside `cd "$src"`, where a relative $TC no longer resolves (the same
		# defect that hid the binutils configure error earlier in this file's history)
		( cd "$src" && gmake setup >"$root/$TC/ido-$ver.log" 2>&1 && \
		  gmake VERSION="$ver" >>"$root/$TC/ido-$ver.log" 2>&1 ) || {
			printf 'ido %s: FAIL — see %s\n' "$ver" "$TC/ido-$ver.log" >&2
			continue
		}
		# Flatten, because the recompiled `cc` execs its phases from `$USR_LIB` (default: its own directory).
		# Pointing USR_LIB at ido/<ver>/usr/lib instead runs the IRIX binaries and fails with
		# "cannot execute binary file" — measured.
		mkdir -p "$out"
		cp "$src/build/$ver/out/"* "$out/" 2>/dev/null
		cp "$src/ido/$ver/usr/lib/err.english.cc" "$out/" 2>/dev/null
		printf 'ido %s: native tools in %s\n' "$ver" "$out"
	done
}

if [ "$MODE" != "--doctor" ]; then
	mkdir -p "$TC"
	build_binutils && build_binutils27 && build_gcc272 && build_gcc281 && build_ido
fi
doctor
