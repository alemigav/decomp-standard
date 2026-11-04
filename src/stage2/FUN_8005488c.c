/* FUN_8005488c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005488c  body 0x8005488c..0x8005495f  size 196 B
 * body sha256 60dc88c8f9d31f73009942a228080dc3918dc24b0e9656814a45928550cb0ec2
 * provider record sha256 0856aa23c948a6dc3368985031f0f950e782d5f8ebc7a89747b0b720618e3dd6
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005488c(void)

{
  int iVar1;
  int unaff_s2;
  uint unaff_s3;
  
  iVar1 = FUN_80052ffc(0,2);
  if (iVar1 != 0) {
    FUN_80053d38();
    DAT_800e860a = 2;
    DAT_800e8609 = 0xb;
  }
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
