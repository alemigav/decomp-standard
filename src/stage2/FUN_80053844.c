/* FUN_80053844
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80053844  body 0x80053844..0x80053993  size 336 B
 * body sha256 cad78a537adad75f4c5be94323c7bcedbc6b4dd065b90461f340d2c04e7e3b44
 * provider record sha256 ff1e0ce7e484c43779ee3dcc0269060735420b20698b5939e999e8068324cf85
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80053844(int param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = DAT_8010d940;
  if (DAT_800e860b == '\0') {
    if (*(byte *)(DAT_8010d940 + 0x2dc) < 0xd) {
      FUN_800537a4(param_1,param_2,param_1 + (uint)*(byte *)(DAT_8010d940 + 0x2dc) * (param_3 / 0xc)
                   ,param_2 + (uint)*(byte *)(DAT_8010d940 + 0x2dc) * (param_4 / 0xc));
      *(char *)(iVar1 + 0x2dc) = *(char *)(iVar1 + 0x2dc) + '\x01';
      return 1;
    }
  }
  else {
    if (DAT_800e860b != '\x01') {
      return 1;
    }
    if (*(byte *)(DAT_8010d940 + 0x2dc) < 0xd) {
      FUN_800537a4(param_1,param_2,
                   (param_1 + param_3) - (*(byte *)(DAT_8010d940 + 0x2dc) * param_3) / 0xc,
                   (param_2 + param_4) - (*(byte *)(DAT_8010d940 + 0x2dc) * param_4) / 0xc);
      *(char *)(iVar1 + 0x2dc) = *(char *)(iVar1 + 0x2dc) + '\x01';
      return 1;
    }
  }
  *(undefined1 *)(DAT_8010d940 + 0x2dc) = 0;
  DAT_800e860b = 0;
  return 0;
}
