/* FUN_801630f0
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x801630f0  body 0x801630f0..0x801631d3  size 228 B
 * body sha256 4a6a171e5771be17434a5aaaff746810b11b34285c19d1961ba587b05c21186d
 * provider record sha256 6c468ffaf34c15b0d9ccf273c0943cf6b92de1c8ee26cc47eef723c08ef66ef3
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801630f0(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x3000700;
    *(undefined2 *)(param_1 + 0x1e2) = 0x28;
    *(undefined1 *)(param_1 + 0x2b5) = 0;
    *(undefined1 *)(param_1 + 6) = 1;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  cVar1 = *(char *)(param_1 + 0x2b5) + -1;
  *(char *)(param_1 + 0x2b5) = cVar1;
  if (cVar1 == -1) {
    *(undefined1 *)(param_1 + 0x2b5) = 0xf;
  }
  func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x20);
  func_0x80032bd8(param_1,0,0);
  if (*(short *)(param_1 + 0x1e0) < 300) {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + 1;
  }
  func_0x80089d54(param_1,param_2,param_3,0x200);
  return;
}
