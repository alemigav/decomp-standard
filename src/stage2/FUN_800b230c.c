/* FUN_800b230c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b230c  body 0x800b230c..0x800b2343  size 56 B
 * body sha256 d928e516481c435d48d394bbcddea3bf0b6bbb41e09f5191a00ed4967a6a178a
 * provider record sha256 5704f19dee0d97dd0d77ae14b9897a6e3067cd5487a3c307a2f944a76df3845c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800b230c(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_800af0d4();
  if (iVar1 == -1) {
    param_1 = 0xffffffff;
  }
  return param_1;
}
