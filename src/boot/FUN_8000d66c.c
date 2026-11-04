/* FUN_8000d66c
 * image   boot (boot), base 0x80000480
 * address 0x8000d66c  body 0x8000d66c..0x8000d697  size 44 B
 * body sha256 19c1b259429dd6f68b87f3233f137bc11ed04c82beebb80acde0e95ca373d95e
 * provider record sha256 728207afb2b32a96f6e0d372cc1f7db6b0b4027569625b1cf3f494ae0261d1df
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8000d66c(void)

{
  int iVar1;
  
  do {
    iVar1 = FUN_8000d9c0();
  } while (iVar1 != 0);
  FUN_8000db10(0x125);
  return;
}
