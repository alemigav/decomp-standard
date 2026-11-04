/* FUN_80165b8c
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80165b8c  body 0x80165b8c..0x80165c1b  size 144 B
 * body sha256 21fc18c62a45d07c021ba08e8af635fabf47f35da12448ddc95092a9b3f22138
 * provider record sha256 8cbd76c094f3037f004d960e36eaac7f3b1e074decf9e83b4d9a39a7cfc576c0
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165b8c(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    FUN_8016561c();
    *(undefined1 *)(param_1 + 0x2c1) = 0x45;
    *(undefined1 *)(param_1 + 0x2c3) = 3;
    FUN_80165310(param_1,8,4);
    uVar2 = 0;
    iVar1 = 0;
    do {
      uVar2 = uVar2 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x234) + iVar1 + 0x60) = 0x3f2f5f;
      iVar1 = iVar1 + 0x178;
    } while (uVar2 < 0x1a);
  }
  else {
    FUN_801656c0(param_1);
  }
  return;
}
