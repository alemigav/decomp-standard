/* FUN_800562d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800562d8  body 0x800562d8..0x8005637f  size 168 B
 * body sha256 fef41da8fae54844e0270a3b96a4d0434e7f10f60f7c108027500f53961d352b
 * provider record sha256 32cf1749ec45ab938cfc3ad2a59ebcef5a7115f3df059f107cc06b71aead4c9a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800562d8(int param_1)

{
  ushort uVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    uVar1 = *(ushort *)(&DAT_8010dc98 + *(char *)(param_1 + 0x1ed) * 2);
    *(undefined1 *)(param_1 + 6) = 1;
    *(uint *)(param_1 + 0x1e8) = (uint)uVar1 * 0x1000000 + 0x700;
    *(undefined1 *)(param_1 + 0x1ea) = 7;
    DAT_800e110c = DAT_800e110c & 0xffffff3f;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  FUN_80089d54(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220),0x200);
  return;
}
