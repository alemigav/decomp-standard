/* FUN_801639f4
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x801639f4  body 0x801639f4..0x80163a83  size 144 B
 * body sha256 5599c8b98f216664daef6fbbdc706933ad2f00a26015967035b7015e7fad16a9
 * provider record sha256 c3c4c25ca0d6c9daef06aa385cce718cfe00801d207f521f126c65f490e19070
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801639f4(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 5) != -1) {
    *(char *)(param_1 + 0x2cc) = *(char *)(param_1 + 5);
    *(undefined1 *)(param_1 + 5) = 0xff;
    FUN_801638cc();
    if (1 < *(byte *)(param_1 + 0x1e9)) {
      *(byte *)(param_1 + 0x1e9) = *(byte *)(param_1 + 0x1e9) - 2;
    }
  }
  (*(code *)(&PTR_FUN_80166110)[*(byte *)(param_1 + 0x26e)])(param_1,param_2,param_3);
  return;
}
