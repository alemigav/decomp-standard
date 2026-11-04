/* FUN_8017c8f0
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017c8f0  body 0x8017c8f0..0x8017c9eb  size 252 B
 * body sha256 beeeee94fc8e0e71d47fa5b952b6c9bf965f45c1969649beee1c00519ee89ce8
 * provider record sha256 b4f1c6bbe8b6ae95818aeb82c2e3412e32d9bae2ef58af0624fa3d8906c48cfd
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017c8f0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_8017e754 = _DAT_8010b6f8;
  func_0x800828ac(&DAT_8017e8b4,&DAT_8017e8c0);
  func_0x800428e0(0xd0);
  func_0x80042d60(0x800e9134);
  func_0x80042dac(0x800e9134);
  if ((_DAT_800e10ec & 0x100) != 0) {
    FUN_8017d9a0();
  }
  (*(code *)(&PTR_FUN_8017e8d0)[*DAT_8017e8e0])();
  *DAT_8017e754 = 0xdf000000;
  DAT_8017e754[1] = 0;
  puVar2 = _DAT_8010b6f8;
  puVar1 = _DAT_800df8b8;
  DAT_8017e754 = DAT_8017e754 + 2;
  puVar3 = _DAT_800df8b8 + 2;
  *_DAT_800df8b8 = 0xde000000;
  _DAT_800df8b8 = puVar3;
  puVar1[1] = puVar2;
  return;
}
