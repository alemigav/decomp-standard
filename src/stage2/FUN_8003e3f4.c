/* FUN_8003e3f4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003e3f4  body 0x8003e3f4..0x8003e6ef  size 764 B
 * body sha256 3ee52434ef4024278d9dd13f3e47341bc48284e4a70cd5034452988c4c7d3670
 * provider record sha256 49b98ebd80b304a1c6f61fe778a3b3d71dec2fb6bf1f39584c3f2d6c4b438477
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003e3f4(void)

{
  ushort uVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  puVar2 = DAT_800ebb94;
  uVar5 = (byte)DAT_800ebb94[0x1e] & 0xf8;
  if (DAT_800ebb94[2] == '\0') {
    *(undefined2 *)(DAT_800ebb94 + 0x18) = 0x8002;
    puVar2[2] = 1;
    DAT_800ebb94[3] = 0x5a;
  }
  else if (DAT_800ebb94[2] != '\x01') {
    return;
  }
  puVar2 = DAT_800ebb94;
  if (DAT_800ebb94[3] == '\0') {
    DAT_800ebb94[1] = 0;
    *puVar2 = 0;
    *(undefined2 *)(puVar2 + 0x18) = 0;
  }
  else {
    uVar3 = FUN_80033604();
    uVar1 = *(ushort *)(DAT_800ebb94 + 0x3a);
    uVar4 = FUN_80033604();
    FUN_80038a20(((uVar3 & 0xff) % 3 + uVar5) * 0x10000 | uVar1 | 0x26000000,
                 (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar4 & 0xff) % 0x1e) * 400) *
                      0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
    uVar3 = FUN_80033604();
    uVar1 = *(ushort *)(DAT_800ebb94 + 0x3a);
    uVar4 = FUN_80033604();
    FUN_80038a20(((uVar3 & 0xff) % 3 + uVar5) * 0x10000 | uVar1 | 0x26000000,
                 (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar4 & 0xff) % 0x1e) * 400) *
                      0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
    uVar3 = FUN_80033604();
    uVar1 = *(ushort *)(DAT_800ebb94 + 0x3a);
    uVar4 = FUN_80033604();
    FUN_80038a20(((uVar3 & 0xff) % 3 + uVar5) * 0x10000 | uVar1 | 0x26000000,
                 (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar4 & 0xff) % 0x1e) * 400) *
                      0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
    if ((byte)DAT_800ebb94[3] < 0x41) {
      *(short *)(DAT_800ebb94 + 0x3a) =
           (short)(((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x3bb) / 1000);
    }
    DAT_800ebb94[3] = DAT_800ebb94[3] + -1;
  }
  return;
}
