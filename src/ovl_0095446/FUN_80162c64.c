/* FUN_80162c64
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80162c64  body 0x80162c64..0x80162db7  size 340 B
 * body sha256 d7bccc6a5dccda6175faed95d7eb4d3043a022e3de4a43a7a8f41659ccbd9f2c
 * provider record sha256 4d1e8aa1a499cb12e02eb5b13c27d7e130923474b31b7f415bd34c4e901a0139
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162c64(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 0x2be) < '\x03') {
    *(byte *)(param_1 + 0x2be) = *(byte *)(param_1 + 0x2be) | 0x82;
  }
  if (*(char *)(param_1 + 700) < '\x02') {
    *(undefined1 *)(param_1 + 700) = 1;
  }
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x8001f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x2b6) = 0;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 2;
    *(ushort *)(param_1 + 0x2ba) = *(ushort *)(param_1 + 0x2ba) | 0x2000;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0xffffffe0);
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x80);
  if (iVar1 == 0) {
    func_0x80032b5c(param_1,0);
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x800;
    uVar2 = func_0x80033604();
    *(char *)(param_1 + 0x2b8) = (char)((uVar2 & 0xff) >> 1) + 'x';
    *(byte *)(param_1 + 0x2be) = *(byte *)(param_1 + 0x2be) & 0x7f;
    *(ushort *)(param_1 + 0x2ba) = *(ushort *)(param_1 + 0x2ba) & 0xdfff;
  }
  return;
}
