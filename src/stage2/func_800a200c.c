/* func_800a200c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a200c  body 0x800a200c..0x800a206f  size 100 B
 * body sha256 f47bd9cc4e6c705b31dce755cda2f6825fbce9eb7bb95e35c64a6f73d9be8008
 * provider record sha256 5f1b3a4bc7ad3a11fe3ebb5a18434e9d11d1feed2d8bf113da1f984a6cc7e840
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void func_800a200c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a12f8(param_1,param_2,param_3);
    FUN_800a56c0();
  }
  return;
}
