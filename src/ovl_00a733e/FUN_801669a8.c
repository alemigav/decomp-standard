/* FUN_801669a8
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x801669a8  body 0x801669a8..0x801669f3  size 76 B
 * body sha256 90036eeb5310cdba58b2c5a0060b2c92d0411c98a078144317498f98cbfbda5b
 * provider record sha256 144310d24430614dd17ef77d1baf54c139f70b821bcf79757c294dd99a31e709
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801669a8(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0xf00;
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  *(undefined2 *)(param_1 + 0x272) = 1;
  return;
}
