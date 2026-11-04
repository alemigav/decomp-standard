/* FUN_80163c44
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80163c44  body 0x80163c44..0x80163d5f  size 284 B
 * body sha256 fc2beefa8d4c13039b514a2140ae3c300e2af6d57d860dcb9791a3eb32223a26
 * provider record sha256 1e96ff3728a3f7f85b8cef8575bd8c175a0284e415291b34389a54f26afceaf9
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163c44(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 7) == '\0') {
    func_0x800334c8();
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x80);
    func_0x80032b5c(param_1,0);
    if (iVar2 != 0) {
      *(undefined1 *)(param_1 + 7) = 1;
      *(undefined2 *)(param_1 + 500) = 2;
      *(undefined4 *)(param_1 + 0x1e8) = 0x19001f00;
      func_0x800334c8(param_1,param_2,param_3,0);
      func_0x80089d54(param_1,param_2,param_3,0x80);
    }
  }
  else {
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x80);
    if ((iVar2 != 0) &&
       (sVar1 = *(short *)(param_1 + 500), *(short *)(param_1 + 500) = sVar1 + -1, sVar1 == 1)) {
      *(undefined1 *)(param_1 + 5) = 0xc;
      *(undefined2 *)(param_1 + 6) = 0;
    }
  }
  func_0x80033648(param_1);
  return;
}
