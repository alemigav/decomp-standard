/* FUN_80166280
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80166280  body 0x80166280..0x801662cf  size 80 B
 * body sha256 f53f769f965d81ab7a4b122e7f0c72e0be75fde2b9a2a31f595d8e06932cd990
 * provider record sha256 ba1b4060389284066d4a77125261e145ea8db0c2db7941795d703944fc021c90
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166280(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x3003f00;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 1;
  }
  func_0x80089d54(param_1,param_2,param_3,0x40);
  return;
}
