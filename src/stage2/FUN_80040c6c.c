/* FUN_80040c6c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040c6c  body 0x80040c6c..0x80040cf3  size 136 B
 * body sha256 2059f2cf9f55d71cb2f0b9a272bdb57fcd8cc037c32c46bf093c9d49f41c5c8e
 * provider record sha256 8703db60cb38ec1ca64124e8dfb89ebf423df377160204048c63d5b99fb54ec8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80040c6c(int *param_1,int *param_2,int *param_3)

{
  *param_3 = param_1[1] * param_2[2] - param_1[2] * param_2[1];
  param_3[1] = param_1[2] * *param_2 - *param_1 * param_2[2];
  param_3[2] = *param_1 * param_2[1] - param_1[1] * *param_2;
  return;
}
