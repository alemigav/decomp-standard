/* FUN_80162e14
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80162e14  body 0x80162e14..0x80162ee7  size 212 B
 * body sha256 8d5030315e86c2753b613cc1b914e8cc438d0aa17e92ca3303aa3196ce600410
 * provider record sha256 614a25399668ab7f4409ee7d9108280108104395231ad183e884ca28d4343503
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162e14(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x250);
  if (*(byte *)(param_1 + 6) < 2) {
    (*(code *)(&PTR_FUN_80163dc8)[*(byte *)(param_1 + 6)])();
  }
  if (*(char *)(param_1 + 0x2c7) != '\0') {
    cVar1 = *(char *)(iVar2 + 0x2c1);
    if (cVar1 == '\a') {
      FUN_80162754(param_1,param_2,param_3);
      *(undefined1 *)(param_1 + 4) = 1;
      return;
    }
    if (cVar1 == 'E') {
      FUN_80162754(param_1,param_2,param_3);
      *(undefined1 *)(param_1 + 5) = 4;
      *(undefined2 *)(param_1 + 6) = 0;
    }
  }
  FUN_8016375c(param_1,0);
  return;
}
