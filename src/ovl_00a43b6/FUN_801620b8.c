/* FUN_801620b8
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x801620b8  body 0x801620b8..0x801625af  size 1272 B
 * body sha256 0e8ba6d494de9413d6cb13dd7cba85322aaf5ca93c698a88142ad099b963c08f
 * provider record sha256 218dfe4329c46a71b88fcd200f4106c43bce3398ec4d617326edec98ba515ed2
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801620b8(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  
  param_1[1] = 0x1000000;
  *(undefined2 *)((int)param_1 + 0x1f2) = 700;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  *(undefined1 *)((int)param_1 + 0x26f) = 0;
  if ((_DAT_800e10ec & 0x20) != 0) {
    *(undefined2 *)((int)param_1 + 0x1f2) = 600;
  }
  uVar2 = param_1[0x8d];
  *(undefined1 *)((int)param_1 + 0x25d) = 3;
  *(undefined1 *)((int)param_1 + 0x1ed) = 0;
  *(undefined1 *)((int)param_1 + 0x1ee) = 0;
  *(undefined1 *)((int)param_1 + 0x1ef) = 0;
  *(undefined1 *)(param_1 + 0x97) = 0;
  *(undefined2 *)(uVar2 + 0x59c) = 0x20;
  *(undefined2 *)(uVar2 + 0x59e) = 0x20;
  *(undefined2 *)(uVar2 + 0x5a0) = 0x264;
  *(undefined2 *)(uVar2 + 0x5a2) = 0x138;
  *(undefined2 *)(uVar2 + 0x598) = 0;
  *(undefined2 *)(uVar2 + 0x59a) = 0;
  *(undefined1 *)((int)param_1 + 0x2b7) = 5;
  *(undefined2 *)(param_1 + 0xb0) = 2000;
  *(undefined1 *)(param_1 + 0xad) = 0;
  *(undefined1 *)((int)param_1 + 0x2b5) = 0;
  *(undefined1 *)((int)param_1 + 0x2b6) = 0;
  *(undefined1 *)((int)param_1 + 0x2ba) = 0;
  *(undefined1 *)(param_1 + 0xaf) = 0;
  *(undefined1 *)((int)param_1 + 0x2bd) = 0;
  *(undefined1 *)((int)param_1 + 0x2c2) = 0;
  *(undefined1 *)((int)param_1 + 0x2c3) = 0;
  *(undefined1 *)(param_1 + 0xb1) = 0;
  DAT_801697e0 = 0;
  DAT_801697e1 = 0;
  DAT_801697e2 = 0;
  DAT_801697e4 = 0;
  DAT_801697e6 = 0;
  DAT_801697e8 = 0;
  DAT_801697ea = 0;
  DAT_801697eb = 0;
  param_1[0xa1] = 1;
  *(undefined2 *)(param_1 + 0xae) = 0;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  *(undefined2 *)(param_1 + 0x4d) = 0xfa24;
  *(undefined2 *)((int)param_1 + 0x13a) = 0x5dc;
  *(undefined2 *)((int)param_1 + 0x28a) = 800;
  *(undefined2 *)((int)param_1 + 0x136) = 900;
  *(undefined2 *)(param_1 + 0x4e) = 900;
  *(undefined2 *)(param_1 + 0x4b) = 900;
  *(undefined2 *)((int)param_1 + 0x12e) = 900;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  param_1[0x7a] = 0;
  *param_1 = *param_1 | 0xc000000;
  func_0x80089d54(param_1,param_2,param_3,0x100);
  func_0x800339dc(param_1 + 0x82,0,0x3200384,0,param_1[0x8d] + 0x4c);
  iVar3 = 0x12;
  *(code **)((*(byte *)(param_1 + 2) - 0x10) * 4 + -0x7ff206b8) = FUN_801689a0;
  *(code **)((*(byte *)(param_1 + 2) - 0x10) * 4 + -0x7ff205b8) = FUN_80168ab0;
  uVar2 = param_1[0x8d];
  *param_1 = *param_1 | 4;
  do {
    *(undefined4 *)(uVar2 + 0x60) = 0x808080;
    iVar3 = iVar3 + -1;
    uVar2 = uVar2 + 0x178;
  } while (iVar3 != 0);
  uVar2 = param_1[0x8d];
  *(undefined2 *)(*(int *)(uVar2 + 0x298) + 0xc) = 0;
  func_0x80066288(param_1,uVar2 + 0x178);
  uVar2 = param_1[0x8d];
  *(undefined2 *)(*(int *)(uVar2 + 0x410) + 0xc) = 0;
  *(undefined2 *)(*(int *)(uVar2 + 0x410) + 0x10) = 0;
  func_0x80066288(param_1,uVar2 + 0x2f0);
  *(undefined1 *)((int)param_1 + 5) = 7;
  param_1[0x7a] = 0x13000000;
  func_0x80089d54(param_1,param_2,param_3,0x100);
  uVar2 = param_1[0x8d];
  *(undefined2 *)(*(int *)(uVar2 + 0x410) + 0xc) = 0x1000;
  *(undefined2 *)(*(int *)(uVar2 + 0x410) + 0x10) = 0;
  func_0x80066288(param_1,uVar2 + 0x2f0);
  uVar2 = param_1[0x8d];
  *(undefined2 *)(*(int *)(uVar2 + 0x700) + 0xc) = 0x1000;
  func_0x80066288(param_1,uVar2 + 0x5e0);
  uVar2 = param_1[0x8d];
  *(uint *)(uVar2 + 0x8d0) = *(uint *)(uVar2 + 0x8d0) | 0x400;
  *(undefined2 *)(uVar2 + 0x9f4) = 0x800;
  *(undefined2 *)(uVar2 + 0x9f6) = 0x200;
  *(undefined2 *)(uVar2 + 0x9f8) = 0x800;
  uVar2 = param_1[0x8d];
  *(uint *)(uVar2 + 0xa48) = *(uint *)(uVar2 + 0xa48) | 0x400;
  *(undefined2 *)(uVar2 + 0xb6c) = 0x800;
  *(undefined2 *)(uVar2 + 0xb6e) = 0x200;
  *(undefined2 *)(uVar2 + 0xb70) = 0x800;
  uVar2 = param_1[0x8d];
  *(uint *)(uVar2 + 0xbc0) = *(uint *)(uVar2 + 0xbc0) | 0x400;
  *(undefined2 *)(uVar2 + 0xce4) = 0x800;
  *(undefined2 *)(uVar2 + 0xce6) = 0x200;
  *(undefined2 *)(uVar2 + 0xce8) = 0x800;
  uVar2 = param_1[0x8d];
  *(uint *)(uVar2 + 0x468) = *(uint *)(uVar2 + 0x468) | 0x400;
  *(undefined2 *)(uVar2 + 0x58c) = 0x1000;
  *(undefined2 *)(uVar2 + 0x58e) = 0x200;
  *(undefined2 *)(uVar2 + 0x590) = 0x1000;
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0xfff) == 2) {
    *(undefined2 *)(param_1 + 0x7d) = 0x3c;
    *(undefined2 *)((int)param_1 + 0x1f2) = 5000;
    *param_1 = *param_1 | 2;
    bVar1 = func_0x80033604();
    *(byte *)((int)param_1 + 0x2c3) = *(byte *)((int)param_1 + 0x2c3) | (bVar1 & 1) << 4;
    *(undefined1 *)(param_1[0x82] + 0xe) = 0;
    iVar3 = 0x12;
    puVar4 = (uint *)param_1[0x8d];
    *(undefined1 *)((int)param_1 + 5) = 0;
    *(undefined1 *)((int)param_1 + 6) = 3;
    do {
      iVar3 = iVar3 + -1;
      *puVar4 = *puVar4 | 0x4000;
      puVar4 = puVar4 + 0x5e;
    } while (iVar3 != 0);
    *(uint *)(param_1[0x8d] + 0x8d0) = *(uint *)(param_1[0x8d] + 0x8d0) & 0xfffffbff;
    *(uint *)(param_1[0x8d] + 0xa48) = *(uint *)(param_1[0x8d] + 0xa48) & 0xfffffbff;
    *(uint *)(param_1[0x8d] + 0xbc0) = *(uint *)(param_1[0x8d] + 0xbc0) & 0xfffffbff;
  }
  iVar3 = 0x12;
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0xfff) == 3) {
    *(undefined2 *)((int)param_1 + 0x1f2) = 5000;
    *param_1 = *param_1 | 10;
    *(undefined1 *)(param_1[0x82] + 0xe) = 0;
    puVar4 = (uint *)param_1[0x8d];
    *(undefined1 *)((int)param_1 + 5) = 9;
    *(undefined1 *)((int)param_1 + 6) = 0;
    do {
      iVar3 = iVar3 + -1;
      *puVar4 = *puVar4 | 0x4000;
      puVar4 = puVar4 + 0x5e;
    } while (iVar3 != 0);
    *(uint *)(param_1[0x8d] + 0x8d0) = *(uint *)(param_1[0x8d] + 0x8d0) & 0xfffffbff;
    *(uint *)(param_1[0x8d] + 0xa48) = *(uint *)(param_1[0x8d] + 0xa48) & 0xfffffbff;
    *(uint *)(param_1[0x8d] + 0xbc0) = *(uint *)(param_1[0x8d] + 0xbc0) & 0xfffffbff;
  }
  return;
}
