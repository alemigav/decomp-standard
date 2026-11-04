/* FUN_8005b5c4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005b5c4  body 0x8005b5c4..0x8005b5eb  size 40 B
 * body sha256 a02bcb51f2a7cfeea10b23ddaea2f0b87a6798f6256e64fbe475ba6809db72e0
 * provider record sha256 b5bda31707850f198db68ac5bfd924423bb23b02bf90382d26afd80feade5440
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int switchD_8005b520::caseD_3(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4)

{
  short sVar1;
  short sVar2;
  int in_t1;
  
  sVar1 = *(short *)(in_t1 + 0xc);
  sVar2 = *(short *)(in_t1 + 0xe);
  *param_3 = (int)sVar1;
  *param_4 = (int)*(short *)(in_t1 + 0xe);
  return ((int)sVar1 - (int)sVar2) / 3;
}
