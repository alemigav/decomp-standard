/* FUN_800a1fc8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a1fc8  body 0x800a1fc8..0x800a200b  size 68 B
 * body sha256 de8401e3ed6a16682b94d8793ac1e3694a50a7782c06bcdb0dd736bde287b50d
 * provider record sha256 26d651b5979e768c4b59dfad077fe31db33bb51f8a46134f6345e11172b5ffd6
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a1fc8(undefined4 param_1)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a1234(param_1);
    FUN_800a56c0();
  }
  return;
}
