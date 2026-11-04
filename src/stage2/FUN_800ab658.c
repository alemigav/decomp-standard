/* FUN_800ab658
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab658  body 0x800ab658..0x800ab693  size 60 B
 * body sha256 422099778ca090dd1ffaad45ee503c64ff13238b6712bd48d35933e0b8282ca5
 * provider record sha256 5cbb1bfb77e0df040d86184b9658deb48099cb89b4de3a1e4dd7727100d93a70
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800ab658(void)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5180();
    FUN_800aaf84();
    DAT_80136310 = '\0';
  }
  return;
}
