/* FUN_8007e30c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e30c  body 0x8007e30c..0x8007e327  size 28 B
 * body sha256 2712ae53f340531c545789e99b01bc7a1f7d35770a57975634543af4bea3f962
 * provider record sha256 758b8de976994fa4ea7945369c7898424a79096d3bcb83b1e6d28cf6decb47a2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007e304::caseD_0(void)

{
  int iVar1;
  int unaff_s0;
  
  *(undefined4 *)(unaff_s0 + 0x1e8) = 0x700;
  *(undefined1 *)(unaff_s0 + 6) = 1;
  *(byte *)(unaff_s0 + 0x26f) = *(byte *)(unaff_s0 + 0x26f) | 0x80;
  FUN_80032ef4();
  iVar1 = FUN_80032f64();
  if (iVar1 == 0) {
    *(undefined1 *)(unaff_s0 + 6) = 2;
    FUN_80032ef4();
  }
  FUN_80089d54();
  if ((**(uint **)(unaff_s0 + 0x214) & 0x4000) != 0) {
    FUN_80077f30(1,((**(uint **)(unaff_s0 + 0x214) & 0x2000) >> 0xd) * 3 + 4);
    DAT_800e112a = DAT_800e112a | 4;
  }
  return;
}
