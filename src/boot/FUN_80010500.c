/* FUN_80010500
 * image   boot (boot), base 0x80000480
 * address 0x80010500  body 0x80010500..0x80010583  size 132 B
 * body sha256 f8a27edc7277a31ad974946f574c9109bcbd9d4b9cde6efa2b94f628bcbeea25
 * provider record sha256 47e98593b94ecd7f5613f80a7a0c7eba11d0074daa449e6824c4965120953f1a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int * FUN_80010500(int *param_1,int param_2,int param_3)

{
  int local_8;
  int local_4;
  
  local_8 = param_2 / param_3;
  if (param_3 == 0) {
    trap(0x1c00);
  }
  if ((param_3 == -1) && (param_2 == -0x80000000)) {
    trap(0x1800);
  }
  local_4 = param_2 - param_3 * local_8;
  if ((local_8 < 0) && (0 < local_4)) {
    local_4 = local_4 - param_3;
    local_8 = local_8 + 1;
  }
  *param_1 = local_8;
  param_1[1] = local_4;
  return param_1;
}
