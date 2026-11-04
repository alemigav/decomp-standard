/* FUN_80164964
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80164964  body 0x80164964..0x80164aab  size 328 B
 * body sha256 5b62450441c72aee3af4b8728ce00a31c948ef40f4b7adce7033e8113bbfd3d4
 * provider record sha256 c3038db12085effefc66b89899f118e3bca8e00c8e3319572754a9375747add9
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164964(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar3;
  short sVar1;
  ushort uVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x5000f00;
    *(undefined1 *)(param_1 + 6) = 1;
    uVar2 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar2 & 7) + 7;
    func_0x800334c8(param_1,param_2,param_3,0);
    bVar3 = func_0x80033604();
    *(byte *)(param_1 + 0x1e9) = bVar3 & 0xf;
    func_0x800334c8(param_1,param_2,param_3,0);
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  if (0x14 < *(short *)(param_1 + 0x1e0)) {
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x18);
    sVar1 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar1;
    if (sVar1 == -1) {
      func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x18
                     );
      uVar2 = func_0x80033604();
      *(ushort *)(param_1 + 500) = (uVar2 & 7) + 7;
    }
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  func_0x80089d54(param_1,param_2,param_3,0x100);
  func_0x80032b5c(param_1,0);
  return;
}
