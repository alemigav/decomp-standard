/* FUN_8005d8cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005d8cc  body 0x8005d8cc..0x8005d8ef  size 36 B
 * body sha256 101271e72812a8958aab76951abe9e49a18d6cbd1774f2421b9106bac57df1b7
 * provider record sha256 77d434eb101356f6511fccb52e0b432054668abb3f5295ff45c18531ebe0ae15
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005d8cc(int param_1)

{
  FUN_8008cea0(*(ushort *)(param_1 + 0x1aa) & 0xfff,0);
  return;
}
