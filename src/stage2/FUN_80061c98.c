/* FUN_80061c98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80061c98  body 0x80061c98..0x80061ccb  size 52 B
 * body sha256 7676d3e43e6ffcdaa25fa6c6bea889f899b20706d8618578821e9b6adf51738a
 * provider record sha256 eec0ac3cac1fea0a3b263a6b3856e8ab22a17b89a999fc1eb20cc1a50f2a60d6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80061c98(int param_1)

{
  (*(code *)(&PTR_FUN_80111118)[*(byte *)(param_1 + 6)])();
  return;
}
