/* FUN_80065628
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80065628  body 0x80065628..0x8006568b  size 100 B
 * body sha256 30caea4dac388d1bfaf9e97ec14ea56524a019519130faf14e2e4641c51fa190
 * provider record sha256 db4d1bbd142fa8c77a24303133f7560613ebb6b063b20fac722e7c997b4d0f9f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_80065628(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)**(ushort **)(DAT_800df92c + 0x38);
  uVar1 = 0xff;
  if (uVar2 != 0) {
    uVar1 = FUN_80033604();
    uVar1 = (uVar1 & 0xff) % uVar2;
    if (uVar2 == 0) {
      trap(0x1c00);
    }
  }
  return uVar1;
}
