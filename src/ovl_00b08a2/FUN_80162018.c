/* FUN_80162018
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80162018  body 0x80162018..0x80162433  size 1052 B
 * body sha256 51856323d844a1c0f4e052e5c8d3418ce6e700c33e0784e0996cea47348f1327
 * provider record sha256 b0955a321cc593f7d31d9a86d8dfdb3a640890a741803feb3b3a0d44fcafde71
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162018(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 auStack_48 [32];
  
  param_1[1] = 0x1000000;
  *(undefined2 *)((int)param_1 + 0x1f2) = 0xffff;
  *(undefined1 *)((int)param_1 + 0x1ed) = 0x82;
  *(undefined1 *)((int)param_1 + 0x1ee) = 0x82;
  *(undefined1 *)((int)param_1 + 0x1ef) = 0x82;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  *(undefined1 *)((int)param_1 + 0x26f) = 0;
  *(undefined1 *)(param_1 + 0x97) = 0;
  *(undefined1 *)((int)param_1 + 0x25d) = 3;
  *(undefined1 *)((int)param_1 + 0x2b5) = 0;
  *(undefined2 *)(param_1 + 0xaf) = 0;
  *(undefined1 *)((int)param_1 + 0x2be) = 0;
  *(undefined2 *)(param_1 + 0xb0) = 0;
  *(undefined1 *)((int)param_1 + 0x2bf) = 0;
  param_1[0xa1] = 0;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  *(undefined2 *)(param_1 + 0x4d) = 0xfe0c;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  *(undefined2 *)((int)param_1 + 0x136) = 500;
  *(undefined2 *)((int)param_1 + 0x13a) = 500;
  *(undefined2 *)(param_1 + 0x4e) = 500;
  *(undefined2 *)(param_1 + 0x4b) = 500;
  *(undefined2 *)((int)param_1 + 0x12e) = 500;
  *(undefined2 *)(param_1 + 0x54) = 0;
  *(undefined2 *)(param_1 + 0x55) = 0xfe0c;
  *(undefined2 *)((int)param_1 + 0x152) = 0;
  *(undefined2 *)((int)param_1 + 0x156) = 0x4b0;
  *(undefined2 *)((int)param_1 + 0x15a) = 500;
  *(undefined2 *)(param_1 + 0x56) = 0x4b0;
  *param_1 = *param_1 | 8;
  *(undefined2 *)(param_1 + 0x53) = 0x4b0;
  *(undefined2 *)((int)param_1 + 0x14e) = 0x4b0;
  *(undefined2 *)((int)param_1 + 0x176) = 600;
  *(undefined2 *)(param_1 + 0x5e) = 600;
  *(undefined2 *)(param_1 + 0x5b) = 600;
  *(undefined2 *)((int)param_1 + 0x16e) = 600;
  *(undefined2 *)((int)param_1 + 0x196) = 700;
  *(undefined2 *)(param_1 + 0x66) = 700;
  *(undefined2 *)(param_1 + 99) = 700;
  *(undefined2 *)((int)param_1 + 0x18e) = 700;
  *(undefined2 *)(param_1 + 0x5c) = 0;
  *(undefined2 *)(param_1 + 0x5d) = 0xfe0c;
  *(undefined2 *)((int)param_1 + 0x172) = 0;
  *(undefined2 *)((int)param_1 + 0x17a) = 500;
  *(undefined2 *)(param_1 + 100) = 0;
  *(undefined2 *)(param_1 + 0x65) = 0xfe0c;
  *(undefined2 *)((int)param_1 + 0x192) = 0;
  *(undefined2 *)((int)param_1 + 0x19a) = 500;
  func_0x800339dc(param_1 + 0x82,0,0,0,param_1[0x8d] + 0x4c);
  iVar4 = 3;
  iVar1 = -0x7ff38944;
  puVar2 = _DAT_800e13f4;
  while (param_1 != puVar2) {
    iVar4 = iVar4 + 1;
    puVar2 = *(uint **)(iVar1 + 0x19d3c);
    iVar1 = iVar1 + 4;
  }
  *(char *)(param_1 + 0xad) = (char)iVar4 + -3;
  if (*(short *)((int)param_1 + 0x1aa) == 8) {
    param_1[0xa1] = 4;
    *(undefined2 *)((int)param_1 + 0x136) = 800;
    *(undefined2 *)(param_1 + 0x4e) = 800;
    *(undefined2 *)(param_1 + 0x4b) = 800;
    *(undefined2 *)((int)param_1 + 0x12e) = 800;
    *(undefined2 *)((int)param_1 + 0x156) = 600;
    *(undefined2 *)(param_1 + 0x56) = 600;
    *(undefined2 *)(param_1 + 0x53) = 600;
    *(undefined2 *)((int)param_1 + 0x14e) = 600;
    *(undefined2 *)((int)param_1 + 0x176) = 600;
    *(undefined2 *)(param_1 + 0x5e) = 600;
    *(undefined2 *)(param_1 + 0x5b) = 600;
    *(undefined2 *)((int)param_1 + 0x16e) = 600;
    *(undefined2 *)((int)param_1 + 0x196) = 600;
    *(undefined2 *)(param_1 + 0x66) = 600;
    *(undefined2 *)(param_1 + 99) = 600;
    *(undefined2 *)((int)param_1 + 0x18e) = 600;
  }
  else {
    *(undefined2 *)((int)param_1 + 0x28a) = 800;
    param_1[0x7a] = 0;
    func_0x80089d54(param_1,param_2,param_3,0x100);
    *(code **)((*(byte *)(param_1 + 2) - 0x10) * 4 + -0x7ff206b8) = FUN_80165bc4;
    *(code **)((*(byte *)(param_1 + 2) - 0x10) * 4 + -0x7ff205b8) = FUN_801664dc;
    puVar2 = (uint *)param_1[0x8d];
    *param_1 = *param_1 | 0xc;
    *(undefined2 *)((int)puVar2 + 0x126) = 0x1000;
    *(undefined2 *)(puVar2 + 0x4a) = 0x1000;
    *(undefined2 *)((int)puVar2 + 0x29e) = 0x1000;
    *(undefined2 *)(puVar2 + 0xa8) = 0x1000;
    *(undefined2 *)((int)puVar2 + 0x416) = 0x1000;
    *(undefined2 *)(puVar2 + 0x106) = 0x1000;
    *(undefined2 *)((int)puVar2 + 0x58e) = 0x1000;
    *(undefined2 *)(puVar2 + 0x164) = 0x1000;
    puVar2[0x33] = 0x808080ff;
    *(undefined2 *)(puVar2 + 0x49) = 0;
    *(undefined2 *)(puVar2 + 0xa7) = 0;
    *(undefined2 *)(puVar2 + 0x105) = 0;
    *(undefined2 *)(puVar2 + 0x163) = 0;
    *puVar2 = *puVar2 | 0x4400;
    puVar2[0x5e] = puVar2[0x5e] | 0x4800;
    puVar2[0xbc] = puVar2[0xbc] | 0x4800;
    puVar2[0x11a] = puVar2[0x11a] | 0x4800;
    if (param_1[0xb] == 0) {
      _DAT_800df934 = FUN_801665e8(param_1,_DAT_800df934);
    }
    param_1[0xa9] = (uint)FUN_80161fe8;
    if ((*(ushort *)((int)param_1 + 0x1aa) & 0xfff) == 0) {
      local_50 = *(undefined4 *)(&UNK_801670d8 + iVar4 * 8);
      local_4c = *(undefined4 *)(&UNK_801670dc + iVar4 * 8);
      func_0x80040e58(_DAT_800e13f0 + 100,auStack_48);
      func_0x8004276c(auStack_48,&local_50,&local_50);
      param_1[10] = *(int *)(_DAT_800e13f0 + 0x28) + (int)local_50._0_2_;
      param_1[0xb] = *(int *)(_DAT_800e13f0 + 0x2c) + (int)local_50._2_2_;
      param_1[0xc] = *(int *)(_DAT_800e13f0 + 0x30) + (int)local_4c._0_2_;
    }
    *(undefined1 *)((int)param_1 + 5) = 8;
    puVar3 = (undefined4 *)FUN_80166a34(0x34,param_1);
    *puVar3 = 0;
    *(undefined2 *)((int)puVar3 + 0x1aa) = 8;
    FUN_80162018(puVar3,param_2,param_3);
    if ((*(ushort *)((int)param_1 + 0x1aa) & 0xfff) == 1) {
      *(undefined1 *)((int)param_1 + 5) = 0xf;
      *(undefined1 *)((int)param_1 + 0x2b5) = 1;
    }
  }
  return;
}
