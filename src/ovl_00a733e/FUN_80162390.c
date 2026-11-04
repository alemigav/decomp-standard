/* FUN_80162390
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80162390  body 0x80162390..0x801623e3  size 84 B
 * body sha256 c21e64e039a0d81f56c9d1c71ed875479b63c5dcb24121c8186f5d479f30fcc5
 * provider record sha256 c0223ec8bfed722f1fb1026f41532ded158213f09ba1bf558fc480517a9a2222
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined2 FUN_80162390(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  func_0x80089d54();
  param_4 = (uint)*(ushort *)(param_1 + 500) - param_4;
  *(short *)(param_1 + 500) = (short)param_4;
  if (param_4 * 0x10000 < 0) {
    *(undefined2 *)(param_1 + 500) = 0;
  }
  return **(undefined2 **)(param_1 + 0x214);
}
