/* inflate_init
 * image   boot (boot), base 0x80000480
 * address 0x80004550  body 0x80004550..0x80004593  size 68 B
 * body sha256 9982576cc83e4af0b7e0dd07c2cdec82822b8a73a382027a83f5c90ceb4af93a
 * provider record sha256 f2acaca27c929f513be592e7d1ef70d124489082e1e9c4846e93525e197d5660
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int inflate_init(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  FUN_800013b0(param_2);
  uVar1 = FUN_800013d4(0x8000);
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  return param_1;
}
