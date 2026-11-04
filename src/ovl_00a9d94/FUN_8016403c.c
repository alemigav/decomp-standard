/* FUN_8016403c
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016403c  body 0x8016403c..0x801641fb  size 448 B
 * body sha256 96ce3dbfb34839c0cf33a2ca77c5f0fd0443952fb63aa885fcebba137a658966
 * provider record sha256 a49a62311b797afb8fe7e9f64cd3da42ed5c72c026807319a1c2fcbabbfccdf9
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016403c(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar2;
  int iVar1;
  
  *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 0x40;
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x5000f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 500) = 0;
    bVar2 = func_0x80033604();
    *(byte *)(param_1 + 0x206) = (bVar2 & 0xf) + 1;
    DAT_8016c31e = 0;
    func_0x80077d18(0,param_1);
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  if (0x14 < *(short *)(param_1 + 0x1e0)) {
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),4);
  }
  if (0x1e < *(short *)(param_1 + 0x1e0)) {
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),8);
  }
  if (((*(ushort *)(param_1 + 0x2b6) & 0x20) != 0) &&
     (func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),8),
     *(char *)(param_1 + 0x206) != '\0')) {
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262));
  }
  if ((((*(uint *)(param_1 + 0x28c) < 0xdac) && ((*(ushort *)(param_1 + 0x2b6) & 0x20) == 0)) &&
      (bVar2 = *(char *)(param_1 + 0x2d3) + 1, *(byte *)(param_1 + 0x2d3) = bVar2, 0x96 < bVar2)) &&
     (1 < *(byte *)(param_1 + 0x2d6))) {
    *(undefined4 *)(param_1 + 4) = 0x10b0000;
    *(undefined1 *)(param_1 + 0x2c2) = 4;
    *(undefined1 *)(param_1 + 0x2d3) = 0;
  }
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar1 != 0) {
    func_0x80077d18(0xb,param_1);
  }
  func_0x80032b5c(param_1,0);
  return;
}
