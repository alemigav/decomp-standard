/* FUN_800ad998
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ad998  body 0x800ad998..0x800ada33  size 156 B
 * body sha256 e3a5cb0d06d8d08e8d04abd5078967a293dd0469337ae477e6612faf1936bc68
 * provider record sha256 625df32fcdb8b972e4a4b0d89b2ae6b8d528b2b77e9570fd146081d709fedc11
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800ad998(ushort param_1)

{
  _DAT_8014e0e4 = (uint)(param_1 >> 6);
  if (*(short *)(&DAT_80153610 + _DAT_8014e0e4 * 4) != 0) {
    _DAT_8014e0e0 = (uint)*(ushort *)(&DAT_80153612 + _DAT_8014e0e4 * 4);
    _DAT_8014e0ec = param_1;
    _DAT_8014e0f0 =
         (undefined4 *)
         FUN_800ab43c(0x8014e0e8,_DAT_8014e0e0 * 8 + -0x7feac1f0,
                      *(short *)(&DAT_80153610 + _DAT_8014e0e4 * 4),8,&LAB_800ae144);
    if (_DAT_8014e0f0 != (undefined4 *)0x0) {
      return *_DAT_8014e0f0;
    }
  }
  return 0;
}
