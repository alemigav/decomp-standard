/* FUN_80163570
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80163570  body 0x80163570..0x801635b3  size 68 B
 * body sha256 c88207cfb9f480de06318277e46269c0d482aeb685a292d8fad50ee8df43cce4
 * provider record sha256 d8e960dfe005d6ef81637dc9debcdc9e7b0399d34b8119107680fc736eff89c3
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163570(int param_1)

{
  short sVar1;
  
  sVar1 = *(short *)(param_1 + 500);
  *(short *)(param_1 + 500) = sVar1 + -1;
  if (sVar1 == 1) {
    *(undefined1 *)(param_1 + 6) = 2;
    *(undefined4 *)(param_1 + 0x1e8) = 0x8000f00;
  }
  func_0x80089d54();
  return;
}
