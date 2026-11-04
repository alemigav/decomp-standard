/* FUN_80025f34
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80025f34  body 0x80025f34..0x80025f77  size 68 B
 * body sha256 f5806da79d5c1b1dec7fcab9ab43cadafe01099101476c3e564093ca0e7981f8
 * provider record sha256 6ec69b4c0c182da4a36777fd5db5a745c49357a46a32bccfc308e8df2738b601
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80025f34(void)

{
  DAT_800c76a0 = 0;
  DAT_800c7678 = 3;
  DAT_800c767c = &DAT_800c768c;
  DAT_800c768c = 0;
  FUN_800879a0();
  return;
}
