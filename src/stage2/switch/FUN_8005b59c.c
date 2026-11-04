/* FUN_8005b59c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005b59c  body 0x8005b59c..0x8005b5c3  size 40 B
 * body sha256 9baf982626564601656b5b00dcd172b42fc25bec8ac69fe11530586ee75a1026
 * provider record sha256 76bbb449b2873d6ccab6b8ed9012224565317682a8de7f44116b72b3a946ab37
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int switchD_8005b520::caseD_2(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4)

{
  short sVar1;
  short sVar2;
  int in_t1;
  
  sVar1 = *(short *)(in_t1 + 0x10);
  sVar2 = *(short *)(in_t1 + 0x12);
  *param_3 = (int)sVar1;
  *param_4 = (int)*(short *)(in_t1 + 0x12);
  return ((int)sVar1 - (int)sVar2) / 3;
}
