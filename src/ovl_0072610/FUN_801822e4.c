/* FUN_801822e4
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x801822e4  body 0x801822e4..0x801824bf  size 476 B
 * body sha256 eadeac4f2e30f97ba62bc2d98d0caafa055c2702f0a3939e4dad20fbc7c8306d
 * provider record sha256 1efbfbe453dc7c972a3d48db6de910ed057009e6ce476b5bdaf300e1d00319bf
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801822e4(int *param_1,int param_2,int *param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9,int param_10,int param_11,int param_12,
                 undefined4 param_13)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_1;
  iVar1 = param_6 >> 1;
  if (param_2 != 0) {
    iVar2 = iVar2 + iVar1;
  }
  iVar3 = *param_3;
  if (param_4 != 0) {
    iVar3 = iVar3 + iVar1;
  }
  FUN_801824c0(iVar2,iVar3,param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12,
               param_13);
  if (DAT_8018575c != 3) {
    param_5 = param_5 >> 1;
    param_7 = param_7 >> 1;
    param_9 = param_9 >> 1;
    param_11 = param_11 / 2;
    param_6 = iVar1;
  }
  if (DAT_8018575c == 1) {
    param_8 = param_8 >> 1;
    param_10 = param_10 >> 1;
    param_12 = param_12 / 2;
  }
  iVar2 = param_1[1];
  iVar1 = param_6 >> 1;
  if (param_2 != 0) {
    iVar2 = iVar2 + iVar1;
  }
  iVar3 = param_3[1];
  if (param_4 != 0) {
    iVar3 = iVar3 + iVar1;
  }
  FUN_801824c0(iVar2,iVar3,param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12,
               param_13);
  iVar2 = param_1[2];
  if (param_2 != 0) {
    iVar2 = iVar2 + iVar1;
  }
  iVar3 = param_3[2];
  if (param_4 != 0) {
    iVar3 = iVar3 + iVar1;
  }
  FUN_801824c0(iVar2,iVar3,param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12,
               param_13);
  return;
}
