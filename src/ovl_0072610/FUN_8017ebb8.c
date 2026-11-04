/* FUN_8017ebb8
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017ebb8  body 0x8017ebb8..0x8017ede3  size 556 B
 * body sha256 d7878674551a8ec3cb8a040bd4620e6325ecf1f8fe09ab93b4cbbf6fcf37185f
 * provider record sha256 28edd6033e9ce5de825b4639be66f7e1edc1e332e0382ff7d14da60758d68ded
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017ebb8(uint *param_1,uint *param_2,uint *param_3,int *param_4,undefined4 *param_5,
                 uint *param_6,uint *param_7,uint *param_8,undefined4 *param_9)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_s0;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar2 = FUN_8017f260();
  if (DAT_80185780 != 0) {
    return;
  }
  if ((uVar2 & 0x20) == 0) {
    uVar7 = uVar2 >> 3 & 8;
  }
  else {
    uVar7 = 4;
    if (DAT_801857c0 != 0) {
      iVar3 = FUN_8017bec8(2);
      uVar7 = (uint)(byte)(&DAT_80184b50)[iVar3 + (DAT_801857c0 + -1) * 4];
    }
  }
  bVar1 = (&DAT_80184b5c)[uVar7];
  if ((uVar2 & 0xc) == 0) {
    if ((((uVar2 & 1) != 0) && (DAT_801857ac != 0)) && (unaff_s0 = 1, DAT_801857a0 == 3)) {
      unaff_s0 = 2;
    }
  }
  else if ((DAT_801857a0 != 3) || (unaff_s0 = 2, DAT_801857a8 == 0)) {
    unaff_s0 = FUN_8017bec8(2);
  }
  if (DAT_801857a0 == 3) {
    uVar5 = 1;
    if ((unaff_s0 == 1) && (bVar1 < 2)) {
      uVar5 = 2;
    }
    uVar6 = (uint)(unaff_s0 == 2);
  }
  else {
    uVar5 = 1;
    if (unaff_s0 == 2) {
      uVar5 = 2;
    }
    uVar6 = 0;
  }
  uVar8 = 0;
  if (uVar6 == 0) {
    uVar8 = (uint)(DAT_801857a0 == 3);
  }
  uVar4 = 0;
  if (DAT_801857a0 == 3) {
    if (DAT_801857a8 != 0) {
      *param_1 = uVar2;
      goto LAB_8017ed74;
    }
    if ((uVar2 & 3) == 0) {
      *param_1 = uVar2;
      goto LAB_8017ed74;
    }
    uVar4 = FUN_8017bec8(1);
  }
  *param_1 = uVar2;
LAB_8017ed74:
  *param_2 = uVar7;
  *param_3 = (uint)bVar1;
  *param_4 = unaff_s0;
  *param_5 = uVar5;
  *param_6 = uVar6;
  *param_7 = (uint)(unaff_s0 == 3);
  *param_8 = uVar8;
  *param_9 = uVar4;
  return;
}
