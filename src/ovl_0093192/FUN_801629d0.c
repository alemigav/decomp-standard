/* FUN_801629d0
 * image   ovl_0093192 (ovl), base 0x80161cf0
 * address 0x801629d0  body 0x801629d0..0x80162a53  size 132 B
 * body sha256 1dc1d2cdf8883c1ac0f4b4583c3231a9fd2cc960f94119e9e87431604e371d98
 * provider record sha256 ef2a8ca819be597f162694c0b45f0e0d9aebb3661fb8ca6afbddf9f3c1efa7f2
 * callees 2 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801629d0(uint *param_1)

{
  *param_1 = *param_1 | 2;
  param_1[0xb] = param_1[0xb] + 0x1e;
  *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + 0x20;
  *(short *)(param_1 + 0x1a) = *(short *)(param_1 + 0x1a) + 0x40;
  func_0x80089d54();
  if (((int)*(short *)((int)param_1 + 0x25e) <= (int)param_1[0xb]) ||
     ((int)param_1[0xb] < (int)*(short *)(param_1 + 0x6a))) {
    func_0x8003247c(param_1);
  }
  return;
}
