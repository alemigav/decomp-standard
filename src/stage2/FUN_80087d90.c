/* FUN_80087d90
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80087d90  body 0x80087d90..0x80087e2f  size 160 B
 * body sha256 ad2f8b1c05ea4d9b6ce92f60e877a43380df1228273531508bab3343d013c6f2
 * provider record sha256 eabdf6d8dfaefa0ecdc73ddf740b534774f67189209ada89b108ce7765426488
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80087d90(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = func_0x8000ac00(0x8013a2f0,&UNK_80129e94 + *param_1 * 0x68);
  *(undefined4 *)param_1[1] = uVar1;
  if (*(int *)param_1[1] == 0) {
    (&DAT_8012a034)[*param_1] = 1;
  }
  else {
    (&DAT_8012a034)[*param_1] = 0;
  }
  osSendMesg(param_1[2],0,0);
  return;
}
