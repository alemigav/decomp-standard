/* FUN_80034d3c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80034d3c  body 0x80034d3c..0x80034e0b  size 208 B
 * body sha256 2395640dfc4133740703a4279023a9858de08a006f16fe5403590e4416db8f03
 * provider record sha256 f65518501f2014768a3cfa5c7dd958da18f6586fafc81adc605e3b6df66d26ca
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80034d3c(int param_1)

{
  ushort uVar1;
  int iVar2;
  undefined1 auStack_78 [96];
  
  iVar2 = *(int *)(param_1 + 0x234);
  FUN_80040e58(param_1 + 100,param_1 + 0x14);
  FUN_800424ec(param_1 + 0x14,iVar2 + 8,auStack_78);
  uVar1 = *(ushort *)(param_1 + 0x66);
  *(ushort *)(iVar2 + 0x5c) = *(ushort *)(iVar2 + 0x5c) & 0xfff;
  FUN_800352c4(iVar2 + 0xd38,auStack_78,400,0,0x28,4,0,400,0,0x18,4,0,
               (int)(((uint)uVar1 + (uint)*(ushort *)(iVar2 + 0x5a)) * 0x10000) >> 0x10);
  return;
}
