/* FUN_8016b080
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016b080  body 0x8016b080..0x8016b213  size 404 B
 * body sha256 b10da4b0182f82deb4d043f62182ffc8be36e5948328e3ad38b816a322e24cd6
 * provider record sha256 01dc8ca12db6b1bcca74d7eff309071cb4fafa6668af153ad0a8c313339f859d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016b080(int param_1,int param_2)

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
  sVar5 = *(short *)(param_1 + 0x2c6) + 1;
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
