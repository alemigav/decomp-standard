/* FUN_80057fc8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80057fc8  body 0x80057fc8..0x8005800f  size 72 B
 * body sha256 8c0e57fdd13eb6f6ebecba9809b843f903d800eb7f6df14713f1d473a026797b
 * provider record sha256 0e361ac0de84e7bee50c58f5e3d2e271d7530e81bc3631bc2de367fd3dc6ac7e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80057fc0::caseD_0(void)

{
  int iVar1;
  uint *unaff_s0;
  
  unaff_s0[0x7a] = 0x700;
  *(undefined1 *)((int)unaff_s0 + 6) = 1;
  DAT_800e110c = DAT_800e110c | 0x40;
  *(byte *)((int)unaff_s0 + 0x26f) = *(byte *)((int)unaff_s0 + 0x26f) | 0x80;
  *unaff_s0 = *unaff_s0 | 4;
  FUN_80032ef4();
  iVar1 = FUN_80032f64();
  if (iVar1 == 0) {
    *(undefined1 *)((int)unaff_s0 + 6) = 2;
    FUN_80032ef4();
  }
  FUN_80089d54();
  if ((*(uint *)unaff_s0[0x85] & 0x4000) != 0) {
    FUN_80077f30(0,((*(uint *)unaff_s0[0x85] & 0x2000) >> 0xd) * 3 + 4);
    DAT_800e112a = DAT_800e112a | 4;
  }
  return;
}
