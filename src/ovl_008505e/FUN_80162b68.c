/* FUN_80162b68
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80162b68  body 0x80162b68..0x80162dd3  size 620 B
 * body sha256 52bc90786b021e7e69e672a781c410a80422cb008b6a64df19f4792620cccde6
 * provider record sha256 1dabe89fa54ed50a0d495d2d155bc35b93918c0f092b956741c5ea50a54b2dab
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162b68(int param_1)

{
  byte bVar1;
  char cVar6;
  int iVar2;
  int iVar3;
  int iVar4;
  byte bVar7;
  uint uVar5;
  byte *pbVar8;
  
  pbVar8 = (byte *)(param_1 + 0x2b4);
  if (*(char *)(param_1 + 0x2c3) == '\0') {
    iVar3 = -0x7ff1eed0;
  }
  else {
    iVar3 = _DAT_800e13ec;
  }
  if (*(char *)(param_1 + 0x2cb) != '\0') {
    *(char *)(param_1 + 0x2cb) = *(char *)(param_1 + 0x2cb) + -1;
  }
  FUN_80166528(param_1,0x28,0xf0);
  cVar6 = func_0x800653d0(param_1,0,*pbVar8,1);
  iVar2 = func_0x80032e74(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),
                          0x40);
  iVar3 = func_0x80032e74(param_1,*(undefined4 *)(iVar3 + 0x28),*(undefined4 *)(iVar3 + 0x2c),0x80);
  if (*(short *)(param_1 + 0x1f6) == 0) {
    if (0xf < *(byte *)(param_1 + 0x2cc)) {
      *(undefined2 *)(param_1 + 0x1f6) = 0x1e;
      iVar4 = iVar2;
      if (iVar2 == 0) {
        iVar4 = iVar3 >> 1;
      }
      *(char *)(param_1 + 0x206) = -(char)iVar4;
    }
  }
  else {
    iVar2 = (int)*(char *)(param_1 + 0x206);
    *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + -1;
  }
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + (short)iVar2;
  func_0x80032b5c(param_1,0);
  FUN_80166590(param_1,(int)(short)iVar2);
  if ((*(char *)(param_1 + 7) == '\0') ||
     ((cVar6 == '\x01' &&
      (iVar2 = *(int *)(param_1 + 0x28) - (int)*(short *)(param_1 + 0x260),
      iVar4 = *(int *)(param_1 + 0x30) - (int)*(short *)(param_1 + 0x262),
      iVar2 = func_0x80040bb4(iVar2 * iVar2 + iVar4 * iVar4), iVar2 < 1000)))) {
    *(undefined1 *)(param_1 + 7) = 1;
    bVar1 = *pbVar8;
    bVar7 = func_0x80065628();
    *pbVar8 = bVar7;
    if (bVar1 == bVar7) {
      *pbVar8 = bVar1 + 1;
    }
    iVar2 = (int)**(short **)(_DAT_800df92c + 0x38);
    if (iVar2 == 0) {
      trap(0x1c00);
    }
    if ((iVar2 == -1) && (*pbVar8 == 0x80000000)) {
      trap(0x1800);
    }
    *pbVar8 = (byte)((int)(uint)*pbVar8 % iVar2);
  }
  if ((*(char *)(param_1 + 0x2cb) == '\0') &&
     ((iVar2 = FUN_801665e8(param_1), iVar2 != 0 || (iVar3 == 0)))) {
    *(undefined1 *)(param_1 + 5) = 3;
    *(undefined2 *)(param_1 + 6) = 0;
    uVar5 = func_0x80033604();
    *(char *)(param_1 + 0x2cb) = (&DAT_80166c90)[uVar5 & 7] + '\x1e';
  }
  return;
}
