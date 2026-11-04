/* FUN_800260d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800260d0  body 0x800260d0..0x8002616b  size 156 B
 * body sha256 4d2a635e4a061e8f5a14d9833c0d723a1b88862e47a8d4aaf5fe04e610320eb7
 * provider record sha256 9c13d56b739444a849bba94fa6c921192a5e41b1ff49e7b680ac8c5bece033f3
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800260d0(void)

{
  DAT_800df90c = 0;
  FUN_8006bc40(0);
  FUN_8006bb0c(0);
  FUN_800274e4(2,1);
  FUN_8004ce14(0);
  FUN_8004ce14(1);
  FUN_80075c9c();
  FUN_80075c78();
  FUN_80027874();
  DAT_800e923d = 0;
  FUN_8004c9d4();
  FUN_8008456c();
  _DAT_80012820 = 0;
  overlay_slot_reader(0,1);
  return;
}
