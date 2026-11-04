/* FUN_801624a4
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x801624a4  body 0x801624a4..0x801624cf  size 44 B
 * body sha256 deacdb29fb41583145d8979bae91501371b23d626ef171a17c6529992099a148
 * provider record sha256 c0d0db2215a845ab4c790564f8adb4704b56e9b38e03a9f3707de22578d39cca
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801624a4(int param_1)

{
  if (*(char *)(param_1 + 4) == '\x01') {
    *(undefined1 *)(param_1 + 5) = 2;
    *(undefined2 *)(param_1 + 6) = 0;
    *(byte *)(param_1 + 0x2bf) = *(byte *)(param_1 + 0x2bf) & 0x7f;
  }
  return;
}
