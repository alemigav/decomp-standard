/* FUN_80165b24
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80165b24  body 0x80165b24..0x80165bef  size 204 B
 * body sha256 80b8a60cd9575bf08bbadbc519532ad92beba28b51265384d0b088614ccafdb4
 * provider record sha256 d953da3e5366f8458cfcbd3b71752dd73e72269a60e1635e2a7e7141abbdfac9
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165b24(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(short *)(param_1 + 0x1f2) < 0) {
    *(undefined4 *)(param_1 + 4) = 0x3000000;
  }
  else {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x298);
    func_0x80077d18(7,param_1);
    FUN_80162ba4(param_1,&UNK_801673e8 + (uint)*(byte *)(param_1 + 0x2cb) * 8,0);
    if (*(char *)(param_1 + 5) != -1) {
      *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) | 1;
      (*(code *)(&PTR_FUN_80167498)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
      *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) & 0xfffe;
    }
  }
  return;
}
