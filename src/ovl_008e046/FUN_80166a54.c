/* FUN_80166a54
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80166a54  body 0x80166a54..0x80166ae7  size 148 B
 * body sha256 3fc3472fb768dce74952b06cdc3e4162cf7228a4669389a8788bdc25099fff55
 * provider record sha256 47cdb64936457a3092b06559682a7816e0da9c05dc4936b5ef5f420a9a7afb4c
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166a54(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 5) != -1) {
    *(char *)(param_1 + 0x2cb) = *(char *)(param_1 + 5);
    *(undefined1 *)(param_1 + 5) = 0xff;
    *(undefined4 *)(param_1 + 0x2c4) = 0x800e1130;
    func_0x80035b84();
    FUN_801630bc(param_1);
    FUN_801669e4(param_1);
  }
  (*(code *)(&PTR_FUN_80167514)[*(byte *)(param_1 + 0x26e)])(param_1,param_2,param_3);
  return;
}
