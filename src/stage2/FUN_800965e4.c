/* FUN_800965e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800965e4  body 0x800965e4..0x80096793  size 432 B
 * body sha256 e8e8b37a23b48fe328b605abeb14147c831fd2d28d8804289623627b816f2d71
 * provider record sha256 2bc33c9d964ca452500cf8f3d17c25d273d7607b12d83e2beecae305eaa6fae1
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800965e4(int param_1)

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
  iVar4 = uVar3 + 0xa3c;
  iVar5 = 2;
  if (DAT_8012bfc3 == '\0') {
    cVar2 = DAT_8012bfc2 + 3;
    if (0x7c < DAT_8012bfc2) {
      DAT_8012bfc3 = '\x01';
      cVar2 = DAT_8012bfc2 + 3;
    }
  }
  else {
    if (DAT_8012bfc2 < 0x46) {
      DAT_8012bfc3 = '\0';
    }
    cVar2 = DAT_8012bfc2 - 3;
  }
  DAT_8012bfc2 = cVar2;
  if (DAT_8012bfa5 == 10) {
    sVar7 = DAT_8012bfcc + DAT_8012bfba + 0x28;
    sVar6 = DAT_8012bfce + DAT_8012bfbb + -0x26;
  }
  else {
    sVar7 = DAT_8012bfcc + DAT_8012bfba + (DAT_8012bfa5 & 1) * 0x28;
    sVar6 = DAT_8012bfce + DAT_8012bfbb + (ushort)(DAT_8012bfa5 >> 1) * 0x1e;
  }
  do {
    iVar5 = iVar5 + -1;
    iVar1 = (iVar5 + param_1 * 3) * 4;
    FUN_800478b8(iVar4,*(short *)(&DAT_80131138 + iVar1) + sVar7,
                 *(short *)(&DAT_8013113a + iVar1) + sVar6);
    FUN_8004786c(iVar4,DAT_8012bfc2,DAT_8012bfc2,DAT_8012bfc2);
    FUN_80043620();
    DAT_800df8b8 = FUN_80043988(DAT_800df8b8,iVar4,0,0);
    iVar4 = iVar4 + 0x14;
  } while (iVar5 != 0);
  return;
}
