/* FUN_801627f0
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x801627f0  body 0x801627f0..0x8016289b  size 172 B
 * body sha256 f43d4f6d1abebeddbb3586e26833a0ee445e520d5676de53540af32e5db2c154
 * provider record sha256 72ad7cd9739b638f0d496cdc0f75b5966b2625dc0afff0721bb083a809b80cc0
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801627f0(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 0x2c7) = 1;
    *(undefined2 *)(param_1 + 0x2c2) = 0x400;
    uVar1 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = (uVar1 & 7) << 0x10;
    func_0x80089d54(param_1,param_2,param_3,0x200);
    if ((*(char *)(param_1 + 0x2bf) == '\x01') && (*(char *)(param_1 + 0x2c6) == '\0')) {
      *(undefined4 *)(param_1 + 4) = 0x2020000;
      *(undefined1 *)(param_1 + 0x2be) = 0;
      *(undefined1 *)(param_1 + 0x206) = 1;
    }
  }
  FUN_8016375c(param_1,0);
  return;
}
