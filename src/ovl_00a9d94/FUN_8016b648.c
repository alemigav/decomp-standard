/* FUN_8016b648
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016b648  body 0x8016b648..0x8016b8d3  size 652 B
 * body sha256 321c38777e1154f080d6eaf70bde1507de7cfec0e3bf363411e3cad17db233a7
 * provider record sha256 8388735a55badf319639208e217479733e9d80db30e9ad20ed8c8989ebd630c6
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016b648(int param_1,int param_2)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  ushort uVar4;
  short sVar5;
  short *psVar6;
  
  bVar1 = *(byte *)(param_1 + 0x2c5);
  if (bVar1 == 1) {
LAB_8016b6c0:
    *(short *)(*(int *)(param_2 + 0x120) + 0x10) = *(short *)(*(int *)(param_2 + 0x120) + 0x10) >> 1
    ;
    psVar6 = (short *)((uint)*(byte *)(param_1 + 0x2d0) * 4 + *(int *)(param_2 + 0x120));
    *psVar6 = *psVar6 - *(short *)(param_1 + 0x2c6);
    psVar6 = (short *)((uint)*(byte *)(param_1 + 0x2d1) * 4 + *(int *)(param_2 + 0x120));
    *psVar6 = *psVar6 + *(short *)(param_1 + 0x2c6);
    if (*(char *)(param_1 + 0x2cb) == '\0') {
      sVar5 = *(short *)(param_1 + 0x2c6) + 4;
      *(short *)(param_1 + 0x2c6) = sVar5;
      if (0x100 < sVar5) {
        *(undefined2 *)(param_1 + 0x2c6) = 0x100;
      }
    }
    else {
      uVar4 = *(short *)(param_1 + 0x2c6) - 8;
      *(ushort *)(param_1 + 0x2c6) = uVar4;
      if ((int)((uint)uVar4 << 0x10) < 0) {
        *(undefined1 *)(param_1 + 0x2c5) = 2;
        *(undefined2 *)(param_1 + 0x2c6) = 0;
        uVar3 = func_0x80033604();
        sVar5 = *(short *)((uint)*(byte *)(param_1 + 0x2d1) * 4 + *(int *)(param_2 + 0x120));
        *(undefined1 *)(param_1 + 0x2cb) = 0;
        *(short *)(param_1 + 0x2c8) = sVar5 - ((short)((uVar3 & 0xff) >> 1) + 0x138);
        goto LAB_8016b8b0;
      }
    }
    bVar2 = *(short *)(param_1 + 0x2c8) <
            *(short *)((uint)*(byte *)(param_1 + 0x2d1) * 4 + *(int *)(param_2 + 0x120));
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 != 0) goto LAB_8016b8b0;
      *(undefined1 *)(param_1 + 0x2c3) = 0;
      *(undefined1 *)(param_1 + 0x2c5) = 1;
      *(undefined2 *)(param_1 + 0x2c6) = 0;
      *(undefined1 *)(param_1 + 0x2ca) = 0x78;
      uVar3 = func_0x80033604();
      *(short *)(param_1 + 0x2c8) = (short)((uVar3 & 0xff) >> 1) + 0x80;
      *(undefined1 *)(param_1 + 0x2cb) = 0;
      goto LAB_8016b6c0;
    }
    if (bVar1 != 2) goto LAB_8016b8b0;
    psVar6 = (short *)((uint)*(byte *)(param_1 + 0x2d0) * 4 + *(int *)(param_2 + 0x120));
    *psVar6 = *psVar6 + *(short *)(param_1 + 0x2c6);
    psVar6 = (short *)((uint)*(byte *)(param_1 + 0x2d1) * 4 + *(int *)(param_2 + 0x120));
    *psVar6 = *psVar6 - *(short *)(param_1 + 0x2c6);
    if (*(char *)(param_1 + 0x2cb) == '\0') {
      sVar5 = *(short *)(param_1 + 0x2c6) + 2;
      *(short *)(param_1 + 0x2c6) = sVar5;
      if (0x100 < sVar5) {
        *(undefined2 *)(param_1 + 0x2c6) = 0x100;
      }
    }
    else {
      uVar4 = *(short *)(param_1 + 0x2c6) - 4;
      *(ushort *)(param_1 + 0x2c6) = uVar4;
      if ((int)((uint)uVar4 << 0x10) < 0) {
        *(undefined1 *)(param_1 + 0x2c5) = 1;
        *(undefined2 *)(param_1 + 0x2c6) = 0;
        uVar3 = func_0x80033604();
        sVar5 = *(short *)((uint)*(byte *)(param_1 + 0x2d1) * 4 + *(int *)(param_2 + 0x120));
        *(undefined1 *)(param_1 + 0x2cb) = 0;
        *(short *)(param_1 + 0x2c8) = sVar5 + (short)((uVar3 & 0xff) >> 1) + 0x178;
        goto LAB_8016b8b0;
      }
    }
    bVar2 = *(short *)((uint)*(byte *)(param_1 + 0x2d1) * 4 + *(int *)(param_2 + 0x120)) <
            *(short *)(param_1 + 0x2c8);
  }
  if ((bVar2) && (*(char *)(param_1 + 0x2cb) == '\0')) {
    *(undefined1 *)(param_1 + 0x2cb) = 1;
  }
LAB_8016b8b0:
  *(byte *)(param_1 + 0x2c3) = *(char *)(param_1 + 0x2c3) + 1U & 0x3f;
  return;
}
