/* FUN_80166ba0
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80166ba0  body 0x80166ba0..0x80166bd3  size 52 B
 * body sha256 16897ee3f171d531838a646182a0c2ac333148951034d59f4a4978e244e5148d
 * provider record sha256 421d5a1d0974ee0290aa259141eb691259ce59b8b55d1c7e49f60c0b0e9f60c3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80166ba0(int param_1)

{
  if ((_DAT_800e1128 & 0x40) != 0) {
    *(undefined1 *)(param_1 + 5) = 0xb;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  return;
}
