/* FUN_80165fa8
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80165fa8  body 0x80165fa8..0x80166427  size 1152 B
 * body sha256 d020c745abe3f72ffc49e0300f99ea039b1d502e9b716c99ca1edf2ce418d231
 * provider record sha256 04681e7b1f0f041601ee0f37f9bdd519fce9cf09f0e2fb2dc0eb212256897b6c
 * callees 3 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165fa8(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  short sVar4;
  int iVar3;
  ushort uVar5;
  
  if ((*(short *)(*(int *)(param_1 + 0x2c4) + 0x1f2) < 0) || (*(char *)(param_1 + 4) == '\a')) {
    uVar1 = 0x10e0000;
  }
  else {
    if (((*(ushort *)(param_1 + 0x1aa) & 0x10) != 0) && (*(short *)(param_1 + 0x1f2) < 0x32)) {
      uVar2 = func_0x80033604();
      uVar1 = 0x1010000;
      if ((uVar2 & 3) == 0) goto LAB_801663cc;
    }
    sVar4 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                            (int)*(short *)(*(int *)(param_1 + 0x2c4) + 0x2a),
                            (int)*(short *)(*(int *)(param_1 + 0x2c4) + 0x32));
    uVar5 = sVar4 - *(short *)(param_1 + 0x66) & 0xfff;
    if (0x800 < uVar5) {
      uVar5 = 0x1000 - uVar5;
    }
    sVar4 = func_0x80036ea0((int)(short)uVar5,0x100,0x200,0x600);
    iVar3 = func_0x80036ea0(*(undefined4 *)(param_1 + 0x28c),0x9c4,0x1194,0x1964);
    if (iVar3 == 1) {
      if (sVar4 == 1) {
        uVar1 = 0x1080000;
        if (*(char *)(param_1 + 0x2ca) != '\0') {
          uVar2 = func_0x80033604();
          uVar1 = 0x1060000;
          if ((uVar2 & 1) == 0) {
            uVar1 = 0x1130000;
          }
        }
      }
      else {
        if (1 < sVar4) {
          if (sVar4 < 4) {
            *(undefined4 *)(param_1 + 4) = 0x1020000;
          }
          goto LAB_801663d0;
        }
        if (sVar4 != 0) goto LAB_801663d0;
        uVar1 = 0x1130000;
        if (*(char *)(param_1 + 0x2ca) == '\0') {
          if (99 < *(short *)(*(int *)(param_1 + 0x2c4) + 0x1f2)) {
            uVar2 = func_0x80033604();
            uVar1 = 0x10a0000;
            if (2 < (uVar2 & 7)) {
              uVar2 = func_0x80033604();
              uVar1 = 0x1130000;
              if ((uVar2 & 2) == 0) {
                uVar1 = 0x1080000;
              }
            }
            *(undefined4 *)(param_1 + 4) = uVar1;
            if (99 < *(short *)(*(int *)(param_1 + 0x2c4) + 0x1f2)) goto LAB_801663d0;
          }
          uVar2 = func_0x80033604();
          uVar1 = 0x10a0000;
          if (1 < (uVar2 & 7)) {
            uVar1 = 0x1080000;
          }
        }
      }
    }
    else if (iVar3 == 0) {
      if (sVar4 == 1) {
        uVar1 = 0x1060000;
        if (*(char *)(param_1 + 0x2ca) == '\0') {
          uVar2 = func_0x80033604();
          uVar1 = 0x1060000;
          if ((uVar2 & 3) == 0) {
            uVar1 = 0x1090000;
          }
        }
      }
      else if (sVar4 < 2) {
        if (sVar4 != 0) goto LAB_801663d0;
        uVar1 = 0x1060000;
        if (*(char *)(param_1 + 0x2ca) == '\0') {
          uVar2 = func_0x80033604();
          uVar1 = 0x1060000;
          if ((uVar2 & 3) == 0) {
            uVar1 = 0x1090000;
          }
        }
      }
      else {
        if (3 < sVar4) goto LAB_801663d0;
        uVar1 = 0x1060000;
        if (*(char *)(param_1 + 0x2ca) == '\0') {
          uVar2 = func_0x80033604();
          uVar1 = 0x1020000;
          if ((uVar2 & 3) == 0) {
            uVar1 = 0x1090000;
          }
        }
      }
    }
    else if (iVar3 == 2) {
      if (sVar4 == 1) {
        uVar2 = func_0x80033604();
        uVar1 = 0x1130000;
        if ((uVar2 & 3) == 0) {
          uVar1 = 0x1020000;
        }
      }
      else {
        if (1 < sVar4) {
          if (sVar4 < 4) {
            *(undefined4 *)(param_1 + 4) = 0x1140000;
          }
          goto LAB_801663d0;
        }
        if (sVar4 != 0) goto LAB_801663d0;
        uVar1 = 0x1130000;
        if ((*(ushort *)(param_1 + 0x2c8) & 1) == 0) {
          if (99 < *(short *)(*(int *)(param_1 + 0x2c4) + 0x1f2)) {
            uVar2 = func_0x80033604();
            uVar1 = 0x10a0000;
            if (4 < (uVar2 & 7)) {
              uVar1 = 0x1130000;
            }
            *(undefined4 *)(param_1 + 4) = uVar1;
            if (99 < *(short *)(*(int *)(param_1 + 0x2c4) + 0x1f2)) goto LAB_801663d0;
          }
          uVar2 = func_0x80033604();
          uVar1 = 0x10a0000;
          if (1 < (uVar2 & 7)) {
            uVar1 = 0x1130000;
          }
        }
      }
    }
    else {
      if (iVar3 != 3) goto LAB_801663d0;
      if (*(uint *)(param_1 + 0x28c) < 10000) {
        *(undefined1 *)(param_1 + 0x2b5) = 2;
      }
      else {
        uVar1 = 0x10c0000;
        if (*(char *)(param_1 + 0x2b5) == '\x02') goto LAB_801663cc;
        *(undefined1 *)(param_1 + 0x2b5) = 2;
      }
      if (sVar4 < 0) goto LAB_801663d0;
      if (sVar4 < 3) {
        if (99 < *(short *)(*(int *)(param_1 + 0x2c4) + 0x1f2)) {
          uVar2 = func_0x80033604();
          uVar1 = 0x10a0000;
          if (4 < (uVar2 & 7)) {
            uVar1 = 0x1140000;
          }
          *(undefined4 *)(param_1 + 4) = uVar1;
          if (99 < *(short *)(*(int *)(param_1 + 0x2c4) + 0x1f2)) goto LAB_801663d0;
        }
        uVar2 = func_0x80033604();
        uVar1 = 0x10a0000;
        if (1 < (uVar2 & 7)) {
          uVar1 = 0x1140000;
        }
      }
      else {
        uVar1 = 0x10c0000;
        if (sVar4 != 3) goto LAB_801663d0;
      }
    }
  }
LAB_801663cc:
  *(undefined4 *)(param_1 + 4) = uVar1;
LAB_801663d0:
  if (*(byte *)(param_1 + 5) != 0xf) {
    (*(code *)(&PTR_FUN_80168cb4)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) & 0xfffe;
  return;
}
