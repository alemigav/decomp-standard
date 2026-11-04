/* FUN_801632a0
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801632a0  body 0x801632a0..0x801632e7  size 72 B
 * body sha256 e46369616a8f02ea9787d8152ae5ec0abe0f8cae80edf1dddcec214ca5a6b44e
 * provider record sha256 01c036f4e8661bf8d39750d2c50665918de2817eaeff105de56d93ddc7aab5df
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801632a0(int param_1)

{
  (*(code *)(&PTR_FUN_801672a0)[*(byte *)(param_1 + 6)])();
  FUN_80162678(param_1);
  return;
}
