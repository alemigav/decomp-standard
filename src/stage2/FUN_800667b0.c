/* FUN_800667b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800667b0  body 0x800667b0..0x800667d3  size 36 B
 * body sha256 32767637a9a57281d56564d8163a590857eda97dede9acb5ca5ee13798a914fe
 * provider record sha256 4a8dfeb4894d03f55dbf5aa6754003b1141fd70f2c945e1b9f926b98b8bb432c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800667b0(int param_1,int param_2,int param_3,int param_4)

{
  return (1 << ((uint)(param_1 - param_3) >> 0x1f)) << ((uint)(param_2 - param_4) >> 0x1e & 2);
}
