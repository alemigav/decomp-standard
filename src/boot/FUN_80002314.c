/* FUN_80002314
 * image   boot (boot), base 0x80000480
 * address 0x80002314  body 0x80002314..0x8000235f  size 76 B
 * body sha256 21262b8427e21d88a1e56413f11e47a1a02a7f46bafcfebb4d94b4dcc23e63f8
 * provider record sha256 d8b3ce97647ce44841303c3101621588f16a8808815d3327ddf89c4e6cb32744
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80002314(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  FUN_8000de9c(*(undefined4 *)(param_1 + 0x24),param_3,param_4);
  param_4 = *(int *)(param_1 + 0x24) + param_4;
  *(int *)(param_1 + 0x30) = param_4;
  *(int *)(param_1 + 0x2c) = param_4;
  return;
}
