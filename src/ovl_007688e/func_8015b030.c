/* func_8015b030
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015b030  body 0x8015b030..0x8015b0c7  size 152 B
 * body sha256 1a866b1b232a45f8959bbe8637f727b119886c456ba272ce8e9bce809be92fb5
 * provider record sha256 16cdc2373ba248512509af039a4329bb60038c84c8342d83f0c4f7ef8fdb4d6a
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  _DAT_800e911c = 0xffffffff;
  _DAT_800e9120 = 0xffffffff;
  _DAT_8010bfa8 = 1;
  _DAT_800e90f8 = 1;
  func_0x80052bbc(0x5000,0xa02);
  DAT_80160c1c = 0;
  do {
    if (1 < DAT_80160c1c) {
      FUN_8015fc08();
    }
    (*(code *)(&PTR_FUN_80160b38)[DAT_80160c1c])();
    func_0x8004cd88(1);
  } while( true );
}
