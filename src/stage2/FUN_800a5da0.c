/* FUN_800a5da0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5da0  body 0x800a5da0..0x800a60f3  size 852 B
 * body sha256 9e00328396cc487c0bc54de44760885f569135dad6dbf222e4238f8d38aa1674
 * provider record sha256 98f3fb8bde340d98010a0aea4e08955b8e8ce279c9690768ffcc8e4830255061
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x800a5ff4) */
/* WARNING: Removing unreachable block (ram,0x800a5eec) */
/* WARNING: Removing unreachable block (ram,0x800a5dcc) */
/* WARNING: Removing unreachable block (ram,0x800a5e40) */
/* WARNING: Removing unreachable block (ram,0x800a5f78) */
/* WARNING: Removing unreachable block (ram,0x800a6070) */

void FUN_800a5da0(undefined2 *param_1,undefined2 *param_2,uint param_3,uint param_4,uint param_5,
                 undefined2 *param_6,uint param_7,undefined2 *param_8)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  
  if (0x7f0000 < param_3) {
    param_3 = 0x7f0000;
  }
  fVar2 = (float)(param_3 & 0xffff) * 1.5258789e-05;
  fVar3 = (1.0 - fVar2) * *(float *)(&UNK_80136100 + (param_3 >> 0x10) * 4) +
          fVar2 * *(float *)(&UNK_80136100 + ((param_3 >> 0x10) + 1) * 4);
  fVar2 = (float)(param_5 & 0x3fffff) * 2.3841858e-07;
  uVar1 = 0x800000 - param_5;
  *param_6 = (short)(int)(fVar3 * ((1.0 - fVar2) * *(float *)(&DAT_80136304 + (param_5 >> 0x16) * 4)
                                  + fVar2 * *(float *)(&DAT_80136304 + ((param_5 >> 0x16) + 1) * 4))
                          * 0.7079 * 32767.0);
  if (0x7fffff < uVar1) {
    uVar1 = 0x7f0000;
  }
  fVar2 = (float)(uVar1 & 0x3fffff) * 2.3841858e-07;
  fVar3 = fVar3 * ((1.0 - fVar2) * *(float *)(&DAT_80136304 + (uVar1 >> 0x16) * 4) +
                  fVar2 * *(float *)(&DAT_80136304 + ((uVar1 >> 0x16) + 1) * 4));
  if (param_4 == 0x800000) {
    fVar2 = -0.7079;
    *param_1 = (short)(int)(fVar3 * 0.7079 * 32767.0);
  }
  else {
    fVar2 = (float)(param_4 & 0x3fffff) * 2.3841858e-07;
    uVar1 = 0x800000 - param_4;
    *param_1 = (short)(int)(fVar3 * ((1.0 - fVar2) *
                                     *(float *)(&DAT_80136304 + (param_4 >> 0x16) * 4) +
                                    fVar2 * *(float *)(&DAT_80136304 + ((param_4 >> 0x16) + 1) * 4))
                           * 32767.0);
    if (0x7fffff < uVar1) {
      uVar1 = 0x7f0000;
    }
    fVar2 = (float)(uVar1 & 0x3fffff) * 2.3841858e-07;
    fVar2 = (1.0 - fVar2) * *(float *)(&DAT_80136304 + (uVar1 >> 0x16) * 4) +
            fVar2 * *(float *)(&DAT_80136304 + ((uVar1 >> 0x16) + 1) * 4);
  }
  *param_2 = (short)(int)(fVar3 * fVar2 * 32767.0);
  if (0x7f0000 < param_7) {
    param_7 = 0x7f0000;
  }
  fVar2 = (float)(param_7 & 0xffff) * 1.5258789e-05;
  *param_8 = (short)(int)(((1.0 - fVar2) * *(float *)(&UNK_80136100 + (param_7 >> 0x10) * 4) +
                          fVar2 * *(float *)(&UNK_80136100 + ((param_7 >> 0x10) + 1) * 4)) * 0.7079
                         * 32767.0);
  return;
}
