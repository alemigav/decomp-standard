/* FUN_8006289c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006289c  body 0x8006289c..0x8006292b  size 144 B
 * body sha256 dc513ebd66a6fb4552ea932076c1235c49062ff05359bbf568c08bd9dc707348
 * provider record sha256 f8b08c3de37df817fc7f40488c3de7de12c364e95b6a1bf43ed071ba5fc0dd85
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_800625a4::caseD_5(void)

{
  char cVar1;
  int unaff_s0;
  uint unaff_s3;
  
  *(undefined2 *)(unaff_s0 + 6) = 0x100;
  cVar1 = DAT_800df8c0;
  if (((unaff_s3 & 8) != 0) || (DAT_800df8c0 < -0x19)) {
    *(short *)(unaff_s0 + 0x66) = *(short *)(unaff_s0 + 0x66) + -8;
  }
  if (((unaff_s3 & 2) != 0) || ('\x19' < cVar1)) {
    *(short *)(unaff_s0 + 0x66) = *(short *)(unaff_s0 + 0x66) + 8;
  }
  return;
}
