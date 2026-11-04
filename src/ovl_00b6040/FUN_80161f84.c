/* FUN_80161f84
 * image   ovl_00b6040 (ovl), base 0x80161cf0
 * address 0x80161f84  body 0x80161f84..0x8016201b  size 152 B
 * body sha256 f2d2d6b1ff35950886073bbf760133b21dd345ebe3acee0671deccef0ae86266
 * provider record sha256 371d7e2c44a5e2e2a7deccee29bbae58161a8ea03829273b190ab6457814a636
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80161f84(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 5) == '\0') {
    iVar1 = *(int *)(param_1 + 0x234);
    *(undefined4 *)(param_1 + 0x1e8) = 0x3b0000;
    *(undefined4 *)(iVar1 + 0x198) = 0x5e;
    *(undefined4 *)(iVar1 + 0x310) = 0xffffff99;
    *(undefined4 *)(iVar1 + 0x600) = 0x70;
    *(undefined4 *)(iVar1 + 0x8f0) = 0x70;
    *(undefined4 *)(iVar1 + 0xbe0) = 0x70;
    *(undefined4 *)(iVar1 + 0xed0) = 0x70;
    *(char *)(param_1 + 5) = *(char *)(param_1 + 5) + '\x01';
  }
  else if (*(char *)(param_1 + 5) != '\x01') {
    return;
  }
  iVar1 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),
                          0);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x2000000;
  }
  return;
}
