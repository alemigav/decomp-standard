/* FUN_8016b594
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016b594  body 0x8016b594..0x8016b62f  size 156 B
 * body sha256 3255802a6c702184c745c4ae394b60b79cc56f43dc04784cda171d6bbb01139f
 * provider record sha256 a68c09861d6c397cc1f831752772beb7a1ac0e2bfa2a4372daa9324db3f131be
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016b594(int param_1)

{
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(uint *)(param_1 + 0x1e8) = (uint)*(byte *)(param_1 + 0x2b4) * 0x1000000 + 0xf00;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x24);
  func_0x800334c8(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0);
  func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0x100);
  func_0x80032b5c(param_1,0);
  return;
}
