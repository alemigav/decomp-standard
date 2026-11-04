/* FUN_801651c0
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801651c0  body 0x801651c0..0x80165277  size 184 B
 * body sha256 4c7579af23f7893a9c7a973c51dc6789bcd13c9353a04f8aa45a7239de3e120c
 * provider record sha256 e9181c7fe77e0c385ee6b56ad94184576eded79ef8e1303221c1453495d63ae4
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801651c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_80166270(param_1,0,(&DAT_8016677f)[*(byte *)(param_1 + 5)]);
  func_0x80077d18(6,param_1);
  if (*(char *)(param_1 + 700) == '\0') {
    *(undefined2 *)(param_1 + 6) = 0x200;
    FUN_801652c8(param_1,param_2,param_3);
  }
  else {
    if (*(char *)(param_1 + 0x2c5) != '\0') {
      *(undefined2 *)(param_1 + 0x68) = 0;
      FUN_801665a0(param_1,0);
    }
    *(undefined2 *)(param_1 + 6) = 0x100;
    FUN_801647ac(param_1,param_2,param_3);
  }
  return;
}
