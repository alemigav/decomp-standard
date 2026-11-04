/* FUN_801803e4
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x801803e4  body 0x801803e4..0x8018046b  size 136 B
 * body sha256 153f23fe07657c3564b23deeec469cef72467b61f16594f1523b6c3a94c6f6e3
 * provider record sha256 c37d0b2b25bd44b6e02d100abefaa41d5c019b545afe8f721f9d0d2f8c684210
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801803e4(int *param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = 0x10 << (param_2 & 0x1f);
  if (param_5 != 0) {
    iVar1 = iVar1 >> 1;
  }
  if ((int)param_3 < 1) {
    if ((int)param_3 < 0) {
      iVar1 = (iVar1 + -1) - ((~param_3 << (param_2 & 0x1f)) + param_4);
      if (iVar1 < -iVar2) {
        iVar1 = iVar1 + iVar2 * 2;
      }
    }
  }
  else {
    iVar1 = iVar1 + 1 + (param_3 - 1 << (param_2 & 0x1f)) + param_4;
    if (iVar2 <= iVar1) {
      iVar1 = iVar1 + iVar2 * -2;
    }
  }
  *param_1 = iVar1;
  if (param_5 != 0) {
    *param_1 = iVar1 << 1;
  }
  return;
}
