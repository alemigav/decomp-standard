/* FUN_8007fe1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007fe1c  body 0x8007fe1c..0x800800a7  size 652 B
 * body sha256 62756ac92387b6355a93062a16b7e4ca336b20b40c44a54db508d12ac5a3f7bf
 * provider record sha256 b3e1d81b817e298ca64f8ad0f44605fc4e2154bd7b7c2e45f719c6460953d1cd
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007fe1c(int param_1)

{
  ushort uVar1;
  short sVar5;
  uint uVar2;
  uint uVar3;
  undefined2 uVar6;
  int iVar4;
  int iVar7;
  undefined4 uVar8;
  
  uVar1 = DAT_8011b560;
  iVar7 = DAT_8011b54c;
  if ((*(uint *)(param_1 + 0x1ac) & 1) == 0) {
LAB_8007ff1c:
    if ((*(ushort *)(param_1 + 0x2b8) & 0x1000) == 0) {
      *(undefined2 *)(param_1 + 0x2c0) = 0;
      goto LAB_8007ff30;
    }
  }
  else {
    if (((*(ushort *)(param_1 + 0x2b8) & 0x1000) == 0) &&
       (sVar5 = *(short *)(param_1 + 0x2c0) + 1, *(short *)(param_1 + 0x2c0) = sVar5, 0x3c < sVar5))
    {
      *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 0x1000;
      uVar2 = FUN_80033604();
      uVar3 = FUN_80033604();
      *(undefined2 *)(param_1 + 0x2c0) = 0xf;
      *(ushort *)(param_1 + 700) =
           *(short *)(param_1 + 0x66) -
           (((ushort)((int)(uVar2 & 0xff) >> (uVar3 & 3)) & 1) * 0x100 + -0x880);
      if ((iVar7 != 0) && (uVar1 < 3000)) {
        uVar6 = FUN_80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                             (int)*(short *)(iVar7 + 0x2a),(int)*(short *)(iVar7 + 0x32));
        *(undefined2 *)(param_1 + 700) = uVar6;
        *(undefined2 *)(param_1 + 0x2c0) = 0x1e;
      }
      *(undefined4 *)(param_1 + 4) = 0x1020000;
      return;
    }
    if ((*(uint *)(param_1 + 0x1ac) & 1) == 0) goto LAB_8007ff1c;
LAB_8007ff30:
    if ((*(ushort *)(param_1 + 0x2b8) & 0x1000) == 0) goto LAB_8007ff80;
  }
  if (*(short *)(param_1 + 0x2c0) != 0) {
    FUN_80032ef4(param_1,(int)*(short *)(param_1 + 700),0x50);
    sVar5 = *(short *)(param_1 + 0x2c0);
    *(short *)(param_1 + 0x2c0) = sVar5 + -1;
    if (sVar5 == 1) {
      *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xefff;
      return;
    }
    return;
  }
LAB_8007ff80:
  if ((*(ushort *)(param_1 + 0x2b8) & 0x2000) == 0) {
    if (*(ushort *)(param_1 + 0x2ba) < 0x1f41) {
      if (*(ushort *)(param_1 + 0x2ba) < 1000) {
        *(undefined4 *)(param_1 + 4) = 0x1010000;
      }
      else {
        if ((((iVar7 == 0) || (1999 < uVar1)) ||
            (iVar4 = FUN_80032e74(param_1,*(undefined4 *)(iVar7 + 0x28),
                                  *(undefined4 *)(iVar7 + 0x30),0x400), iVar4 != 0)) ||
           (uVar8 = 0xffffffb8, (*(uint *)(param_1 + 0x1ac) & 1) != 0)) {
          iVar4 = (int)*(short *)(param_1 + 0x260);
          iVar7 = (int)*(short *)(param_1 + 0x262);
          uVar8 = 0x48;
        }
        else {
          iVar4 = *(int *)(iVar7 + 0x28);
          iVar7 = *(int *)(iVar7 + 0x30);
        }
        FUN_80032dbc(param_1,iVar4,iVar7,uVar8);
        FUN_8004e774(param_1);
      }
    }
    else {
      uVar1 = *(ushort *)(param_1 + 0x2b8);
      *(undefined2 *)(param_1 + 500) = 0;
      *(ushort *)(param_1 + 0x2b8) = uVar1 | 0x2000;
      *(undefined4 *)(param_1 + 4) = 0x1000000;
      *(ushort *)(param_1 + 0x2b8) = uVar1 & 0xefff | 0x2000;
    }
  }
  else {
    if (iVar7 != 0) {
      if (7000 < uVar1) {
        *(undefined4 *)(param_1 + 4) = 0x1000000;
        return;
      }
      FUN_80032dbc(param_1,*(undefined4 *)(iVar7 + 0x28),*(undefined4 *)(iVar7 + 0x30),0xffffffc8);
    }
    if (*(ushort *)(param_1 + 0x2ba) < 3000) {
      *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xdfff;
    }
  }
  return;
}
