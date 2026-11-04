/* FUN_800af9cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800af9cc  body 0x800af9cc..0x800afbfb  size 560 B
 * body sha256 f0b7efe179a9a181d871e9cd3119224f7177821a80a1959fb06100f6dbb0a50b
 * provider record sha256 cb93c40d620a71f486ba99198395381b5470981edb6bd575a34a7ed56215aa6a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800af9cc(int param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  ushort *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  uVar6 = *(uint *)(param_1 + 0x5c);
  uVar5 = *param_2 >> 8 & 0xffff;
  uVar2 = uVar6 & 0xffffff;
  if (uVar2 == uVar5) {
    *(ushort *)(param_1 + 0x50) = (ushort)(byte)(uVar6 >> 0x18);
    *(undefined1 *)(param_1 + 0xc0) = 0;
  }
  else if (uVar2 < uVar5) {
    uVar5 = (uVar5 << 0xc) / uVar2;
    if (uVar2 == 0) {
      trap(0x1c00);
    }
    uVar2 = 1;
    uVar6 = 0;
    do {
      uVar4 = uVar2;
      if ((uVar5 >> 0xc) >> (uVar4 & 0x1f) == 0) break;
      uVar2 = uVar4 + 1;
      uVar6 = uVar4;
    } while (uVar4 < 0xb);
    iVar7 = 0xb;
    puVar3 = &DAT_80136b46;
    uVar2 = 1 << (uVar6 & 0x1f);
    uVar5 = uVar5 / uVar2;
    if (uVar2 == 0) {
      trap(0x1c00);
    }
    while (uVar1 = *puVar3, puVar3 = puVar3 + -1, uVar5 <= uVar1) {
      iVar7 = iVar7 + -1;
    }
    *(ushort *)(param_1 + 0x50) =
         (ushort)*(byte *)(param_1 + 0x5c) + (short)uVar6 * 0xc + (short)iVar7;
    uVar2 = (uint)*(ushort *)(&UNK_80136b30 + (iVar7 + 1) * 2) -
            (uint)*(ushort *)(&UNK_80136b30 + iVar7 * 2);
    if (uVar2 == 0) {
      trap(0x1c00);
    }
    *(char *)(param_1 + 0xc0) =
         (char)(((uVar5 - *(ushort *)(&UNK_80136b30 + iVar7 * 2)) * 100) / uVar2);
  }
  else {
    uVar2 = (uVar6 << 0xc) / uVar5;
    if (uVar5 == 0) {
      trap(0x1c00);
    }
    uVar5 = 1;
    uVar6 = 0;
    do {
      uVar4 = uVar5;
      if ((uVar2 >> 0xc) >> (uVar4 & 0x1f) == 0) break;
      uVar5 = uVar4 + 1;
      uVar6 = uVar4;
    } while (uVar4 < 0xb);
    iVar7 = 0xb;
    puVar3 = &DAT_80136b46;
    uVar5 = 1 << (uVar6 & 0x1f);
    uVar2 = uVar2 / uVar5;
    if (uVar5 == 0) {
      trap(0x1c00);
    }
    while (uVar1 = *puVar3, puVar3 = puVar3 + -1, uVar2 <= uVar1) {
      iVar7 = iVar7 + -1;
    }
    *(ushort *)(param_1 + 0x50) =
         ((ushort)*(byte *)(param_1 + 0x5c) + (short)uVar6 * -0xc) - (short)iVar7;
    uVar5 = (uint)*(ushort *)(&UNK_80136b30 + (iVar7 + 1) * 2) -
            (uint)*(ushort *)(&UNK_80136b30 + iVar7 * 2);
    if (uVar5 == 0) {
      trap(0x1c00);
    }
    *(char *)(param_1 + 0xc0) =
         -(char)(((uVar2 - *(ushort *)(&UNK_80136b30 + iVar7 * 2)) * 100) / uVar5);
  }
  *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) | 0x100;
  return 0;
}
