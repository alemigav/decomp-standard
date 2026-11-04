/* FUN_8003faf8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003faf8  body 0x8003faf8..0x8003fd3f  size 584 B
 * body sha256 fbde17c0eaa2f22cee2a8bd2598f7c1856cadca05bd4ac4e5727ba0d44ecec02
 * provider record sha256 d03644413f669f2b511be5bbc23c0644d0fd95e5fbd257b039b7eea767ee68b4
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8003fca8) */
/* WARNING: Removing unreachable block (ram,0x8003fbe4) */

void switchD_8003faf0::caseD_0(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint unaff_s3;
  
  iVar1 = DAT_800ebb94;
  *(undefined1 *)(DAT_800ebb94 + 2) = 1;
  iVar2 = DAT_800ebb94;
  *(undefined2 *)(iVar1 + 0x18) = 0x8002;
  *(undefined2 *)(iVar2 + 0x12) = *(undefined2 *)(iVar2 + 0x2e);
  uVar3 = FUN_80033604();
  uVar4 = (unaff_s3 | 1) << 0x10;
  FUN_80038a20(uVar4 | ((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0xb4) / 100 | 0x1a000000,
               (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar3 & 0xff) % 0x1e) * 400) *
                    0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
  *(short *)(DAT_800ebb94 + 0x2e) =
       *(short *)(DAT_800ebb94 + 0x2e) -
       (short)((int)((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 300) >> 0xc);
  uVar3 = FUN_80033604();
  FUN_80038a20(uVar4 | ((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x96) / 100 | 0x1a000000,
               (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar3 & 0xff) % 0x1e) * 400) *
                    0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
  *(short *)(DAT_800ebb94 + 0x2e) =
       *(short *)(DAT_800ebb94 + 0x2e) -
       (short)((int)((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x122) >> 0xc);
  uVar3 = FUN_80033604();
  FUN_80038a20(uVar4 | ((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x78) / 100 | 0x1a000000,
               (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar3 & 0xff) % 0x1e) * 400) *
                    0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
  return;
}
