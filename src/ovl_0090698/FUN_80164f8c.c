/* FUN_80164f8c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80164f8c  body 0x80164f8c..0x80165037  size 172 B
 * body sha256 84c136858d5f171659ee423a30c8adfe1b443f077d7ca8f33be8477d2474cd2b
 * provider record sha256 b1f6696f7ed9544c583bb03f6961e54372f865b3902ea410c26dc5951ea38c6e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164f8c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_80164c34();
  func_0x80089d54(param_1,param_2,param_3,0x400);
  *(undefined2 *)(param_1 + 0x78) = 0x1e0;
  *(undefined2 *)((int)param_1 + 0x1e2) = 0;
  *(undefined2 *)(param_1 + 0x79) = 0;
  if ((param_1[0xb3] & 0x1000000) == 0) {
    *(undefined2 *)((int)param_1 + 0x1f6) = 0;
    *(short *)(param_1 + 0x7d) = -*(short *)(param_1 + 0x19);
  }
  else {
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *(ushort *)((int)param_1 + 0x1f6) =
         (ushort)*(byte *)(param_1 + 0xb3) * 0x400 - *(short *)((int)param_1 + 0x66);
  }
  *param_1 = *param_1 & 0xe3ffffff;
  return;
}
