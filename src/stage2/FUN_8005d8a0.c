/* FUN_8005d8a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005d8a0  body 0x8005d8a0..0x8005d8c3  size 36 B
 * body sha256 2b0abd1ddab9474904933b57ebb269a068b8ed67a87b4076965e68df9cf07ae2
 * provider record sha256 4dbe3895876a0927eca27673d90fa20d5d126ba981449227bcb7014be61b70e7
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005d8a0(int param_1)

{
  FUN_8008cea0(*(ushort *)(param_1 + 0x1aa) & 0xfff,0);
  return;
}
