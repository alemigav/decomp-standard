/* FUN_801631cc
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x801631cc  body 0x801631cc..0x8016327f  size 180 B
 * body sha256 93e11ca8d8eb21ff45c16aa5c555104dba4e11aed420a4dae477bf1521cf9e6a
 * provider record sha256 ecc4c15ff701cf49813a279d89f807c929f36c6f2378473326ee057b35188853
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801631cc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x2003f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 2;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x40);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1050000;
  }
  func_0x80032b5c(param_1,0);
  return;
}
