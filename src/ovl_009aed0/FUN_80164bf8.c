/* FUN_80164bf8
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80164bf8  body 0x80164bf8..0x80164c6f  size 120 B
 * body sha256 8b9303fbad16c0a605ae02a21b6aba911f94c75bb068c58bfc959fb7a21ca334
 * provider record sha256 fe45e6fb601a197030e66b23ba72ca21ad0b1d54cd578353a4beb1786f8436a2
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164bf8(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 5) != -1) {
    *(char *)(param_1 + 699) = *(char *)(param_1 + 5);
    *(undefined1 *)(param_1 + 5) = 0xff;
    FUN_8016496c();
  }
  (*(code *)(&PTR_FUN_8016662c)[*(byte *)(param_1 + 0x26e)])(param_1,param_2,param_3);
  return;
}
