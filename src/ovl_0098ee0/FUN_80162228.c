/* FUN_80162228
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80162228  body 0x80162228..0x8016227b  size 84 B
 * body sha256 c5a633ea36bd91aeb62d9b78e84e1e495220de064ae169b7d92cc15830085687
 * provider record sha256 76a4573d21173b1763246c9fc6142136fb43169ffb11a69b5b4c037bb0a3e731
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162228(undefined4 param_1)

{
  char cVar1;
  
  _DAT_800e1134 = 0x2000000;
  cVar1 = func_0x80033144(0x800e1130,param_1);
  _DAT_800e1380 = param_1;
  cVar1 = DAT_800e1135 + cVar1;
  _DAT_800e1135 = CONCAT12(cVar1,DAT_800e1134_1._1_2_);
  return;
}
