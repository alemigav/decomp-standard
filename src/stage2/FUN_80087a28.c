/* FUN_80087a28
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80087a28  body 0x80087a28..0x80087aef  size 200 B
 * body sha256 c9efc5ae246fb4a2383d153aa26834c62729475dc8764f0a2189743f8d54371d
 * provider record sha256 abf062dbb8f15f7e70c14e9deca6eae2132848874dcee8ed9b142038fad7335c
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80087a28(int *param_1)

{
  undefined4 uVar1;
  
  func_0x800068d0(0x8013a2f0,&DAT_80129e90,0x8013a340);
  uVar1 = func_0x800082d0(0x8013a2f0,&UNK_80129e94 + *param_1 * 0x68);
  *(undefined4 *)param_1[1] = uVar1;
  if (*(int *)param_1[1] == 0) {
    (&DAT_8012a034)[*param_1] = 2;
  }
  else {
    (&DAT_8012a034)[*param_1] = 0;
  }
  if (param_1[2] != 0) {
    osSendMesg(param_1[2],0,0);
  }
  return;
}
