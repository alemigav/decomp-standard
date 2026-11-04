/* FUN_80164d80
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80164d80  body 0x80164d80..0x80164dbb  size 60 B
 * body sha256 01db2079b4a1aa8609427f4677473a84331db3be02d67bbdfcf30263e6b5910f
 * provider record sha256 5394d69dfbd969f57c408d2c0b9eebb3877521512b9c6e63f592d9dff394ecfc
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164d80(undefined4 param_1)

{
  uint uVar1;
  
  FUN_80163620();
  uVar1 = func_0x80033604();
  FUN_801663a4(param_1,3,uVar1 & 7);
  return;
}
