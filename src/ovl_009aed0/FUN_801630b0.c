/* FUN_801630b0
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x801630b0  body 0x801630b0..0x80163153  size 164 B
 * body sha256 022212ae47ccea6228a0b7c8a2049b89d08d402b3f261d13b508fc979e909938
 * provider record sha256 3229084a83b850e52732d899226fbd5035e8fde7fe4deaf5f42768a16de49996
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801630b0(int param_1,short param_2)

{
  short sVar1;
  short local_18 [4];
  
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[0] = param_2;
  func_0x800837d0((int)*(short *)(param_1 + 0x66),local_18,local_18);
  local_18[0] = local_18[0] + *(short *)(param_1 + 0x2a);
  _DAT_800e1158 = (int)local_18[0];
  local_18[2] = local_18[2] + *(short *)(param_1 + 0x32);
  _DAT_800e1160 = (int)local_18[2];
  sVar1 = func_0x80032d14((int)local_18[0],(int)local_18[2],(int)*(short *)(param_1 + 0x2a),
                          (int)*(short *)(param_1 + 0x32));
  _DAT_800e1196 = sVar1 + -0x32;
  return;
}
