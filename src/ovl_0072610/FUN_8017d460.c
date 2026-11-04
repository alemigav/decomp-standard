/* FUN_8017d460
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017d460  body 0x8017d460..0x8017d523  size 196 B
 * body sha256 19f54c862807da09a602317bfe071e346e86596fe5d8471cd5c3f7e656d91b28
 * provider record sha256 df12e8f495b50954f179d668a04983119780a7095b120eee810acb66ef8c2567
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017d460(void)

{
  int iVar1;
  
  *(undefined4 *)(DAT_80186c94 + 0x42c) = 0;
  FUN_8017bec8(10);
  DAT_8018576c = FUN_8017bec8(3);
  FUN_8017bec8(0x10);
  if (DAT_8018576c - 2U < 2) {
    DAT_80185778 = FUN_8017bec8(1);
    iVar1 = FUN_8017bec8(3);
    DAT_80185770 = iVar1 + -1;
  }
  if (DAT_8018576c == 3) {
    DAT_8018577c = FUN_8017bec8(1);
    iVar1 = FUN_8017bec8(3);
    DAT_80185774 = iVar1 + -1;
  }
  FUN_8017dd78();
  FUN_8017d61c();
  return;
}
