/* FUN_80027874
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80027874  body 0x80027874..0x80027927  size 180 B
 * body sha256 b7425da23f36365a5049f1e5ec23b148c5e42276aaa81e38e6ce11b963adf199
 * provider record sha256 0c15ddffe8e8a09f557908beafa94f815b78a9f5fd04684093412189f95c6030
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80027874(void)

{
  undefined1 uVar1;
  
  uVar1 = DAT_800e9012;
  FUN_80082498(&DAT_800e110c,0x1fc4);
  DAT_800e9184 = 0xffff;
  DAT_800e91b0 = 0xffff;
  DAT_800e91dc = 0xffff;
  DAT_800e9208 = 0xffff;
  DAT_800e8cb0 = 0xffff;
  DAT_800e8cae = 0xffff;
  DAT_800df8bc = 0xffff0000;
  DAT_800df8e0 = 0xffff0000;
  DAT_800e9012 = uVar1;
  DAT_800e10ec = DAT_800e10ec & 0xd9;
  DAT_800e8b3e = DAT_800e923e;
  return;
}
