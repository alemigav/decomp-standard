/* FUN_801668fc
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801668fc  body 0x801668fc..0x8016697f  size 132 B
 * body sha256 855a762ca9a85c498883081c7a2cc49e992b3598642f60b95e80fff47a9c1ee8
 * provider record sha256 946c8ac2d7cb2cd18336556a068e4b21b0cce65c186b8baba5fe53fb65fffb38
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_801668fc(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x2c8) != '\0') {
    return 0;
  }
  iVar1 = FUN_801666f8(param_1,0);
  if (iVar1 == 0) {
    if ((_DAT_800e110c & 0x10000000) == 0) {
      return 0;
    }
    iVar1 = FUN_801666f8(param_1,1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return *(undefined1 *)(param_1 + 0x2ba);
}
