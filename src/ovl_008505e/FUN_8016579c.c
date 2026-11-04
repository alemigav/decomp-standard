/* FUN_8016579c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x8016579c  body 0x8016579c..0x80165857  size 188 B
 * body sha256 bab47dd72bfaa9af00e1e63752100c3d16e4110f76e3dabd6285dcc8bc20a352
 * provider record sha256 641c9349f33a9c5bc94c678ed5ecb802924753dc26b68a7c3d6100bd37263684
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016579c(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 4 - *(byte *)(param_1 + 0x26e) / 3;
  *(char *)(param_1 + 699) = (char)uVar1;
  uVar2 = 0;
  if ((uVar1 & 0xff) != 0) {
    do {
      uVar2 = uVar2 + 1;
      uVar1 = func_0x80033604();
      FUN_80166980(param_1,uVar1 & 0xf,8);
    } while (uVar2 < *(byte *)(param_1 + 699));
  }
  *(undefined1 *)(param_1 + 5) = 1;
  *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
  FUN_80164d5c(param_1,param_2,param_3);
  return;
}
