/* FUN_80163e60
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80163e60  body 0x80163e60..0x801640df  size 640 B
 * body sha256 87662a97f8cadeace41de28a996fc7c043399b91970bff2e8f6e8bab72598935
 * provider record sha256 ab786c5668a4cc32e364afe8b628aa28a6e0fcd54b849a7b66e8c8c8e754a92b
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163e60(int param_1)

{
  byte bVar1;
  short sVar3;
  char cVar5;
  uint uVar2;
  short sVar4;
  int iVar6;
  undefined1 *puVar7;
  
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    puVar7 = &DAT_800e1130;
  }
  else {
    puVar7 = _DAT_800e13ec;
  }
  if ((*(char *)(param_1 + 0x207) == '\0') && (*(char *)(param_1 + 0x2c7) != '\0')) {
    sVar3 = func_0x80032e74(param_1,*(undefined4 *)(puVar7 + 0x28),*(undefined4 *)(puVar7 + 0x30),4)
    ;
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + sVar3;
    cVar5 = FUN_80166074(param_1);
    *(char *)(param_1 + 0x207) = cVar5;
    if (cVar5 != '\0') {
      sVar3 = *(short *)(param_1 + 0x66);
      uVar2 = func_0x80033604(param_1);
      sVar4 = sVar3 + 0x80;
      if ((uVar2 & 1) == 0) {
        sVar4 = sVar3 + -0x80;
      }
      *(short *)(param_1 + 0x66) = sVar4;
    }
  }
  *(short *)(param_1 + 0x1e2) = *(short *)(param_1 + 0x1e2) + *(short *)(param_1 + 500);
  func_0x80032bd8(param_1,0,0);
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 == 1) {
    if ((int)*(short *)(param_1 + 0x2d8) <= *(int *)(param_1 + 0x2c)) {
      *(undefined1 *)(param_1 + 7) = 2;
      *(short *)(param_1 + 500) = -*(short *)(param_1 + 500);
    }
  }
  else if (bVar1 < 2) {
    if ((bVar1 == 0) && (-1 < *(short *)(param_1 + 0x1e2))) {
      *(undefined1 *)(param_1 + 7) = 1;
      *(short *)(param_1 + 0x2d8) =
           (short)(*(int *)(param_1 + 0x2c) - (int)*(short *)(param_1 + 0x25e) >> 1);
    }
  }
  else if (bVar1 == 2) {
    if ((int)*(short *)(param_1 + 0x25e) <= *(int *)(param_1 + 0x2c) + 0xc3) {
LAB_80164024:
      *(undefined2 *)(param_1 + 6) = 0x200;
      return;
    }
    iVar6 = (int)*(short *)(param_1 + 0x1e2);
    if (*(short *)(param_1 + 500) < iVar6) goto LAB_80164030;
    sVar3 = *(short *)(param_1 + 500);
    *(undefined1 *)(param_1 + 7) = 3;
    if (sVar3 < 0) {
      sVar3 = -sVar3;
    }
    *(short *)(param_1 + 0x1e2) = sVar3;
    *(undefined2 *)(param_1 + 500) = 0;
  }
  else if ((bVar1 == 3) && ((int)*(short *)(param_1 + 0x25e) <= *(int *)(param_1 + 0x2c) + 0xc3))
  goto LAB_80164024;
  iVar6 = (int)*(short *)(param_1 + 0x1e2);
LAB_80164030:
  if (iVar6 < 0) {
    iVar6 = -iVar6;
  }
  if ((iVar6 < (int)*(short *)(param_1 + 500) << 1) && (*(byte *)(param_1 + 7) < 2)) {
    if ((*(char *)(param_1 + 0x2c4) != '\0') && ((*(uint *)(param_1 + 0x1ac) & 1) != 0)) {
      *(undefined1 *)(param_1 + 5) = 7;
      *(undefined2 *)(param_1 + 6) = 0;
    }
    if ((*(char *)(param_1 + 0x2c6) != '\0') &&
       (iVar6 = FUN_80165fb4(param_1,0,0x73a,0x180), iVar6 != 0)) {
      *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
      puVar7[0x26f] = puVar7[0x26f] | 0x80;
      *(undefined1 *)(param_1 + 5) = 3;
      *(undefined2 *)(param_1 + 6) = 0;
    }
  }
  return;
}
