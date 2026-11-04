/* FUN_80164e1c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80164e1c  body 0x80164e1c..0x80164e87  size 108 B
 * body sha256 895958211b3acc64f7e59ac2089e2b3beb79197e56ee466d8481a9496f4cba75
 * provider record sha256 22878070ab6a40b9d5db1b73958bae297dc57edc4978b7788f92a281446e781e
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164e1c(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    uVar1 = func_0x80033604();
    FUN_80167688(param_1,0x2004,(uVar1 & 1) + 1);
  }
  FUN_80164aac(param_1,param_2,param_3);
  return;
}
