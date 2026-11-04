/* FUN_8017d158
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017d158  body 0x8017d158..0x8017d213  size 188 B
 * body sha256 52bd3ffb1a8c816204406878e33b9ddd0f8ab2d08d315dd3c0d7e740c2c22eb8
 * provider record sha256 2fe77ce572477807e81d6d237773ae0ab0d3b15043ea81d58df9558230af71bb
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8017d158(void)

{
  uint uVar1;
  
  while( true ) {
    while( true ) {
      while( true ) {
        FUN_8017d214();
        uVar1 = FUN_8017befc();
        if (uVar1 != 0x1b3) break;
        FUN_8017d25c();
      }
      if (0x1b3 < uVar1) break;
      if (uVar1 == 0x100) {
        FUN_8017d460();
        return 1;
      }
    }
    if (uVar1 == 0x1b7) break;
    if (uVar1 == 0x1b8) {
      FUN_8017d404();
    }
  }
  return 0;
}
