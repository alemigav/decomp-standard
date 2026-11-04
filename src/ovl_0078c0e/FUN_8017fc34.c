/* FUN_8017fc34
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017fc34  body 0x8017fc34..0x8017fdbb  size 392 B
 * body sha256 92fa552d98d61c6fa8bc19960a859faf0366b1816e91912302e99c179f9e1b45
 * provider record sha256 b9071ec89a7e8c63ea145cc74e62fa7dc6d06b2f3c0179969b09763f926984da
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017fc34(undefined4 param_1,int param_2,short param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar4 = -0x7fe7f4be;
  puVar1 = &DAT_80180af0;
  puVar3 = &DAT_80180af0;
  *(undefined1 *)(param_2 + 0x14a) = 0;
  *(undefined4 *)(param_2 + 0x14c) = 0;
  do {
    if (((puVar3[2] == 0) && (*(short *)(puVar1 + 0x14) == param_3)) && (puVar1[0x13] == param_4)) {
      func_0x80082224(param_2 + (uint)*(byte *)(param_2 + 0x14a) * 0x16,iVar2 * 0x20 + -0x7fe7f4ba,
                      0x10);
      func_0x80082224(param_2 + (uint)*(byte *)(param_2 + 0x14a) * 0x16 + 0x10,iVar4,4);
      *(undefined1 *)(param_2 + (uint)*(byte *)(param_2 + 0x14a) * 0x16 + 0x14) = 0;
      *(undefined1 *)(param_2 + (uint)*(byte *)(param_2 + 0x14a) * 0x16 + 0x15) = 0;
      *(undefined4 *)(param_2 + (uint)*(byte *)(param_2 + 0x14a) * 4 + 0x150) = puVar1[0x12];
      *(int *)(param_2 + 0x14c) = *(int *)(param_2 + 0x14c) + puVar1[0x12];
      *(char *)(param_2 + 0x14a) = *(char *)(param_2 + 0x14a) + '\x01';
    }
    iVar4 = iVar4 + 0x20;
    puVar1 = puVar1 + 8;
    iVar2 = iVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar2 < 0x10);
  return;
}
