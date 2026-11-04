/* FUN_801665d0
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x801665d0  body 0x801665d0..0x8016669f  size 208 B
 * body sha256 d42947b4a119013639c92df7d4caa400c348b7d29c84ec8ba6a5ac444f95c7af
 * provider record sha256 a3cf1dc652461a2e6b8669ddc16cfb094300882a289fd3f4f2aa4552c6767044
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801665d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x11000f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x1e0) = 0xb;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  if (*(char *)(param_1 + 0x1e9) == '\n') {
    func_0x80037780(0xa001000,(int)*(short *)(param_1 + 0x66),*(int *)(param_1 + 0x234) + 0xbf8,0);
    func_0x80077d18(5,param_1);
  }
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    *(undefined1 *)(param_1 + 0x2da) = 0x3c;
  }
  return;
}
