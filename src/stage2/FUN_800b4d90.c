/* FUN_800b4d90
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b4d90  body 0x800b4d90..0x800b4dab  size 28 B
 * body sha256 cf9681e4d8544a479d3cd8e747ce497cd7f6e203ef4145e1a79781a95c32754f
 * provider record sha256 844f7c1cce934195c380e3dbf89d93c1060e3b84d8145a2011cda13ac77ba863
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800b4d90(int param_1)

{
  if (*(char *)(param_1 + 0x11dd) == '\x02') {
    *(undefined1 *)(param_1 + 0x11dd) = 3;
  }
  return;
}
