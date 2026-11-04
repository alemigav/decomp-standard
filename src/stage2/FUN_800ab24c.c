/* FUN_800ab24c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab24c  body 0x800ab24c..0x800ab2cb  size 128 B
 * body sha256 712d890c89d7571768c71e5023b5ddb5aead6a912fd886237ac56e803b87be31
 * provider record sha256 f08adcb0520b43bbf0c9ff8cf92a5edfa24bd4dd37e55f47d8fb8eebec92dff8
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x800ab290) */

void FUN_800ab24c(float *param_1)

{
  float fVar1;
  
  fVar1 = SQRT(*param_1 * *param_1 + param_1[1] * param_1[1] + param_1[2] * param_1[2]);
  *param_1 = *param_1 / fVar1;
  param_1[2] = param_1[2] / fVar1;
  param_1[1] = param_1[1] / fVar1;
  return;
}
