/* FUN_80007df0
 * image   boot (boot), base 0x80000480
 * address 0x80007df0  body 0x80007df0..0x80007ee3  size 244 B
 * body sha256 7af93d22e329a6b2b9950fe0b9e387b36ed3fa394c2c9b80893c551f959c0f32
 * provider record sha256 652179ecbe4933526d18e0ff2c3dd0f2c2ee3a539d6470f70f22ee477d65b722
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_80007df0(void)

{
  undefined4 uVar1;
  
  DAT_800161b4 = 2;
  _DAT_800161bc = 0xa5000000;
  DAT_800161b5 = 3;
  DAT_800161b8 = 6;
  DAT_800161b6 = 6;
  DAT_800161b9 = 1;
  DAT_800161b7 = 2;
  _DAT_a4600024 = 3;
  _DAT_a4600028 = 6;
  _DAT_a460002c = 6;
  _DAT_a4600030 = 2;
  _DAT_800161c0 = 0;
  FUN_80006650(0x800161c4,0x60);
  uVar1 = FUN_800072e0();
  _DAT_800161b0 = _DAT_8001290c;
  _DAT_8001290c = &DAT_800161b0;
  _DAT_80016224 = &DAT_800161b0;
  FUN_80007300(uVar1);
  return &DAT_800161b0;
}
