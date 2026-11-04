/* FUN_80033604
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80033604  body 0x80033604..0x80033647  size 68 B
 * body sha256 2e83ce32b3f9114c0e245f66d551db8e12bd0267f3b115164407fee0ea3bb15b
 * provider record sha256 39ee61f6dee39b1edb7eb3214853bc6c2f8608ca5b399799a67f7ba10f9193d5
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_80033604(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_800df920 >> 7 & 0xff;
  uVar1 = (DAT_800df920 & 0xffff) + uVar2 & 0xff;
  DAT_800df920 = uVar1 | uVar2 << 8;
  return uVar1;
}
