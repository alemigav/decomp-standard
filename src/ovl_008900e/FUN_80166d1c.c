/* FUN_80166d1c
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80166d1c  body 0x80166d1c..0x80166de7  size 204 B
 * body sha256 c107c04c26a86c9f2a44d9dbdde9bce664de6d8bf91ddc2b6610b88ccc12f833
 * provider record sha256 82af7255570d589f940404e2bda3ead5bacf5ebf15070216614978227ad4b28b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166d1c(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(short *)(param_1 + 0x1f2) < 0) {
    *(undefined4 *)(param_1 + 4) = 0x3000000;
  }
  else {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x298);
    func_0x80077d18(7,param_1);
    FUN_80162ba4(param_1,&UNK_80168bf4 + (uint)*(byte *)(param_1 + 0x2cb) * 8,0);
    if (*(char *)(param_1 + 5) != -1) {
      *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) | 1;
      (*(code *)(&PTR_FUN_80168cb4)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
      *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) & 0xfffe;
    }
  }
  return;
}
