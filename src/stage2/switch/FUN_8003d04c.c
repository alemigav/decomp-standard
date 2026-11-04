/* FUN_8003d04c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003d04c  body 0x8003d04c..0x8003d083  size 56 B
 * body sha256 d60cfece13113bfaaf7035efce74b340cc644e2105c7c137da5a1429bbb5fa15
 * provider record sha256 79832c7927663883dbf2fdf945ec7801b50e2845881f19227ecf953a2fd1cb32
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8003cea0::caseD_2(void)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = DAT_800ebb94;
  pcVar1 = (char *)(DAT_800ebb94 + 0xb);
  *(undefined2 *)(DAT_800ebb94 + 0x12) = 3;
  if (*pcVar1 == -1) {
    *(short *)(iVar2 + 0x36) = *(short *)(iVar2 + 0x36) + -600;
  }
  FUN_80038a20(0x3142000,(int)*(short *)(DAT_800ebb94 + 0x22),&DAT_800e9028,DAT_800ebb94 + 0x34);
  return;
}
