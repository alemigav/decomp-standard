/* FUN_8000ecb0
 * image   boot (boot), base 0x80000480
 * address 0x8000ecb0  body 0x8000ecb0..0x8000ef9b  size 748 B
 * body sha256 5252ebfcfc4aef0c6b9e2b49def3d940306ceeca1ecf05f68f512b4d42a04142
 * provider record sha256 3002986ac37d3b73a1420147c18fecbd75219ab4615b73b234160c674810553e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8000ed68) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000ecb0(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  ushort *puVar7;
  undefined4 *puVar8;
  ushort *puVar9;
  int iVar10;
  uint uVar11;
  float fVar12;
  
  puVar7 = _DAT_800129d4;
  iVar10 = *(int *)(_DAT_800129d4 + 4);
  uVar11 = _DAT_a4400010 & 1;
  iVar2 = FUN_8000e800(*(undefined4 *)(_DAT_800129d4 + 2));
  iVar2 = iVar2 + *(int *)(iVar10 + uVar11 * 0x14 + 0x28);
  if ((*puVar7 & 2) == 0) {
    *(undefined4 *)(puVar7 + 0x10) = *(undefined4 *)(iVar10 + 0x20);
  }
  else {
    *(uint *)(puVar7 + 0x10) = *(uint *)(puVar7 + 0x10) | *(uint *)(iVar10 + 0x20) & 0xfffff000;
  }
  if ((*puVar7 & 4) == 0) {
    uVar3 = *(uint *)(iVar10 + uVar11 * 0x14 + 0x2c);
  }
  else {
    fVar12 = *(float *)(puVar7 + 0x12) * (float)(*(uint *)(iVar10 + uVar11 * 0x14 + 0x2c) & 0xfff);
    if (fVar12 < 2.1474836e+09) {
      uVar3 = (uint)fVar12;
    }
    else {
      uVar3 = (int)(fVar12 - 2.1474836e+09) | 0x80000000;
    }
    *(uint *)(puVar7 + 0x16) = uVar3;
    uVar3 = uVar3 | *(uint *)(iVar10 + uVar11 * 0x14 + 0x2c) & 0xfffff000;
  }
  *(uint *)(puVar7 + 0x16) = uVar3;
  uVar1 = *puVar7;
  uVar3 = *(uint *)(iVar10 + 0x1c);
  if ((uVar1 & 0x40) != 0) {
    uVar4 = *(undefined4 *)(puVar7 + 2);
    puVar7[0x16] = 0;
    puVar7[0x17] = 0;
    iVar2 = FUN_8000e800(uVar4);
  }
  if ((*puVar7 & 0x80) != 0) {
    *(uint *)(puVar7 + 0x16) = (puVar7[0x14] & 0x3ff) << 0x10;
    iVar2 = FUN_8000e800(*(undefined4 *)(puVar7 + 2));
  }
  puVar8 = (undefined4 *)_DAT_800129d0;
  _DAT_a4400008 = *(undefined4 *)(iVar10 + 8);
  _DAT_a4400014 = *(undefined4 *)(iVar10 + 0xc);
  _DAT_a4400018 = *(undefined4 *)(iVar10 + 0x10);
  _DAT_a440001c = *(undefined4 *)(iVar10 + 0x14);
  _DAT_a4400020 = *(undefined4 *)(iVar10 + 0x18);
  iVar10 = iVar10 + uVar11 * 0x14;
  _DAT_a4400028 = *(undefined4 *)(iVar10 + 0x30);
  _DAT_a440002c = *(undefined4 *)(iVar10 + 0x34);
  _DAT_a440000c = *(undefined4 *)(iVar10 + 0x38);
  _DAT_a4400030 = *(undefined4 *)(puVar7 + 0x10);
  _DAT_a4400034 = *(undefined4 *)(puVar7 + 0x16);
  _DAT_a4400000 = *(undefined4 *)(puVar7 + 6);
  puVar9 = puVar7 + 0x18;
  _DAT_800129d0 = puVar7;
  _DAT_800129d4 = (ushort *)puVar8;
  _DAT_a4400004 = iVar2;
  _DAT_a4400024 = uVar3 & -(uint)((uVar1 & 0x20) == 0);
  do {
    uVar4 = *(undefined4 *)(puVar7 + 2);
    uVar5 = *(undefined4 *)(puVar7 + 4);
    uVar6 = *(undefined4 *)(puVar7 + 6);
    *puVar8 = *(undefined4 *)puVar7;
    puVar8[1] = uVar4;
    puVar8[2] = uVar5;
    puVar8[3] = uVar6;
    puVar7 = puVar7 + 8;
    puVar8 = puVar8 + 4;
  } while (puVar7 != puVar9);
  return;
}
