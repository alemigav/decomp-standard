/* FUN_80163288
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80163288  body 0x80163288..0x8016333b  size 180 B
 * body sha256 9173ccfbdc7419fc3c8b1f3082d77c520876ee54fa266444171abfa53c5a4291
 * provider record sha256 611bc20a56a285abe0e7c89bba697c461599fbb70309b48141e4c1ab5f387eba
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163288(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x3003f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x40);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  func_0x80032b5c(param_1,0);
  return;
}
