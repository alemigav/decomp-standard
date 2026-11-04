/* FUN_80054b68
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80054b68  body 0x80054b68..0x80054ba3  size 60 B
 * body sha256 6ab549c589fd0bc7757d7d0c8a484296e5213fb670eaf9464fe81c1754348c3e
 * provider record sha256 91b8ab3db02713224a1a32f18d25c5ef51de84d003fac754cf646acc48686a60
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80054b68(void)

{
  int unaff_s2;
  uint unaff_s3;
  
  FUN_800539a0(1,"UMBRELLA \"RODEM\" SYSTEM]                      Ver 5.0]",&DAT_8010da24);
  if (DAT_8010da24 != 0) {
    DAT_800e8609 = 2;
  }
  if (*(char *)(unaff_s2 + 0x2d9) == '\x01') {
    *(undefined1 *)(unaff_s2 + 0x2d9) = 0;
    DAT_800e8609 = 0xb;
  }
  if (((DAT_8010da20 & DAT_8010da24) != 0) || (unaff_s3 != DAT_800e8609)) {
    DAT_80139bef = 0;
    DAT_8010da24 = 0;
    DAT_8010da20 = 0;
    DAT_80139bee = 0;
  }
  FUN_80053d7c(1);
  FUN_80053eb8(0x16c);
  return;
}
