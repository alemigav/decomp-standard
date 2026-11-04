/* FUN_80084510
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80084510  body 0x80084510..0x8008456b  size 92 B
 * body sha256 871653bb72a316e19ac711faeb44513b3a876978371bf85691bbdcd3267703af
 * provider record sha256 8e2d62bf770c4571a2dcad540288c949c6e7cb6b37d2878f6b1aac410a4203f8
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80084510(void)

{
  if (((DAT_800e1130 & 0x80000) == 0) || ((DAT_800e10ec & 0x4000100) != 0x4000000)) {
    FUN_8008457c();
  }
  return;
}
