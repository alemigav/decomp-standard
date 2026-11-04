/* FUN_8004cec4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004cec4  body 0x8004cec4..0x8004cef7  size 52 B
 * body sha256 c9311817d1ae9b5a0f293875a3ed13bec346dab582494c0ef95515a75ac9fb76
 * provider record sha256 cdc9dcdda654f7fd65ef5ab8197acb181a93c98677f77b4c374178fa916b03f7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004cec4(int param_1)

{
  (&DAT_8010b328)[param_1 * 0xe4] = (&DAT_8010b328)[param_1 * 0xe4] & 0xffbf;
  return;
}
