/* FUN_8007e0a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e0a0  body 0x8007e0a0..0x8007e10b  size 108 B
 * body sha256 3b10c0c51cfabcb51be7d1ad14f49939509af72d755c1bcbc0ba59379e3545f0
 * provider record sha256 557e4f44a794d8e2c41542683e92bc2de9cb4818d410751d72631c36b7447287
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007e0a0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x9010f00;
  }
  iVar1 = FUN_80089d54(param_1,param_2,param_3,0x10100);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    *(undefined1 *)(param_1 + 0x2c6) = 0x1e;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xed;
  }
  return;
}
