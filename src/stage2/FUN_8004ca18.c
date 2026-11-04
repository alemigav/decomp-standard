/* FUN_8004ca18
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004ca18  body 0x8004ca18..0x8004ca83  size 108 B
 * body sha256 bacbd838147364f4d4b39b4e50003b393611b43d60870224fc60e30a56203a7f
 * provider record sha256 34a4177bbc5483614ec2d6e2477e1c31340b4af2f4281ff5ddbe0e2667b233ba
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004ca18(void)

{
  osCreateMesgQueue(0x80139b30,0x80139b20,1);
  DAT_8010b4e4 = 4;
  DAT_8010b6ac = 5;
  DAT_8010b4e8 = &DAT_800c24a0;
  DAT_8010b6b0 = &DAT_800c34a0;
  DAT_8010b328 = 0;
  DAT_8010b4f0 = 0;
  DAT_8010b4ec = 0;
  DAT_8010b6b4 = 0;
  return;
}
