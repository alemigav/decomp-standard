/* FUN_80164b80
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80164b80  body 0x80164b80..0x80164bbb  size 60 B
 * body sha256 7489a4fcf421877db2f47f73a63569ffa09b16bfde0e29d994b39a894f3b73f4
 * provider record sha256 21799f134daa20791f404bf8bb5b12e08d34b1417adafedaf543fe4d6de8e46a
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164b80(undefined4 param_1)

{
  uint uVar1;
  
  FUN_801625e0();
  uVar1 = func_0x80033604();
  FUN_801663a4(param_1,3,uVar1 & 7);
  return;
}
