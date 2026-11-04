/* FUN_800331b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800331b8  body 0x800331b8..0x800331fb  size 68 B
 * body sha256 834710bee88d56c9bb6a9e040470b42e0dc5e8f182e5603531b2e57501bd1de6
 * provider record sha256 2368ec66053f55d0a0146e27e9cd994a8c6643c943715c60b379d261f668f651
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800331b8(void)

{
  if (((DAT_800df918 & 0x34f) == 0) && ((DAT_8010c274 & 0xf000) == 0)) {
    return 0;
  }
  return 1;
}
