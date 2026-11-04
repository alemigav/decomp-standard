/* FUN_80067578
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80067578  body 0x80067578..0x800675f3  size 124 B
 * body sha256 98dc47040d97351338d85b5a3a632128df408b60dae6ddce2fb83b1b6fb0ed0c
 * provider record sha256 b7fbb9b0b7166a5b848a62b97a50c441732baf01c3771a32e11eef9901c5ccc3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80067578(int *param_1,int param_2,short *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*param_1 - (*param_3 - param_2)) * (param_2 * -2 - (uint)(ushort)param_3[3]);
  iVar2 = (uint)(ushort)param_3[2] + param_2 * 2;
  if (iVar2 == 0) {
    trap(0x1c00);
  }
  if ((iVar2 == -1) && (iVar1 == -0x80000000)) {
    trap(0x1800);
  }
  return iVar1 / iVar2 < (int)(param_1[2] - ((int)param_3[1] + (uint)(ushort)param_3[3] + param_2));
}
