/* FUN_80082498
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80082498  body 0x80082498..0x800824af  size 24 B
 * body sha256 a7f37e11f2938a40c28f64632727b99e5b17672f8f8630480dabe5c261e5b5a7
 * provider record sha256 8fff67d62c25588037a0cf6db0f44561afbd04bbd286e498d3f921f2ac9a07e9
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80082498(undefined4 *param_1,int param_2)

{
  do {
    *param_1 = 0;
    param_2 = param_2 + -1;
    param_1 = param_1 + 1;
  } while (param_2 != 0);
  return;
}
