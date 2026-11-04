/* FUN_80162184
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80162184  body 0x80162184..0x8016250b  size 904 B
 * body sha256 a16c51792e3b5994a2df3c8db5cf31036b4d5d18cc9beb2c54841c26df14b080
 * provider record sha256 f8bed42196326161ae22fa3572dc55cab5fa967f65ef1ab20499abb468417ff1
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162184(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  
  param_1[1] = 0x1000000;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  *(undefined1 *)((int)param_1 + 0x26f) = 0;
  *(undefined2 *)((int)param_1 + 0x1f2) = 1000;
  if ((_DAT_800e10ec & 0x20) != 0) {
    *(undefined2 *)((int)param_1 + 0x1f2) = 900;
  }
  *(undefined1 *)((int)param_1 + 0x1ed) = 0x82;
  *(undefined1 *)((int)param_1 + 0x1ee) = 0x82;
  *(undefined1 *)((int)param_1 + 0x1ef) = 0x82;
  *(undefined1 *)((int)param_1 + 0x25d) = 0x1a;
  uVar1 = param_1[0x8d];
  *(undefined1 *)(param_1 + 0x97) = 0;
  *(undefined2 *)(uVar1 + 0x2764) = 0x10;
  *(undefined2 *)(uVar1 + 0x2766) = 0x20;
  *(undefined2 *)(uVar1 + 0x2768) = 0xe4;
  *(undefined2 *)(uVar1 + 0x276a) = 0xd4;
  *(undefined2 *)(uVar1 + 0x2760) = 0;
  *(undefined2 *)(uVar1 + 0x2762) = 0;
  param_1[0xa1] = 2;
  *(undefined2 *)(param_1 + 0x4c) = 400;
  *(undefined1 *)(param_1 + 0xae) = 0;
  *(undefined1 *)((int)param_1 + 0x2b9) = 0;
  *(undefined1 *)((int)param_1 + 0x2ba) = 0;
  *(undefined2 *)((int)param_1 + 0x2b6) = 0;
  *(undefined1 *)(param_1 + 0xb1) = 0;
  *(undefined1 *)((int)param_1 + 0x2c5) = 0;
  *(undefined2 *)(param_1 + 0xb3) = 0;
  *(undefined1 *)((int)param_1 + 0x2c2) = 0;
  *(undefined1 *)((int)param_1 + 0x2c3) = 0;
  *(undefined1 *)((int)param_1 + 0x2ce) = 0;
  *(undefined1 *)((int)param_1 + 0x2cf) = 0;
  *(undefined2 *)(param_1 + 0xb5) = 0;
  *(undefined1 *)((int)param_1 + 0x2d6) = 0;
  *(undefined1 *)((int)param_1 + 0x2d3) = 0;
  *(undefined1 *)(param_1 + 0xb6) = 0;
  *(undefined2 *)(param_1 + 0x4d) = 0xf830;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  *(undefined2 *)((int)param_1 + 0x136) = 0x44c;
  *(undefined2 *)((int)param_1 + 0x13a) = 2000;
  *(undefined2 *)(param_1 + 0x4e) = 0x44c;
  *(undefined2 *)(param_1 + 0x4b) = 0x44c;
  *(undefined2 *)((int)param_1 + 0x12e) = 0x44c;
  *(undefined2 *)(param_1 + 0x54) = 0;
  *(undefined2 *)(param_1 + 0x55) = 0xf830;
  *(undefined2 *)((int)param_1 + 0x152) = 0;
  *(undefined2 *)((int)param_1 + 0x156) = 1000;
  *(undefined2 *)((int)param_1 + 0x15a) = 2000;
  *(undefined2 *)(param_1 + 0x56) = 1000;
  *(undefined2 *)(param_1 + 0x53) = 1000;
  *(undefined2 *)((int)param_1 + 0x14e) = 1000;
  DAT_8016c3ac = 0;
  DAT_8016c3ad = 0;
  DAT_8016c3ae = 0;
  DAT_8016c3af = 0;
  DAT_8016c3b0 = 0;
  DAT_8016c3b2 = 0;
  DAT_8016c3b4 = 0;
  DAT_8016c3b6 = 0;
  DAT_8016c3c8 = 0;
  DAT_8016c3c9 = 0;
  DAT_8016c3ca = 0;
  DAT_8016c3cb = 0;
  DAT_8016c3cc = 0;
  DAT_8016c3ce = 0;
  DAT_8016c3d0 = 0;
  DAT_8016c3d2 = 0;
  DAT_8016c3e4 = 0;
  DAT_8016c3e5 = 0;
  DAT_8016c3e6 = 0;
  DAT_8016c3e7 = 0;
  DAT_8016c3e8 = 0;
  DAT_8016c3ea = 0;
  DAT_8016c3ec = 0;
  DAT_8016c3ee = 0;
  *(undefined2 *)((int)param_1 + 0x28a) = 800;
  param_1[0x7a] = 0;
  *param_1 = *param_1 | 0x1c000000;
  func_0x80089d54(param_1,param_2,param_3,0x100);
  func_0x800339dc(param_1 + 0x82,0,0x70805dc,0,param_1[0x8d] + 0x4c);
  *(code **)((*(byte *)(param_1 + 2) - 0x10) * 4 + -0x7ff206b8) = FUN_80169bcc;
  *(code **)((*(byte *)(param_1 + 2) - 0x10) * 4 + -0x7ff205b8) = FUN_80169f84;
  *param_1 = *param_1 & 0xffffdfff | 4;
  _DAT_800df934 = FUN_8016ba28(param_1,_DAT_800df934);
  param_1[0xa9] = (uint)FUN_80162158;
  _DAT_800e1354 = param_1[0x89];
  iVar2 = 0x1b;
  _DAT_800e1358 = param_1[0x8a];
  uVar1 = param_1[0x8d];
  _DAT_800e1380 = param_1;
  do {
    iVar2 = iVar2 + -1;
    *(undefined2 *)(*(int *)(uVar1 + 0x120) + 0xc) = 0x1000;
    func_0x80066288(param_1,uVar1);
    uVar1 = uVar1 + 0x178;
  } while (iVar2 != 0);
  func_0x80066554(param_1,param_1[0x8d]);
  *(undefined1 *)((int)param_1 + 5) = 1;
  *(uint *)(param_1[0x8d] + 0x2630) = *(uint *)(param_1[0x8d] + 0x2630) & 0xffffbfff;
  uVar1 = param_1[0x8d];
  *(undefined2 *)((int)param_1 + 0x1aa) = 0;
  *(undefined2 *)(*(int *)(uVar1 + 0xfd0) + 0x10) = 0;
  *(undefined2 *)(*(int *)(uVar1 + 0xfd0) + 0x14) = 0;
  DAT_8016c6c0 = 100;
  *(undefined2 *)(*(int *)(uVar1 + 0xfd0) + 0x18) = 0;
  *(undefined2 *)(*(int *)(uVar1 + 0xfd0) + 0x1c) = 0;
  func_0x80066288(param_1,uVar1 + 0xeb0);
  *(undefined1 *)((int)param_1 + 5) = 0xd;
  *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) | 0x1000;
  *(undefined4 *)((*(byte *)(param_1 + 2) - 0x10) * 4 + -0x7feefac8) = 0x8010f6d0;
  *(undefined1 *)(param_1[0x82] + 0xe) = 0;
  *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x4000;
  return;
}
