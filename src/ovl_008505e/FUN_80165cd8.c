/* FUN_80165cd8
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165cd8  body 0x80165cd8..0x80165dd3  size 252 B
 * body sha256 180b296b7ce47c629f6261ed3fa2642c8a02fa12878d6b3f6c3e673be3048926
 * provider record sha256 d29b4ad6d7980b360b79777dbe199e7a0d231c1f88da027f0ea1fe6750f4a106
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165cd8(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined1 uVar2;
  
  if ((((*(char *)(param_1 + 0x2b5) == '\0') || (*(char *)(param_1 + 0x2be) == '\0')) ||
      (uVar1 = func_0x80033604(), (uVar1 & 5) == 0)) || (2 < *(byte *)(param_1 + 0x26e))) {
    *(undefined1 *)(param_1 + 5) = 1;
    FUN_80165b38(param_1,param_2,param_3);
  }
  else {
    func_0x80035b84(param_1);
    *(undefined2 *)(param_1 + 6) = 0x100;
    FUN_80165dd4(param_1);
    if (*(char *)(param_1 + 0x2c3) == '\0') {
      uVar2 = func_0x80033144(param_1,0x800e1130);
      FUN_80166ac8(0,uVar2);
    }
    *(undefined1 *)(param_1 + 699) = 0x12;
    *(undefined4 *)(param_1 + 0x1e8) = 0x11000700;
    func_0x80089d54(param_1,param_2,param_3,0x200);
  }
  return;
}
