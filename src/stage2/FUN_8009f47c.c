/* FUN_8009f47c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009f47c  body 0x8009f47c..0x8009f5af  size 308 B
 * body sha256 325f96a5b90c87e04992b8b4a011180c42469bdf06a6bb42b8d9ea6c852833d2
 * provider record sha256 2c398e528d65745729285dbabdbc9673c8244f1f541397ac8636d254fa8aa653
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009f47c(void)

{
  int iVar1;
  
  if (((&DAT_80134512)[DAT_801344b0 * 0x89] & 1) != 0) {
    FUN_800274e4(0,0);
  }
  if (((&DAT_80134512)[DAT_801344b0 * 0x89] & 0x40) != 0) {
    FUN_800274e4(2,0);
  }
  if (((&DAT_80134512)[DAT_801344b0 * 0x89] & 0x80) != 0) {
    FUN_800274e4(2,0xffff);
  }
  DAT_800e10ec = DAT_800e10ec & 0xffff7dff;
  iVar1 = FUN_800837ac(&DAT_800e8ce0,0xc3);
  if (iVar1 != 0) {
    FUN_80083780(&DAT_800e8ce0,0xc3);
    FUN_800274f8(0x200,0xffffe800,7,1);
  }
  return;
}
