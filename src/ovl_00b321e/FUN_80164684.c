/* FUN_80164684
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80164684  body 0x80164684..0x801647ab  size 296 B
 * body sha256 d7181657ce84d17e62a2e3b80a7780f37271df4d727bf12a7f6eeeaf33dacf80
 * provider record sha256 d79ddffbfc04610b24a93ac82f742ca3e99275241654a62969733f43b2f7b86f
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164684(int param_1,undefined4 param_2,undefined4 param_3)

{
  func_0x80077d18(3,param_1);
  *(undefined1 *)(param_1 + 0x2de) = 0;
  if (*(char *)(param_1 + 700) == '\0') {
    *(undefined1 *)(param_1 + 0x2ba) = 0;
    *(undefined1 *)(param_1 + 699) = 0;
    *(undefined4 *)(param_1 + 0x1e8) = 0x3000000;
    *(byte *)(param_1 + 0x2bd) = *(byte *)(param_1 + 0x2bd) | 0x80;
    func_0x80089d54(param_1,param_2,param_3,0x100);
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    *(undefined1 *)(param_1 + 0x2df) = 1;
    *(undefined1 *)(param_1 + 0x2c8) = 0;
    *(undefined1 *)(param_1 + 0x2c0) = *(undefined1 *)(param_1 + 5);
    *(undefined1 *)(param_1 + 0x2c1) = *(undefined1 *)(param_1 + 6);
    *(undefined1 *)(param_1 + 0x2c2) = *(undefined1 *)(param_1 + 7);
  }
  else if (*(char *)(param_1 + 0x2c5) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    if (*(char *)(param_1 + 0x2d7) == '\0') {
      func_0x80077d18(3,param_1);
    }
    *(undefined1 *)(param_1 + 0x2d7) = 0;
    FUN_80166270(param_1,0,(&DAT_8016677f)[*(byte *)(param_1 + 5)]);
    FUN_801647ac(param_1,param_2,param_3);
  }
  else {
    FUN_801643d4(param_1,param_2,param_3);
  }
  return;
}
