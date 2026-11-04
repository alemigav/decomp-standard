/* FUN_801620d0
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x801620d0  body 0x801620d0..0x801626f3  size 1572 B
 * body sha256 6a95a908bfbeb6e664e9c54e6758aec6442254eb0738e305815f96160facde8d
 * provider record sha256 fcb6fb229cdf12249090e933555a1fb6b6972a8a9f54dcf2164dc53d9283a424
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801620d0(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  *(undefined2 *)((int)param_1 + 0x1f2) = 600;
  param_1[1] = 0x1000000;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  *(undefined1 *)((int)param_1 + 0x26f) = 0;
  if ((_DAT_800e10ec & 0x20) != 0) {
    *(undefined2 *)((int)param_1 + 0x1f2) = 0x1c2;
  }
  uVar1 = param_1[0x8d];
  *(undefined1 *)((int)param_1 + 0x1ed) = 0x82;
  *(undefined1 *)((int)param_1 + 0x1ee) = 0x82;
  *(undefined1 *)((int)param_1 + 0x1ef) = 0x82;
  *(undefined1 *)((int)param_1 + 0x25d) = 4;
  *(undefined1 *)(param_1 + 0x97) = 0;
  *param_1 = *param_1 | 0x400000;
  *(undefined2 *)(uVar1 + 0x714) = 0x20;
  *(undefined2 *)(uVar1 + 0x716) = 0x20;
  *(undefined2 *)(uVar1 + 0x718) = 0x32c;
  *(undefined2 *)(uVar1 + 0x71a) = 0x138;
  *(undefined2 *)(uVar1 + 0x710) = 0;
  *(undefined2 *)(uVar1 + 0x712) = 0;
  *(undefined2 *)(param_1 + 0xad) = 10;
  *(undefined2 *)((int)param_1 + 0x2b6) = 0;
  uVar1 = func_0x80033604();
  *(char *)(param_1 + 0xae) = (char)((uVar1 & 0xff) >> 1) + 'x';
  *(undefined1 *)(param_1 + 0xaf) = 6;
  *(undefined1 *)((int)param_1 + 0x2b9) = 0;
  *(undefined1 *)((int)param_1 + 0x2bd) = 0;
  *(undefined1 *)((int)param_1 + 0x2be) = 0;
  *(undefined1 *)((int)param_1 + 0x2bf) = 0;
  *(undefined1 *)(param_1 + 0xb1) = 0;
  DAT_80167fc0 = 0;
  DAT_80167fc1 = 0;
  DAT_80167fc2 = 0;
  DAT_80167fc4 = 0;
  DAT_80167fc6 = 0;
  DAT_80167fc8 = 0;
  DAT_80167fca = 0;
  DAT_80167fcb = 0;
  param_1[0xa1] = 3;
  *(undefined2 *)((int)param_1 + 0x136) = 0x514;
  *(undefined2 *)(param_1 + 0x4e) = 0x514;
  *(undefined2 *)(param_1 + 0x4b) = 0x514;
  *(undefined2 *)((int)param_1 + 0x12e) = 0x514;
  *(undefined2 *)((int)param_1 + 0x2ba) = 0;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  *(undefined2 *)(param_1 + 0x4d) = 0xfa24;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  *(undefined2 *)((int)param_1 + 0x13a) = 0x5dc;
  *(undefined2 *)((int)param_1 + 0x156) = 800;
  *(undefined2 *)((int)param_1 + 0x15a) = 0x5dc;
  *(undefined2 *)(param_1 + 0x56) = 800;
  *(undefined2 *)(param_1 + 0x53) = 800;
  *(undefined2 *)((int)param_1 + 0x14e) = 800;
  *(undefined2 *)(param_1 + 0x54) = 0;
  *(undefined2 *)(param_1 + 0x55) = 0xfa24;
  *(undefined2 *)((int)param_1 + 0x152) = 0;
  *(undefined2 *)((int)param_1 + 0x176) = 800;
  *(undefined2 *)(param_1 + 0x5e) = 800;
  *(undefined2 *)(param_1 + 0x5b) = 800;
  *(undefined2 *)((int)param_1 + 0x16e) = 800;
  *(undefined2 *)((int)param_1 + 0x28a) = 800;
  param_1[0x7a] = 0x1000000;
  *(undefined2 *)((int)param_1 + 0x17a) = 0x5dc;
  *(undefined2 *)(param_1 + 0x5c) = 0;
  *(undefined2 *)(param_1 + 0x5d) = 0xfa24;
  *(undefined2 *)((int)param_1 + 0x172) = 0;
  *param_1 = *param_1 | 0xc000000;
  func_0x80089d54(param_1,param_2,param_3,0x100);
  func_0x800339dc(param_1 + 0x82,0,0x5140514,0,param_1 + 10);
  *(code **)((*(byte *)(param_1 + 2) - 0x10) * 4 + -0x7ff206b8) = FUN_8016780c;
  *(code **)((*(byte *)(param_1 + 2) - 0x10) * 4 + -0x7ff205b8) = FUN_80167ae4;
  uVar1 = param_1[0x8d];
  *param_1 = *param_1 | 4;
  *(uint *)(uVar1 + 0xd38) = *(uint *)(uVar1 + 0xd38) & 0xffffdfbf;
  *(undefined4 *)(uVar1 + 0xd98) = 0x808080;
  *(undefined2 *)(uVar1 + 0xe5c) = 0x1000;
  *(undefined2 *)(uVar1 + 0xe5e) = 0x1000;
  *(undefined2 *)(uVar1 + 0xe60) = 0x1000;
  *(uint *)(uVar1 + 0xeb0) = *(uint *)(uVar1 + 0xeb0) & 0xffffddff;
  *(undefined4 *)(uVar1 + 0xf10) = 0x808080;
  *(undefined2 *)(uVar1 + 0xfd4) = 0x1000;
  *(undefined2 *)(uVar1 + 0xfd6) = 0x1000;
  *(undefined2 *)(uVar1 + 0xfd8) = 0x1000;
  *(uint *)(uVar1 + 0x1028) = *(uint *)(uVar1 + 0x1028) & 0xffffddff;
  *(undefined4 *)(uVar1 + 0x1088) = 0x808080;
  *(undefined2 *)(uVar1 + 0x114c) = 0x1000;
  *(undefined2 *)(uVar1 + 0x114e) = 0x1000;
  *(undefined2 *)(uVar1 + 0x1150) = 0x1000;
  *(uint *)(uVar1 + 0x11a0) = *(uint *)(uVar1 + 0x11a0) & 0xffffddff;
  *(undefined4 *)(uVar1 + 0x1200) = 0x808080;
  *(undefined2 *)(uVar1 + 0x12c4) = 0x1000;
  *(undefined2 *)(uVar1 + 0x12c6) = 0x1000;
  *(undefined2 *)(uVar1 + 0x12c8) = 0x1000;
  *(uint *)(param_1[0x8d] + 0x2f0) = *(uint *)(param_1[0x8d] + 0x2f0) | 0x4000;
  _DAT_800df934 = func_0x80035dbc(param_1,_DAT_800df934);
  param_1[0xa9] = (uint)FUN_801620b4;
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0xfff) == 1) {
    *(undefined1 *)((int)param_1 + 5) = 1;
    *(undefined2 *)((int)param_1 + 0x1aa) = 0;
    *(ushort *)((int)param_1 + 0x2ba) = *(ushort *)((int)param_1 + 0x2ba) | 0x100;
  }
  else {
    uVar1 = param_1[0x8d];
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x4000;
    *(undefined2 *)(*(int *)(uVar1 + 0x298) + 0xc) = 0x1000;
    *(undefined2 *)(*(int *)(uVar1 + 0x298) + 0x10) = 0;
    func_0x80066288(param_1,uVar1 + 0x178);
    func_0x80066554(param_1,uVar1 + 0x178);
    param_1[0x7a] = 0xc000000;
    func_0x80089d54(param_1,param_2,param_3,0x10100);
    uVar1 = param_1[0x8d];
    *(undefined1 *)((int)param_1 + 5) = 8;
    *(uint *)(uVar1 + 0x2f0) = *(uint *)(uVar1 + 0x2f0) | 0x400;
    *(undefined2 *)(uVar1 + 0x414) = 0;
    *(undefined2 *)(uVar1 + 0x416) = 0x1000;
    *(undefined2 *)(uVar1 + 0x418) = 0x1000;
    uVar1 = param_1[0x8d];
    *(uint *)(uVar1 + 0x468) = *(uint *)(uVar1 + 0x468) | 0xc00;
    *(undefined2 *)(uVar1 + 0x58c) = 0;
    *(undefined2 *)(uVar1 + 0x58e) = 0x1000;
    *(undefined2 *)(uVar1 + 0x590) = 0x1000;
    uVar1 = param_1[0x8d];
    *(uint *)(uVar1 + 0x5e0) = *(uint *)(uVar1 + 0x5e0) | 0xc00;
    *(undefined2 *)(uVar1 + 0x704) = 0;
    *(undefined2 *)(uVar1 + 0x706) = 0x1000;
    *(undefined2 *)(uVar1 + 0x708) = 0x1000;
    uVar1 = param_1[0x8d];
    *(uint *)(uVar1 + 0xd38) = *(uint *)(uVar1 + 0xd38) | 0x400;
    *(undefined2 *)(uVar1 + 0xe5c) = 0x1000;
    *(undefined2 *)(uVar1 + 0xe5e) = 0;
    *(undefined2 *)(uVar1 + 0xe60) = 0x1000;
    uVar1 = param_1[0x8d];
    *(uint *)(uVar1 + 0xeb0) = *(uint *)(uVar1 + 0xeb0) | 0xc00;
    *(undefined2 *)(uVar1 + 0xfd4) = 0x1000;
    *(undefined2 *)(uVar1 + 0xfd6) = 0;
    *(undefined2 *)(uVar1 + 0xfd8) = 0x1000;
    uVar1 = param_1[0x8d];
    *(uint *)(uVar1 + 0x1028) = *(uint *)(uVar1 + 0x1028) | 0xc00;
    *(undefined2 *)(uVar1 + 0x114c) = 0x1000;
    *(undefined2 *)(uVar1 + 0x114e) = 0;
    *(undefined2 *)(uVar1 + 0x1150) = 0x1000;
    uVar1 = param_1[0x8d];
    *(uint *)(uVar1 + 0x11a0) = *(uint *)(uVar1 + 0x11a0) | 0xc00;
    *(undefined2 *)(uVar1 + 0x12c4) = 0x1000;
    *(undefined2 *)(uVar1 + 0x12c6) = 0;
    *(undefined2 *)(uVar1 + 0x12c8) = 0x1000;
    uVar1 = param_1[0x8d];
    *(uint *)(uVar1 + 0x1318) = *(uint *)(uVar1 + 0x1318) | 0x400;
    *(undefined2 *)(uVar1 + 0x143c) = 0x1000;
    *(undefined2 *)(uVar1 + 0x143e) = 0;
    *(undefined2 *)(uVar1 + 0x1440) = 0x1000;
    uVar1 = param_1[0x8d];
    *(uint *)(uVar1 + 0x1490) = *(uint *)(uVar1 + 0x1490) | 0xc00;
    *(undefined2 *)(uVar1 + 0x15b4) = 0x1000;
    *(undefined2 *)(uVar1 + 0x15b6) = 0;
    *(undefined2 *)(uVar1 + 0x15b8) = 0x1000;
    uVar1 = param_1[0x8d];
    *(uint *)(uVar1 + 0x1608) = *(uint *)(uVar1 + 0x1608) | 0xc00;
    *(undefined2 *)(uVar1 + 0x172c) = 0x1000;
    *(undefined2 *)(uVar1 + 0x172e) = 0;
    *(undefined2 *)(uVar1 + 0x1730) = 0x1000;
    uVar1 = param_1[0x8d];
    *(uint *)(uVar1 + 0x1780) = *(uint *)(uVar1 + 0x1780) | 0x400;
    *(undefined2 *)(uVar1 + 0x18a4) = 0x400;
    *(undefined2 *)(uVar1 + 0x18a6) = 0xc00;
    *(undefined2 *)(uVar1 + 0x18a8) = 0x400;
    uVar1 = param_1[0x8d];
    *(uint *)(uVar1 + 0x18f8) = *(uint *)(uVar1 + 0x18f8) | 0xc00;
    *(undefined2 *)(uVar1 + 0x1a1c) = 0x400;
    *(undefined2 *)(uVar1 + 0x1a1e) = 0xc00;
    *(undefined2 *)(uVar1 + 0x1a20) = 0x400;
    uVar1 = param_1[0x8d];
    *(uint *)(uVar1 + 0x1a70) = *(uint *)(uVar1 + 0x1a70) | 0xc00;
    *(undefined2 *)(uVar1 + 0x1b94) = 0x800;
    *(undefined2 *)(uVar1 + 0x1b96) = 0xc00;
    *(undefined2 *)(uVar1 + 0x1b98) = 0x800;
    uVar1 = param_1[0x8d];
    *(uint *)(uVar1 + 0x1be8) = *(uint *)(uVar1 + 0x1be8) | 0xc00;
    *(undefined2 *)(uVar1 + 0x1d0c) = 0x800;
    *(undefined2 *)(uVar1 + 0x1d0e) = 0xc00;
    *(undefined2 *)(uVar1 + 0x1d10) = 0x800;
    uVar1 = param_1[0x8d];
    *(uint *)(uVar1 + 0x1d60) = *(uint *)(uVar1 + 0x1d60) | 0xc00;
    *(undefined2 *)(uVar1 + 0x1e84) = 0x800;
    *(undefined2 *)(uVar1 + 0x1e86) = 0xc00;
    *(undefined2 *)(uVar1 + 0x1e88) = 0x800;
    uVar1 = param_1[0x8d];
    *(uint *)(uVar1 + 0x1ed8) = *(uint *)(uVar1 + 0x1ed8) | 0xc00;
    *(undefined2 *)(uVar1 + 0x1ffc) = 0x800;
    *(undefined2 *)(uVar1 + 0x1ffe) = 0xc00;
    *(undefined2 *)(uVar1 + 0x2000) = 0x800;
    uVar1 = param_1[0x8d];
    *(uint *)(uVar1 + 0x2050) = *(uint *)(uVar1 + 0x2050) | 0xc00;
    *(undefined2 *)(uVar1 + 0x2174) = 0x800;
    *(undefined2 *)(uVar1 + 0x2176) = 0xc00;
    *(undefined2 *)(uVar1 + 0x2178) = 0x800;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 2;
  }
  return;
}
