/* FUN_8009dd50
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009dd50  body 0x8009dd50..0x8009dd87  size 56 B
 * body sha256 3d1eac7f414bf00807a79a78299b9d6c95a5505f80c83d7cb70be893fa6e0954
 * provider record sha256 72cb79b6d315b0c6a7ce7610b7cb214c1cb9b73bdde485a1ccd9e168b6e535b6
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009dd50(void)

{
  if ((DAT_800e10ec & 0x200) == 0) {
    FUN_8006c070(1);
    DAT_8013272e = 9;
    DAT_8013273a = 0;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
