/* FUN_80073f64
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073f64  body 0x80073f64..0x80073fb3  size 80 B
 * body sha256 464057a355004e4bc8c058d9d0f96903ab5abdae7e7b52a715876d9d0533c0b4
 * provider record sha256 36b9f65d987c3b33ff7cc6cd2914e9bfb250aab07c6155266eb53072273e59f6
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80073f64(undefined2 *param_1)

{
  if ((DAT_800e1110 & 0x2000000) == 0) {
    FUN_8006d628(*param_1,*(undefined1 *)((int)param_1 + 3));
  }
  return 0;
}
