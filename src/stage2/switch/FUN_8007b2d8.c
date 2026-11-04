/* FUN_8007b2d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007b2d8  body 0x8007b2d8..0x8007b4f3  size 540 B
 * body sha256 cf14d52cb272d7d2e93d9dba3c7e64d641c83778edb5ca02fded629d41a33568
 * provider record sha256 636c58de7e38e774f1d055dbd252cf18c750d4bad016bbebe081c6ddab6b70bd
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007adfc::caseD_3(void)

{
  short sVar1;
  int iVar2;
  int unaff_s2;
  
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
