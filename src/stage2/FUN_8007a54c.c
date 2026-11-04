/* FUN_8007a54c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007a54c  body 0x8007a54c..0x8007a5eb  size 160 B
 * body sha256 ee8a5efc0103726c5aaaf24fb0940c6040791b4b669f51b9b115a10dafb1011d
 * provider record sha256 30950d79a17f54889cb2fdab36779be1539420948fa2fbb123e53328e225f29d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007a54c(int param_1)

{
  **(uint **)(param_1 + 0x234) = **(uint **)(param_1 + 0x234) | 0x4000;
  *(code **)(param_1 + 0x2a0) = FUN_80035e3c;
  *(undefined1 **)(param_1 + 0x2a4) = &LAB_800805f4;
  if ((*(ushort *)(param_1 + 0x1aa) & 0x80) == 0) {
    DAT_800df934 = FUN_80035e34(param_1,DAT_800df934);
  }
  *(undefined2 *)(param_1 + 0x2b8) = 0;
  *(undefined2 *)(param_1 + 0x2c0) = 0;
  *(undefined2 *)(param_1 + 700) = 0;
  *(undefined1 *)(param_1 + 0x2bf) = 0;
  *(undefined1 *)(param_1 + 0x1ed) = 0;
  *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) | 0x80;
  return;
}
