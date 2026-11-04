/* FUN_80040d2c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040d2c  body 0x80040d2c..0x80040e07  size 220 B
 * body sha256 2584c728ae8ef08e1fe84baa8572b4302c69616902051d4511504b173a82184e
 * provider record sha256 17c6e97e7593be0fc8aee8d16d38d96fd65f68aa4a4e799a04cc680f0f17440f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80040d2c(short *param_1,int *param_2)

{
  *param_1 = (short)((int)*param_1 * *param_2 >> 0xc);
  param_1[3] = (short)((int)param_1[3] * *param_2 >> 0xc);
  param_1[6] = (short)((int)param_1[6] * *param_2 >> 0xc);
  param_1[1] = (short)((int)param_1[1] * param_2[1] >> 0xc);
  param_1[4] = (short)((int)param_1[4] * param_2[1] >> 0xc);
  param_1[7] = (short)((int)param_1[7] * param_2[1] >> 0xc);
  param_1[2] = (short)((int)param_1[2] * param_2[2] >> 0xc);
  param_1[5] = (short)((int)param_1[5] * param_2[2] >> 0xc);
  param_1[8] = (short)((int)param_1[8] * param_2[2] >> 0xc);
  return;
}
