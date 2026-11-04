/* FUN_8018046c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8018046c  body 0x8018046c..0x801805ef  size 388 B
 * body sha256 41c7726eb98de6affa3456a018f92d6377e69af378a03227e087335391899fb1
 * provider record sha256 a7b77db572f5c43bdcf02af487db88129e82ef57f29f46b2e013d34aac686a73
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8018046c(int *param_1,int *param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_3 >> 1;
  iVar2 = param_4 >> 1;
  if (DAT_801857a0 != 3) {
    if (0 < param_3) {
      iVar3 = param_3 + 1 >> 1;
    }
    *param_1 = iVar3 + *param_2;
    if (0 < param_4) {
      iVar2 = param_4 + 1 >> 1;
    }
    iVar2 = iVar2 + param_2[1];
    bVar1 = DAT_801857a0 == 1;
    param_1[1] = iVar2;
    if (bVar1) {
      param_1[1] = iVar2 + -1;
      return;
    }
    param_1[1] = iVar2 + 1;
    return;
  }
  if (DAT_801857a4 == 0) {
    iVar2 = param_3 * 3;
    if (0 < param_3) {
      iVar2 = iVar2 + 1;
    }
    *param_1 = (iVar2 >> 1) + *param_2;
    iVar2 = param_4 * 3;
    if (0 < param_4) {
      iVar2 = iVar2 + 1;
    }
    param_1[1] = (iVar2 >> 1) + param_2[1] + -1;
    if (0 < param_3) {
      iVar3 = param_3 + 1 >> 1;
    }
    param_1[2] = iVar3 + *param_2;
    iVar2 = param_2[1];
    iVar3 = param_4 + 1;
    if (param_4 < 1) goto LAB_80180504;
  }
  else {
    if (0 < param_3) {
      iVar3 = param_3 + 1 >> 1;
    }
    *param_1 = iVar3 + *param_2;
    if (0 < param_4) {
      iVar2 = param_4 + 1 >> 1;
    }
    param_1[1] = iVar2 + param_2[1] + -1;
    iVar3 = param_3 * 3;
    if (0 < param_3) {
      iVar3 = iVar3 + 1;
    }
    param_1[2] = (iVar3 >> 1) + *param_2;
    iVar2 = param_2[1];
    iVar3 = param_4 * 3;
    if (0 < param_4) {
      iVar3 = iVar3 + 1;
    }
  }
  param_4 = iVar3;
LAB_80180504:
  param_1[3] = (param_4 >> 1) + iVar2 + 1;
  return;
}
