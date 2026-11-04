/* FUN_80033404
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80033404  body 0x80033404..0x800334c7  size 196 B
 * body sha256 cea9678250a8ffd5b7d07f69d9ada8775588edd108dd95c368286ef4d9ad1e78
 * provider record sha256 bca6e4fe0d23f0464d3f92fb4c75b94268ffe5c43bd2164768430f5277fed59a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80033404(undefined2 *param_1,int param_2,ushort *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar2 = *(uint *)(param_4 + (uint)*(byte *)(DAT_800df938 + 0x1e8) * 4);
  if (param_2 == 0) {
    uVar3 = (uint)*(byte *)(DAT_800df938 + 0x1e9);
  }
  else {
    uVar3 = ((uVar2 & 0xffff) - (uint)*(byte *)(DAT_800df938 + 0x1e9)) - 1;
  }
  puVar4 = (uint *)(param_4 + (uVar2 >> 0x10) + uVar3 * 4);
  uVar2 = *puVar4;
  while ((uVar2 & 0x8000) != 0) {
    puVar4 = puVar4 + 1;
    uVar2 = *puVar4;
  }
  iVar1 = (uint)(param_3[2] >> 2) * (*puVar4 & 0xfff) * 4 + (uint)*param_3;
  *param_1 = *(undefined2 *)((int)param_3 + iVar1 + 4);
  param_1[1] = *(undefined2 *)((int)param_3 + iVar1 + 10);
  param_1[2] = *(undefined2 *)((int)param_3 + iVar1 + 8);
  return;
}
