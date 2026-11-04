/* FUN_8007caec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007caec  body 0x8007caec..0x8007cb73  size 136 B
 * body sha256 96b157e410bdfe25ef7fe93f23b0f15abd00d13b01dae55af60ca651da655031
 * provider record sha256 e5dcd0e639f5ced0f1b3bfe89c0b0ae9f2799724e23992537424618aef30ae1f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007caec(int param_1)

{
  ushort uVar1;
  ushort local_10 [4];
  
  local_10[0] = 2;
  local_10[1] = 5;
  local_10[2] = 8;
  if (*(char *)(param_1 + 6) == '\0') {
    uVar1 = local_10[*(char *)(param_1 + 0x1ed)];
    *(undefined1 *)(param_1 + 6) = 1;
    *(uint *)(param_1 + 0x1e8) = (uint)uVar1 * 0x1000000 + 0x700;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  FUN_80089d54(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220),0x200);
  return;
}
