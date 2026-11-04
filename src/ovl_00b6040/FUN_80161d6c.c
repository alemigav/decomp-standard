/* FUN_80161d6c
 * image   ovl_00b6040 (ovl), base 0x80161cf0
 * address 0x80161d6c  body 0x80161d6c..0x80161deb  size 128 B
 * body sha256 9395ee361c8177bbd3d7f8a56ad86a846fd712121b9dd092a8f642721ad65db3
 * provider record sha256 50de22a386cba4460458f4620db97b411c67d3c9b76302506d7a306d671dd037
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80161d6c(uint *param_1)

{
  param_1[1] = 0x2000000;
  param_1[0x7a] = 0;
  func_0x80089d54(param_1,param_1[0x69],param_1[0x86],0);
  *(undefined1 *)((int)param_1 + 0x25d) = 0;
  param_1[0xa1] = 0;
  func_0x800339dc(param_1 + 0x82,0,0,0,param_1 + 10);
  *(undefined1 *)(param_1[0x82] + 0xe) = 0;
  *param_1 = *param_1 | 10;
  *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x4000;
  return;
}
