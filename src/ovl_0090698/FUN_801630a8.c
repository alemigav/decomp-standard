/* FUN_801630a8
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801630a8  body 0x801630a8..0x80163263  size 444 B
 * body sha256 6c7bd24ff47bb45eb113f2a9db1f0067a1e5331b6cf107a60c1caae9d48ceba2
 * provider record sha256 6d3952e294ab50d1650d2dabc28b2cde54b69b59bc7c53b2df0c178fbfb20491
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801630a8(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined1 uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  
  FUN_80162454();
  iVar5 = *(int *)(param_1 + 0x2dc);
  iVar6 = 9999;
  if (((iVar5 != 0) && (*(char *)(iVar5 + 4) != '\a')) &&
     (iVar6 = *(int *)(param_1 + 0x28) - *(int *)(iVar5 + 0x28),
     iVar2 = *(int *)(param_1 + 0x30) - *(int *)(iVar5 + 0x30),
     iVar6 = func_0x80040bb4(iVar6 * iVar6 + iVar2 * iVar2), *(byte *)(iVar5 + 0x2be) < 2)) {
    iVar6 = 9999;
  }
  iVar2 = func_0x800667d4(param_1 + 0x28,800,1 << (*(byte *)(param_1 + 0x1a2) & 0x1f),0x200);
  if (iVar2 == 0) {
    iVar2 = func_0x800667d4(param_1 + 0x28,800,1 << (*(byte *)(param_1 + 0x1a2) & 0x1f),0x400);
    if (iVar2 != 0) {
      if (iVar6 < 0x9c4) {
        uVar3 = 4;
        if (iVar5 != 0) {
          uVar3 = 0xb;
        }
      }
      else {
        uVar3 = 4;
        if ((*(char *)(param_1 + 0x2ce) == '\0') && (uVar3 = 4, (_DAT_800e1128 & 0x20) == 0)) {
          cVar4 = FUN_80166b94(param_1);
          *(char *)(param_1 + 0x2cc) = cVar4;
          bVar1 = false;
          if (cVar4 == '\0') {
            return;
          }
          *(char *)(param_1 + 0x2cc) = *(char *)(param_1 + 0x2cc) + -1;
          iVar6 = FUN_80166d58(param_1,0x400);
          if (iVar6 == 0) {
            iVar6 = FUN_80166d58(param_1,0xfffffc00);
            bVar1 = iVar6 == 0;
          }
          if (!bVar1) {
            return;
          }
          iVar6 = FUN_80166e18(param_1,*(undefined4 *)(param_1 + 0x2c4),
                               *(undefined1 *)(param_1 + 0x2cc));
          if (iVar6 == 0) {
            return;
          }
          *(undefined1 *)(param_1 + 5) = 10;
          *(undefined2 *)(param_1 + 6) = 0;
          *(undefined1 *)(param_1 + 0x2d2) = 1;
          _DAT_800e1128 = _DAT_800e1128 | 0x20;
          return;
        }
      }
      *(undefined1 *)(param_1 + 5) = uVar3;
      *(undefined2 *)(param_1 + 6) = 0;
    }
  }
  return;
}
