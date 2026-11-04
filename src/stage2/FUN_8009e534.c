/* FUN_8009e534
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009e534  body 0x8009e534..0x8009e583  size 80 B
 * body sha256 11ed5e7debae4f88ea70f56255d4b9aa9c28df9baa23207ca207b07b59fc0e49
 * provider record sha256 8421dd22b37b29a5bddf2508c1524e8bc82d588e349b332b218343a4516f43e1
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009e534(void)

{
  if (DAT_8013273a == 10) {
    DAT_8013272a = 3;
    DAT_8013273c = 4;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
