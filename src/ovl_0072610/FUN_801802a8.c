/* FUN_801802a8
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x801802a8  body 0x801802a8..0x801803e3  size 316 B
 * body sha256 cb4e9aec6e91017938557e88bc73947be735005c8f628ba17603dad58e48c2e1
 * provider record sha256 694a88520a6e01c107a65e7e8aa3e79b04aa9c96c2e27f7b194e494d1291156b
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801802a8(int param_1,undefined4 *param_2,int param_3,int param_4,int param_5,int param_6,
                 undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_8017f6bc();
  if (param_3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = FUN_8017bec8(param_3);
    }
  }
  FUN_801803e4(param_1,param_3,iVar1,uVar2,param_7);
  if (param_5 != 0) {
    uVar2 = FUN_8017f7a0();
    *param_2 = uVar2;
  }
  iVar1 = FUN_8017f6bc();
  if (param_4 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = FUN_8017bec8(param_4);
    }
  }
  if (param_6 != 0) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) >> 1;
  }
  FUN_801803e4(param_1 + 4,param_4,iVar1,uVar2,param_7);
  if (param_6 != 0) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) << 1;
  }
  if (param_5 != 0) {
    uVar2 = FUN_8017f7a0();
    param_2[1] = uVar2;
  }
  return;
}
