/* FUN_8009b224
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009b224  body 0x8009b224..0x8009b24b  size 40 B
 * body sha256 3cf7e5f2a0a58d98cd88661f098a1163682591943d8d85077b3ba21cfbc61e80
 * provider record sha256 906ac164fcc73a6ece508489eaa0c9249c8bee8083a319fa76e64cb3b9b32e31
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_8009b224(void)

{
  int iVar1;
  
  iVar1 = FUN_800837ac(&DAT_800e8ce0,0xc3);
  return iVar1 != 0;
}
