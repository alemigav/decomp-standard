/* FUN_80166a04
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80166a04  body 0x80166a04..0x80166a43  size 64 B
 * body sha256 98d53199b5aec355820dac16844122903c65b8bffdc8534a0c176e416356c40e
 * provider record sha256 bfd8fd74be99176897bc705f1b22a7664f97bdfadb0ab4f552efad3b68cbe698
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80166a04(int param_1)

{
  if (((*(short *)(param_1 + 0x2c4) < *(short *)(param_1 + 0x1f2)) ||
      (*(short *)(param_1 + 0x1f2) < 0)) || (*(char *)(param_1 + 0x2b8) != '\0')) {
    return 0;
  }
  *(undefined1 *)(param_1 + 5) = 7;
  *(undefined2 *)(param_1 + 6) = 0;
  return 1;
}
