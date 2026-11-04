/* stage2_entry
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004d344  body 0x8004d344..0x8004d397  size 84 B
 * body sha256 0617aac80d041b4eb971fbc55f417cc707553e724b813998dd6e5dad35072279
 * provider record sha256 95d1efd405b231659f81630a521b72d2b231e7277d673372e6cfa28951698908
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void stage2_entry(void)

{
  osCreateThread(&DAT_8010b700,7,stage2_init,0,&DAT_800c36a0,0);
  osStartThread(&DAT_8010b700);
  return;
}
