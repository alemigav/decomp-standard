/* FUN_80161da4
 * image   ovl_00b2d7a (ovl), base 0x80161cf0
 * address 0x80161da4  body 0x80161da4..0x80161ebb  size 280 B
 * body sha256 b686c9ed6f487641db70e89c04efced070b870f4b491fac8aecd04160770f5e1
 * provider record sha256 8031c3638fe4974349b6e2add98b973a0439b27fa940a396900b0d87d5307757
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80161da4(uint *param_1)

{
  param_1[1] = 0x1000000;
  *(undefined2 *)((int)param_1 + 0x1f2) = 200;
  *(undefined1 *)((int)param_1 + 0x1ed) = 0x82;
  *(undefined1 *)((int)param_1 + 0x1ee) = 0x82;
  *(undefined1 *)((int)param_1 + 0x1ef) = 0x82;
  param_1[0xa1] = 1;
  *(undefined2 *)(param_1 + 0x4d) = 0xfa24;
  *(undefined2 *)((int)param_1 + 0x13a) = 0x5dc;
  *(undefined2 *)((int)param_1 + 0x136) = 800;
  *(undefined2 *)(param_1 + 0x4e) = 800;
  *(undefined2 *)(param_1 + 0x4b) = 800;
  *(undefined2 *)((int)param_1 + 0x12e) = 800;
  *(undefined2 *)((int)param_1 + 0x28a) = 800;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  *(undefined1 *)((int)param_1 + 0x26f) = 0;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  *param_1 = *param_1 | 0xc000000;
  func_0x800339dc(param_1 + 0x82,0,0x2bc0320,0,param_1[0x8d] + 0x4c);
  *(code **)((*(byte *)(param_1 + 2) - 0x10) * 4 + -0x7ff206b8) = FUN_80162290;
  *(code **)((*(byte *)(param_1 + 2) - 0x10) * 4 + -0x7ff205b8) = FUN_80162568;
  *param_1 = *param_1 | 4;
  return;
}
