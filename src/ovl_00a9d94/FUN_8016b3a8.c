/* FUN_8016b3a8
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016b3a8  body 0x8016b3a8..0x8016b53b  size 404 B
 * body sha256 fbec5c60b14e935c516f6066942e489b6d1d1b217e76aac3bea7ef604d3b8c2d
 * provider record sha256 2d307b8d1e85f95373e36932df3c0aa335e842283c6ac2878739938cb46eb76c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016b3a8(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  short *psVar4;
  short sVar5;
  
  if (*(char *)(param_1 + 0x2c5) == '\0') {
    *(undefined1 *)(param_1 + 0x2c5) = 1;
    *(undefined2 *)(param_1 + 0x2c6) = 0;
    uVar2 = func_0x80033604();
    uVar3 = func_0x80033604();
    cVar1 = ((byte)((int)(uVar2 & 0xff) >> (uVar3 & 3)) & 1) + 5;
    *(char *)(param_1 + 0x2d0) = cVar1;
    *(char *)(param_1 + 0x2d1) = '\v' - cVar1;
    uVar2 = func_0x80033604();
    *(short *)(param_1 + 0x2c8) = *(short *)(&DAT_8016c53c + (uVar2 & 0x1f) * 2) + 0x800;
  }
  else if (*(char *)(param_1 + 0x2c5) != '\x01') {
    return;
  }
  psVar4 = (short *)((uint)*(byte *)(param_1 + 0x2d0) * 4 + *(int *)(param_2 + 0x120));
  *psVar4 = *psVar4 + *(short *)(param_1 + 0x2c6);
  sVar5 = *(short *)(param_1 + 0x2c6) + 8;
  *(short *)(param_1 + 0x2c6) = sVar5;
  psVar4 = (short *)((uint)*(byte *)(param_1 + 0x2d1) * 4 + *(int *)(param_2 + 0x120));
  *psVar4 = *psVar4 + sVar5 / 3;
  psVar4 = (short *)((uint)*(byte *)(param_1 + 0x2d1) * 4 + *(int *)(param_2 + 0x120));
  if (0x1000 - *(short *)(param_1 + 0x2c8) < (int)*psVar4) {
    *psVar4 = 0x1000 - *(short *)(param_1 + 0x2c8);
  }
  *(short *)(*(int *)(param_2 + 0x120) + 0x10) = *(short *)(*(int *)(param_2 + 0x120) + 0x10) >> 1;
  psVar4 = (short *)((uint)*(byte *)(param_1 + 0x2d0) * 4 + *(int *)(param_2 + 0x120));
  if (*(short *)(param_1 + 0x2c8) < *psVar4) {
    *psVar4 = *(short *)(param_1 + 0x2c8);
    *(undefined1 *)(param_1 + 0x2c4) = 6;
    *(undefined1 *)(param_1 + 0x2c5) = 0;
  }
  return;
}
