/* FUN_80097c4c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80097c4c  body 0x80097c4c..0x80097f13  size 712 B
 * body sha256 6486860b2671720e0cd024dcbc322c2901f2c96c08658bf73db415473a53c965
 * provider record sha256 367edae347dfcaf00c28ab56df564040e046912ffae5d85460205e168d8278e8
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80097c4c(void)

{
  char cVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  short sVar9;
  short sVar10;
  uint uVar11;
  
  sVar2 = DAT_8012bfce;
  uVar6 = DAT_800c52dc + 0x3bb64U;
  if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
    uVar6 = DAT_800c52dc + 0x3c004U;
  }
  iVar7 = uVar6 + 0x640;
  uVar5 = 7;
  uVar11 = (uint)DAT_8012bfa0;
  sVar10 = DAT_8012bfce + -0x29;
  cVar1 = (&DAT_800e8eca)[uVar11 * 4];
  sVar9 = DAT_8012bfcc + -0x34;
  if (DAT_8012bfa8 == '\x01') {
    uVar5 = 6;
    iVar7 = uVar6 + 0x654;
    sVar9 = DAT_8012bfcc;
  }
  psVar3 = (short *)(&DAT_801313fc + uVar5 * 4);
  uVar6 = uVar5;
  do {
    iVar8 = iVar7;
    uVar6 = uVar6 - 1;
    iVar7 = iVar8 + 0x14;
    FUN_800478b8(iVar8,*psVar3 + sVar9,psVar3[1] + sVar10);
    psVar3 = psVar3 + -2;
  } while (2 < uVar6);
  iVar4 = iVar7;
  do {
    uVar5 = uVar5 - 1;
    iVar4 = iVar4 + -0x14;
    DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar4,0,0);
  } while (2 < (uVar5 & 0xffff));
  FUN_800478b8(iVar7,sVar9 + 5,sVar2 + -0x23);
  *(undefined **)(iVar8 + 0x20) = &DAT_8012f530;
  *(undefined2 *)(iVar8 + 0x1e) = 0x200;
  iVar4 = iVar8 + 0x28;
  DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar7,0,0);
  if (cVar1 == '\0') {
    FUN_800478b8(iVar4,sVar9 + 0x19,sVar2 + -0x23);
    FUN_800479bc(iVar4,0x28,0x1e);
  }
  else {
    FUN_800478b8(iVar4,sVar9 + 5,sVar2 + -0x23);
    FUN_800479bc(iVar4,0x50,0x1e);
    if (cVar1 == '\x02') {
      uVar11 = uVar11 - 1;
    }
  }
  FUN_800478ac(iVar4,(uVar11 & 1) * 0x28,(uVar11 >> 1) * 0x1e & 0xfffe);
  *(undefined **)(iVar8 + 0x34) = &DAT_8012f530;
  *(undefined2 *)(iVar8 + 0x32) = 0x200;
  if (DAT_8012bfa0 != 0x80) {
    DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar4,0,0);
  }
  return;
}
