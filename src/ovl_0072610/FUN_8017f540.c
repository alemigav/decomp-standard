/* FUN_8017f540
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017f540  body 0x8017f540..0x8017f5bb  size 124 B
 * body sha256 55c55bcf4556f6f0511f6faaeb6b4dc9f358638c1952bab00ee39ec071ad8524
 * provider record sha256 c41e21767d3fbdd5fe3fb7093d7d8b5c5aa8d1adce592a607a1b7d6f8b81eea0
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8017f540(void)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = FUN_8017bbb0(7);
  if (iVar1 < 2) {
    DAT_80185780 = 1;
    iVar1 = 0;
  }
  else {
    if (iVar1 < 0x10) {
      puVar2 = &DAT_80184c00;
    }
    else {
      iVar1 = iVar1 >> 3;
      puVar2 = &UNK_80184be0;
    }
    FUN_8017bbe8((int)(char)(puVar2 + iVar1 * 2)[1]);
    iVar1 = (int)(char)puVar2[iVar1 * 2];
  }
  return iVar1;
}
