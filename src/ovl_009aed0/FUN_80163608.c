/* FUN_80163608
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80163608  body 0x80163608..0x80163697  size 144 B
 * body sha256 65462f7bfe3f233af78502044ea81b3a358092f2b7dc93e12ecea584940e6689
 * provider record sha256 efc18809cbde3d2bb76e4d074ab495d1fa9311a33bd1dbfb2710ec294cedeb44
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163608(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_LAB_801665e4)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_80166608)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  func_0x80036c44(param_1,*(undefined4 *)(param_1 + 0x2b4));
  *(undefined4 *)(param_1 + 0x2b4) = *(undefined4 *)(param_1 + 4);
  return;
}
