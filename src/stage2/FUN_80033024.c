/* FUN_80033024
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80033024  body 0x80033024..0x8003307b  size 88 B
 * body sha256 dd02060777b23cef7bae06b84f47e4c5f4e8f3eb8d9735cbae9a9b7f67b99aac
 * provider record sha256 f2302229baef289b4a0917ccf8b6032b9fed5938f93441c2dba9c22af580c8ee
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80033024(int *param_1,int *param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = FUN_80040bb4((*param_1 - *param_2) * (*param_1 - *param_2) +
                       (param_1[2] - param_2[2]) * (param_1[2] - param_2[2]));
  return uVar1 < param_3;
}
