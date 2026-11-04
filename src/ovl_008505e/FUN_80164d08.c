/* FUN_80164d08
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80164d08  body 0x80164d08..0x80164d5b  size 84 B
 * body sha256 a197fddf73d30ee92a5c9efda9411ac6d8770975daed889f303e4e4c9c72f1d5
 * provider record sha256 5b7e94adad81735a36a98413d5142c84632304a4b6ffa126217726c0c12fa8cb
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164d08(int param_1)

{
  if ((*(byte *)(param_1 + 0x2bf) & 0x80) == 0) {
    (*(code *)(&PTR_FUN_80166e0c)[*(byte *)(param_1 + 5) - 1])();
  }
  else {
    FUN_80165300();
  }
  return;
}
