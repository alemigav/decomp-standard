/* FUN_8009e93c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009e93c  body 0x8009e93c..0x8009e9ab  size 112 B
 * body sha256 8c6d35e84b681802a279b9ab38f9bd862c91506d8af8b564d2ade4429459a7cb
 * provider record sha256 b2fb48cbab51a83b0a082c9a0622f419ad138d53d772523943c4e9eabe7d740f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009e93c(int param_1,undefined2 param_2,uint param_3,undefined2 *param_4)

{
  byte bVar1;
  
  bVar1 = *(byte *)((int)&DAT_800e9194 + param_1 * 0x2c + 3);
  (&DAT_800e9184)[param_1 * 0x16] = param_2;
  (&DAT_800e9194)[param_1 * 0xb] = param_3 | (uint)bVar1 << 0x18;
  if (param_4 == (undefined2 *)0x0) {
    *(undefined4 *)(&DAT_800e9198 + param_1 * 0x16) = 0;
    *(undefined4 *)(&DAT_800e919c + param_1 * 0x16) = 0x14000f0;
    return;
  }
  (&DAT_800e9198)[param_1 * 0x16] = *param_4;
  (&DAT_800e919a)[param_1 * 0x16] = param_4[1];
  (&DAT_800e919c)[param_1 * 0x16] = param_4[2];
  (&DAT_800e919e)[param_1 * 0x16] = param_4[3];
  return;
}
