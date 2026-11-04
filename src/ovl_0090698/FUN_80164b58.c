/* FUN_80164b58
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80164b58  body 0x80164b58..0x80164c33  size 220 B
 * body sha256 83d45194d628ef6878217a273d9e34abc309ccfa3f96474cf5d44a518ac3b6bb
 * provider record sha256 5490be058bba736bbe131f15c30a83a7d96d4b587fde2418eda99c7250193bb4
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164b58(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 0x2d2) == '\0') {
    if ((*(ushort *)(param_1 + 0x1aa) & 1) == 0) {
      (*(code *)(&PTR_FUN_80167f00)[*(byte *)(param_1 + 6)])(param_1,param_2,param_3);
    }
    else {
      FUN_80164e1c(param_1,param_2,param_3);
    }
  }
  else {
    FUN_8016753c();
    *(uint *)(param_1 + 4) =
         (uint)*(byte *)(param_1 + 0x2cf) * 0x10000 + (uint)*(byte *)(param_1 + 0x2d0) * 0x100 +
         (uint)*(byte *)(param_1 + 0x2d1) + 0x1000000;
    FUN_80162148(param_1,param_2,param_3);
  }
  return;
}
