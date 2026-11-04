/* FUN_8003ed0c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003ed0c  body 0x8003ed0c..0x8003edf3  size 232 B
 * body sha256 02021d71d8d4eab773a0dae7282e8e51c70f80a9e65e41ebbfdadf829dc64644
 * provider record sha256 b4370489ff91b3c02be250301f91580fe009921b0fc76d321e64254a97661041
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003ed0c(void)

{
  byte bVar1;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 10;
  bVar1 = DAT_800ebb94[0x1e];
  do {
    iVar4 = iVar4 + -1;
    uVar3 = FUN_80033604();
    FUN_80038a20((bVar1 & 0xf8) << 0x10 | *(ushort *)(DAT_800ebb94 + 0x3a) | 0x1a000000,
                 (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar3 & 0xff) % 0x1e) * 400) *
                      0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
    puVar2 = DAT_800ebb94;
  } while (iVar4 != 0);
  DAT_800ebb94[1] = 0;
  *puVar2 = 0;
  *(undefined2 *)(puVar2 + 0x18) = 0;
  return;
}
