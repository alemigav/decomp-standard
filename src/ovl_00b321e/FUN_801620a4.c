/* FUN_801620a4
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801620a4  body 0x801620a4..0x8016217b  size 216 B
 * body sha256 acde8a5f2fdf231d333b19c0f6d442927c5c6e88d98b496c25b64b6438b65aac
 * provider record sha256 755050293812f77b0801fdbe557f0b59a6104ff2f05cb5e1766766df87b90247
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801620a4(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_80165f44();
  if (*(char *)(param_1 + 0x2c8) != '\0') {
    *(char *)(param_1 + 0x2c8) = *(char *)(param_1 + 0x2c8) + -1;
  }
  (*(code *)(&PTR_FUN_80166670)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  *(undefined1 *)(param_1 + 0x2c0) = *(undefined1 *)(param_1 + 5);
  *(undefined1 *)(param_1 + 0x2c1) = *(undefined1 *)(param_1 + 6);
  *(undefined1 *)(param_1 + 0x2c2) = *(undefined1 *)(param_1 + 7);
  *(undefined2 *)(param_1 + 0x2d0) = *(undefined2 *)(param_1 + 0x1e0);
  *(undefined2 *)(param_1 + 0x2d2) = *(undefined2 *)(param_1 + 0x1e2);
  *(undefined2 *)(param_1 + 0x2d4) = *(undefined2 *)(param_1 + 0x1e4);
  if ((_DAT_800e1128 & 0x20) != 0) {
    *(undefined1 *)(param_1 + 0x2c8) = 0x3c;
  }
  return;
}
