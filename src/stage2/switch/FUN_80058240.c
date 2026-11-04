/* FUN_80058240
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80058240  body 0x80058240..0x800582ef  size 176 B
 * body sha256 a59da18e06d28e5f9a3aa114042a6b470a5c4a24a64533a402e0345926a38a5b
 * provider record sha256 41d69eb1b38616a29f5c2951d1617e8fac37e76c32ba990c43cea93b4098452b
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80057fc0::caseD_5(void)

{
  int iVar1;
  int unaff_s0;
  undefined4 uStack00000018;
  short sStack0000001c;
  
  FUN_800334c8();
  iVar1 = FUN_80089d54();
  if (iVar1 != 0) {
    *(undefined1 *)(unaff_s0 + 6) = 6;
  }
  FUN_80032bd8();
  uStack00000018._0_2_ = 200;
  if (*(char *)(unaff_s0 + 0x206) == '\0') {
    uStack00000018._0_2_ = -200;
  }
  FUN_8004276c(unaff_s0 + 0x14,&uStack00000018,&uStack00000018);
  iVar1 = *(int *)(unaff_s0 + 0x234);
  DAT_8010dcb8 = (int)uStack00000018._0_2_ + *(int *)(iVar1 + 0x4c);
  DAT_8010dcbc = (int)uStack00000018._2_2_ + *(int *)(iVar1 + 0x50);
  DAT_8010dcc0 = (int)sStack0000001c + *(int *)(iVar1 + 0x54);
  if ((**(uint **)(unaff_s0 + 0x214) & 0x4000) != 0) {
    FUN_80077f30(0,((**(uint **)(unaff_s0 + 0x214) & 0x2000) >> 0xd) * 3 + 4);
    DAT_800e112a = DAT_800e112a | 4;
  }
  return;
}
