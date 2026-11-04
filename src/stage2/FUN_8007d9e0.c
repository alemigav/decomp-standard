/* FUN_8007d9e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007d9e0  body 0x8007d9e0..0x8007daaf  size 208 B
 * body sha256 faadf0f7c62a51855023790de0ca8629cf6b1d6273676d4b2ea7c3a1c913de50
 * provider record sha256 c15e4d4b26850bd524e4aed98e54a9d6c548ab52374726c9af980b0861b24d3f
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007d9e0(int param_1)

{
  short sVar1;
  short local_10 [4];
  
  local_10[0] = 0;
  local_10[1] = 3;
  local_10[2] = 6;
  if (*(char *)(param_1 + 6) == '\0') {
    sVar1 = local_10[*(char *)(param_1 + 0x1ed)];
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e0) = 0;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(int *)(param_1 + 0x1e8) = sVar1 * 0x1000000 + 0x700;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  FUN_80089d54(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220),0x200);
  if ((**(uint **)(param_1 + 0x214) & 0x4000) != 0) {
    FUN_80077f30(0,((**(uint **)(param_1 + 0x214) & 0x2000) >> 0xd) * 3 + 4,param_1);
  }
  return;
}
