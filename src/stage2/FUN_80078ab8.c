/* FUN_80078ab8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80078ab8  body 0x80078ab8..0x80078af7  size 64 B
 * body sha256 cdad6d194a6a412612ef20fe3128a23e14d0faac55611f1b404019bb597916fb
 * provider record sha256 31c1fe7d9eea8d0d04f89fff0edabf660f061640bcaaf4ed102dae6b122f5757
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80078ab8(uint param_1)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = &DAT_80119e50;
  do {
    bVar1 = *pbVar2;
    pbVar2 = pbVar2 + 1;
    if (bVar1 == param_1) {
      return 1;
    }
  } while (*pbVar2 != 0xff);
  return 0;
}
