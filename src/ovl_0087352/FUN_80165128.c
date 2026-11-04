/* FUN_80165128
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80165128  body 0x80165128..0x8016519b  size 116 B
 * body sha256 2842bba53cab12e93cba2be8e464d464032ff694ddb78676375fdad02b5e67b1
 * provider record sha256 5249a0942f88178f1902c9ee7170f693a6230b79bbd551d06691aa957c0e0314
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165128(int param_1,undefined4 param_2,undefined4 param_3)

{
  func_0x800653d0(param_1,&DAT_800e1158,0,0);
  (*(code *)(&PTR_FUN_801666cc)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
