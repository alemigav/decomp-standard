/* FUN_8005b564
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005b564  body 0x8005b564..0x8005b59b  size 56 B
 * body sha256 52679774209334556cf613a44f5caef0ecb5be0cd38727e6e40749b269c28eab
 * provider record sha256 665dfeadcb9942f076a94163ae82206e2c01a7762becc90372e4e2a8de26d189
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int switchD_8005b520::caseD_1(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4)

{
  int iVar1;
  int in_t1;
  
  iVar1 = ((int)*(short *)(in_t1 + 0x10) - (int)*(short *)(in_t1 + 0x12)) / 3;
  *param_3 = *(short *)(in_t1 + 0x10) - iVar1;
  *param_4 = *(short *)(in_t1 + 0x12) - iVar1;
  return iVar1;
}
