/* FUN_8016caf8
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016caf8  body 0x8016caf8..0x8016cb83  size 140 B
 * body sha256 e044eec5de744b1f537c135b37532a4e41b0b20329f8bd2a4ca3d04af2c49012
 * provider record sha256 161a042c1ee8a82b0b351f6f7ea2db3c0c185db8c847a6796da40d419e260246
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016caf8(int param_1)

{
  (*(code *)(&PTR_FUN_8016e85c)[*(byte *)(param_1 + 5)])();
  if (((*(short *)(param_1 + 0x1a8) != 0) &&
      (*(int *)(*(int *)(param_1 + 0x234) + 0x50) + -500 < (int)*(short *)(param_1 + 0x1a8))) &&
     ((*(byte *)(param_1 + 0x1e9) & 0xf) == 1)) {
    FUN_8016d778(param_1);
    func_0x80077adc(0x2020001,param_1 + 0x28);
  }
  return;
}
