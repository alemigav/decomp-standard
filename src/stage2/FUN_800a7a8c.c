/* FUN_800a7a8c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a7a8c  body 0x800a7a8c..0x800a7b63  size 216 B
 * body sha256 fa61772e98931bd451f2697a064da7699b4192d29e7751b223bf05d38a8f0c55
 * provider record sha256 afa33a85b29fdc78e32bd316eec6175a702e627d50c9d526a7a2f13189243129
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800a7a8c(undefined4 param_1,undefined1 param_2)

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
    FUN_800ac614(7,uVar4,uVar1,param_2);
    uVar2 = *(uint *)(uVar4 * 0x1a0 + -0x7febbba8);
    uVar5 = 0;
  }
  return uVar5;
}
