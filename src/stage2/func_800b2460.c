/* func_800b2460
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2460  body 0x800b2460..0x800b24c3  size 100 B
 * body sha256 1a208d6362af2df067e9445a5617c76917e5f42e8b49c58c6375e52ddf08e659
 * provider record sha256 57ba998d9c795dd36b88d055800183df1271b85de3e86c418c5732ced8720da0
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 func_800b2460(undefined4 param_1,undefined2 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    uVar1 = FUN_800a7970(param_1,param_2);
    FUN_800a56c0();
  }
  return uVar1;
}
