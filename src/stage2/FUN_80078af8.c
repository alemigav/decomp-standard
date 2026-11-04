/* FUN_80078af8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80078af8  body 0x80078af8..0x80078b37  size 64 B
 * body sha256 e8bd04538e7d598dd26e4b499bde6db4582d700ad811ffda374c4f8afebd4c32
 * provider record sha256 5a3b9748bf633ded44d284a97a3309c1c59d810aa13a28872997b6f8a77fd677
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80078af8(uint param_1)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = &DAT_80119e5c;
  do {
    bVar1 = *pbVar2;
    pbVar2 = pbVar2 + 1;
    if (bVar1 == param_1) {
      return 1;
    }
  } while (*pbVar2 != 0xff);
  return 0;
}
