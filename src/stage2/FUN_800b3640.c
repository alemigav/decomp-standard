/* FUN_800b3640
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b3640  body 0x800b3640..0x800b3703  size 196 B
 * body sha256 255061beb96a14749d2042a3cdd8b639c96f4a48ea0bf58cccb34e937a823eba
 * provider record sha256 40c6f879135a001013a8a88d9203499b32145506e0bcb88dd558f31bf2d1a4b5
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800b3640(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  do {
    uVar1 = 0;
    iVar2 = -0x7fea74e0;
    do {
      if (((*(char *)(iVar2 + 0x1200) != '\0') && (uVar1 != param_1)) &&
         (*(int *)(iVar2 + 0x1224) == _DAT_8015af70)) break;
      uVar1 = uVar1 + 1;
      iVar2 = iVar2 + 0x1228;
    } while (uVar1 < 2);
    if (uVar1 == 2) {
      *(int *)(param_1 * 0x1228 + -0x7fea62bc) = _DAT_8015af70;
      _DAT_8015af70 = _DAT_8015af70 + 1;
      if (_DAT_8015af70 == -1) {
        _DAT_8015af70 = 0;
      }
      return *(undefined4 *)(param_1 * 0x1228 + -0x7fea62bc);
    }
    _DAT_8015af70 = _DAT_8015af70 + 1;
    if (_DAT_8015af70 == -1) {
      _DAT_8015af70 = 0;
    }
  } while( true );
}
