/* FUN_8009bd84
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009bd84  body 0x8009bd84..0x8009be77  size 244 B
 * body sha256 79321793b8777086743dcebe185112fdb3fc5b9481a07d11460c1054dc733136
 * provider record sha256 caeadc4aab6e83b5291fdcc8602f3e0d5acd624769ac0eb43b9239ca8998764b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8009bd84(int param_1)

{
  ushort uVar1;
  undefined4 *puVar2;
  uint *puVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x1c);
  puVar3 = (uint *)(&DAT_80132118)[*(byte *)(iVar4 + 1)];
  *(undefined1 *)(puVar3 + 2) = *(undefined1 *)(iVar4 + 2);
  *(ushort *)((int)puVar3 + 0x1aa) = (ushort)*(byte *)(iVar4 + 3);
  *puVar3 = (uint)*(byte *)(iVar4 + 4);
  *(ushort *)((int)puVar3 + 0x1e2) = (ushort)*(byte *)(iVar4 + 5);
  uVar1 = *(ushort *)(iVar4 + 6);
  *(ushort *)(puVar3 + 0x78) = uVar1;
  puVar3[4] = (int)*(short *)(iVar4 + 8);
  puVar3[10] = (int)*(short *)(iVar4 + 10);
  puVar3[0xb] = (int)*(short *)(iVar4 + 0xc);
  puVar3[0xc] = (int)*(short *)(iVar4 + 0xe);
  *(undefined2 *)(puVar3 + 0x19) = *(undefined2 *)(iVar4 + 0x10);
  *(undefined2 *)((int)puVar3 + 0x66) = *(undefined2 *)(iVar4 + 0x12);
  *(undefined2 *)(puVar3 + 0x1a) = *(undefined2 *)(iVar4 + 0x14);
  if ((uVar1 & 0x10) == 0) {
    puVar2 = &DAT_800e9028;
  }
  else {
    puVar2 = (undefined4 *)((&DAT_80132118)[uVar1 & 0xf] + 0x44);
  }
  puVar3[0x1c] = (uint)puVar2;
  if ((uVar1 & 0x800) != 0) {
    *(undefined2 *)(_DAT_8013a430 + 0x244) = 1;
  }
  *(int *)(param_1 + 0x1c) = iVar4 + 0x16;
  FUN_8009bb70(puVar3,*(undefined2 *)((int)puVar3 + 0x1e2));
  return 1;
}
