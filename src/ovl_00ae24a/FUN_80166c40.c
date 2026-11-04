/* FUN_80166c40
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x80166c40  body 0x80166c40..0x80166e1f  size 480 B
 * body sha256 960c59868902d05a884312164993f9f49f7557923987e48d4c14a64cb9167772
 * provider record sha256 9899dc6efc85f9509bd4d570dc15f2688779f65bcdf9ac86e8154e857aff650c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166c40(int param_1)

{
  ushort uVar3;
  uint uVar1;
  uint uVar2;
  int iVar4;
  short local_18;
  short local_16;
  short local_14;
  
  if (((*(ushort *)(param_1 + 0x2c2) & 4) != 0) && ((*(ushort *)(param_1 + 0x2c2) & 2) != 0)) {
    uVar3 = func_0x80033604();
    local_18 = 0x80 - (uVar3 & 0xff);
    uVar3 = func_0x80033604();
    local_16 = 0x80 - (uVar3 & 0xff);
    uVar3 = func_0x80033604();
    local_14 = 0x80 - (uVar3 & 0xff);
    if ((*(byte *)(param_1 + 0x1e9) & 7) == 0) {
      iVar4 = *(int *)(param_1 + 0x234);
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      func_0x80037780((uVar1 & 1) << 0x10 | (uVar2 & 0xff) * 4 + 0x1fa0,
                      (int)*(short *)(param_1 + 0x66),iVar4 + 0x38,&local_18);
      iVar4 = *(int *)(param_1 + 0x234);
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      func_0x80037780((uVar1 & 1) << 0x10 | (uVar2 & 0xff) * 4 + 0x1fa0,
                      (int)*(short *)(param_1 + 0x66),iVar4 + 0x618,&local_18);
      iVar4 = *(int *)(param_1 + 0x234);
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      func_0x80037780((uVar1 & 1) << 0x10 | (uVar2 & 0xff) * 4 + 0x1fa0,
                      (int)*(short *)(param_1 + 0x66),iVar4 + 0x790,&local_18);
    }
    if ((*(byte *)(param_1 + 0x1e9) & 7) == 4) {
      iVar4 = *(int *)(param_1 + 0x234);
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      func_0x80037780((uVar1 & 1) << 0x10 | (uVar2 & 0xff) * 4 + 0x1fa0,
                      (int)*(short *)(param_1 + 0x66),iVar4 + 0x908,&local_18);
      iVar4 = *(int *)(param_1 + 0x234);
      local_18 = local_18 + 0x4b0;
      local_16 = local_16 + 400;
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      func_0x80037780((uVar1 & 1) << 0x10 | (uVar2 & 0xff) * 4 + 0x1fa0,
                      (int)*(short *)(param_1 + 0x66),iVar4 + 0x1b0,&local_18);
    }
  }
  return;
}
