/* FUN_8009ddc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009ddc0  body 0x8009ddc0..0x8009de03  size 68 B
 * body sha256 7066f3731efb554ffd03797c2f59e87eb69e37e411ca5bcd9c219c192c15a05e
 * provider record sha256 f0d30438c882b62750ab681b80afcc92f43400c3930d5986ea8c96121429bb61
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009ddc0(void)

{
  if ((DAT_800e10ec & 0x200) == 0) {
    FUN_8006c070(1);
    DAT_8013272e = 0xb;
    DAT_8013273a = 0;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
