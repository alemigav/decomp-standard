/* FUN_800a8364
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a8364  body 0x800a8364..0x800a83b3  size 80 B
 * body sha256 6b5db792bff20393c61b9a4d8e743aead4e756fb48dea485559b7ccc037b4257
 * provider record sha256 8489f01b3f290698ac87d43146ac8a5f641c98de209565211fa93a9fce0279b3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800a8364(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (param_1 & 0xff) * 0x28;
  uVar2 = 0;
  if ((((&DAT_80147ab4)[iVar1] != '\x04') && (uVar2 = 0, *(int *)(&DAT_80147aac + iVar1) != 0)) &&
     (uVar2 = 1, -1 < *(int *)(&DAT_80147aa8 + iVar1))) {
    uVar2 = 0;
  }
  return uVar2;
}
