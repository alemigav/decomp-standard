/* FUN_80161de0
 * image   ovl_0093aba (ovl), base 0x80161cf0
 * address 0x80161de0  body 0x80161de0..0x801621a7  size 968 B
 * body sha256 5c49a9c666191889358f103774bf2920901cf74ec4cbfcab882572eb91e8cf3f
 * provider record sha256 e543ce20d32cc69d23d8e8ea231d913c57b585b6b531478f400c7ae2a7c9e3e7
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80161de0(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  short local_40;
  short local_3e;
  short local_3c;
  
  param_1[1] = 0x1000000;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  *(undefined1 *)((int)param_1 + 0x26f) = 0;
  *(undefined2 *)(param_1 + 0x78) = 0x96;
  uVar1 = func_0x80033604();
  *(ushort *)((int)param_1 + 0x1f2) = (uVar1 & 1) + 1;
  *(undefined2 *)(param_1 + 0x78) = 0x50;
  *(undefined2 *)(param_1 + 0x4d) = 0xff38;
  *(undefined2 *)((int)param_1 + 0x136) = 200;
  *(undefined2 *)((int)param_1 + 0x13a) = 200;
  *(undefined2 *)(param_1 + 0x4e) = 200;
  *(undefined2 *)(param_1 + 0x4b) = 200;
  *(undefined2 *)((int)param_1 + 0x12e) = 200;
  *(undefined2 *)((int)param_1 + 0x28a) = 300;
  param_1[0xa1] = 1;
  *(undefined1 *)(param_1 + 0x97) = 0;
  *(undefined1 *)((int)param_1 + 0x25d) = 0;
  *(undefined2 *)(param_1 + 0xb2) = 0;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  param_1[0x7a] = 0;
  *param_1 = *param_1 | 0x400000;
  uVar2 = *param_1;
  *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x2000;
  *param_1 = uVar2 | 2;
  *param_1 = uVar2 | 0x4000002;
  func_0x80089d54(param_1,param_2,param_3,0x100);
  func_0x800339dc(param_1 + 0x82,0,0x12c0190,0,param_1[0x8d] + 0x4c);
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0xfff) == 0) {
    param_1[0xa1] = 0;
    *param_1 = *param_1 & 0xfbffffff;
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x4000;
    iVar3 = 10;
    *(byte *)(param_1[0x82] + 0xe) = *(byte *)(param_1[0x82] + 0xe) | 8;
    puVar4 = (uint *)param_1[0x8d];
    do {
      iVar3 = iVar3 + -1;
      *puVar4 = *puVar4 | 0x4000;
      puVar4 = puVar4 + 0x5e;
    } while (iVar3 != 0);
  }
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0xfff) == 1) {
    *(undefined1 *)((int)param_1 + 5) = 3;
    *(undefined1 *)((int)param_1 + 6) = 0;
    *(uint *)(_DAT_800e13f0 + 0x224) = param_1[0x89];
    *(uint *)(_DAT_800e13f0 + 0x228) = param_1[0x8a];
    *param_1 = *param_1 & 0xfbffffff;
    param_1[0xa1] = 0;
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x4000;
    iVar3 = 10;
    *(byte *)(param_1[0x82] + 0xe) = *(byte *)(param_1[0x82] + 0xe) | 8;
    puVar4 = (uint *)param_1[0x8d];
    do {
      iVar3 = iVar3 + -1;
      *puVar4 = *puVar4 | 0x4000;
      puVar4 = puVar4 + 0x5e;
    } while (iVar3 != 0);
  }
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0xfff) == 2) {
    *(undefined1 *)((int)param_1 + 5) = 6;
    *param_1 = *param_1 & 0xfbffffff;
    *(uint *)(param_1[0x8d] + 0x5e0) = *(uint *)(param_1[0x8d] + 0x5e0) | 0x4000;
    *(uint *)(param_1[0x8d] + 0x758) = *(uint *)(param_1[0x8d] + 0x758) | 0x4000;
    *(uint *)(param_1[0x8d] + 0x8d0) = *(uint *)(param_1[0x8d] + 0x8d0) | 0x4000;
    *(uint *)(param_1[0x8d] + 0xa48) = *(uint *)(param_1[0x8d] + 0xa48) | 0x4000;
    *(uint *)(param_1[0x8d] + 0xbc0) = *(uint *)(param_1[0x8d] + 0xbc0) | 0x4000;
    *(uint *)(param_1[0x8d] + 0xd38) = *(uint *)(param_1[0x8d] + 0xd38) | 0x4000;
    *(uint *)(param_1[0x8d] + 0x178) = *(uint *)(param_1[0x8d] + 0x178) | 0x4000;
    iVar3 = *(int *)(_DAT_800e13f0 + 0x234);
    local_40 = 0;
    local_3e = 0x32;
    local_3c = 0;
    func_0x8004276c(iVar3 + 0x618,&local_40,&local_40);
    param_1[10] = (int)local_40 + *(int *)(iVar3 + 0x62c);
    param_1[0xb] = (int)local_3e + *(int *)(iVar3 + 0x630);
    iVar3 = *(int *)(iVar3 + 0x634);
    *param_1 = *param_1 | 0x800;
    *(undefined2 *)((int)param_1 + 0x212) = 0x800;
    *(undefined1 *)((int)param_1 + 0x26f) = 0x80;
    param_1[0xc] = local_3c + iVar3;
  }
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0xfff) == 3) {
    *(undefined1 *)((int)param_1 + 5) = 1;
    uVar1 = func_0x80033604();
    *(ushort *)((int)param_1 + 0x1f2) = (uVar1 & 1) + 2;
  }
  *(code **)((*(byte *)(param_1 + 2) - 0x10) * 4 + -0x7ff206b8) = FUN_80165078;
  *(code **)((*(byte *)(param_1 + 2) - 0x10) * 4 + -0x7ff205b8) = FUN_8016535c;
  return;
}
