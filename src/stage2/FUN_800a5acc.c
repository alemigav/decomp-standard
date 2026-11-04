/* FUN_800a5acc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5acc  body 0x800a5acc..0x800a5b13  size 72 B
 * body sha256 357d20109402b7c8f357fae8a2e3365c8388c770d915bbf16d56c8c5686b2210
 * provider record sha256 e1ff6d01878a531c01108a33d14e790c83f761ffe785375acf8bb741b14f9330
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a5acc(int param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)(param_1 * 0x68 + _DAT_80143f0c);
  if (*pcVar1 != '\0') {
    *pcVar1 = '\0';
    *(undefined1 *)(param_1 * 0x68 + _DAT_80143f0c + 0x61) = 1;
  }
  return;
}
