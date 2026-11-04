/* FUN_80166b1c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80166b1c  body 0x80166b1c..0x80166b5f  size 68 B
 * body sha256 4d2719a934c9b3def1e643b5d4fe649147ae9e837fb5583b17b61c5d01cace5a
 * provider record sha256 592ec9d5277c6c373edbbe8b7d41ee6e968429135a951c7729695db71f032187
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80166b1c(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = -0x7ff1eed0;
  }
  else {
    iVar1 = _DAT_800e13ec;
  }
  *(undefined1 *)(iVar1 + 4) = 3;
  *(undefined1 *)(iVar1 + 5) = 0;
  *(undefined1 *)(iVar1 + 6) = 0;
  *(undefined1 *)(iVar1 + 7) = 0;
  return;
}
