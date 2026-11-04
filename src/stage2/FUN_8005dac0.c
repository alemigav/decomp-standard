/* FUN_8005dac0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005dac0  body 0x8005dac0..0x8005db07  size 72 B
 * body sha256 af3b6eb9215781e5b2fb7782944f17c105850b35fab8efd2a8bd1b45f5b94800
 * provider record sha256 4a9f4d399c3f4d43a06054e452d22207d56129ec8b4eeae55e27eb2f16cf75ed
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005dac0(int param_1)

{
  if ((**(uint **)(param_1 + 0x214) & 0x100000) != 0) {
    FUN_80077adc(**(uint **)(param_1 + 0x214) & 0xf0000 | 0x1000001,param_1 + 0x28);
  }
  return;
}
