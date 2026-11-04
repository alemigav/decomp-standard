/* FUN_8003d0dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003d0dc  body 0x8003d0dc..0x8003d143  size 104 B
 * body sha256 521f16dbf2d60ccee4f75dfafe229e7395684a889ac76e1d27bef55788fba223
 * provider record sha256 45be364a8dd701f06160478e17ded983b5a4d258e88110d5b897484fced62a60
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8003cea0::caseD_4(void)

{
  undefined1 *puVar1;
  
  if (DAT_800ebb94[0xb] == -1) {
    *(short *)(DAT_800ebb94 + 0x36) = *(short *)(DAT_800ebb94 + 0x36) + -600;
  }
  FUN_80038a20(0x30f2000,(int)*(short *)(DAT_800ebb94 + 0x22),&DAT_800e9028,DAT_800ebb94 + 0x34);
  puVar1 = DAT_800ebb94;
  DAT_800ebb94[1] = 0;
  *puVar1 = 0;
  *(undefined2 *)(puVar1 + 0x18) = 0;
  return;
}
