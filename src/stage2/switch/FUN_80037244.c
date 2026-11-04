/* FUN_80037244
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80037244  body 0x80037244..0x80037253  size 16 B
 * body sha256 39e28acec68e765b8444eb703fe8de12b5a016318b02a397bf76a95e6c70fd59
 * provider record sha256 1b7b3dc833d0ccb667dcaf002a189b8fbb47816a6e2952b0671eb1c484039fe1
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8003722c::caseD_1(void)

{
  short sVar1;
  uint uVar2;
  int unaff_s0;
  int unaff_s1;
  short unaff_s2;
  short sStack00000010;
  short sStack00000014;
  
  sVar1 = FUN_80032d14(0,0,(int)sStack00000010,(int)sStack00000014);
  uVar2 = (sVar1 - unaff_s0) + (int)unaff_s2 & 0xfff;
  if ((int)unaff_s2 << 1 <= (int)uVar2) {
    if (uVar2 < 0x801) {
      sVar1 = *(short *)(unaff_s1 + 0x66) + unaff_s2;
    }
    else {
      sVar1 = *(short *)(unaff_s1 + 0x66) - unaff_s2;
    }
    *(short *)(unaff_s1 + 0x66) = sVar1;
  }
  return;
}
