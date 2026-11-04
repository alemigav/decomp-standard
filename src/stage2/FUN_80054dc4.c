/* FUN_80054dc4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80054dc4  body 0x80054dc4..0x80054e0b  size 72 B
 * body sha256 565caef7dd3602ef3298e096cb7d5e1e24eddd929eacae87fa0d3d556651b801
 * provider record sha256 f7c64af57fff00ef831231e1a0865ef840b2e5528162c51f1fbc0045f24d70c1
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80054dc4(void)

{
  int unaff_s2;
  uint unaff_s3;
  
  DAT_80139bef = 8;
  FUN_800539a0(1,"Please wait[025.[025.[025.[025.[025.]",&DAT_8010da24);
  if (DAT_8010da24 != 0) {
    DAT_800e8609 = 9;
  }
  if (*(char *)(unaff_s2 + 0x2d9) == '\x01') {
    *(undefined1 *)(unaff_s2 + 0x2d9) = 0;
    DAT_800e8609 = 0xb;
  }
  if (((DAT_8010da20 & DAT_8010da24) != 0) || (unaff_s3 != DAT_800e8609)) {
    DAT_80139bef = 0;
    DAT_8010da24 = 0;
    DAT_8010da20 = 0;
    DAT_80139bee = 0;
  }
  FUN_80053d7c(1);
  FUN_80053eb8(0x16c);
  return;
}
