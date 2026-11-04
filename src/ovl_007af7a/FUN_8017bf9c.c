/* FUN_8017bf9c
 * image   ovl_007af7a (ovl), base 0x8017b410
 * address 0x8017bf9c  body 0x8017bf9c..0x8017c01f  size 132 B
 * body sha256 53d59d8321794e005e824571d229026051ccc52c928cc8fec8d2d74bed2f17e5
 * provider record sha256 33d4274b886dad036c2a48946a9a89563191b44df91f4b7ea6e690a810177b6f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017bf9c(void)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = 7;
  puVar1 = &UNK_8017e300 + (uint)DAT_8017e5bd * 0x8c;
  do {
    iVar2 = iVar2 + -1;
    _DAT_800df8b4 = func_0x80043988(_DAT_800df8b4,puVar1,0,0);
    puVar1 = puVar1 + 0x14;
  } while (iVar2 != 0);
  return;
}
