/* FUN_8007d300
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007d300  body 0x8007d300..0x8007d4af  size 432 B
 * body sha256 870ada21f659f3a22e4bcebc890b23033f04c677e2fba471a5e4572382e444d5
 * provider record sha256 03e9a4ae876209426cce9ca0c43ed665a4968654c04a68ad9899f8dfdfdf5850
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007d300(int param_1)

{
  ushort uVar1;
  short sVar5;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar6;
  undefined4 uVar7;
  
  uVar1 = DAT_8011b560;
  iVar6 = DAT_8011b54c;
  if ((*(uint *)(param_1 + 0x1ac) & 1) == 0) {
LAB_8007d3bc:
    if ((*(ushort *)(param_1 + 0x2b8) & 0x1000) == 0) {
      *(undefined2 *)(param_1 + 0x2c0) = 0;
      goto LAB_8007d3d0;
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
      return;
    }
    if ((*(uint *)(param_1 + 0x1ac) & 1) == 0) goto LAB_8007d3bc;
LAB_8007d3d0:
    if ((*(ushort *)(param_1 + 0x2b8) & 0x1000) == 0) goto LAB_8007d424;
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
LAB_8007d424:
  if (*(ushort *)(param_1 + 0x2ba) < 3000) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  else {
    if (((uVar1 < 2000) &&
        (iVar4 = FUN_80032e74(param_1,*(undefined4 *)(iVar6 + 0x28),*(undefined4 *)(iVar6 + 0x30),
                              0x400), iVar4 == 0)) &&
       (uVar7 = 0xffffffc8, (*(uint *)(param_1 + 0x1ac) & 1) == 0)) {
      iVar4 = *(int *)(iVar6 + 0x28);
      iVar6 = *(int *)(iVar6 + 0x30);
    }
    else {
      iVar4 = (int)*(short *)(param_1 + 0x260);
      iVar6 = (int)*(short *)(param_1 + 0x262);
      uVar7 = 0x38;
    }
    FUN_80032dbc(param_1,iVar4,iVar6,uVar7);
    FUN_8004e774(param_1);
  }
  return;
}
