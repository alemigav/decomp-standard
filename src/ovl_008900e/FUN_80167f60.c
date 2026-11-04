/* FUN_80167f60
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80167f60  body 0x80167f60..0x80167ff3  size 148 B
 * body sha256 72930d23c4c6cdc373b5a75f7b5d410118eba9cae36d54f137c6ae033d92d442
 * provider record sha256 48e4537b1122220dbc0d71554e3801ce42c69bcd13f3cdcdab0bb928571ee951
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80167f60(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 5) != -1) {
    *(char *)(param_1 + 0x2cb) = *(char *)(param_1 + 5);
    *(undefined1 *)(param_1 + 5) = 0xff;
    *(undefined4 *)(param_1 + 0x2c4) = 0x800e1130;
    func_0x80035b84();
    FUN_801630bc(param_1);
    FUN_80167eb0(param_1);
  }
  (*(code *)(&PTR_FUN_80168d34)[*(byte *)(param_1 + 0x26e)])(param_1,param_2,param_3);
  return;
}
