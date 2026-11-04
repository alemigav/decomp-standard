/* FUN_800691c0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800691c0  body 0x800691c0..0x80069227  size 104 B
 * body sha256 7af20f12614a2ee384e8c69bafceeff0a8250c7b68be3b686946ca2541dea9a4
 * provider record sha256 3f92ab5091fc6aaae42037800911bb2347b4df93425d0d2467dd77c165229ddb
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_800691c0(int *param_1,int param_2,short *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)((ushort)param_3[2] >> 1);
  iVar1 = *param_1 - ((int)*param_3 + uVar3);
  iVar2 = param_1[2] - ((int)param_3[1] + uVar3);
  iVar1 = FUN_80040bb4(iVar1 * iVar1 + iVar2 * iVar2);
  return 0 < (int)((uVar3 + param_2) - iVar1);
}
