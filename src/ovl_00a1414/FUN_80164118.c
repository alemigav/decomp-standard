/* FUN_80164118
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80164118  body 0x80164118..0x8016425b  size 324 B
 * body sha256 a29c131376cde5eedc24995472664b5f6c17fe482f05cfda80b813af7d63ec85
 * provider record sha256 46042fd42dfab4c35a44dc8c9d1362dc3be9a5c9fd120ec70d13b82538724d6b
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164118(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x7000200;
    *(undefined1 *)(param_1 + 6) = 1;
    *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 0x20;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x10);
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x400);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(undefined1 *)(param_1 + 0x2b6) = 0x28;
    uVar3 = func_0x80033604();
    if ((uVar3 & 1) == 0) {
      *(undefined4 *)(param_1 + 4) = 0x1080000;
    }
    bVar1 = false;
    uVar3 = func_0x80033604();
    if (((uVar3 & 1) == 0) && (DAT_800e139f == '\0')) {
      iVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x100);
      bVar1 = iVar2 == 0;
    }
    if (bVar1) {
      *(undefined4 *)(param_1 + 4) = 0x1040200;
    }
  }
  func_0x80032b5c(param_1,0);
  return;
}
