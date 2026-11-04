/* FUN_8008c3a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008c3a0  body 0x8008c3a0..0x8008c407  size 104 B
 * body sha256 3eda6b413917022e7841125f9ca102168bd96116ae5a14726aab877095e7d7fb
 * provider record sha256 decfa5788192eebb538ca426ff95112b92f0409a25ec1698ff4fd6ded22f9517
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8008c3fc) */
/* WARNING: Removing unreachable block (ram,0x8008c400) */

undefined4 FUN_8008c3a0(void)

{
  if (DAT_800e13e4 != 0) {
    return 4;
  }
  if (DAT_800e1322 == 0) {
    return 3;
  }
  return 0;
}
