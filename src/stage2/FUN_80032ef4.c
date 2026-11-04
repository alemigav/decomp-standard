/* FUN_80032ef4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80032ef4  body 0x80032ef4..0x80032f63  size 112 B
 * body sha256 3679e78a0edbed705c655a2e06182209cf8b44b9c848167cbd08d7478e5c845b
 * provider record sha256 ff9f611bc8ae6d927547d0ae1a56bd2546fa3d18343237594b6224fea0e59039
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80032ef4(int param_1,uint param_2,int param_3)

{
  short sVar1;
  uint uVar2;
  
  if (((int)(short)param_3 & 0x8000U) != 0) {
    param_3 = -(int)(short)param_3;
    param_2 = param_2 + 0x800 & 0xfff;
  }
  uVar2 = param_3 + (param_2 - *(ushort *)(param_1 + 0x66)) & 0xfff;
  sVar1 = *(ushort *)(param_1 + 0x66) - (short)param_3;
  if ((int)uVar2 < (param_3 << 0x10) >> 0xf) {
    *(short *)(param_1 + 0x66) = (short)param_2;
    return;
  }
  *(short *)(param_1 + 0x66) = sVar1;
  if (uVar2 < 0x801) {
    *(short *)(param_1 + 0x66) = sVar1 + (short)param_3 * 2;
  }
  return;
}
