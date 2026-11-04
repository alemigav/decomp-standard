/* FUN_800962fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800962fc  body 0x800962fc..0x800964bf  size 452 B
 * body sha256 d91060adab81c97f58305c1675b71d271cc4c929dbf81e817c798fe4b8dd0076
 * provider record sha256 cd3513115d4821b7148b2c06b2454efb04be77216a39d981e74efe6c93b9846f
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800962fc(int param_1)

{
  char cVar2;
  int iVar1;
  uint uVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  short sVar7;
  
  uVar3 = DAT_800c52dc + 0x3bb64U;
  if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
    uVar3 = DAT_800c52dc + 0x3c004U;
  }
  iVar4 = uVar3 + 0xa00;
  iVar5 = 3;
  if (DAT_8012bf9a == '\0') {
    if (DAT_8012bfc1 == '\0') {
      cVar2 = DAT_8012bfc0 + 3;
      if (0x78 < DAT_8012bfc0) {
        DAT_8012bfc1 = '\x01';
        cVar2 = DAT_8012bfc0 + 3;
      }
    }
    else {
      if (DAT_8012bfc0 < 0x32) {
        DAT_8012bfc1 = '\0';
      }
      cVar2 = DAT_8012bfc0 - 3;
    }
  }
  else {
    cVar2 = '<';
  }
  DAT_8012bfc0 = cVar2;
  if (DAT_8012bfa4 == 10) {
    sVar7 = DAT_8012bfcc + DAT_8012bfb6 + 0x28;
    sVar6 = DAT_8012bfce + DAT_8012bfb7 + -0x26;
  }
  else {
    sVar7 = DAT_8012bfcc + DAT_8012bfb6 + (DAT_8012bfa4 & 1) * 0x28;
    sVar6 = DAT_8012bfce + DAT_8012bfb7 + (ushort)(DAT_8012bfa4 >> 1) * 0x1e;
  }
  do {
    iVar5 = iVar5 + -1;
    iVar1 = (iVar5 + param_1 * 3) * 4;
    FUN_800478b8(iVar4,*(short *)(&DAT_80131108 + iVar1) + sVar7,
                 *(short *)(&DAT_8013110a + iVar1) + sVar6);
    FUN_8004786c(iVar4,DAT_8012bfc0,DAT_8012bfc0,DAT_8012bfc0);
    FUN_80043620();
    DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar4,0,0);
    iVar4 = iVar4 + 0x14;
  } while (iVar5 != 0);
  return;
}
