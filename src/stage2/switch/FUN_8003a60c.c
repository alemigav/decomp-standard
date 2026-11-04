/* FUN_8003a60c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003a60c  body 0x8003a60c..0x8003a97f  size 884 B
 * body sha256 f4e9bd5540a8976fe5bd5a774edea5c6a593b1321f3c60fb6aeebbd458e8d66b
 * provider record sha256 e1ac636a16a1deb43caf36bfbccf61b73cc0d98cb86bb736998f2c17c7ec9214
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8003a604::caseD_0(void)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  short sVar8;
  uint uVar6;
  uint uVar7;
  short sVar9;
  uint uVar10;
  undefined4 uStack00000010;
  undefined2 uStack00000014;
  undefined4 uStack00000018;
  int iStack0000001c;
  int iStack00000020;
  undefined4 uStack00000028;
  
  iVar3 = DAT_800ebb94;
  *(undefined2 *)(DAT_800ebb94 + 0x18) = *(undefined2 *)(DAT_800ebb94 + 0x12);
  DAT_80131781 = 1;
  uStack00000018 = (int)*(short *)(iVar3 + 0x34);
  iStack0000001c = (int)*(short *)(iVar3 + 0x36);
  iStack00000020 = (int)*(short *)(iVar3 + 0x38);
  FUN_80077adc(0x1100001,&uStack00000018);
  FUN_800609e0(0x120,(int)*(short *)(DAT_800ebb94 + 0x22),&uStack00000028,0x3000e);
  sVar9 = 0;
  if (iStack0000001c < iRam00000124) {
    iStack0000001c = iRam00000124 - iStack0000001c;
  }
  else {
    if (iStack0000001c <= iRam00000124) goto LAB_8003a6c0;
    iStack0000001c = iStack0000001c - iRam00000124;
  }
  sVar9 = (short)(iStack0000001c / 5);
LAB_8003a6c0:
  uStack00000018 = iRam00000120 - *(short *)(DAT_800ebb94 + 0x34);
  if (uStack00000018 < 0) {
    uStack00000018 = -uStack00000018;
  }
  iStack0000001c = iRam00000124 - *(short *)(DAT_800ebb94 + 0x36);
  if (iStack0000001c < 0) {
    iStack0000001c = -iStack0000001c;
  }
  iStack00000020 = iRam00000128 - *(short *)(DAT_800ebb94 + 0x38);
  if (iStack00000020 < 0) {
    iStack00000020 = -iStack00000020;
  }
  iVar3 = FUN_80040bb4(uStack00000018 * uStack00000018 + iStack00000020 * iStack00000020);
  iVar4 = FUN_80040bb4(uStack00000018 * uStack00000018 + iStack00000020 * iStack00000020);
  uVar5 = FUN_80040bb4(iStack0000001c * iStack0000001c + iVar3 * iVar4);
  sVar8 = FUN_80078824((int)*(short *)(DAT_800ebb94 + 0x34),(int)*(short *)(DAT_800ebb94 + 0x38),
                       iRam00000120,iRam00000128);
  sVar1 = *(short *)(DAT_800ebb94 + 0x22);
  uStack00000010._0_2_ = *(short *)(DAT_800ebb94 + 0x2c);
  uStack00000010._2_2_ = *(short *)(DAT_800ebb94 + 0x2e);
  uVar5 = uVar5 / 0x1b0;
  uStack00000014 = *(undefined2 *)(DAT_800ebb94 + 0x30);
  if (uVar5 == 0) {
    uVar5 = 1;
  }
  uVar10 = (uint)(iRam00000124 - *(short *)(DAT_800ebb94 + 0x36)) / uVar5;
  if (uVar5 == 0) {
    trap(0x1c00);
  }
  do {
    uVar5 = uVar5 - 1;
    uVar6 = FUN_80038a20(0x6012600,((int)sVar8 - (int)sVar1) * 0x10000 >> 0x10,DAT_800ebb94 + 0x4c,
                         &uStack00000010);
    if ((uVar6 & 0xff) < 0xff) {
      iVar3 = (uVar6 & 0xff) * 0x7c;
      uVar6 = FUN_80033604();
      *(short *)(&DAT_800ebdec + iVar3) = (short)((uVar6 & 0xff) % 0x1e) * 10 + -0x96;
      uVar6 = FUN_80033604();
      *(short *)(&DAT_800ebdee + iVar3) = (short)((uVar6 & 0xff) % 0x32) * 0x28 + -1000;
      uVar6 = FUN_80033604();
      uVar7 = FUN_80033604();
      sVar2 = sVar9;
      if ((uVar7 & 2) != 0) {
        sVar2 = sVar9 + 0x800;
      }
      *(short *)(&DAT_800ebdf0 + iVar3) = (short)((uVar6 & 0xff) % 0x14) * 0x1e + 0x338 + sVar2;
    }
    else {
      uVar5 = 0;
    }
    uStack00000010._2_2_ = uStack00000010._2_2_ + 0x1b0;
    uStack00000010._0_2_ = uStack00000010._0_2_ - (short)uVar10;
  } while (uVar5 != 0);
  FUN_800274f8(0x100,0,7,1);
  FUN_800275c0(0,0x2000,0x8421,0);
  *(char *)(DAT_800ebb94 + 2) = *(char *)(DAT_800ebb94 + 2) + '\x01';
  return;
}
