/* FUN_80164dbc
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80164dbc  body 0x80164dbc..0x80164e83  size 200 B
 * body sha256 15824fff3c2a37b5e0a65c55fb692412fea53aefc41ab63378d9ce7f33c63cdc
 * provider record sha256 d5900de663c26c3b539022f04f89ca82f4d032e429e1d95b684430b93f88228c
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164dbc(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    uVar1 = func_0x80033604();
    FUN_801663a4(param_1,8,uVar1 & 3);
    uVar1 = func_0x80033604();
    FUN_801663a4(param_1,8,uVar1 & 3 | 4);
    FUN_80164684(param_1,param_2,param_3);
  }
  else {
    (*(code *)(&PTR_FUN_801667a8)[*(byte *)(param_1 + 6)])(param_1,param_2,param_3);
    func_0x80089d54(param_1,param_2,param_3,0x100);
  }
  return;
}
