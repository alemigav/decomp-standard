/* FUN_80162c44
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80162c44  body 0x80162c44..0x80162dab  size 360 B
 * body sha256 833c5853807ac7ddc1301a407d1cc1f4fd7d05ea9db100cf7665e6be0daa2272
 * provider record sha256 0f77f8665e74c8c4bd2d8fc8feec230ea4d94b8f9b84244ed9d460e434dda325
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162c44(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x1001f00;
    if ((*(ushort *)(param_1 + 0x2b8) & 1) != 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0xc001f00;
    }
    *(undefined1 *)(param_1 + 6) = 1;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x10);
  iVar1 = func_0x80032e74(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),
                          0x338);
  if (iVar1 != 0) {
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x20);
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  if (0xf < *(byte *)(param_1 + 0x1ea)) {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) >> 1;
  }
  iVar1 = func_0x80083d2c(param_1 + 0x28,_DAT_800df940);
  if (iVar1 == 0) {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + 0x28;
  }
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x80);
  if ((iVar1 != 0) && (uVar2 = func_0x80033604(param_1), (uVar2 & 3) == 0)) {
    func_0x80077d18(7,param_1);
  }
  func_0x80032b5c(param_1,0);
  return;
}
