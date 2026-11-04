/* FUN_801671dc
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x801671dc  body 0x801671dc..0x80167227  size 76 B
 * body sha256 a062e2bf51164cb07d6feec10f71b343e93d1fbb879684c1ceccd526ec66a7fe
 * provider record sha256 29cb716ccc111fe4d29b7afa5525597901fb537ed8f928b28ff6bddd1348d8dc
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801671dc(int param_1,int param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(*(int *)(param_1 + 0x234) + (param_2 * -5 + 0x13) * 0x178);
  puVar1[0x4c] = 0x40;
  puVar1[0x4d] = 0x30;
  *puVar1 = *puVar1 | 0x80;
  return;
}
