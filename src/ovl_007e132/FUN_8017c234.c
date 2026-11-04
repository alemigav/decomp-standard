/* FUN_8017c234
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017c234  body 0x8017c234..0x8017c287  size 84 B
 * body sha256 1e8fef1e3ddd44abb0bd8ca88c6681ba21468b2da1a610dbd785f36b92d49ad5
 * provider record sha256 e3b4e011f1944e57e4d705d894dbd125366582ff97845738f8bdaa769b429021
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017c234(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = iVar2 << 0x10;
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 >> 0xe;
    *(undefined2 *)((int)&DAT_8017e744 + iVar1) = 0;
    *(undefined2 *)((int)&DAT_8017e746 + iVar1) = 0;
  } while (iVar2 * 0x10000 >> 0x10 < 4);
  _DAT_800df940 = &DAT_8017e740;
  return;
}
