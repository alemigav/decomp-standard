/* FUN_8004d918
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004d918  body 0x8004d918..0x8004da3f  size 296 B
 * body sha256 4a01fa7e5f2d1041f9c6f973fbbb9458fa029465949a66ae0c55cea0f2755c82
 * provider record sha256 b362ce928f092886986d1b9153200a284ef00a78cc77b809d25386493758c1b9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8004d918(int *param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((*param_2 | *param_3) & 2) != 0) {
    return 0;
  }
  if ((*param_2 & *param_3 & 0x1000) != 0) {
    return 0;
  }
  iVar3 = (uint)*(ushort *)((int)param_2 + 0x136) + (uint)*(ushort *)((int)param_3 + 0x136);
  iVar2 = param_3[0x48] - (*param_1 + (int)*(short *)(param_2 + 0x4f));
  iVar1 = param_3[0x4a] - (param_1[2] + (int)*(short *)((int)param_2 + 0x13e));
  if ((uint)(iVar2 + iVar3) <= (uint)(iVar3 * 2)) {
    if ((uint)(iVar3 * 2) < (uint)(iVar1 + iVar3)) {
      return 0;
    }
    iVar1 = FUN_80040bb4(iVar2 * iVar2 + iVar1 * iVar1);
    if (iVar3 - iVar1 < 1) {
      return 0;
    }
    iVar2 = (uint)*(ushort *)((int)param_3 + 0x13a) + (uint)*(ushort *)((int)param_2 + 0x13a);
    iVar1 = param_3[0x49] - (param_1[1] + (int)*(short *)(param_2 + 0x4d));
    if ((-iVar2 < iVar1) && (iVar1 < iVar2)) {
      return 1;
    }
  }
  return 0;
}
