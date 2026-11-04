/* FUN_800995fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800995fc  body 0x800995fc..0x800996a3  size 168 B
 * body sha256 c11b765dd88dd9902a6c25102bc6eedae3497d9a533697da1bbf3c4933a08af1
 * provider record sha256 00eb786f57c8fdbb15b77eabd6d12fcd67cc5c2149fa76119da826ba61296032
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800995fc(void)

{
  func_0x8015fde0();
  DAT_800e911c = 0xffffffff;
  DAT_800e9120 = 0xffffffff;
  FUN_800995e0();
  if ((DAT_800e10ec & 0x2000) != 0) {
    DAT_800e90f8 = 1;
  }
  FUN_8004cd88(1);
  DAT_800e1110 = 0;
  _DAT_8013a3f0 = 0;
  DAT_8010bfa8 = DAT_8010bfa8 << 1;
  FUN_80099d2c();
  return;
}
