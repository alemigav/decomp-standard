/* FUN_8000e3b0
 * image   boot (boot), base 0x80000480
 * address 0x8000e3b0  body 0x8000e3b0..0x8000e4b3  size 260 B
 * body sha256 58e17f88ebb9e92f7ceb3f0b656cc10bb7c0de20442126c85b85893bc4a2ed4f
 * provider record sha256 248cbedae12fa12b5ef751f986a27e3cd751e59421a157089a16ecb43d7b5dfb
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_8000e3b0(void)

{
  FUN_80006650(0x80012970,0x60);
  _DAT_800129d0 = 0x80012970;
  _DAT_800129a2 = 1;
  _DAT_80012972 = 1;
  _DAT_800129d4 = &DAT_800129a0;
  _DAT_800129a4 = 0x80000000;
  _DAT_80012974 = 0x80000000;
  if (_DAT_80000300 == 0) {
    _DAT_800129a8 = -0x7ffed560;
  }
  else if (_DAT_80000300 == 2) {
    _DAT_800129a8 = -0x7ffed600;
  }
  else {
    _DAT_800129a8 = -0x7ffed5b0;
  }
  _DAT_800129a0 = 0x20;
  _DAT_800129ac = *(undefined4 *)(_DAT_800129a8 + 4);
  do {
  } while (10 < _DAT_a4400010);
  _DAT_a4400000 = 0;
  FUN_8000ecb0();
  return;
}
