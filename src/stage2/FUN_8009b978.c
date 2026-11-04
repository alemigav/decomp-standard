/* FUN_8009b978
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009b978  body 0x8009b978..0x8009ba37  size 192 B
 * body sha256 3ddc305107e4fe98e7151f6c0b83976456935fb0022ba2d10bbc4561430d50d6
 * provider record sha256 d702535939a70da00cf48078f08114ac2af940f3911370c889f92c796f61b8a7
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8009b978(void)

{
  int iVar1;
  
  while (iVar1 = FUN_8002767c(0), iVar1 == 0) {
    FUN_8004cd88(1);
  }
  FUN_800274f8(0x200,0,7,1);
  FUN_800275c0(0,0x7fff,0xffff,0);
  if (*(short *)(_DAT_8013a430 + 0x244) != 0) {
    FUN_80077adc(0x10000,&DAT_800e1158);
  }
  FUN_80085398(DAT_80132100,DAT_80132104,&DAT_800ba424);
  DAT_800e10ec = DAT_800e10ec & 0xfdffffff;
  FUN_8004cdd4();
  return;
}
