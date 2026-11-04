/* FUN_8003fed8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003fed8  body 0x8003fed8..0x8003ffcf  size 248 B
 * body sha256 290139a2d730261e4d6793fb4c2b45b1c49027d485269362a03b3a687c729dc6
 * provider record sha256 073cfef9d4a2eef7124e4b90a173b4f37185c82e89b5c08c4a07a9e2c955d71a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8003ff04) */

void switchD_8003faf0::caseD_2(void)

{
  uint uVar1;
  uint unaff_s3;
  
  *(undefined1 *)(DAT_800ebb94 + 2) = 3;
  *(short *)(DAT_800ebb94 + 0x2e) =
       *(short *)(DAT_800ebb94 + 0x2e) -
       (short)((int)((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0xbe) >> 0xc);
  uVar1 = FUN_80033604();
  FUN_80038a20((unaff_s3 | 1) << 0x10 |
               ((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x5a) / 100 | 0x1a000000,
               (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar1 & 0xff) % 0x1e) * 400) *
                    0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
  return;
}
