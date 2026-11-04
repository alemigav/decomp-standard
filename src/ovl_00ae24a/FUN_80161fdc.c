/* FUN_80161fdc
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x80161fdc  body 0x80161fdc..0x801623af  size 980 B
 * body sha256 77df310dd22201ae99137de66f6f4b240fdeebc28da004542825e3012e1225d6
 * provider record sha256 a26ca65dedec255f242200b32878e27028a7586a66cb743f795683eafd770b65
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80161fdc(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  param_1[1] = 0x1000000;
  *(undefined2 *)((int)param_1 + 0x1f2) = 600;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  *(undefined1 *)((int)param_1 + 0x26f) = 0;
  if ((_DAT_800e10ec & 0x20) != 0) {
    *(undefined2 *)((int)param_1 + 0x1f2) = 400;
  }
  *(undefined1 *)((int)param_1 + 0x1ed) = 0x82;
  *(undefined1 *)((int)param_1 + 0x1ee) = 0x82;
  *(undefined1 *)((int)param_1 + 0x1ef) = 0x82;
  *(undefined1 *)(param_1 + 0x97) = 1;
  *(undefined1 *)((int)param_1 + 0x25d) = 1;
  uVar1 = param_1[0x8d];
  *(undefined2 *)((int)param_1 + 0x66) = 0;
  *(undefined2 *)(uVar1 + 0x2ac) = 8;
  *(undefined2 *)(uVar1 + 0x2ae) = 8;
  *(undefined2 *)(uVar1 + 0x2b0) = 0xd4;
  *(undefined2 *)(uVar1 + 0x2b2) = 0xd4;
  *(undefined2 *)(uVar1 + 0x2a8) = 0;
  *(undefined2 *)(uVar1 + 0x2aa) = 0;
  param_1[0xa3] = 30000;
  *(undefined1 *)(param_1 + 0xad) = 0;
  *(undefined1 *)((int)param_1 + 0x2b5) = 0;
  *(undefined1 *)((int)param_1 + 0x2b6) = 0;
  *(undefined2 *)(param_1 + 0xae) = 0;
  *(undefined1 *)((int)param_1 + 0x2b7) = 0;
  *(undefined1 *)((int)param_1 + 0x2bf) = 0;
  *(undefined1 *)(param_1 + 0xb0) = 0;
  *(undefined1 *)((int)param_1 + 0x2c1) = 0;
  *(undefined1 *)(param_1 + 0xb1) = 0;
  *(undefined1 *)((int)param_1 + 0x2c5) = 0;
  DAT_80166f54 = 0;
  DAT_80166f55 = 0;
  DAT_80166f56 = 0;
  DAT_80166f57 = 0;
  DAT_80166f58 = 0;
  DAT_80166f5a = 0;
  DAT_80166f5c = 0;
  DAT_80166f5e = 0;
  DAT_80166f70 = 0;
  DAT_80166f71 = 0;
  DAT_80166f72 = 0;
  DAT_80166f73 = 0;
  DAT_80166f74 = 0;
  DAT_80166f76 = 0;
  DAT_80166f78 = 0;
  DAT_80166f7a = 0;
  *(undefined2 *)(param_1 + 0x4c) = 0xf830;
  *(undefined2 *)(param_1 + 0x4d) = 0xfa24;
  *(undefined2 *)(param_1 + 0x55) = 0xfa24;
  uVar1 = *param_1;
  *(undefined2 *)((int)param_1 + 0x136) = 6000;
  *(undefined2 *)(param_1 + 0x4e) = 6000;
  *(undefined2 *)(param_1 + 0x4b) = 6000;
  *(undefined2 *)((int)param_1 + 0x12e) = 6000;
  *(undefined2 *)(param_1 + 0x54) = 0x898;
  *(undefined2 *)((int)param_1 + 0x156) = 0x514;
  *(undefined2 *)(param_1 + 0x56) = 0x514;
  *(undefined2 *)(param_1 + 0x53) = 0x514;
  *(undefined2 *)((int)param_1 + 0x14e) = 0x514;
  param_1[0xa1] = 2;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  *(undefined2 *)((int)param_1 + 0x13a) = 0x5dc;
  *(undefined2 *)((int)param_1 + 0x152) = 0;
  *(undefined2 *)((int)param_1 + 0x15a) = 0x5dc;
  *(undefined2 *)((int)param_1 + 0x28a) = 0x1644;
  param_1[0x7a] = 0;
  *param_1 = uVar1 | 8;
  *param_1 = uVar1 | 10;
  *param_1 = uVar1 | 0xc00000a;
  func_0x80089d54(param_1,param_2,param_3,0x100);
  *(code **)((*(byte *)(param_1 + 2) - 0x10) * 4 + -0x7ff206b8) = FUN_8016534c;
  *(code **)((*(byte *)(param_1 + 2) - 0x10) * 4 + -0x7ff205b8) = FUN_80165390;
  *param_1 = *param_1 | 4;
  func_0x800339dc(param_1 + 0x82,0,0xfa00fa0,0,param_1[0x8d] + 0x4c);
  *(uint *)param_1[0x8d] = *(uint *)param_1[0x8d] | 0x4000;
  if (*(int *)(_DAT_800e13f4 + 0x2c) == 0) {
    _DAT_800df934 = FUN_80165568(param_1,_DAT_800df934);
  }
  param_1[0xa9] = (uint)FUN_80161fc0;
  *(undefined4 *)(param_1[0x8d] + 0xcc) = 0x808080ff;
  *(undefined4 *)(param_1[0x8d] + 0x244) = 0x808080ff;
  uVar1 = param_1[0x8d];
  *(undefined4 *)(uVar1 + 0x3bc) = 0x808080ff;
  uVar3 = param_1[0x8d];
  *(undefined4 *)(uVar1 + 0x2f0) = 1;
  *(undefined4 *)(uVar1 + 0x30c) = 0x708;
  *(undefined4 *)(uVar1 + 0x310) = 0x1194;
  *(undefined4 *)(uVar1 + 0x314) = 0;
  *(uint *)(uVar1 + 0x354) = uVar3 + 0x38;
  *(uint *)(uVar1 + 0x41c) = uVar3;
  uVar1 = param_1[0x8d];
  *(undefined4 *)(uVar1 + 0x534) = 0x808080ff;
  uVar3 = param_1[0x8d];
  *(undefined4 *)(uVar1 + 0x468) = 1;
  *(undefined4 *)(uVar1 + 0x484) = 800;
  *(undefined4 *)(uVar1 + 0x488) = 500;
  *(undefined4 *)(uVar1 + 0x48c) = 0;
  *(uint *)(uVar1 + 0x4cc) = uVar3 + 0x38;
  *(uint *)(uVar1 + 0x594) = uVar3;
  uVar1 = param_1[0x8d];
  *(undefined4 *)(uVar1 + 0x6ac) = 0x808080ff;
  uVar3 = param_1[0x8d];
  *(undefined4 *)(uVar1 + 0x5e0) = 1;
  *(undefined4 *)(uVar1 + 0x5fc) = 0x6a2;
  *(undefined4 *)(uVar1 + 0x600) = 0xfffffa8a;
  *(undefined4 *)(uVar1 + 0x604) = 0;
  iVar4 = uVar3 + 0x2f0;
  iVar2 = uVar3 + 0x328;
  *(int *)(uVar1 + 0x644) = iVar2;
  *(int *)(uVar1 + 0x70c) = iVar4;
  uVar1 = param_1[0x8d];
  *(undefined4 *)(uVar1 + 0x824) = 0x808080ff;
  *(undefined4 *)(uVar1 + 0x758) = 1;
  *(undefined4 *)(uVar1 + 0x774) = 0x598;
  *(undefined4 *)(uVar1 + 0x778) = 0xfffff57d;
  *(int *)(uVar1 + 0x7bc) = iVar2;
  *(int *)(uVar1 + 0x884) = iVar4;
  *(undefined4 *)(uVar1 + 0x77c) = 0x3ff;
  uVar1 = param_1[0x8d];
  *(undefined4 *)(uVar1 + 0x99c) = 0x808080ff;
  *(undefined4 *)(uVar1 + 0x8d0) = 1;
  *(undefined4 *)(uVar1 + 0x8ec) = 0x596;
  *(undefined4 *)(uVar1 + 0x8f0) = 0xfffff714;
  *(int *)(uVar1 + 0x934) = iVar2;
  *(int *)(uVar1 + 0x9fc) = iVar4;
  *(undefined4 *)(uVar1 + 0x8f4) = 0xfffff7e2;
  uVar1 = param_1[0x8d];
  *(undefined2 *)(*(int *)(uVar1 + 0x410) + 0xc) = 0;
  *(undefined2 *)(*(int *)(uVar1 + 0x410) + 0x10) = 0;
  func_0x80066288(param_1,uVar1 + 0x2f0);
  *(undefined1 *)((int)param_1 + 5) = 2;
  return;
}
