/* FUN_80162540
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x80162540  body 0x80162540..0x8016264b  size 268 B
 * body sha256 ad7ebd1e95a457d71e47a40b82183b528048a1d67c991434670c5bafb5f5b024
 * provider record sha256 feeed880b7ea2aa0f44c85b13686e4c87bc3b920e3d36afdbb769fe0954d4d54
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162540(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = func_0x800837ac(0x800e8d00,0x1f);
  if (iVar1 == 0) {
    if (*(char *)(param_1 + 6) == '\0') {
      *(undefined1 *)(param_1 + 6) = 1;
      *(undefined2 *)(param_1 + 0x1e2) = 0x28;
      *(undefined2 *)(param_1 + 0x68) = 0x200;
      *(undefined2 *)(param_1 + 0x1e4) = 0;
      *(undefined2 *)(param_1 + 0x1e0) = 0;
      *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
      *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xbfff;
    }
    if (*(short *)(param_1 + 0x1e2) < 600) {
      *(short *)(param_1 + 0x1e2) = *(short *)(param_1 + 0x1e2) + 0x28;
    }
    func_0x80032bd8(param_1,0,-(int)*(short *)(param_1 + 0x68));
    if ((int)*(short *)(param_1 + 0x25e) <= *(int *)(param_1 + 0x2c)) {
      *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x25e);
      *(undefined2 *)(param_1 + 0x68) = 0;
      *(undefined1 *)(param_1 + 5) = 0;
      *(undefined2 *)(param_1 + 6) = 0;
      *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
      func_0x80077d18(1,param_1);
    }
    func_0x80089d54(param_1,param_2,param_3,0x80);
  }
  return;
}
