/* FUN_80164490
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80164490  body 0x80164490..0x8016460f  size 384 B
 * body sha256 3d76b0e8082ec5fc4108581aa594c97e63554fc0e4d5b60cd5d9093505590d49
 * provider record sha256 a4214ea9e2d8299d9723ff7bfa61986374151e23a3c2321499d7c53359892fef
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164490(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar3;
  int iVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x1001f00;
    if ((*(ushort *)(param_1 + 0x1aa) & 1) != 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0x2001f00;
    }
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 500) = 0x28;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
  func_0x800334c8(param_1,param_2,param_3,1);
  if (0x14 < *(byte *)(param_1 + 0x1ea)) {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) >> 1;
  }
  func_0x80089d54(param_1,param_2,param_3,0x10080);
  func_0x80032b5c(param_1,0);
  sVar3 = *(short *)(param_1 + 500) + -1;
  *(short *)(param_1 + 500) = sVar3;
  if (sVar3 == -1) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    iVar1 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400);
    if ((iVar1 == 0) && (*(uint *)(param_1 + 0x28c) < 3000)) {
      *(undefined4 *)(param_1 + 4) = 0x1020000;
      uVar2 = func_0x80033604();
      if (((uVar2 & 1) != 0) || (_DAT_800e1322 < 1)) {
        *(undefined4 *)(param_1 + 4) = 0x1040000;
      }
    }
  }
  return;
}
