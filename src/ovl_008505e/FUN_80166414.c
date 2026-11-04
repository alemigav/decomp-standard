/* FUN_80166414
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80166414  body 0x80166414..0x801664d7  size 196 B
 * body sha256 4d8f3238fc3abc600e684f8154cd4aee6ad9f36222bd06124dc0c76907b26f8f
 * provider record sha256 17b9e5f32b4335b1a95fdf06d10daa8ea144fc7d45f61101755d36ee4e14e765
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166414(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 5) == '\0') {
    *(undefined1 *)(param_1 + 5) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x1f00;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 1;
  }
  else if (*(char *)(param_1 + 5) == '\x01') {
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x800;
    func_0x8003331c(param_1,param_2,param_3,0);
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + -0x800;
    *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x25e);
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x80);
    if (iVar1 != 0) {
      *(undefined1 *)(param_1 + 5) = 2;
    }
  }
  return;
}
