/* FUN_80163a54
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80163a54  body 0x80163a54..0x80163b23  size 208 B
 * body sha256 20f779e1d2c31d5e08f662b52e770970b324636f9b3851079bfded60ba389c37
 * provider record sha256 a064d25f2fcb06c6eb82decd2cddab21cb9791c0c209745b24b3624a68dadf0b
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163a54(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x1e0) = 100;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined4 *)(param_1 + 0x1e8) = 0x2000300;
  }
  if (*(short *)(param_1 + 500) != 0) {
    FUN_80166cbc(param_1,0,0,0);
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + -1;
  }
  func_0x80089d54(param_1,param_2,param_3,0x400);
  FUN_80167938(param_1);
  if (*(short *)(param_1 + 500) == 0) {
    *(undefined2 *)(param_1 + 6) = 0;
    *(undefined1 *)(param_1 + 5) = *(undefined1 *)(param_1 + 0x2cd);
    uVar1 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar1 & 0xf) + 0xf;
  }
  return;
}
