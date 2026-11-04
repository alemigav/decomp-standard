/* FUN_800411b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800411b8  body 0x800411b8..0x8004131f  size 360 B
 * body sha256 58d19aa616b7a1ea94cb3ce8e3bc79a7e189fce918b5b09ff433d1efa3d468de
 * provider record sha256 9f8f617fb1e5dcf3f5b5195256270e11033aeeba20cef9c35ba43e71f11150be
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800411b8(short *param_1,uint *param_2)

{
  int iVar1;
  
  *param_2 = ((int)*param_1 & 0xffff000U) << 4 |
             (int)((uint)(ushort)param_1[3] << 0x10) >> 0x1c & 0xffffU;
  param_2[8] = (int)*param_1 << 0x14 | ((int)param_1[3] & 0xfffU) << 4;
  param_2[1] = ((int)param_1[6] & 0xffff000U) << 4;
  param_2[9] = (int)param_1[6] << 0x14;
  param_2[2] = ((int)param_1[1] & 0xffff000U) << 4 |
               (int)((uint)(ushort)param_1[4] << 0x10) >> 0x1c & 0xffffU;
  param_2[10] = (int)param_1[1] << 0x14 | ((int)param_1[4] & 0xfffU) << 4;
  param_2[3] = ((int)param_1[7] & 0xffff000U) << 4;
  param_2[0xb] = (int)param_1[7] << 0x14;
  param_2[4] = ((int)param_1[2] & 0xffff000U) << 4 |
               (int)((uint)(ushort)param_1[5] << 0x10) >> 0x1c & 0xffffU;
  param_2[0xc] = (int)param_1[2] << 0x14 | ((int)param_1[5] & 0xfffU) << 4;
  param_2[5] = ((int)param_1[8] & 0xffff000U) << 4;
  param_2[0xd] = (int)param_1[8] << 0x14;
  param_2[6] = *(int *)(param_1 + 10) << 0x10 | (uint)(ushort)param_1[0xd];
  param_2[0xe] = 0;
  iVar1 = *(int *)(param_1 + 0xe);
  param_2[0xf] = 0;
  param_2[7] = iVar1 * 0x10000 + 1;
  return;
}
