/* FUN_8007ccec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ccec  body 0x8007ccec..0x8007cf97  size 684 B
 * body sha256 ba477ea6b25981806a56f60e2bf452e10e9d86ec4fabb69e9c65ffe9911ab30a
 * provider record sha256 f563248de1c51dff76e23a1f17b16c360be9818685935dc01bdc9013afc1f801
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007ccec(int param_1)

{
  ushort uVar1;
  short sVar4;
  uint uVar2;
  char cVar5;
  int iVar3;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  
  iVar6 = DAT_8011b54c;
  uVar8 = (uint)DAT_8011b560;
  if ((*(uint *)(param_1 + 0x1ac) & 1) == 0) {
LAB_8007cdac:
    if ((*(ushort *)(param_1 + 0x2b8) & 0x1000) == 0) {
      *(undefined2 *)(param_1 + 0x2c0) = 0;
      goto LAB_8007cdc0;
    }
  }
  else {
    if (((*(ushort *)(param_1 + 0x2b8) & 0x1000) == 0) &&
       (sVar4 = *(short *)(param_1 + 0x2c0) + 1, *(short *)(param_1 + 0x2c0) = sVar4, 0x3c < sVar4))
    {
      *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 0x1000;
      uVar8 = FUN_80033604();
      uVar2 = FUN_80033604();
      *(undefined2 *)(param_1 + 0x2c0) = 0x1e;
      *(ushort *)(param_1 + 700) =
           *(short *)(param_1 + 0x66) -
           (((ushort)((int)(uVar8 & 0xff) >> (uVar2 & 3)) & 1) * 0x100 + -0x880);
      return;
    }
    if ((*(uint *)(param_1 + 0x1ac) & 1) == 0) goto LAB_8007cdac;
LAB_8007cdc0:
    if ((*(ushort *)(param_1 + 0x2b8) & 0x1000) == 0) goto LAB_8007ce10;
  }
  if (*(short *)(param_1 + 0x2c0) != 0) {
    FUN_80032ef4(param_1,(int)*(short *)(param_1 + 700),0x28);
    sVar4 = *(short *)(param_1 + 0x2c0);
    *(short *)(param_1 + 0x2c0) = sVar4 + -1;
    if (sVar4 == 1) {
      *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xefff;
      return;
    }
    return;
  }
LAB_8007ce10:
  if (iVar6 != 0) {
    if (*(char *)(param_1 + 0x1ed) != '\0') {
      (*(code *)(&PTR_LAB_8011b268)[*(byte *)((int)&PTR_LAB_8011b210 + (uint)*(byte *)(iVar6 + 8))])
                (param_1,*(undefined2 *)(param_1 + 0x1aa));
    }
    if ((uVar8 < 2000) && (uVar8 < *(uint *)(param_1 + 0x28c))) {
      (*(code *)(&PTR_LAB_8011b268)[*(byte *)((int)&PTR_LAB_8011b210 + (uint)*(byte *)(iVar6 + 8))])
                (param_1,*(undefined2 *)(param_1 + 0x1aa));
    }
  }
  uVar1 = *(ushort *)(param_1 + 0x2ba);
  if (uVar1 < 300) {
    *(undefined4 *)(param_1 + 4) = 0x10b0000;
  }
  else if (uVar1 < 0x1389) {
    if (((uVar1 < 2000) && (DAT_800e1134._1_1_ == '\x02')) &&
       (cVar5 = FUN_80033160(param_1,&DAT_800e1130), cVar5 == '\0')) {
      *(undefined4 *)(param_1 + 4) = 0x1030000;
    }
    else {
      if (((uVar8 < 0x5dc) &&
          (iVar3 = FUN_80032e74(param_1,*(undefined4 *)(iVar6 + 0x28),*(undefined4 *)(iVar6 + 0x30),
                                0x4b0), iVar3 == 0)) &&
         (uVar7 = 0xffffffd8, (*(uint *)(param_1 + 0x1ac) & 1) == 0)) {
        iVar3 = *(int *)(iVar6 + 0x28);
        iVar6 = *(int *)(iVar6 + 0x30);
      }
      else {
        iVar3 = (int)*(short *)(param_1 + 0x260);
        iVar6 = (int)*(short *)(param_1 + 0x262);
        uVar7 = 0x28;
      }
      FUN_80032dbc(param_1,iVar3,iVar6,uVar7);
      FUN_8004e774(param_1);
    }
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x1020000;
  }
  return;
}
