/* FUN_801626fc
 * image   ovl_0093aba (ovl), base 0x80161cf0
 * address 0x801626fc  body 0x801626fc..0x8016289f  size 420 B
 * body sha256 1c788824b0006dcd3c05f236479b8f43267199105a5b270f65f18fc55d7dda0d
 * provider record sha256 6cb3476193cbfc191ba699d74d83751ace5c3fca2fe5b7faeb78ba5079af23a1
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801626fc(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar3;
  int iVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x2000300;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x1e2) = 0xff4c;
    sVar3 = *(short *)(param_1 + 0x1e0) + 200;
    *(short *)(param_1 + 0x1e0) = sVar3;
    if (sVar3 < 0x12d) {
      *(undefined2 *)(param_1 + 500) = 0;
    }
    else {
      *(undefined2 *)(param_1 + 0x1e0) = 300;
      *(undefined2 *)(param_1 + 500) = 0;
    }
    *(undefined2 *)(param_1 + 0x1f6) = 0;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x28);
  func_0x80089d54(param_1,param_2,param_3,0x200);
  func_0x80032bd8(param_1,0,0);
  iVar1 = (uint)*(ushort *)(param_1 + 0x1e2) + *(short *)(param_1 + 500) * 0xf;
  *(short *)(param_1 + 0x1e2) = (short)iVar1;
  if ((0 < iVar1 * 0x10000) && (*(short *)(param_1 + 0x1f6) == 0)) {
    *(undefined2 *)(param_1 + 0x1f6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x3000700;
  }
  *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
  if ((int)*(short *)(param_1 + 0x25e) < *(int *)(param_1 + 0x2c)) {
    *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x25e);
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + -0x96;
    uVar2 = func_0x80033604();
    if ((uVar2 & 1) != 0) {
      *(undefined4 *)(param_1 + 4) = 0x1070000;
    }
  }
  if ((*(uint *)(param_1 + 0x28c) < 700) && (DAT_800e139f == '\0')) {
    *(undefined4 *)(param_1 + 4) = 0x1040000;
  }
  return;
}
