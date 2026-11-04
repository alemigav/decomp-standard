/* FUN_80162c84
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x80162c84  body 0x80162c84..0x80162dff  size 380 B
 * body sha256 3d8ce8e32f1f7ca2de72aa5d12084082be4cf9843e8f11879261fc5ed0b9047b
 * provider record sha256 47bb83451f1929ad6c549badb388269fb2635827d549c0e01ff554965f62bbc0
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162c84(int param_1)

{
  byte bVar1;
  short sVar2;
  undefined2 uVar3;
  int iVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  bVar1 = *(byte *)(param_1 + 6);
  iVar8 = *(int *)(param_1 + 0x208);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      uVar7 = 0;
      if (_DAT_800e1110 < 0) {
        return;
      }
      iVar6 = 0;
      do {
        uVar7 = uVar7 + 1;
        uVar3 = *(undefined2 *)(param_1 + 500);
        iVar4 = *(int *)(param_1 + 0x234) + iVar6;
        *(undefined2 *)(iVar4 + 0x128) = uVar3;
        *(undefined2 *)(iVar4 + 0x124) = uVar3;
        iVar6 = iVar6 + 0x178;
      } while (uVar7 < 3);
      uVar5 = *(short *)(param_1 + 500) - 0x80;
      *(ushort *)(param_1 + 500) = uVar5;
      if ((int)((uint)uVar5 << 0x10) < 0) {
        *(undefined2 *)(param_1 + 500) = 0;
      }
      uVar5 = *(short *)(iVar8 + 6) - 4;
      if ((*(short *)(iVar8 + 6) != 0) &&
         (*(ushort *)(iVar8 + 6) = uVar5, (int)((uint)uVar5 << 0x10) < 1)) {
        *(undefined2 *)(iVar8 + 6) = 0;
      }
      uVar5 = *(short *)(iVar8 + 4) - 0xc;
      if (*(short *)(iVar8 + 4) == 0) {
        return;
      }
      *(ushort *)(iVar8 + 4) = uVar5;
      if (0 < (int)((uint)uVar5 << 0x10)) {
        return;
      }
      if (*(char *)(param_1 + 0x2b8) != '\0') {
        _DAT_800e1128 = _DAT_800e1128 & 0xffef;
      }
      *(undefined1 *)(iVar8 + 0xe) = 0;
      func_0x8003247c();
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)(param_1 + 6) = 1;
    *(ushort *)(param_1 + 500) = (ushort)(byte)(&DAT_8016309b)[*(byte *)(param_1 + 5)];
  }
  if ((-1 < _DAT_800e1110) &&
     (sVar2 = *(short *)(param_1 + 500), *(short *)(param_1 + 500) = sVar2 + -1, sVar2 == 1)) {
    *(undefined1 *)(param_1 + 6) = 2;
    *(undefined2 *)(param_1 + 500) = 0x1000;
  }
  return;
}
