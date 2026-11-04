/* FUN_80163718
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80163718  body 0x80163718..0x801637df  size 200 B
 * body sha256 39837c4e743051a6970a32aab10130d9c6d5c0e05e86003158483c5c36fc349e
 * provider record sha256 8d51d62a2fe4d5978ec5813140bc9dee52d9c9f242b624cf33bf7058d4b49b23
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163718(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0xa003f00;
    *(undefined1 *)(param_1 + 6) = 1;
    uVar1 = func_0x80033604();
    *(char *)(param_1 + 0x2b8) = (char)((uVar1 & 0xff) >> 1) + 'x';
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x40);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  func_0x80032b5c(param_1,0);
  return;
}
