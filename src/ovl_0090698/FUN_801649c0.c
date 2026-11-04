/* FUN_801649c0
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801649c0  body 0x801649c0..0x80164a77  size 184 B
 * body sha256 b3cac75d5cda2141b79b1ef9337dd095055101f7483d0f6d7347c87645f4f823
 * provider record sha256 5946b91a0c691593043995446c1237274f671dc008d06b2f30612c0a23207cd8
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801649c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 0x2d8) != '\x01') {
    FUN_8016703c(param_1,1,0);
  }
  if (*(char *)(param_1 + 0x2d2) == '\0') {
    *(undefined1 *)(param_1 + 0x2cd) = 1;
    *(undefined4 *)(param_1 + 4) = 0x1040000;
  }
  else {
    *(uint *)(param_1 + 4) =
         (uint)*(byte *)(param_1 + 0x2cf) * 0x10000 + (uint)*(byte *)(param_1 + 0x2d0) * 0x100 +
         (uint)*(byte *)(param_1 + 0x2d1) + 0x1000000;
    FUN_80162148(param_1,param_2,param_3);
  }
  return;
}
