/* FUN_800b431c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b431c  body 0x800b431c..0x800b439f  size 132 B
 * body sha256 6233da6c9d1df8d86dd5983dc1ece23a3d3309c8e26bf366ba695d7d57337056
 * provider record sha256 376af6259bcc3b85c6fe42ebff528bd944f63d40fa376fe50c655c7d01c3e584
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800b431c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if ((param_1 == -1) || (uVar3 = 0, DAT_80136d80 == '\0')) {
    uVar1 = 0;
  }
  else {
    iVar2 = -0x7fea74e0;
    do {
      if ((*(char *)(iVar2 + 0x1200) != '\0') && (*(int *)(iVar2 + 0x1224) == param_1))
      goto LAB_800b4378;
      uVar3 = uVar3 + 1;
      iVar2 = iVar2 + 0x1228;
    } while (uVar3 < 2);
    uVar3 = 0xffffffff;
LAB_800b4378:
    uVar1 = 0;
    if (uVar3 != 0xffffffff) {
      FUN_800b398c();
      uVar1 = 1;
    }
  }
  return uVar1;
}
