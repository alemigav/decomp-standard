/* FUN_8003d084
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003d084  body 0x8003d084..0x8003d0db  size 88 B
 * body sha256 e75894051949b341377a60498dfeb893b6b4f2f9e5f846796636474f996f3229
 * provider record sha256 e68ae5c0604bbca174cb246008c92412a486675dec4dd5e1424391764819f128
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8003cea0::caseD_3(void)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = DAT_800ebb94;
  pcVar1 = (char *)(DAT_800ebb94 + 0xb);
  *(undefined2 *)(DAT_800ebb94 + 0x12) = 4;
  if (*pcVar1 == -1) {
    *(short *)(iVar2 + 0x36) = *(short *)(iVar2 + 0x36) + -600;
  }
  FUN_80038a20(0x40d2800,(int)*(short *)(DAT_800ebb94 + 0x22),&DAT_800e9028,DAT_800ebb94 + 0x34);
  return;
}
