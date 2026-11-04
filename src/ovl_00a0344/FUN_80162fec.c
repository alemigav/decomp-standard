/* FUN_80162fec
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80162fec  body 0x80162fec..0x80163203  size 536 B
 * body sha256 57df703dc5f24e63127c0c43c3f5c8aaef8ea0d2b8cd261d00a7379557956c60
 * provider record sha256 0fff53150790b3016878846f0dbf0a03dd4b579b49338a9fa19893711fe22aac
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162fec(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  ushort uVar2;
  undefined1 uVar4;
  int iVar3;
  char cVar5;
  int iVar6;
  short sVar7;
  uint uVar8;
  
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        if ((*(char *)(param_1 + 0x207) == '\0') &&
           (iVar3 = func_0x80089d54(param_1,param_2,param_3,0x200), iVar3 != 0)) {
          *(undefined1 *)(param_1 + 0x207) = 1;
        }
        if (*(char *)(param_1 + 0x206) == '\0') {
          *(undefined1 *)(param_1 + 7) = 3;
          *(undefined4 *)(param_1 + 0x1e8) = 0x33c0700;
          *(undefined2 *)(param_1 + 0x2c2) = *(undefined2 *)(param_1 + 0x1f6);
          return;
        }
        if (*(short *)(param_1 + 0x1f6) < 1) {
          sVar7 = *(short *)(param_1 + 0x2c2) + 0x100;
        }
        else {
          sVar7 = *(short *)(param_1 + 0x2c2) + -0x100;
        }
        *(short *)(param_1 + 0x2c2) = sVar7;
        *(char *)(param_1 + 0x206) = *(char *)(param_1 + 0x206) + -1;
        return;
      }
      if (bVar1 != 3) {
        return;
      }
      func_0x80089d54(param_1,param_2,param_3,0x200);
      if (*(char *)(param_1 + 0x1ea) != '\0') {
        return;
      }
      if (*(char *)(param_1 + 0x2c5) == '\0') {
        cVar5 = *(char *)(param_1 + 0x2cb) + -1;
      }
      else {
        cVar5 = '\0';
      }
      *(char *)(param_1 + 0x2cb) = cVar5;
      if (cVar5 == '\0') {
        *(undefined2 *)(param_1 + 6) = 0x200;
        return;
      }
      *(undefined2 *)(param_1 + 6) = 0;
      *(undefined1 *)(param_1 + 0x2be) = 0x3c;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x4000700;
    *(undefined1 *)(param_1 + 0x206) = 0;
    *(undefined1 *)(param_1 + 0x207) = 0;
    *(undefined1 *)(param_1 + 0x2c5) = 0;
    *(undefined2 *)(param_1 + 500) = *(undefined2 *)(param_1 + 700);
    *(ushort *)(param_1 + 0x1f6) = *(ushort *)(param_1 + 0x2c2);
    *(ushort *)(param_1 + 0x2c2) = *(ushort *)(param_1 + 0x2c2) & 0xfff;
  }
  uVar2 = *(ushort *)(param_1 + 0x2c2);
  iVar6 = (int)((0x800 - (uint)uVar2) * 0x10000) >> 0x10;
  iVar3 = iVar6;
  if (iVar6 < 0) {
    iVar3 = -iVar6;
  }
  if (0x100 < iVar3) {
    if (iVar6 < 1) {
      sVar7 = uVar2 - 0x100;
    }
    else {
      sVar7 = uVar2 + 0x100;
    }
    *(short *)(param_1 + 0x2c2) = sVar7;
    *(char *)(param_1 + 0x206) = *(char *)(param_1 + 0x206) + '\x01';
  }
  func_0x80089d54(param_1,param_2,param_3,0x200);
  func_0x80033648(param_1);
  uVar8 = **(uint **)(param_1 + 0x214);
  if (((uVar8 & 0x20000) != 0) && (*(char *)(param_1 + 0x2c5) == '\0')) {
    uVar4 = FUN_80163a30(param_1,5);
    *(undefined1 *)(param_1 + 0x2c5) = uVar4;
  }
  if ((uVar8 & 0x10000) != 0) {
    *(undefined1 *)(param_1 + 7) = 2;
  }
  return;
}
