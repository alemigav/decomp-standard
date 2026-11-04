/* FUN_801651c0
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801651c0  body 0x801651c0..0x80165233  size 116 B
 * body sha256 4d1446019832ff918d3ffd1e8f87afc7bfde26d294f2e2f8bb4804ff0e1e15b9
 * provider record sha256 ddb1333edb41930e4eb7aec715d36e5d126d1a464a08b280bcd6d36e98a0ce0c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801651c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x160f0300;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
  }
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x400);
  if (iVar1 != 0) {
    FUN_80165a5c(param_1,1);
    *(undefined1 *)(param_1 + 0x2bf) = 0;
    *(undefined4 *)(param_1 + 4) = 0x1020000;
  }
  return;
}
