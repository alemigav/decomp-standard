/* FUN_80083780
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80083780  body 0x80083780..0x800837ab  size 44 B
 * body sha256 7e71ce1970c322008e71aafbe29db265b3aa2bf788034ae28ebf3d1ab5837bc6
 * provider record sha256 15c701951d052738739cc98d94c5536b6416e38b29ae6a2a4f75deb914d36abe
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80083780(int param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)((param_2 >> 5) * 4 + param_1);
  *puVar1 = *puVar1 & ~(0x80000000U >> (param_2 & 0x1f));
  return;
}
