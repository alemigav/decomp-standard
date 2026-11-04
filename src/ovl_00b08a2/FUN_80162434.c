/* FUN_80162434
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80162434  body 0x80162434..0x8016246b  size 56 B
 * body sha256 5630fc7bcd7e536ccef4092ed7f4cac2f1bf75b2aaad7f91e78484e228355df0
 * provider record sha256 c90f98fce0e598000440d1727cf4823f0631bb1ae29997713c523a93effdfafd
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162434(int param_1)

{
  (*(code *)(&PTR_FUN_80167130)[*(ushort *)(param_1 + 0x1aa) & 0x3f])();
  return;
}
