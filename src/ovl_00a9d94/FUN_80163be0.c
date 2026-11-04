/* FUN_80163be0
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80163be0  body 0x80163be0..0x8016403b  size 1116 B
 * body sha256 e1748fff3d91c1f73f1a38dc0f17a6735ffe252524b7cbc44d71035825738796
 * provider record sha256 49c6a2088993af1a61944a4cc505b2c03fb6ac2cc2261c09bd1e846000a1fcf8
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163be0(int param_1)

{
  bool bVar1;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  byte bVar8;
  undefined4 uVar2;
  uint uVar3;
  uint uVar9;
  
  uVar9 = *(uint *)(param_1 + 0x28c);
  sVar4 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x5f4);
  sVar5 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x2c8);
  sVar6 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x338);
  sVar7 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x100);
  if ((*(ushort *)(param_1 + 0x2b6) & 0x20) == 0) {
    if (DAT_800e139f == '\0') {
      if (((sVar6 == 0) && (uVar9 < 0xce4)) && (*(char *)(param_1 + 0x2ba) == '\0')) {
        *(undefined4 *)(param_1 + 4) = 0x10e0000;
        if (*(char *)(param_1 + 0x2d6) != '\0') {
          *(char *)(param_1 + 0x2d6) = *(char *)(param_1 + 0x2d6) + -1;
        }
      }
      if (((*(char *)(param_1 + 0x2d8) == '\0') && (sVar7 == 0)) &&
         ((uVar9 < 0xed8 && ((*(char *)(param_1 + 0x2d6) == '\0' || (_DAT_800e1322 < 0x1e)))))) {
        *(undefined4 *)(param_1 + 4) = 0x10f0000;
        bVar8 = func_0x80033604();
        *(byte *)(param_1 + 0x2d6) = (bVar8 & 3) + 3;
        return;
      }
    }
    if (sVar6 != 0) {
      *(short *)(param_1 + 0x2d4) = *(short *)(param_1 + 0x2d4) + 1;
    }
    if (((2 < DAT_8016c2d0) && (sVar6 != 0)) && (*(char *)(param_1 + 0x2ce) == '\0')) {
      *(undefined4 *)(param_1 + 4) = 0x1100000;
      bVar8 = func_0x80033604();
      *(byte *)(param_1 + 0x2d2) = (bVar8 & 1) + 1;
    }
    if (((DAT_8016c2d0 != 0) && (sVar4 != 0)) &&
       ((*(byte *)(param_1 + 0x2ce) < 0x2d && (100 < *(ushort *)(param_1 + 0x2d4))))) {
      *(undefined4 *)(param_1 + 4) = 0x1100000;
      bVar8 = func_0x80033604();
      *(byte *)(param_1 + 0x2d2) = (bVar8 & 1) + 1;
    }
    if (((sVar5 == 0) && (3000 < uVar9)) &&
       ((*(char *)(param_1 + 0x2ce) == '\0' && ((*(ushort *)(param_1 + 0x1f0) & 0x800) != 0)))) {
      *(undefined4 *)(param_1 + 4) = 0x1050000;
      *(char *)(param_1 + 0x2d7) = *(char *)(param_1 + 0x2d7) + '\x01';
      if (DAT_800e1135 == '\x05') {
        *(undefined4 *)(param_1 + 4) = 0x10c0000;
      }
    }
    if ((4 < *(byte *)(param_1 + 0x2d7)) && (DAT_8016c2d0 != 0)) {
      *(undefined4 *)(param_1 + 4) = 0x1100000;
      bVar8 = func_0x80033604();
      *(byte *)(param_1 + 0x2d2) = (bVar8 & 3) + 1;
    }
    if (200 < *(ushort *)(param_1 + 0x2d4)) {
      uVar2 = 0x1050000;
      if ((*(ushort *)(param_1 + 0x1f0) & 0x800) == 0) {
        uVar2 = 0x1040000;
      }
      *(undefined4 *)(param_1 + 4) = uVar2;
      uVar3 = func_0x80033604();
      if (((uVar3 & 3) != 0) && (DAT_8016c2d0 != 0)) {
        *(undefined4 *)(param_1 + 4) = 0x1100000;
        bVar8 = func_0x80033604();
        *(byte *)(param_1 + 0x2d2) = (bVar8 & 1) + 1;
      }
    }
    if (((8000 < uVar9) && (*(char *)(param_1 + 0x2ce) == '\0')) &&
       ((*(ushort *)(param_1 + 0x1f0) & 0x800) == 0)) {
      *(undefined4 *)(param_1 + 4) = 0x1040000;
    }
    if (sVar6 != 0) {
      return;
    }
    if (0x9c3 < uVar9) {
      return;
    }
    if (_DAT_800e1322 < 0) {
      *(undefined4 *)(param_1 + 4) = 0x10a0000;
      return;
    }
    return;
  }
  bVar1 = DAT_8016c2d0 < 3;
  *(short *)(param_1 + 0x2d4) = *(short *)(param_1 + 0x2d4) + 1;
  if (bVar1) {
LAB_80163f70:
    if (*(char *)(param_1 + 0x2d2) != '\0') goto LAB_80163fbc;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x1110000;
    *(undefined2 *)(param_1 + 0x2d4) = 0;
    if (*(char *)(param_1 + 0x2d2) != '\0') {
      *(char *)(param_1 + 0x2d2) = *(char *)(param_1 + 0x2d2) + -1;
      goto LAB_80163f70;
    }
  }
  if (sVar5 == 0) {
    *(undefined4 *)(param_1 + 4) = 0x1050000;
    *(undefined2 *)(param_1 + 0x2d4) = 0;
    if ((8000 < uVar9) || (uVar3 = func_0x80033604(), (uVar3 & 3) == 0)) {
      *(undefined4 *)(param_1 + 4) = 0x10b0000;
      *(undefined1 *)(param_1 + 0x2c2) = 5;
    }
  }
LAB_80163fbc:
  if (0x96 < *(ushort *)(param_1 + 0x2d4)) {
    *(undefined4 *)(param_1 + 4) = 0x1050000;
    if (8000 < uVar9) {
      *(undefined4 *)(param_1 + 4) = 0x10b0000;
      *(undefined1 *)(param_1 + 0x2c2) = 5;
    }
    if (DAT_8016c2d0 != 0) {
      *(undefined4 *)(param_1 + 4) = 0x1110000;
      *(undefined2 *)(param_1 + 0x2d4) = 0;
      if (*(char *)(param_1 + 0x2d2) != '\0') {
        *(char *)(param_1 + 0x2d2) = *(char *)(param_1 + 0x2d2) + -1;
      }
    }
  }
  return;
}
