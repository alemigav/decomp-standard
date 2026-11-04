/* FUN_80163020
 * image   ovl_0097e42 (ovl), base 0x80161cf0
 * address 0x80163020  body 0x80163020..0x8016303f  size 32 B
 * body sha256 101be4e18ecfbb653d349d5b77c8748ba317315118140960002b4208f5e73055
 * provider record sha256 85fa9e10db3aa06c0797369d484f31c461dea218ba7beb6517e277257059a417
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163020(int param_1)

{
  if ((*(ushort *)(param_1 + 0x2ba) & 4) == 0) {
    *(undefined1 *)(param_1 + 0x26e) = 0;
    return;
  }
  *(undefined1 *)(param_1 + 0x26e) = 1;
  return;
}
