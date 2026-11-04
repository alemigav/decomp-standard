/* FUN_80164f14
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80164f14  body 0x80164f14..0x8016502f  size 284 B
 * body sha256 081cd2744598fa1a6654041f1a4203f7ac8e60006ad7c36e820a235d548b6e7f
 * provider record sha256 ea7761a768b9b0714dcccf072967f3e9f2071bce0295a40e51b621964879ea8f
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164f14(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined2 uVar2;
  
  func_0x80032bd8(param_1,(int)*(short *)(param_1 + 500),0);
  *(short *)(param_1 + 0x1e2) = *(short *)(param_1 + 0x1e2) + 0x28;
  if ((int)*(short *)(param_1 + 0x25e) <= *(int *)(param_1 + 0x2c)) {
    *(undefined2 *)(param_1 + 0x1f6) = 0x200;
    *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x25e);
    *(undefined1 *)(param_1 + 0x2b5) = 0;
    *(undefined1 *)(param_1 + 700) = 1;
    FUN_80165a5c(param_1,0);
    uVar1 = func_0x80033604();
    if (((((0x404 >> (uVar1 & 0xf) & 1U) == 0) || ((*(byte *)(param_1 + 0x2bf) & 0x80) != 0)) ||
        (*(short *)(param_1 + 0x1f2) < 0)) || (*(char *)(param_1 + 0x2c9) != '\0')) {
      func_0x80077d18(0xb,param_1);
      uVar2 = 0x200;
    }
    else {
      func_0x80077d18(10,param_1);
      uVar2 = 0x300;
    }
    *(undefined2 *)(param_1 + 6) = uVar2;
  }
  if (*(char *)(param_1 + 0x1e9) != '\x03') {
    func_0x80089d54(param_1,param_2,param_3,0x200);
  }
  return;
}
