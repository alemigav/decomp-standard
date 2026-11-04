/* FUN_80162f48
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80162f48  body 0x80162f48..0x8016302b  size 228 B
 * body sha256 fd998ff73d4b7c7ca26022ef85ac580c571f23c68eae9cd292662465f8db14e3
 * provider record sha256 290c4ac9e4f640a147cf40152e721ad1cf582d5d0ce5a7138b304bc66fe634fc
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162f48(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x4000700;
    *(undefined2 *)(param_1 + 0x1e2) = 0xffd8;
    *(undefined1 *)(param_1 + 0x2b5) = 0;
    *(undefined1 *)(param_1 + 6) = 1;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  cVar1 = *(char *)(param_1 + 0x2b5) + -1;
  *(char *)(param_1 + 0x2b5) = cVar1;
  if (cVar1 == -1) {
    *(undefined1 *)(param_1 + 0x2b5) = 9;
  }
  func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x20);
  func_0x80032bd8(param_1,0,0);
  if (*(short *)(param_1 + 0x1e0) < 300) {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + 2;
  }
  func_0x80089d54(param_1,param_2,param_3,0x200);
  return;
}
