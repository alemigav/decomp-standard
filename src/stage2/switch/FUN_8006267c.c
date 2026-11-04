/* FUN_8006267c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006267c  body 0x8006267c..0x800626b3  size 56 B
 * body sha256 73852b49877c8017074d067a0e5ad64aa7b4532074401ed0c54ed14bb27d27c2
 * provider record sha256 63af44811cb6e39616bda585a305b58b8434b569267d4562f642bf00b30c235a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void switchD_800625a4::caseD_1(void)

{
  char cVar1;
  int iVar2;
  int unaff_s0;
  uint unaff_s3;
  
  FUN_8005c308();
  iVar2 = FUN_80089d54();
  if (iVar2 != 0) {
    *(undefined4 *)(unaff_s0 + 0x1e8) = 0xb000700;
    *(undefined1 *)(unaff_s0 + 7) = 2;
  }
  cVar1 = DAT_800df8c0;
  if (((unaff_s3 & 8) != 0) || (DAT_800df8c0 < -0x19)) {
    *(short *)(unaff_s0 + 0x66) = *(short *)(unaff_s0 + 0x66) + -8;
  }
  if (((unaff_s3 & 2) != 0) || ('\x19' < cVar1)) {
    *(short *)(unaff_s0 + 0x66) = *(short *)(unaff_s0 + 0x66) + 8;
  }
  return;
}
