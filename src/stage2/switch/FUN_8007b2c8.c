/* FUN_8007b2c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007b2c8  body 0x8007b2c8..0x8007b2d7  size 16 B
 * body sha256 3e33987063b7cb21403cfbf7ad8fd8e5292852018c9e34bbcb4bb5f8a4b79ab4
 * provider record sha256 113a6128d2a4173ad489e257690191683ef7ee8aaa33d5f82c1d1980ed07443c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007adfc::caseD_2(void)

{
  short sVar1;
  int iVar2;
  int unaff_s2;
  
  *(undefined2 *)(unaff_s2 + 500) = 0x96;
  *(undefined1 *)(unaff_s2 + 6) = 3;
  if (*(short *)(unaff_s2 + 500) == 0x82) {
    *(char *)(DAT_800e13f4 + 6) = *(char *)(DAT_800e13f4 + 6) + '\x01';
  }
  if ((DAT_800e9012 & 8) != 0) {
    if (*(ushort *)(unaff_s2 + 500) - 0x78 < 10) {
      iVar2 = *(int *)(*(int *)(unaff_s2 + 0x234) + 0x120);
      *(short *)(iVar2 + 0x10) = *(short *)(iVar2 + 0x10) + 100;
      FUN_80066288();
      iVar2 = *(int *)(*(int *)(unaff_s2 + 0x234) + 0x18a0);
      *(short *)(iVar2 + 0x10) = *(short *)(iVar2 + 0x10) + 100;
      FUN_80066288();
    }
    if (*(ushort *)(unaff_s2 + 500) - 0x72 < 5) {
      iVar2 = *(int *)(*(int *)(unaff_s2 + 0x234) + 0x120);
      *(short *)(iVar2 + 0x10) = *(short *)(iVar2 + 0x10) + -200;
      FUN_80066288();
      iVar2 = *(int *)(*(int *)(unaff_s2 + 0x234) + 0x18a0);
      *(short *)(iVar2 + 0x10) = *(short *)(iVar2 + 0x10) + -200;
      FUN_80066288();
    }
    if (*(ushort *)(unaff_s2 + 500) - 0x67 < 10) {
      iVar2 = *(int *)(*(int *)(unaff_s2 + 0x234) + 0x120);
      *(short *)(iVar2 + 0x10) = *(short *)(iVar2 + 0x10) + 0x50;
      FUN_80066288();
      iVar2 = *(int *)(*(int *)(unaff_s2 + 0x234) + 0x18a0);
      *(short *)(iVar2 + 0x10) = *(short *)(iVar2 + 0x10) + 0x50;
      FUN_80066288();
    }
    if (*(ushort *)(unaff_s2 + 500) - 0x61 < 5) {
      iVar2 = *(int *)(*(int *)(unaff_s2 + 0x234) + 0x120);
      *(short *)(iVar2 + 0x10) = *(short *)(iVar2 + 0x10) + -0xa0;
      FUN_80066288();
      iVar2 = *(int *)(*(int *)(unaff_s2 + 0x234) + 0x18a0);
      *(short *)(iVar2 + 0x10) = *(short *)(iVar2 + 0x10) + -0xa0;
      FUN_80066288();
    }
  }
  if ((*(ushort *)(unaff_s2 + 500) - 0x74 < 0x18) && ((*(ushort *)(unaff_s2 + 500) & 7) == 0)) {
    FUN_80037780(0x20fa0,(int)*(short *)(unaff_s2 + 0x66),*(int *)(unaff_s2 + 0x234) + 0x38,0);
  }
  sVar1 = *(short *)(unaff_s2 + 500) + -1;
  *(short *)(unaff_s2 + 500) = sVar1;
  if (sVar1 == -1) {
    *(undefined1 *)(unaff_s2 + 6) = 4;
    *(char *)(DAT_800e13f4 + 6) = *(char *)(DAT_800e13f4 + 6) + '\x01';
  }
  return;
}
