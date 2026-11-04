/* FUN_80164890
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80164890  body 0x80164890..0x80164aef  size 608 B
 * body sha256 96a42ba1dc643742ea069c9caf97a81ea98f81e642b2cb131c2bc7f11af41338
 * provider record sha256 93e1bbd6c599187a90b11ec7b22ac1eb4b9255bd743af610a0f8849f7f7196af
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164890(int param_1)

{
  short sVar2;
  uint uVar1;
  int iVar3;
  
  *(undefined2 *)(param_1 + 0x1e2) = 0;
  sVar2 = func_0x80032d14((int)_DAT_800e115a,(int)_DAT_800e1162,(int)*(short *)(param_1 + 0x2a),
                          (int)*(short *)(param_1 + 0x32));
  iVar3 = (int)sVar2;
  uVar1 = func_0x80033604();
  FUN_80164af0(*(undefined4 *)(param_1 + 0x234),iVar3);
  if ((uVar1 & 1) == 0) {
    FUN_80164b50(*(int *)(param_1 + 0x234) + 0x178,iVar3);
    FUN_80164b50(*(int *)(param_1 + 0x234) + 0x2f0,iVar3);
  }
  else {
    FUN_80164af0(*(int *)(param_1 + 0x234) + 0x178);
    FUN_80164af0(*(int *)(param_1 + 0x234) + 0x2f0,iVar3);
  }
  if ((uVar1 & 2) == 0) {
    FUN_80164b50(*(int *)(param_1 + 0x234) + 0x468,iVar3);
    FUN_80164b50(*(int *)(param_1 + 0x234) + 0x5e0,iVar3);
    FUN_80164b50(*(int *)(param_1 + 0x234) + 0x758,iVar3);
  }
  else {
    FUN_80164af0(*(int *)(param_1 + 0x234) + 0x468);
    FUN_80164af0(*(int *)(param_1 + 0x234) + 0x5e0,iVar3);
    FUN_80164af0(*(int *)(param_1 + 0x234) + 0x758,iVar3);
  }
  if ((uVar1 & 4) == 0) {
    FUN_80164b50(*(int *)(param_1 + 0x234) + 0x8d0,iVar3);
    FUN_80164b50(*(int *)(param_1 + 0x234) + 0xa48,iVar3);
    FUN_80164b50(*(int *)(param_1 + 0x234) + 0xbc0,iVar3);
  }
  else {
    FUN_80164af0(*(int *)(param_1 + 0x234) + 0x8d0);
    FUN_80164af0(*(int *)(param_1 + 0x234) + 0xa48,iVar3);
    FUN_80164af0(*(int *)(param_1 + 0x234) + 0xbc0,iVar3);
  }
  FUN_80164af0(*(int *)(param_1 + 0x234) + 0xd38,iVar3);
  FUN_80164af0(*(int *)(param_1 + 0x234) + 0xeb0,iVar3);
  if ((uVar1 & 8) == 0) {
    FUN_80164b50(*(int *)(param_1 + 0x234) + 0x1028,iVar3);
  }
  else {
    FUN_80164af0(*(int *)(param_1 + 0x234) + 0x1028);
  }
  if ((uVar1 & 0x10) == 0) {
    FUN_80164b50(*(int *)(param_1 + 0x234) + 0x11a0,iVar3);
  }
  else {
    FUN_80164af0(*(int *)(param_1 + 0x234) + 0x11a0);
  }
  FUN_80166100(param_1);
  FUN_80166100(param_1);
  FUN_80166100(param_1);
  uVar1 = func_0x80033604();
  FUN_801661d8(param_1,uVar1 & 3 | 8);
  func_0x80035b84(param_1);
  FUN_80165c58(param_1,7,1);
  return;
}
