/* FUN_8007d608
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007d608  body 0x8007d608..0x8007d747  size 320 B
 * body sha256 f1a7d8141cf8c4c3d58753f54d108d1d2415c21eb668859ce646911a20c9f097
 * provider record sha256 fe1dfaa73a5bfeb7eaf0d30faecc7b0fdf6d4959a3cc07cd90333d6e5cb748ae
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007d608(int param_1)

{
  byte bVar1;
  byte local_10 [8];
  
  local_10[0] = 1;
  local_10[1] = 4;
  local_10[2] = 7;
  if (*(char *)(param_1 + 6) == '\0') {
    bVar1 = local_10[*(char *)(param_1 + 0x1ed)];
    *(undefined1 *)(param_1 + 6) = 1;
    *(uint *)(param_1 + 0x1e8) = (uint)bVar1 * 0x1000000 + 0x700;
  }
  else if (*(char *)(param_1 + 6) != '\x01') goto LAB_8007d6d0;
  FUN_800334c8(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220),0);
  FUN_80089d54(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220),0x200);
  if ((**(uint **)(param_1 + 0x214) & 0x4000) != 0) {
    FUN_80077f30(1,((**(uint **)(param_1 + 0x214) & 0x2000) >> 0xd) * 3 + 4,param_1);
  }
LAB_8007d6d0:
  if (*(char *)(param_1 + 0x1ea) != '\0') {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) >> 1;
  }
  if ((int)*(short *)(param_1 + 0x1a8) < *(short *)(param_1 + 0x25e) + -500) {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) - *(short *)(param_1 + 0x1e0) / 3;
  }
  FUN_80032b5c(param_1,0);
  return;
}
