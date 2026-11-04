/* FUN_80163fe8
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80163fe8  body 0x80163fe8..0x8016410f  size 296 B
 * body sha256 1ee0c9821ce8c0e6ce74a74b437c17d6bbd19364cab5db45cc5aaaae89191a95
 * provider record sha256 ca78312c5b25ad4aed37e60519d185fe2b2477911114b8d6f4e7f637b48d9f74
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163fe8(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x1001f00;
    if ((*(ushort *)(param_1 + 0x2b8) & 1) != 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0xc001f00;
    }
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 500) = 0x3c;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
  func_0x800334c8(param_1,param_2,param_3,1);
  if (0x14 < *(byte *)(param_1 + 0x1ea)) {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) >> 1;
  }
  func_0x80089d54(param_1,param_2,param_3,0x10080);
  func_0x80032b5c(param_1,0);
  sVar1 = *(short *)(param_1 + 500) + -1;
  *(short *)(param_1 + 500) = sVar1;
  if (sVar1 == -1) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  return;
}
