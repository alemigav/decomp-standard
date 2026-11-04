/* FUN_800581d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800581d4  body 0x800581d4..0x8005823f  size 108 B
 * body sha256 240c77552aaee46c5c53961f915fe4c944fc529a5d595be2880e2e0087e2da38
 * provider record sha256 6a147ef4dd6b171ca7083f6ddbfd70f624367f79e3ee445c120c085c7b363678
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80057fc0::caseD_4(void)

{
  short sVar1;
  int iVar2;
  int unaff_s0;
  undefined4 uStack00000010;
  undefined4 uStack00000018;
  short sStack0000001c;
  
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
  uStack00000018._0_2_ = 200;
  if (*(char *)(unaff_s0 + 0x206) == '\0') {
    uStack00000018._0_2_ = -200;
  }
  FUN_8004276c(unaff_s0 + 0x14,&uStack00000018,&uStack00000018);
  iVar2 = *(int *)(unaff_s0 + 0x234);
  DAT_8010dcb8 = (int)uStack00000018._0_2_ + *(int *)(iVar2 + 0x4c);
  DAT_8010dcbc = (int)uStack00000018._2_2_ + *(int *)(iVar2 + 0x50);
  DAT_8010dcc0 = (int)sStack0000001c + *(int *)(iVar2 + 0x54);
  if ((**(uint **)(unaff_s0 + 0x214) & 0x4000) != 0) {
    FUN_80077f30(0,((**(uint **)(unaff_s0 + 0x214) & 0x2000) >> 0xd) * 3 + 4);
    DAT_800e112a = DAT_800e112a | 4;
  }
  return;
}
