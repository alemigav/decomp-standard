/* FUN_80054210
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80054210  body 0x80054210..0x80054293  size 132 B
 * body sha256 1f26b88e72f3cfa158453933cdf80ef55f005e6f28e20f8b02c3e0e9181d0a1a
 * provider record sha256 84ba6c109a8ed4034c2b8ade9d235e350f525452d15a3b6e8dd976b0fdec4726
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80054210(void)

{
  int iVar1;
  uint unaff_s3;
  
  iVar1 = DAT_800df934;
  DAT_8010d940 = DAT_800df934;
  DAT_800df934 = DAT_800df934 + 0x5320;
  FUN_80054f98(DAT_800e10f0 >> 4,1);
  DAT_80139be0 = FUN_8008c51c(0x35);
  if ((int)((uint)DAT_80139be0 << 0x18) < 0) {
    DAT_80139be0 = FUN_8008c51c(0x35);
  }
  DAT_8010da18 = 0;
  DAT_8010da14 = 0;
  DAT_800e8609 = 1;
  _DAT_80139be8 = &DAT_8010d960;
  FUN_800539a0(1,"DOOR LOCK SERVICE]------------------------------",&DAT_8010da18);
  if ((DAT_8010da18 & DAT_8010da14) != 0) {
    DAT_800e8609 = 2;
  }
  if (*(char *)(iVar1 + 0x2d9) == '\x01') {
    *(undefined1 *)(iVar1 + 0x2d9) = 0;
    DAT_800e8609 = 0xb;
  }
  if (((DAT_8010da14 & DAT_8010da18) != 0) || (unaff_s3 != DAT_800e8609)) {
    _DAT_80139be8 = (undefined *)0x0;
    DAT_8010da18 = 0;
    DAT_8010da14 = 0;
    _DAT_80139be4 = 0;
  }
  FUN_80053d7c(1);
  FUN_80053eb8(0x16c);
  return;
}
