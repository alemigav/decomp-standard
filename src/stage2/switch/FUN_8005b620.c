/* FUN_8005b620
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005b620  body 0x8005b620..0x8005b657  size 56 B
 * body sha256 d6af440afcd88f1344078612dd3c05b040ad3c44b9c73583bfecfda02f50a714
 * provider record sha256 7a14f49890c254ed1845b38f0c6710c2f2246b1c13373567bac8d05debf95037
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int switchD_8005b520::caseD_5(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4)

{
  int iVar1;
  int in_t1;
  
  iVar1 = ((int)*(short *)(in_t1 + 8) - (int)*(short *)(in_t1 + 10)) / 3;
  *param_3 = *(short *)(in_t1 + 8) + iVar1;
  *param_4 = *(short *)(in_t1 + 10) + iVar1;
  return iVar1;
}
