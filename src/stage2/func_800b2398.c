/* func_800b2398
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2398  body 0x800b2398..0x800b23fb  size 100 B
 * body sha256 00b27ca814ed0a0f85fc29cfaa905a2874f2abe73f2dba6b1f0039fb1d9b0ac0
 * provider record sha256 32f7ee90c965c3981ef2102d3c17b5a4eb2644e4afe7a645b7ef6b2a1ea36141
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 func_800b2398(undefined4 param_1,undefined1 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    uVar1 = FUN_800a76a4(param_1,param_2);
    FUN_800a56c0();
  }
  return uVar1;
}
