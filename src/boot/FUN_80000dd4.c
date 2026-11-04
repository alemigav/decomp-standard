/* FUN_80000dd4
 * image   boot (boot), base 0x80000480
 * address 0x80000dd4  body 0x80000dd4..0x80000de7  size 20 B
 * body sha256 8c62e6d827e597bfa7fa68519f9f4a486b3708ecd422c84365244ee8c52d525a
 * provider record sha256 202999f89f2f166073123e3198a7f099ea76273b74f6be310913ed8ca5da3066
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80000dd4(void)

{
  *(uint *)(_DAT_80012950 + 0x118) = Status | 2;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
