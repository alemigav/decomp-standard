/* FUN_8005b5ec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005b5ec  body 0x8005b5ec..0x8005b61f  size 52 B
 * body sha256 8a1d3f92d89a16bed2b43cc062ea01565bb6d2110de9387dd814cf9f22e65a01
 * provider record sha256 eccc142fa4b477f7205b50bbb2afa8758c6a92135a5c3acd27fd8f961ceab9d5
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int switchD_8005b520::caseD_4(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4)

{
  short sVar1;
  short sVar2;
  int in_t1;
  
  sVar1 = *(short *)(in_t1 + 8);
  sVar2 = *(short *)(in_t1 + 10);
  *param_3 = (int)sVar1;
  *param_4 = (int)*(short *)(in_t1 + 10);
  return ((int)sVar1 - (int)sVar2) / 3;
}
