/* FUN_80162c6c
 * image   ovl_0093192 (ovl), base 0x80161cf0
 * address 0x80162c6c  body 0x80162c6c..0x80162c8f  size 36 B
 * body sha256 61467b5d88d956bf9b383682cd2a3982c817ee60ec18d6c1d03d188b8b31f980
 * provider record sha256 6bedadde20607d4a6cf1da446fe157d7ddb97f6d4f68ecd331e1d883ebc023c2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162c6c(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 4) = 2;
  *(undefined1 *)(param_1 + 5) = param_2;
  *(undefined1 *)(param_1 + 6) = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
  return;
}
