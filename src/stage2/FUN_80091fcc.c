/* FUN_80091fcc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80091fcc  body 0x80091fcc..0x8009202b  size 96 B
 * body sha256 8fbe3669c2a48e80558b160ac148226f6db7571c6e40ac3ca3b218041a2e83ba
 * provider record sha256 17d9662f02269241eb937c21f1502889cf7b770702e905943f82e27c46e7dd4c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80091fcc(void)

{
  (*(code *)(&PTR_FUN_8012fa18)[DAT_8012bf99])();
  FUN_80097fd0();
  if (DAT_8012bf9a == '\0') {
    FUN_8009109c();
  }
  return;
}
