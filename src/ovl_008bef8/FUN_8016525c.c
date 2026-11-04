/* FUN_8016525c
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x8016525c  body 0x8016525c..0x801652e3  size 136 B
 * body sha256 1590c7d63ef59da38dbc6c053c6578cecc8765e7a67d076f7f8d46c863cdb917
 * provider record sha256 3ca7c532c68a0864e1b2dbbd207ea026be116a052e5b984a8dfa78a6cfae2a8b
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016525c(undefined4 param_1)

{
  uint uVar1;
  
  func_0x80052bd0(3,0);
  func_0x80052d10(0xe,0xd2,0x28,2);
  uVar1 = func_0x80059e00(param_1,0);
  if ((uVar1 & 1) != 0) {
    _DAT_800e1136 = CONCAT11(4,(undefined1)DAT_800e1134_2);
  }
  if ((uVar1 & 2) != 0) {
    _DAT_800e1134 = 0x3000000;
  }
  return;
}
