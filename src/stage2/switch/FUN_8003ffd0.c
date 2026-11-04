/* FUN_8003ffd0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003ffd0  body 0x8003ffd0..0x8004018f  size 448 B
 * body sha256 79688d4cae6ce885fc125066004f6fcb39c8834af87069de727f9ce98757423a
 * provider record sha256 608ab14a99066325e889c24097ce54a9907d0b920eeb722066837bb84b179cac
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8003fffc) */
/* WARNING: Removing unreachable block (ram,0x800400e4) */

void switchD_8003faf0::caseD_3(void)

{
  uint uVar1;
  uint uVar2;
  uint unaff_s3;
  
  *(undefined1 *)(DAT_800ebb94 + 2) = 4;
  *(short *)(DAT_800ebb94 + 0x2e) =
       *(short *)(DAT_800ebb94 + 0x2e) +
       (short)((int)((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0xbe) >> 0xc);
  uVar1 = FUN_80033604();
  uVar2 = (unaff_s3 | 1) << 0x10;
  FUN_80038a20(uVar2 | ((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x5a) / 100 | 0x1a000000,
               (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar1 & 0xff) % 0x1e) * 400) *
                    0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
  *(short *)(DAT_800ebb94 + 0x2e) =
       *(short *)(DAT_800ebb94 + 0x2e) +
       (short)((int)((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0xe6) >> 0xc);
  uVar1 = FUN_80033604();
  FUN_80038a20(uVar2 | ((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x69) / 100 | 0x1a000000,
               (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar1 & 0xff) % 0x1e) * 400) *
                    0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
  return;
}
