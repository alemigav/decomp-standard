/* FUN_8017f5bc
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017f5bc  body 0x8017f5bc..0x8017f657  size 156 B
 * body sha256 52e032d478f318037005dc50c314b607bf00e1433112dc561c4b9c8ebe0094f5
 * provider record sha256 9e6b05bbe2d5d169c4e410f961e677f29917e31a7d4d217a3a0e839b661aa615
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8017f5bc(void)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = FUN_8017bbb0(9);
  if (iVar1 < 0x40) {
    if (iVar1 < 0x10) {
      if (iVar1 < 8) {
        DAT_80185780 = 1;
        return 0;
      }
      iVar1 = iVar1 << 1;
      puVar2 = &DAT_80184c44;
    }
    else {
      iVar1 = (iVar1 >> 2) << 1;
      puVar2 = &UNK_80184c34;
    }
  }
  else {
    iVar1 = (iVar1 >> 5) << 1;
    puVar2 = &UNK_80184c1c;
  }
  FUN_8017bbe8((int)(char)(puVar2 + iVar1)[1]);
  return (int)(char)puVar2[iVar1];
}
