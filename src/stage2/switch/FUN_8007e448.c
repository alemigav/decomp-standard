/* FUN_8007e448
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e448  body 0x8007e448..0x8007e4b3  size 108 B
 * body sha256 9c639f454895563f78d9eca1731418110e201276dd655eaade9d55773dd4b023
 * provider record sha256 932d479ba42886f8f2141e60ab23012519576f1fef88d55f0cd926fef0fd25f9
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007e304::caseD_4(void)

{
  short sVar1;
  int iVar2;
  int unaff_s0;
  undefined4 uStack00000010;
  
  FUN_800334c8();
  iVar2 = FUN_80089d54();
  if ((iVar2 != 0) &&
     (sVar1 = *(short *)(unaff_s0 + 0x1f6), *(short *)(unaff_s0 + 0x1f6) = sVar1 + -1, sVar1 == 1))
  {
    *(undefined1 *)(unaff_s0 + 6) = 5;
    *(uint *)(unaff_s0 + 0x1e8) =
         (*(byte *)((int)&uStack00000010 + (int)*(char *)(unaff_s0 + 0x206)) + 2) * 0x1000000;
  }
  FUN_80032bd8();
  if ((**(uint **)(unaff_s0 + 0x214) & 0x4000) != 0) {
    FUN_80077f30(1,((**(uint **)(unaff_s0 + 0x214) & 0x2000) >> 0xd) * 3 + 4);
    DAT_800e112a = DAT_800e112a | 4;
  }
  return;
}
