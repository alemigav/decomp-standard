/* FUN_8002fcc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002fcc0  body 0x8002fcc0..0x8002fccf  size 16 B
 * body sha256 cec17c79d3a814377cbbd26ea5ce24f79e26df0704615bc92cfbb45c1688fe2d
 * provider record sha256 4ebcb3dd59ea2cbb1cb1b31c9c01437106ccefb8ff8e9d8443753a448b92e1e7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8002fcc0(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  return *(int *)(*(int *)(param_1 + 4) + 0x2c) - param_4;
}
