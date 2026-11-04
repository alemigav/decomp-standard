/* FUN_80069aa8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80069aa8  body 0x80069aa8..0x80069c5f  size 440 B
 * body sha256 2b8de84d9ecebb08961bbdc6b30f2ca905a048c8f9748928e55f3fe37b268174
 * provider record sha256 e98f8c58d9c00dd07820afefb92ac020d99d3eaa9b1f8d2829ba9b083ed002c9
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80069aa8(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar3 = (uint)(*(ushort *)(param_3 + 6) >> 1);
  iVar2 = ((int)*(short *)(param_3 + 2) + uVar3) - *(int *)(param_1 + 0x128);
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  if ((int)(uVar3 / 2) < iVar2) {
    iVar2 = (iVar2 * 2 - uVar3) * 0xa0;
    if (uVar3 == 0) {
      trap(0x1c00);
    }
    if ((uVar3 == 0xffffffff) && (iVar2 == -0x80000000)) {
      trap(0x1800);
    }
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + iVar2 / (int)uVar3;
  }
  iVar6 = (*(int *)(param_1 + 0x128) + (int)*(short *)(param_1 + 0x13e)) -
          ((int)*(short *)(param_3 + 2) + uVar3);
  iVar2 = FUN_8006b264();
  iVar5 = *(int *)(param_1 + 0x2c) - (iVar2 - uVar3);
  iVar1 = FUN_80040bb4(iVar6 * iVar6 + iVar5 * iVar5);
  iVar4 = uVar3 - iVar1;
  iVar2 = iVar4;
  if (iVar4 < 0) {
    iVar2 = -iVar4;
  }
  if (10 < iVar2) {
    iVar1 = iVar1 + 1;
    if (iVar1 == 0) {
      trap(0x1c00);
    }
    if ((iVar1 == -1) && (iVar6 * iVar4 == -0x80000000)) {
      trap(0x1800);
    }
    if (iVar1 == 0) {
      trap(0x1c00);
    }
    if ((iVar1 == -1) && (iVar5 * iVar4 == -0x80000000)) {
      trap(0x1800);
    }
    *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) + (iVar6 * iVar4) / iVar1;
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (iVar5 * iVar4) / iVar1;
  }
  return 1;
}
