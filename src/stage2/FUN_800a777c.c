/* FUN_800a777c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a777c  body 0x800a777c..0x800a7853  size 216 B
 * body sha256 328207e210148c0f46fa965d0cd693012f19e5653f459fe04d67b674a21e604a
 * provider record sha256 3b254df5a4dfd8c89399dec7b5fdbe1ac581d0a224877b3cc4d352bde331b9f4
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800a777c(undefined4 param_1,undefined1 param_2)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar5 = 0xffffffff;
  uVar2 = FUN_800af0d4();
  while( true ) {
    if (uVar2 == 0xffffffff) {
      return uVar5;
    }
    uVar4 = uVar2 & 0xff;
    iVar3 = uVar4 * 0x1a0;
    if (*(uint *)(&DAT_801444a8 + iVar3) != uVar2) break;
    if ((*(uint *)(&DAT_8014446c + iVar3) & 2) == 0) {
      uVar1 = *(undefined1 *)(iVar3 + -0x7febbb6d);
    }
    else {
      uVar1 = *(undefined1 *)(iVar3 + -0x7febbb63);
    }
    FUN_800ac614(0x83,uVar4,uVar1,param_2);
    uVar2 = *(uint *)(uVar4 * 0x1a0 + -0x7febbba8);
    uVar5 = 0;
  }
  return uVar5;
}
