/* FUN_8005448c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005448c  body 0x8005448c..0x800544ff  size 116 B
 * body sha256 b8cfbdfc147e37ecdc50334b953027f0b8f807030d7265322af5495e5087bf15
 * provider record sha256 edb897eecb4684da73f1e24bae299983e3c5d268585b9457a1d3c06d86587205
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005448c(void)

{
  int iVar1;
  int unaff_s2;
  uint unaff_s3;
  
  iVar1 = FUN_8008c51c(0x35);
  if (-1 < iVar1) {
    DAT_8010b297 = 0x35;
    FUN_8004ac04(0,0x100,7,0xff000000);
  }
  DAT_800e8609 = 5;
  if (*(char *)(unaff_s2 + 0x2d9) == '\x01') {
    *(undefined1 *)(unaff_s2 + 0x2d9) = 0;
    DAT_800e8609 = 0xb;
  }
  if (((DAT_8010da14 & DAT_8010da18) != 0) || (unaff_s3 != DAT_800e8609)) {
    _DAT_80139be8 = 0;
    DAT_8010da18 = 0;
    DAT_8010da14 = 0;
    _DAT_80139be4 = 0;
  }
  FUN_80053d7c(1);
  FUN_80053eb8(0x16c);
  return;
}
