/* FUN_8017d744
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017d744  body 0x8017d744..0x8017d81b  size 216 B
 * body sha256 f2f2e4e753cc4fa8035c7cc010419b6347c2cb30d3876934088ecf4d260ba1a7
 * provider record sha256 0ccfc8e4597492576e5eb38cf0cef67e3ef84da7643bd75bc9c4b37e9fc21438
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017d744(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_80186c94;
  *(undefined4 *)(DAT_80186c94 + 0x41c) = 1;
  *(undefined4 *)(iVar1 + 0x420) = 0;
  FUN_8017bec8(8);
  DAT_80185788 = FUN_8017bec8(1);
  DAT_8018575c = FUN_8017bec8(2);
  iVar1 = FUN_8017bec8(2);
  iVar2 = FUN_8017bec8(2);
  FUN_8017bec8(0xc);
  FUN_8017bbe8(1);
  FUN_8017bec8(8);
  FUN_8017bec8(1);
  FUN_8017bec8(2);
  FUN_8017bec8(5);
  DAT_80185744 = iVar1 << 0xc | DAT_80185744 & 0xfff;
  DAT_80185748 = iVar2 << 0xc | DAT_80185748 & 0xfff;
  return;
}
