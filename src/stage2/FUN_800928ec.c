/* FUN_800928ec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800928ec  body 0x800928ec..0x80092993  size 168 B
 * body sha256 55287e509b9145d32379ecd2d4b1d82cbb8bad38716379ab69d88bad7a4b7087
 * provider record sha256 e44048360d8f7ee0ded77a486b648923f1892a47b6c48800266a4b5d17b97855
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800928ec(void)

{
  DAT_8012bfae = 1;
  FUN_80043620();
  FUN_80096d90();
  FUN_800978a4();
  FUN_80097c4c();
  (*(code *)(&PTR_FUN_8012fa90)[DAT_8012bf99])();
  FUN_80093ddc();
  FUN_80095c34();
  FUN_800962fc((&DAT_800e8eca)[(uint)DAT_8012bfa4 * 4]);
  return;
}
