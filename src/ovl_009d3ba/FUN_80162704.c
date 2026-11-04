/* FUN_80162704
 * image   ovl_009d3ba (ovl), base 0x80161cf0
 * address 0x80162704  body 0x80162704..0x801627cf  size 204 B
 * body sha256 4b47cfa7fa7d4c3a924a083bc8780bb47beaed189eea5b5da2fde11968cf856d
 * provider record sha256 75e2b627b74f6530148e8e78afd77408ba06592e5599a81580101215695cac5e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162704(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined4 *)(param_1 + 4) = 0x1050000;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x3000f00;
    *(undefined1 *)(param_1 + 6) = 1;
  }
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x30);
  cVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar2;
  return;
}
