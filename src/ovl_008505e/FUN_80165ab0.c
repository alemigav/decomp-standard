/* FUN_80165ab0
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165ab0  body 0x80165ab0..0x80165ae7  size 56 B
 * body sha256 23b908adc3aead890f264197e99618ae5156365b06bfbab73931039a31b58c79
 * provider record sha256 0b088d5df94810b663e1c8e5a87aa9f68ec72d688c6a685c60b48b3c77880c66
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165ab0(int param_1)

{
  (*(code *)(&PTR_FUN_80166ea0)[*(byte *)(param_1 + 5) - 1])();
  return;
}
