/* FUN_800ab2cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab2cc  body 0x800ab2cc..0x800ab32f  size 100 B
 * body sha256 14703bdd7ebc401af2604d13a0d3612575329acc83bb29078f3edc8def52ba29
 * provider record sha256 835e65a42ba44ad1f66356cefc965ac088801c21c705fac24e5b0536028ce256
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800ab2cc(float *param_1,float *param_2,float *param_3)

{
  *param_1 = param_2[1] * param_3[2] - param_2[2] * param_3[1];
  param_1[1] = param_2[2] * *param_3 - *param_2 * param_3[2];
  param_1[2] = *param_2 * param_3[1] - param_2[1] * *param_3;
  return;
}
