/* FUN_80035dbc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80035dbc  body 0x80035dbc..0x80035de7  size 44 B
 * body sha256 c38e9dd80cde54f010ace80c2b3935ac48bd06ca85217fda0652b4b7de06c2fa
 * provider record sha256 31d6fea4f33bf529cd6b92ffd9e41d76fb689f920c079fe3c191d6eaa219d857
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80035dbc(int param_1,undefined4 param_2)

{
  FUN_80036008(param_1,*(int *)(param_1 + 0x234) + 0x2f0,&DAT_800eb78c,param_2);
  return;
}
