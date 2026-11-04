/* FUN_80162054
 * image   ovl_00b2d7a (ovl), base 0x80161cf0
 * address 0x80162054  body 0x80162054..0x801620a7  size 84 B
 * body sha256 6ee33e36d3182ab9255789f28385031be0fc7d1ec1f6cf0f93afe3dfe787d839
 * provider record sha256 dcb69a634905f6ad23dde064ee0adc41a9577bf05dbe4ba3d00ced08bf74f656
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162054(int param_1)

{
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x700;
    *(undefined1 *)(param_1 + 6) = 1;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x80089d54();
  return;
}
