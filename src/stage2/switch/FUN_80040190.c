/* FUN_80040190
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040190  body 0x80040190..0x80040453  size 708 B
 * body sha256 87be6347a43feac3c719ef0cb2e1455797f87dd208aecd36f3bb34268bab4a14
 * provider record sha256 21b51289842d60babcb73294b6836fe2e23c1b6d164d590780ce5a0ee626ebf4
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x800401a8) */
/* WARNING: Removing unreachable block (ram,0x8004028c) */
/* WARNING: Removing unreachable block (ram,0x80040350) */

void switchD_8003faf0::caseD_4(void)

{
  undefined1 *puVar1;
  uint uVar2;
  uint uVar3;
  uint unaff_s3;
  
  *(short *)(DAT_800ebb94 + 0x2e) =
       *(short *)(DAT_800ebb94 + 0x2e) +
       (short)((int)((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x104) >> 0xc);
  uVar2 = FUN_80033604();
  uVar3 = ((unaff_s3 & 0xff) + 1) * 0x10000;
  FUN_80038a20(uVar3 | ((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x6e) / 100 | 0x1a000000,
               (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar2 & 0xff) % 0x1e) * 400) *
                    0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
  *(short *)(DAT_800ebb94 + 0x2e) =
       *(short *)(DAT_800ebb94 + 0x2e) +
       (short)((int)((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x122) >> 0xc);
  uVar2 = FUN_80033604();
  FUN_80038a20(uVar3 | ((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x8c) / 100 | 0x1a000000,
               (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar2 & 0xff) % 0x1e) * 400) *
                    0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
  *(short *)(DAT_800ebb94 + 0x2e) =
       *(short *)(DAT_800ebb94 + 0x2e) +
       (short)((int)((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 300) >> 0xc);
  uVar2 = FUN_80033604();
  FUN_80038a20(uVar3 | ((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0xaa) / 100 | 0x1a000000,
               (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar2 & 0xff) % 0x1e) * 400) *
                    0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
  FUN_80038a20(((unaff_s3 & 0xff) + 4) * 0x10000 | *(ushort *)(DAT_800ebb94 + 0x3a) | 0x1a000000,
               (int)*(short *)(DAT_800ebb94 + 0x22),*(undefined4 *)(DAT_800ebb94 + 0x6c),
               DAT_800ebb94 + 0x2c);
  puVar1 = DAT_800ebb94;
  DAT_800ebb94[1] = 0;
  *puVar1 = 0;
  *(undefined2 *)(puVar1 + 0x18) = 0;
  return;
}
