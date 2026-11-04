/* FUN_8007fb80
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007fb80  body 0x8007fb80..0x8007fe1b  size 668 B
 * body sha256 7dd8f00d9ed196ee708fc8245853d67a5f1ad0559dd55db5ab4152a8bbcce7a6
 * provider record sha256 456b303db766756b7e2ba531c3122f15b47d411c7e1c6958ee20eeba4db53284
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007fb80(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  short sVar6;
  uint uVar3;
  uint uVar4;
  undefined2 uVar7;
  char cVar8;
  int iVar5;
  int iVar9;
  undefined4 uVar10;
  
  uVar2 = DAT_8011b560;
  iVar9 = DAT_8011b54c;
  if ((*(uint *)(param_1 + 0x1ac) & 1) == 0) {
LAB_8007fc78:
    if ((*(ushort *)(param_1 + 0x2b8) & 0x1000) == 0) {
      *(undefined2 *)(param_1 + 0x2c0) = 0;
    }
  }
  else {
    if (((*(ushort *)(param_1 + 0x2b8) & 0x1000) == 0) &&
       (sVar6 = *(short *)(param_1 + 0x2c0) + 1, *(short *)(param_1 + 0x2c0) = sVar6, 0x3c < sVar6))
    {
      *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 0x1000;
      uVar3 = FUN_80033604();
      uVar4 = FUN_80033604();
      *(undefined2 *)(param_1 + 0x2c0) = 0xf;
      *(ushort *)(param_1 + 700) =
           *(short *)(param_1 + 0x66) -
           (((ushort)((int)(uVar3 & 0xff) >> (uVar4 & 3)) & 1) * 0x100 + -0x880);
      if ((iVar9 != 0) && (uVar2 < 3000)) {
        uVar7 = FUN_80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                             (int)*(short *)(iVar9 + 0x2a),(int)*(short *)(iVar9 + 0x32));
        *(undefined2 *)(param_1 + 700) = uVar7;
        *(undefined2 *)(param_1 + 0x2c0) = 0x1e;
      }
      goto LAB_8007fd48;
    }
    if ((*(uint *)(param_1 + 0x1ac) & 1) == 0) goto LAB_8007fc78;
  }
  if ((*(ushort *)(param_1 + 0x2b8) & 0x2000) != 0) {
    if (iVar9 != 0) {
      if (uVar2 < 5000) goto LAB_8007fd48;
      if (7000 < uVar2) {
        *(undefined4 *)(param_1 + 4) = 0x1000000;
        return;
      }
      FUN_80032dbc(param_1,*(undefined4 *)(iVar9 + 0x28),*(undefined4 *)(iVar9 + 0x30),0xffffffd8);
    }
    if (*(ushort *)(param_1 + 0x2ba) < 4000) {
      *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xdfff;
      return;
    }
    return;
  }
  uVar1 = *(ushort *)(param_1 + 0x2ba);
  if (8000 < uVar1) {
    uVar2 = *(ushort *)(param_1 + 0x2b8);
    *(undefined2 *)(param_1 + 500) = 0;
    *(ushort *)(param_1 + 0x2b8) = uVar2 | 0x2000;
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    *(ushort *)(param_1 + 0x2b8) = uVar2 & 0xefff | 0x2000;
    return;
  }
  if (uVar1 < 0x96) {
    *(undefined4 *)(param_1 + 4) = 0x10b0000;
    return;
  }
  if (uVar1 < 0x7d1) {
    if (((uVar1 < 2000) && (DAT_800e1134._1_1_ == '\x02')) &&
       (cVar8 = FUN_80033160(param_1,&DAT_800e1130), cVar8 == '\0')) {
      *(undefined4 *)(param_1 + 4) = 0x1030000;
      return;
    }
    if (((iVar9 == 0) || (0x5db < uVar2)) ||
       ((iVar5 = FUN_80032e74(param_1,*(undefined4 *)(iVar9 + 0x28),*(undefined4 *)(iVar9 + 0x30),
                              0x4b0), iVar5 != 0 ||
        (uVar10 = 0xffffffd8, (*(uint *)(param_1 + 0x1ac) & 1) != 0)))) {
      iVar5 = (int)*(short *)(param_1 + 0x260);
      iVar9 = (int)*(short *)(param_1 + 0x262);
      uVar10 = 0x28;
    }
    else {
      iVar5 = *(int *)(iVar9 + 0x28);
      iVar9 = *(int *)(iVar9 + 0x30);
    }
    FUN_80032dbc(param_1,iVar5,iVar9,uVar10);
    FUN_8004e774(param_1);
    return;
  }
LAB_8007fd48:
  *(undefined4 *)(param_1 + 4) = 0x1020000;
  return;
}
