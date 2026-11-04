/* FUN_800275c0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800275c0  body 0x800275c0..0x8002764f  size 144 B
 * body sha256 8c465f69c835749c7e49b6dd4ccdb003b54b7ebeee7284c50bd844b54b4e40fc
 * provider record sha256 57db28fd2d6ed651ab3e8001320c8d417a56d2e9d418ba543eb4d9edfb28be47
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800275c0(int param_1,undefined2 param_2,uint param_3,undefined2 *param_4)

{
  byte bVar1;
  
  bVar1 = *(byte *)((int)&DAT_800e9194 + param_1 * 0x2c + 3);
  (&DAT_800e9184)[param_1 * 0x16] = param_2;
  *(uint *)(&DAT_800e9184 + param_1 * 0x16 + (uint)DAT_800dfbe8 * 8 + 8) =
       param_3 | (uint)bVar1 << 0x18;
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
