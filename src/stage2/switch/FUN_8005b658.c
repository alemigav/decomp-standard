/* FUN_8005b658
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005b658  body 0x8005b658..0x8005b69b  size 68 B
 * body sha256 8dd8ca6ea05d29aad460e9a0876d01c32ab630cb28a30e551918af432ded0436
 * provider record sha256 3a4032688821d6ed8d3bbb6e9f22ec36d8c81423eb2afdf6b43f6c0474eb7451
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int switchD_8005b520::caseD_6(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int in_t1;
  
  iVar1 = ((int)*(short *)(in_t1 + 8) - (int)*(short *)(in_t1 + 10)) / 3;
  iVar2 = iVar1 * 2;
  *param_3 = *(short *)(in_t1 + 8) + iVar2;
  *param_4 = *(short *)(in_t1 + 10) + iVar2;
  return iVar1;
}
