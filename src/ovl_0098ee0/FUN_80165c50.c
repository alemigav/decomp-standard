/* FUN_80165c50
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80165c50  body 0x80165c50..0x80165ca7  size 88 B
 * body sha256 c5932336d1cc71d5a4667fe0726588291b719d36db814a011296ea32e009387f
 * provider record sha256 5be48d5d929001469f9dad03e5039bbfd5065286b5ff0fba79bb891848cbb2dc
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165c50(int param_1)

{
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x298);
  if (*(char *)(param_1 + 4) == '\x01') {
    (*(code *)(&PTR_LAB_80166894)[*(byte *)(param_1 + 5)])();
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  return;
}
