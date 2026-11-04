/* FUN_8007e114
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e114  body 0x8007e114..0x8007e167  size 84 B
 * body sha256 34241e25257d3ec6598fcb362085a624f854a35fada9d5fe71e21a7bb120e3a6
 * provider record sha256 204f26ec6b4a5a950c4a160bebb1140ca3639a1e77cc994b6e739de5d6839a6a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007e114(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x10000700;
  }
  iVar1 = FUN_80089d54(param_1,param_2,param_3,0x200);
  if (iVar1 != 0) {
    *(undefined2 *)(param_1 + 6) = 0x100;
  }
  return;
}
