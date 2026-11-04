/* FUN_801632e8
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801632e8  body 0x801632e8..0x801633b3  size 204 B
 * body sha256 c1b84ffa2197162f328cf122b248906a26b7bc0ed004a6e8239ba0f16f0ba286
 * provider record sha256 049d601e3c9afea1b0fffeafdc58d143aa73134fcf83b7fdeaeb75770323fb1e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801632e8(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined1 *)(param_1 + 6) = 1;
  *(undefined1 *)(param_1 + 0x2b9) = 0xf;
  *(uint *)(param_1 + 0x1e8) = ((uint)*(byte *)(param_1 + 0x2cd) * 0xd + 2) * 0x1000000 + 0x3f00;
  *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
  func_0x800334c8();
  func_0x80089d54(param_1,param_2,param_3,0x40);
  *(undefined2 *)(param_1 + 0x1e4) = 0;
  *(undefined2 *)(param_1 + 0x1e0) = 0;
  _DAT_800e1128 = _DAT_800e1128 | 0x40;
  *(undefined1 *)(param_1 + 0x206) = 0;
  *(undefined1 *)(param_1 + 0x2bf) = 0x5a;
  *(undefined1 *)(param_1 + 0x2b6) = 0;
  return;
}
