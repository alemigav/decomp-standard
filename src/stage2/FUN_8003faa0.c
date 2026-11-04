/* FUN_8003faa0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003faa0  body 0x8003faa0..0x8003faf7  size 88 B
 * body sha256 0b2aa26d6b20d0d34fd8fecc2813c5f34ac8ba24e96ee1a86535bad7e64fea1c
 * provider record sha256 9649a59d015265f7b32270fde5642cba682aee4bd214a7eaef604fecf1befbea
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x800401a8) */
/* WARNING: Removing unreachable block (ram,0x8003fca8) */
/* WARNING: Removing unreachable block (ram,0x8003fd64) */
/* WARNING: Removing unreachable block (ram,0x8004028c) */
/* WARNING: Removing unreachable block (ram,0x8003fbe4) */
/* WARNING: Removing unreachable block (ram,0x8003ff04) */
/* WARNING: Removing unreachable block (ram,0x800400e4) */
/* WARNING: Removing unreachable block (ram,0x8003fffc) */
/* WARNING: Removing unreachable block (ram,0x8003fe50) */
/* WARNING: Removing unreachable block (ram,0x80040350) */

void FUN_8003faa0(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  
  puVar1 = DAT_800ebb94;
  uVar7 = (byte)DAT_800ebb94[0x1e] & 0xf8;
  switch(DAT_800ebb94[2]) {
  case 0:
    DAT_800ebb94[2] = 1;
    puVar2 = DAT_800ebb94;
    *(undefined2 *)(puVar1 + 0x18) = 0x8002;
    *(undefined2 *)(puVar2 + 0x12) = *(undefined2 *)(puVar2 + 0x2e);
    uVar3 = FUN_80033604();
    uVar6 = (uVar7 | 1) << 0x10;
    FUN_80038a20(uVar6 | ((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0xb4) / 100 | 0x1a000000,
                 (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar3 & 0xff) % 0x1e) * 400) *
                      0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
    *(short *)(DAT_800ebb94 + 0x2e) =
         *(short *)(DAT_800ebb94 + 0x2e) -
         (short)((int)((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 300) >> 0xc);
    uVar7 = FUN_80033604();
    FUN_80038a20(uVar6 | ((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x96) / 100 | 0x1a000000,
                 (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar7 & 0xff) % 0x1e) * 400) *
                      0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
    *(short *)(DAT_800ebb94 + 0x2e) =
         *(short *)(DAT_800ebb94 + 0x2e) -
         (short)((int)((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x122) >> 0xc);
    uVar3 = FUN_80033604();
    uVar5 = *(undefined4 *)(DAT_800ebb94 + 0x6c);
    uVar7 = (uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x78;
    iVar4 = (uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar3 & 0xff) % 0x1e) * 400;
    goto LAB_8004017c;
  case 1:
    DAT_800ebb94[2] = 2;
    *(short *)(DAT_800ebb94 + 0x2e) =
         *(short *)(DAT_800ebb94 + 0x2e) -
         (short)((int)((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x104) >> 0xc);
    uVar3 = FUN_80033604();
    uVar6 = (uVar7 | 1) << 0x10;
    FUN_80038a20(uVar6 | ((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x73) / 100 | 0x1a000000,
                 (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar3 & 0xff) % 0x1e) * 400) *
                      0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
    *(short *)(DAT_800ebb94 + 0x2e) =
         *(short *)(DAT_800ebb94 + 0x2e) -
         (short)((int)((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0xe6) >> 0xc);
    uVar7 = FUN_80033604();
    FUN_80038a20(uVar6 | *(ushort *)(DAT_800ebb94 + 0x3a) | 0x1a000000,
                 (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar7 & 0xff) % 0x1e) * 400) *
                      0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
    break;
  case 2:
    DAT_800ebb94[2] = 3;
    *(short *)(DAT_800ebb94 + 0x2e) =
         *(short *)(DAT_800ebb94 + 0x2e) -
         (short)((int)((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0xbe) >> 0xc);
    uVar3 = FUN_80033604();
    FUN_80038a20((uVar7 | 1) << 0x10 |
                 ((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x5a) / 100 | 0x1a000000,
                 (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar3 & 0xff) % 0x1e) * 400) *
                      0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
    break;
  case 3:
    DAT_800ebb94[2] = 4;
    *(short *)(DAT_800ebb94 + 0x2e) =
         *(short *)(DAT_800ebb94 + 0x2e) +
         (short)((int)((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0xbe) >> 0xc);
    uVar3 = FUN_80033604();
    uVar6 = (uVar7 | 1) << 0x10;
    FUN_80038a20(uVar6 | ((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x5a) / 100 | 0x1a000000,
                 (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar3 & 0xff) % 0x1e) * 400) *
                      0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
    *(short *)(DAT_800ebb94 + 0x2e) =
         *(short *)(DAT_800ebb94 + 0x2e) +
         (short)((int)((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0xe6) >> 0xc);
    uVar3 = FUN_80033604();
    uVar5 = *(undefined4 *)(DAT_800ebb94 + 0x6c);
    uVar7 = (uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x69;
    iVar4 = (uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar3 & 0xff) % 0x1e) * 400;
LAB_8004017c:
    FUN_80038a20(uVar6 | uVar7 / 100 | 0x1a000000,iVar4 * 0x10000 >> 0x10,uVar5,DAT_800ebb94 + 0x2c)
    ;
    break;
  case 4:
    *(short *)(DAT_800ebb94 + 0x2e) =
         *(short *)(DAT_800ebb94 + 0x2e) +
         (short)((int)((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x104) >> 0xc);
    uVar3 = FUN_80033604();
    uVar6 = (uVar7 + 1) * 0x10000;
    FUN_80038a20(uVar6 | ((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x6e) / 100 | 0x1a000000,
                 (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar3 & 0xff) % 0x1e) * 400) *
                      0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
    *(short *)(DAT_800ebb94 + 0x2e) =
         *(short *)(DAT_800ebb94 + 0x2e) +
         (short)((int)((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x122) >> 0xc);
    uVar3 = FUN_80033604();
    FUN_80038a20(uVar6 | ((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x8c) / 100 | 0x1a000000,
                 (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar3 & 0xff) % 0x1e) * 400) *
                      0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
    *(short *)(DAT_800ebb94 + 0x2e) =
         *(short *)(DAT_800ebb94 + 0x2e) +
         (short)((int)((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 300) >> 0xc);
    uVar3 = FUN_80033604();
    FUN_80038a20(uVar6 | ((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0xaa) / 100 | 0x1a000000,
                 (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar3 & 0xff) % 0x1e) * 400) *
                      0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
    FUN_80038a20((uVar7 + 4) * 0x10000 | *(ushort *)(DAT_800ebb94 + 0x3a) | 0x1a000000,
                 (int)*(short *)(DAT_800ebb94 + 0x22),*(undefined4 *)(DAT_800ebb94 + 0x6c),
                 DAT_800ebb94 + 0x2c);
    puVar1 = DAT_800ebb94;
    DAT_800ebb94[1] = 0;
    *puVar1 = 0;
    *(undefined2 *)(puVar1 + 0x18) = 0;
  }
  return;
}
