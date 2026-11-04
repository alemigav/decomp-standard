/* FUN_80026524
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80026524  body 0x80026524..0x800265f3  size 208 B
 * body sha256 5e12d36fbc2b83992a253885e3249826f222b3a7d3403dcda1837febd0848b4e
 * provider record sha256 3e9a9986de9230248260c607cac5d6fc6c5b64b76edc1e56cd90b11eb0ed4f2f
 * callees 9 direct (8 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80026524(void)

{
  FUN_80042a24();
  FUN_8004ca18();
  func_0x80004a20();
  DAT_800e9012 = 0;
  DAT_800e10ec = DAT_800e10ec | 0x40;
  FUN_80027874();
  DAT_800dfbe8 = 0;
  DAT_80119e73 = 100;
  DAT_80119e74 = 100;
  DAT_800dfbe9 = 0;
  DAT_800e923e = 0;
  DAT_800e9234 = 0;
  DAT_800e9238 = 0x14000f0;
  FUN_800750b0(1);
  FUN_80075f54();
  FUN_8004c94c();
  FUN_800850a4();
  FUN_8004cd54(0,FUN_80026610);
  return;
}
