/* FUN_80166210
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80166210  body 0x80166210..0x80166297  size 136 B
 * body sha256 1020c892416febfbfa548ce46dd2c493639515952568d18245440ff6b671f657
 * provider record sha256 c058934605c6cf34a4cbfcee13ab9d5f70c019d6cbf5575c25b91838510b7aab
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166210(int param_1)

{
  byte bVar2;
  uint uVar1;
  
  (*(code *)(&PTR_FUN_80166f68)[*(byte *)(param_1 + 6)])();
  bVar2 = *(char *)(param_1 + 0x207) + 1;
  *(byte *)(param_1 + 0x207) = bVar2;
  if ((bVar2 & 1) != 0) {
    uVar1 = func_0x80033604();
    FUN_80166980(param_1,uVar1 & 0xf,0xb);
    uVar1 = func_0x80033604();
    FUN_80166980(param_1,uVar1 & 0xf,0xb);
  }
  return;
}
