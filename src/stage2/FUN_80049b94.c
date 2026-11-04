/* FUN_80049b94
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80049b94  body 0x80049b94..0x80049dcf  size 572 B
 * body sha256 ae541d9e02d3b2b1db1b2020cc873a67d7fc0689274d6adf939da9da54262cb6
 * provider record sha256 a6532cd6bbae0de9141e6362bb3e43419c55a42a993f582ee468eeeef9748468
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80049b94(float *param_1,uint *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)(*param_1 * 0.25 * 65536.0);
  uVar2 = (uint)(param_1[1] * 0.25 * 65536.0);
  *param_2 = uVar1 & 0xffff0000 | uVar2 >> 0x10;
  param_2[8] = uVar1 << 0x10 | uVar2 & 0xffff;
  uVar1 = (uint)(param_1[2] * 0.25 * 65536.0);
  param_2[1] = uVar1 & 0xffff0000;
  param_2[9] = uVar1 << 0x10;
  uVar1 = (uint)(param_1[3] * 0.25 * 65536.0);
  uVar2 = (uint)(param_1[4] * 0.25 * 65536.0);
  param_2[2] = uVar1 & 0xffff0000 | uVar2 >> 0x10;
  param_2[10] = uVar1 << 0x10 | uVar2 & 0xffff;
  uVar1 = (uint)(param_1[5] * 0.25 * 65536.0);
  param_2[3] = uVar1 & 0xffff0000;
  param_2[0xb] = uVar1 << 0x10;
  uVar1 = (uint)(param_1[6] * 0.25 * 65536.0);
  uVar2 = (uint)(param_1[7] * 0.25 * 65536.0);
  param_2[4] = uVar1 & 0xffff0000 | uVar2 >> 0x10;
  param_2[0xc] = uVar1 << 0x10 | uVar2 & 0xffff;
  uVar1 = (uint)(param_1[8] * 0.25 * 65536.0);
  param_2[5] = uVar1 & 0xffff0000;
  param_2[0xd] = uVar1 << 0x10;
  if (param_3 != 0) {
    uVar1 = (uint)(param_1[9] * 0.25 * 65536.0);
    uVar2 = (uint)(param_1[10] * 0.25 * 65536.0);
    param_2[6] = uVar1 & 0xffff0000 | uVar2 >> 0x10;
    param_2[0xe] = uVar1 << 0x10 | uVar2 & 0xffff;
    uVar1 = (uint)(param_1[0xb] * 0.25 * 65536.0);
    param_2[7] = uVar1 & 0xffff0000 | 1;
    param_2[0xf] = uVar1 << 0x10;
  }
  return;
}
