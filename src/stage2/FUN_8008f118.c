/* FUN_8008f118
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008f118  body 0x8008f118..0x8008f18f  size 120 B
 * body sha256 fe086095adb352d8b56cecb8debdd5787e4c33cc7a7f16f43949e63f8c263ff0
 * provider record sha256 13136deddb2965dcf7df847c47dcfcda5a93f50c72953e8c4d9d2a787e735c49
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008f118(void)

{
  byte bVar1;
  int unaff_s2;
  int unaff_s3;
  
  FUN_800479c8(DAT_800c52dc + 0x44800,&DAT_8012fa38,*(undefined2 *)(&DAT_8012f5e0 + unaff_s3 * 2));
  DAT_800e1124 = 0x817;
  FUN_800824b0(DAT_800c52dc + 0x44800);
  FUN_80096e74(0);
  FUN_800986a4(0);
  *(undefined2 *)(unaff_s2 + 0x4e) = 0x102;
  *(undefined1 *)(unaff_s2 + 5) = 0;
  *(char *)(unaff_s2 + 4) = *(char *)(unaff_s2 + 4) + '\x01';
  *(short *)(unaff_s2 + 0x38) = *(short *)(unaff_s2 + 0x38) + -0xc;
  bVar1 = *(char *)(unaff_s2 + 5) + 1;
  *(byte *)(unaff_s2 + 5) = bVar1;
  if (4 < bVar1) {
    *(undefined1 *)(unaff_s2 + 5) = 0;
    *(char *)(unaff_s2 + 4) = *(char *)(unaff_s2 + 4) + '\x01';
  }
  *(short *)(unaff_s2 + 0x38) = *(short *)(unaff_s2 + 0x38) + 6;
  *(short *)(unaff_s2 + 0x3a) = *(short *)(unaff_s2 + 0x3a) + 8;
  *(short *)(unaff_s2 + 0x48) = *(short *)(unaff_s2 + 0x48) + 8;
  *(short *)(unaff_s2 + 0x40) = *(short *)(unaff_s2 + 0x40) + -6;
  FUN_800988a4(0);
  FUN_80096f68(0);
  return;
}
