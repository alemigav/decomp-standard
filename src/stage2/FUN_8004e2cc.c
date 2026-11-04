/* FUN_8004e2cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004e2cc  body 0x8004e2cc..0x8004e437  size 364 B
 * body sha256 4f8c6144117c4703761fa1f645b04da736e5830cce74ede668067523a9211763
 * provider record sha256 8f97b95dfe6cf0c6d9eca26bd4d5e2275719acdcbd0abe72b37cdcf3b4e8108d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_8004e2cc(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short local_18 [2];
  short local_14;
  
  local_14 = 0;
  local_18[0] = (short)(((uint)*(ushort *)(param_1 + 0x136) * 0x78) / 100) + 0x80;
  FUN_800837d0((int)*(short *)(param_1 + 0x66),local_18,local_18);
  iVar4 = *(ushort *)(param_2 + 300) - 0x80;
  iVar5 = *(ushort *)(param_2 + 0x12e) - 0x80;
  iVar3 = *(int *)(param_2 + 0x28) - *(int *)(param_1 + 0x28);
  iVar2 = *(int *)(param_2 + 0x30) - *(int *)(param_1 + 0x30);
  if (((uint)(iVar3 + iVar4) <= (uint)(iVar4 * 2)) ||
     (bVar1 = false, (uint)(iVar2 + iVar5) <= (uint)(iVar5 * 2))) {
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    if (iVar2 < iVar3) {
      iVar2 = (int)(short)(local_18[0] + *(short *)(param_1 + 0x2a)) - *(int *)(param_2 + 0x120);
      iVar3 = *(int *)(param_1 + 0x30) - *(int *)(param_2 + 0x128);
      iVar5 = iVar5 + (uint)*(ushort *)(param_1 + 300);
    }
    else {
      iVar2 = *(int *)(param_1 + 0x28) - *(int *)(param_2 + 0x120);
      iVar3 = (int)(short)(local_14 + *(short *)(param_1 + 0x32)) - *(int *)(param_2 + 0x128);
      iVar4 = iVar4 + (uint)*(ushort *)(param_1 + 300);
    }
    if ((uint)(iVar4 << 1) < (uint)(iVar2 + iVar4)) {
      bVar1 = false;
    }
    else {
      bVar1 = (uint)(iVar3 + iVar5) <= (uint)(iVar5 << 1);
    }
  }
  return bVar1;
}
