/* FUN_80162b44
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80162b44  body 0x80162b44..0x80162c5b  size 280 B
 * body sha256 d79bde80319b7125cd930e8da4abebe867912d56d1e486c1f9a94276086a4761
 * provider record sha256 ce0e8d7da637656ad64b607bb37c44ee11387e80a4bbd2dcfcbf0967ac115e06
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162b44(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x1003f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  if (0xf < *(short *)(param_1 + 0x1e0)) {
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),8);
  }
  if (10 < *(short *)(param_1 + 0x1e0)) {
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),8);
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  func_0x80089d54(param_1,param_2,param_3,0x40);
  iVar1 = func_0x80083d2c(param_1 + 0x28,_DAT_800df940);
  if (iVar1 == 0) {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + 0x32;
  }
  func_0x80032b5c(param_1,0);
  return;
}
