/* FUN_8016587c
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016587c  body 0x8016587c..0x801659a3  size 296 B
 * body sha256 8164065e40b3e52968d3eb5daf7143132ae75efac843c2e35271af421c6530b1
 * provider record sha256 98c2d777734ae35b6c339375d3005f15d1fb2a76253305456a253660ff4bec64
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016587c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  short sVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x2001f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 500) = 0x28;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x20);
  iVar1 = func_0x80032e74(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),
                          0x338);
  if (iVar1 != 0) {
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x20);
  }
  func_0x800334c8(param_1,param_2,param_3,1);
  if (0x14 < *(byte *)(param_1 + 0x1ea)) {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) >> 1;
  }
  func_0x80089d54(param_1,param_2,param_3,0x10080);
  func_0x80032b5c(param_1,0);
  sVar2 = *(short *)(param_1 + 500) + -1;
  *(short *)(param_1 + 500) = sVar2;
  if (sVar2 == -1) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  return;
}
