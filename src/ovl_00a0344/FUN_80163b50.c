/* FUN_80163b50
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80163b50  body 0x80163b50..0x80163bb7  size 104 B
 * body sha256 71050e0fed4eabef3e037f440a410eefbc70a098145ac7e0d7596ee226e7779c
 * provider record sha256 3482d6d5f4c93b85d2a30aa18702e0b66da38b3f457084e762c1807cba72910c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163b50(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = 0;
  iVar5 = 0;
  do {
    iVar4 = *(int *)(param_1 + 0x234) + iVar5;
    uVar1 = *(uint *)(iVar4 + 0x60);
    uVar3 = uVar1 & 0xff;
    if (uVar3 != 0) {
      uVar3 = uVar3 - 1;
    }
    uVar2 = uVar1 & 0xff00;
    if (uVar2 != 0) {
      uVar2 = uVar2 - 0x100;
    }
    uVar1 = uVar1 & 0xff0000;
    if (uVar1 != 0) {
      uVar1 = uVar1 - 0x10000;
    }
    *(uint *)(iVar4 + 0x60) = uVar1 | uVar2 | uVar3;
    uVar6 = uVar6 + 1;
    iVar5 = iVar5 + 0x178;
  } while (uVar6 < 3);
  return;
}
