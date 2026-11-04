/* FUN_800350e8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800350e8  body 0x800350e8..0x800351e7  size 256 B
 * body sha256 27dd00428523f770ce58d5234214ed8c803b40dae91baf341765c90d3287947b
 * provider record sha256 0d6d3948ad94e9ac737804a5618de4b486d133403ee7c6501f22d074135e09df
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800350e8(uint *param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_78 [96];
  
  uVar3 = param_1[0x8d];
  if ((*param_1 & 0x40000) == 0) {
    FUN_80040e58(param_1 + 0x19,param_1 + 5);
  }
  FUN_800424ec(param_1 + 5,uVar3 + 8,auStack_78);
  FUN_800424ec(auStack_78,uVar3 + 0xbc8,uVar3 + 0xbf8);
  sVar1 = *(short *)(uVar3 + 0xc1a) + *(short *)((int)param_1 + 0x66) + *(short *)(uVar3 + 0x5a);
  *(ushort *)(uVar3 + 0x5c) = *(ushort *)(uVar3 + 0x5c) & 0xfff;
  if ((param_1[0x97] & 0x1000000) == 0) {
    sVar1 = *(short *)(uVar3 + 0xcf0) + sVar1;
  }
  iVar2 = (int)sVar1;
  FUN_80034e0c(param_1,0,iVar2);
  FUN_80034e0c(param_1,1,iVar2);
  FUN_80034e0c(param_1,2,iVar2);
  FUN_80034e0c(param_1,3,iVar2);
  return;
}
