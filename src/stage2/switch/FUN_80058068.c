/* FUN_80058068
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80058068  body 0x80058068..0x800580c3  size 92 B
 * body sha256 8ba8c6e2390dbfa9ebca7eaab0c3445396749cdab76ab8afd771f341a7dbd336
 * provider record sha256 03109b3b21e166db6b4560336724073116a815ae368117388eb5b99855e6a109
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80057fc0::caseD_2(void)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  char cVar4;
  int unaff_s0;
  undefined4 uStack00000010;
  undefined4 uStack00000018;
  short sStack0000001c;
  
  bVar1 = *(byte *)((int)&uStack00000010 + (int)*(char *)(unaff_s0 + 0x206));
  *(undefined1 *)(unaff_s0 + 6) = 3;
  cVar4 = *(char *)(unaff_s0 + 0x1a2) + *(char *)(unaff_s0 + 0x1f7);
  *(char *)(unaff_s0 + 0x1a2) = cVar4;
  *(uint *)(unaff_s0 + 0x1e8) = (uint)bVar1 * 0x1000000 + 0x300;
  if (*(char *)(unaff_s0 + 0x206) != '\0') {
    *(char *)(unaff_s0 + 0x1a2) = cVar4 + *(char *)(unaff_s0 + 0x1f7) * -2;
  }
  *(int **)(*(int *)(unaff_s0 + 0x208) + 0x14) = &DAT_8010dcb8;
  *(undefined2 *)(unaff_s0 + 500) = 0;
  FUN_800334c8();
  iVar3 = FUN_80089d54();
  if (iVar3 != 0) {
    *(undefined1 *)(unaff_s0 + 6) = 4;
    sVar2 = *(short *)(unaff_s0 + 0x1f6);
    bVar1 = *(byte *)((int)&uStack00000010 + (int)*(char *)(unaff_s0 + 0x206));
    *(short *)(unaff_s0 + 0x1f6) = sVar2 + -1;
    *(uint *)(unaff_s0 + 0x1e8) = (bVar1 + 1) * 0x1000000;
    if (sVar2 == 1) {
      *(undefined1 *)(unaff_s0 + 6) = 5;
      *(uint *)(unaff_s0 + 0x1e8) =
           (*(byte *)((int)&uStack00000010 + (int)*(char *)(unaff_s0 + 0x206)) + 2) * 0x1000000;
    }
  }
  FUN_80032bd8();
  if (*(char *)(unaff_s0 + 0x206) == '\0') {
    *(short *)(unaff_s0 + 500) = *(short *)(unaff_s0 + 500) + -0x14;
    *(short *)(unaff_s0 + 0x2ae) = *(short *)(unaff_s0 + 0x2ae) + 0x14;
    if (-0xc9 < *(short *)(unaff_s0 + 500)) goto LAB_800581c8;
    *(undefined2 *)(unaff_s0 + 500) = 0xff38;
  }
  else {
    *(short *)(unaff_s0 + 500) = *(short *)(unaff_s0 + 500) + 0x14;
    *(short *)(unaff_s0 + 0x2ae) = *(short *)(unaff_s0 + 0x2ae) + 0x14;
    if (*(short *)(unaff_s0 + 500) < 0xc9) goto LAB_800581c8;
    *(undefined2 *)(unaff_s0 + 500) = 200;
  }
  *(undefined2 *)(unaff_s0 + 0x2ae) = 200;
LAB_800581c8:
  uStack00000018._0_2_ = *(short *)(unaff_s0 + 500);
  FUN_8004276c(unaff_s0 + 0x14,&uStack00000018,&uStack00000018);
  iVar3 = *(int *)(unaff_s0 + 0x234);
  DAT_8010dcb8 = (int)uStack00000018._0_2_ + *(int *)(iVar3 + 0x4c);
  DAT_8010dcbc = (int)uStack00000018._2_2_ + *(int *)(iVar3 + 0x50);
  DAT_8010dcc0 = (int)sStack0000001c + *(int *)(iVar3 + 0x54);
  if ((**(uint **)(unaff_s0 + 0x214) & 0x4000) != 0) {
    FUN_80077f30(0,((**(uint **)(unaff_s0 + 0x214) & 0x2000) >> 0xd) * 3 + 4);
    DAT_800e112a = DAT_800e112a | 4;
  }
  return;
}
