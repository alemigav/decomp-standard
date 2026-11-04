/* FUN_80163138
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80163138  body 0x80163138..0x801632bb  size 388 B
 * body sha256 a00993542e7197f21ea04ca9cd0c3e9f4076787125c1eba6fc363a126a929971
 * provider record sha256 7004b26aa875c688ad033c5946e27ad154a159d422fa5a9118ce0095f7842fa0
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163138(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  uint uVar2;
  short unaff_s5;
  
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    uVar2 = *(uint *)(param_1 + 0x28c);
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x290) & 0x3fffffff;
  }
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x2000f00;
    *(undefined2 *)(param_1 + 0x1e0) = 0x32;
    *(short *)(param_1 + 500) = (short)(((int)uVar2 >> 1) / 0x32);
    *(undefined1 *)(param_1 + 0x2bf) = 0x10;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 100) = 0;
  }
  FUN_8016304c(param_1,param_2,param_3);
  sVar1 = *(short *)(param_1 + 500);
  *(short *)(param_1 + 500) = sVar1 + -1;
  if ((sVar1 == 1) || (unaff_s5 == 0)) {
    *(undefined1 *)(param_1 + 5) = 0xb;
    if (*(char *)(param_1 + 0x2be) == '\0') {
      if (10000 < (int)uVar2) {
        *(undefined1 *)(param_1 + 5) = 1;
      }
    }
    else if (*(char *)(param_1 + 0x2be) == '\x01') {
      if ((int)uVar2 < 0x1771) {
        *(undefined1 *)(param_1 + 0x2c7) = 0;
        *(undefined1 *)(param_1 + 0x2c6) = 1;
      }
      else {
        *(undefined1 *)(param_1 + 5) = 1;
      }
    }
    *(char *)(param_1 + 0x2be) = *(char *)(param_1 + 0x2be) + '\x01';
    *(undefined2 *)(param_1 + 6) = 0;
  }
  FUN_801623ac(param_1);
  func_0x80089d54(param_1,param_2,param_3,0x100);
  func_0x80033648(param_1);
  return;
}
