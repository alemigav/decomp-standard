/* FUN_80166018
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80166018  body 0x80166018..0x801660df  size 200 B
 * body sha256 500d6a81227f85dc33faac7d9c3f5063d76728705377788e382b361cbba55807
 * provider record sha256 aff0ad16ca4fa968e84a2f159e6672d83552009b3d49cbb92664cfb0a645191b
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166018(int param_1)

{
  uint uVar1;
  
  if ((*(char *)(param_1 + 5) == '\t') && (2 < *(byte *)(param_1 + 0x26e))) {
    FUN_80165b38();
  }
  else {
    *(undefined1 *)(param_1 + 0x2cd) = 1;
    FUN_80165b38(param_1);
    FUN_80165dd4(param_1);
    if (*(char *)(param_1 + 5) == '\t') {
      *(undefined1 *)(param_1 + 699) = 1;
      uVar1 = func_0x80033604();
      if ((*(uint *)(*(int *)(param_1 + 0x234) + (uVar1 & 0xf) * 0x178) & 0x4a) == 0) {
        FUN_80166980(param_1,uVar1 & 0xf,7);
      }
    }
    *(undefined1 *)(param_1 + 699) = 0x12;
  }
  return;
}
