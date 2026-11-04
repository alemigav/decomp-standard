/* FUN_80166294
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80166294  body 0x80166294..0x801662a7  size 20 B
 * body sha256 aae6ed224f0883938e78685116b81193047130ad689950fa1f2047568d6be803
 * provider record sha256 bef04e9c592102413b0fbefecf7fb87c8ac9d5bcf26a577533d595843f3f643e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166294(int param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 0x136) = param_2;
  *(undefined2 *)(param_1 + 0x138) = param_2;
  *(undefined2 *)(param_1 + 300) = param_2;
  *(undefined2 *)(param_1 + 0x12e) = param_2;
  return;
}
