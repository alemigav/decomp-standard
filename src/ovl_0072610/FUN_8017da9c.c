/* FUN_8017da9c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017da9c  body 0x8017da9c..0x8017db53  size 184 B
 * body sha256 dbf0c7605c3692d2dab32a2b47bceb07b888bc1bd1503aef37607d806fe3ed13
 * provider record sha256 a7f6dfe64e8ffc07cc26142508c6f5ee38fdccdecee6bb04650b4cd213aa1730
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017da9c(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined2 local_28 [4];
  undefined2 local_20 [4];
  
  if ((DAT_80185788 == 0) && (DAT_801857a0 == 3)) {
    iVar5 = 2;
    if (DAT_801857b4 != 0) {
      iVar5 = 3;
    }
  }
  else {
    iVar5 = 1;
  }
  iVar2 = 0;
  if (iVar5 != 0) {
    puVar4 = local_20;
    puVar3 = local_28;
    do {
      uVar1 = FUN_8017bec8(0x10);
      *puVar3 = uVar1;
      FUN_8017bbe8(1);
      uVar1 = FUN_8017bec8(0x10);
      *puVar4 = uVar1;
      FUN_8017bbe8(1);
      puVar4 = puVar4 + 1;
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar2 < iVar5);
  }
  return;
}
