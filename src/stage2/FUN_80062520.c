/* FUN_80062520
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80062520  body 0x80062520..0x80062553  size 52 B
 * body sha256 eddcfc047e68d79c6be72585e0a002033a37c7ef9b53a8f287f1eb8b58973fe7
 * provider record sha256 49bb091c1726700067c508a1be174e5f8029d6d88d0e4bf2f070d7e5da450af3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80062520(int param_1)

{
  (*(code *)(&PTR_FUN_80111148)[*(byte *)(param_1 + 6)])();
  return;
}
