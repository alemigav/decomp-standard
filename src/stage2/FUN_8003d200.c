/* FUN_8003d200
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003d200  body 0x8003d200..0x8003d2a7  size 168 B
 * body sha256 d23d0a778c0567e68964171b51aab9493207f489389b370a3628a63d1e1404f0
 * provider record sha256 c4eb3295e94f2e14bf677cf8e9f636ac5fcf573da4737dd76b0a17c88bffcb3e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003d200(void)

{
  undefined4 *puVar1;
  int local_18;
  int local_14;
  int iStack_10;
  
  local_18 = (int)*(short *)(DAT_800ebb94 + 0xd);
  local_14 = (int)*(short *)((int)DAT_800ebb94 + 0x36);
  iStack_10 = (int)*(short *)(DAT_800ebb94 + 0xe);
  FUN_80077adc(0x3040001,&local_18);
  *(undefined1 *)((int)DAT_800ebb94 + 0x21) = 0xd;
  *(undefined1 *)(DAT_800ebb94 + 8) = 2;
  FUN_80038a20(0x30f2800,0,&DAT_800e9028,DAT_800ebb94 + 0xd);
  puVar1 = DAT_800ebb94;
  *(undefined1 *)((int)DAT_800ebb94 + 9) = 0;
  *(undefined1 *)(puVar1 + 2) = 0;
  puVar1 = DAT_800ebb94;
  *(undefined2 *)((int)DAT_800ebb94 + 0xe) = 0;
  *(undefined2 *)(puVar1 + 3) = 0;
  *(undefined2 *)(puVar1 + 6) = 0xb001;
  *puVar1 = 0;
  return;
}
