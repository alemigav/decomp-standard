/* FUN_80165528
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80165528  body 0x80165528..0x801658a7  size 896 B
 * body sha256 45476b9ee491ba2e627175cea550da8eeebb8147b5e483585d804690afd0b847
 * provider record sha256 3d11305abe07c926d160c3ec4a69df07d8e62ddd545b234dc727c4e2e3b92738
 * callees 3 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165528(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  short sVar3;
  uint uVar2;
  ushort uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x2c4);
  if ((*(short *)(iVar5 + 0x1f2) < 0) || (*(char *)(param_1 + 4) == '\a')) {
    uVar1 = 0x10e0000;
  }
  else {
    sVar3 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                            (int)*(short *)(iVar5 + 0x2a),(int)*(short *)(iVar5 + 0x32));
    uVar4 = sVar3 - *(short *)(param_1 + 0x66) & 0xfff;
    if (0x800 < uVar4) {
      uVar4 = 0x1000 - uVar4;
    }
    sVar3 = func_0x80036ea0((int)(short)uVar4,0x100,0x200,0x600);
    iVar5 = func_0x80036ea0(*(undefined4 *)(param_1 + 0x28c),0x9c4,0x1194,0x1964);
    if (iVar5 == 1) {
      if (sVar3 == 1) {
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
        if (1 < sVar3) {
          if (sVar3 < 4) {
            *(undefined4 *)(param_1 + 4) = 0x1020000;
          }
          goto LAB_80165850;
        }
        if (sVar3 != 0) goto LAB_80165850;
        uVar1 = 0x1130000;
        if (*(char *)(param_1 + 0x2ca) == '\0') {
          uVar1 = 0x1080000;
        }
      }
    }
    else if (iVar5 == 0) {
      if (sVar3 == 1) {
        uVar1 = 0x1060000;
        if (*(char *)(param_1 + 0x2ca) == '\0') {
          uVar2 = func_0x80033604();
          uVar1 = 0x1060000;
          if ((uVar2 & 3) == 0) {
            uVar1 = 0x1090000;
          }
        }
      }
      else if (sVar3 < 2) {
        if (sVar3 != 0) goto LAB_80165850;
        uVar1 = 0x1060000;
        if (*(char *)(param_1 + 0x2ca) == '\0') {
          uVar2 = func_0x80033604();
          uVar1 = 0x1060000;
          if ((uVar2 & 1) == 0) {
            uVar1 = 0x1090000;
          }
        }
      }
      else {
        if (3 < sVar3) goto LAB_80165850;
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
    else if (iVar5 == 2) {
      if (sVar3 == 1) {
        uVar2 = func_0x80033604();
        uVar1 = 0x1020000;
        if ((uVar2 & 3) != 0) {
          uVar2 = func_0x80033604();
          uVar1 = 0x1130000;
          if (((uVar2 & 1) != 0) &&
             (uVar1 = 0x10a0000, 100 < *(short *)(*(int *)(param_1 + 0x2c4) + 0x1f2))) {
            uVar1 = 0x1130000;
          }
        }
      }
      else {
        if (1 < sVar3) {
          if (sVar3 < 4) {
            *(undefined4 *)(param_1 + 4) = 0x1060000;
          }
          goto LAB_80165850;
        }
        if (sVar3 != 0) goto LAB_80165850;
        uVar1 = 0x1130000;
        if ((*(ushort *)(param_1 + 0x2c8) & 1) == 0) {
          uVar2 = func_0x80033604();
          uVar1 = 0x1130000;
          if ((uVar2 & 2) != 0) {
            uVar2 = func_0x80033604();
            uVar1 = 0x10a0000;
            if (5 < (uVar2 & 7)) {
              uVar1 = 0x1080000;
            }
          }
        }
      }
    }
    else {
      if (iVar5 != 3) goto LAB_80165850;
      if (*(uint *)(param_1 + 0x28c) < 10000) {
        *(undefined1 *)(param_1 + 0x2b5) = 2;
      }
      else {
        uVar1 = 0x10c0000;
        if (*(char *)(param_1 + 0x2b5) == '\x02') goto LAB_8016584c;
        *(undefined1 *)(param_1 + 0x2b5) = 2;
      }
      if (sVar3 < 0) goto LAB_80165850;
      if (sVar3 < 3) {
        uVar2 = func_0x80033604();
        uVar1 = 0x10a0000;
        if (4 < (uVar2 & 7)) {
          uVar1 = 0x1140000;
        }
      }
      else {
        uVar1 = 0x10c0000;
        if (sVar3 != 3) goto LAB_80165850;
      }
    }
  }
LAB_8016584c:
  *(undefined4 *)(param_1 + 4) = uVar1;
LAB_80165850:
  if (*(byte *)(param_1 + 5) != 0xf) {
    (*(code *)(&PTR_FUN_80167498)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) & 0xfffe;
  return;
}
