/* FUN_800a8594
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a8594  body 0x800a8594..0x800a860b  size 120 B
 * body sha256 82b1971d1b26528ae1e868aeac81de5d816353b293ddbd0da70257cb6a7f8649
 * provider record sha256 ebfe39e9a21cdad077572cf57cd40b16da83ed11aa88968d597f70530570b3ce
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined2 FUN_800a8594(void)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar1 = FUN_800af0d4();
  if (uVar1 == 0xffffffff) {
    uVar3 = 0;
  }
  else {
    iVar2 = (uVar1 & 0xff) * 0x1a0;
    uVar3 = 0;
    if ((*(uint *)(&DAT_801444a8 + iVar2) == uVar1) &&
       (uVar3 = 0, (*(uint *)(&DAT_8014446c + iVar2) & 2) == 0)) {
      uVar3 = *(undefined2 *)(iVar2 + -0x7febbaf6);
    }
  }
  return uVar3;
}
