/* FUN_80032fac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80032fac  body 0x80032fac..0x80033023  size 120 B
 * body sha256 eca6e730f2e656b0cf1f15f75c9673fa02df423eaca2fd5bd0190c2e7735f0da
 * provider record sha256 a9e3192fae0f8b8798068787c5a59a899e946f145d8ed727c6ecf4f5e7c951d9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80032fac(int param_1,int param_2,short param_3,short param_4)

{
  short sVar1;
  
  sVar1 = FUN_80032d14((int)*(short *)(param_1 + 2),(int)*(short *)(param_1 + 10),
                       (int)*(short *)(param_2 + 2),(int)*(short *)(param_2 + 10));
  return (uint)((int)param_4 << 1) <= (((int)sVar1 - (int)param_3) + (int)param_4 & 0xfffU);
}
