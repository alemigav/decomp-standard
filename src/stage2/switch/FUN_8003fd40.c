/* FUN_8003fd40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003fd40  body 0x8003fd40..0x8003fed7  size 408 B
 * body sha256 00367fe5ebe224d72a7b0a4447914bd436b8e9e3feea0efedbb4f9c8062a1e9b
 * provider record sha256 20a84b702861d6da9ecc5102d1533c46c9e6a7515acfaa124d4ad4e76048863a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8003fd64) */
/* WARNING: Removing unreachable block (ram,0x8003fe50) */

void switchD_8003faf0::caseD_1(void)

{
  uint uVar1;
  uint uVar2;
  uint unaff_s3;
  
  *(undefined1 *)(DAT_800ebb94 + 2) = 2;
  *(short *)(DAT_800ebb94 + 0x2e) =
       *(short *)(DAT_800ebb94 + 0x2e) -
       (short)((int)((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x104) >> 0xc);
  uVar1 = FUN_80033604();
  uVar2 = (unaff_s3 | 1) << 0x10;
  FUN_80038a20(uVar2 | ((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x73) / 100 | 0x1a000000,
               (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar1 & 0xff) % 0x1e) * 400) *
                    0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
  *(short *)(DAT_800ebb94 + 0x2e) =
       *(short *)(DAT_800ebb94 + 0x2e) -
       (short)((int)((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0xe6) >> 0xc);
  uVar1 = FUN_80033604();
  FUN_80038a20(uVar2 | *(ushort *)(DAT_800ebb94 + 0x3a) | 0x1a000000,
               (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar1 & 0xff) % 0x1e) * 400) *
                    0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
  return;
}
