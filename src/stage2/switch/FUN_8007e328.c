/* FUN_8007e328
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e328  body 0x8007e328..0x8007e37f  size 88 B
 * body sha256 c372356793582144a899d3b7d047460185b6f7505ee0f680f6531de46ae5535c
 * provider record sha256 bacc1c08865cb5b900febfc6578be59f9341f82a18472104db3207dbd64b5976
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007e304::caseD_1(void)

{
  int iVar1;
  int unaff_s0;
  
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
