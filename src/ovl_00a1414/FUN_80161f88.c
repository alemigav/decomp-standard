/* FUN_80161f88
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80161f88  body 0x80161f88..0x80162623  size 1692 B
 * body sha256 1848178acd6846a5d1b85dce18455db5b83f6d326627c2776066da163607964d
 * provider record sha256 a115dfa2f7c45c455de55cf4d6191ac122bffd8bfeb5993be7f129e5e37d1b56
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80161f88(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint *puVar7;
  uint *puVar8;
  
  param_1[1] = 0x1000000;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  *(undefined1 *)((int)param_1 + 0x26f) = 0;
  *(undefined2 *)((int)param_1 + 0x1f2) = 500;
  if ((_DAT_800e10ec & 0x20) != 0) {
    *(undefined2 *)((int)param_1 + 0x1f2) = 400;
  }
  *(undefined1 *)((int)param_1 + 0x1ed) = 0x82;
  *(undefined1 *)((int)param_1 + 0x1ee) = 0x82;
  *(undefined1 *)((int)param_1 + 0x1ef) = 0x82;
  *(undefined1 *)((int)param_1 + 0x25d) = 3;
  uVar3 = param_1[0x8d];
  *(undefined1 *)(param_1 + 0x97) = 0;
  *(undefined2 *)(uVar3 + 0x59c) = 0x20;
  *(undefined2 *)(uVar3 + 0x59e) = 0x20;
  *(undefined2 *)(uVar3 + 0x5a0) = 0x264;
  *(undefined2 *)(uVar3 + 0x5a2) = 0x138;
  *(undefined2 *)(uVar3 + 0x598) = 0;
  *(undefined2 *)(uVar3 + 0x59a) = 0;
  *(undefined1 *)(param_1 + 0xad) = 0;
  *(undefined1 *)((int)param_1 + 0x2b5) = 0;
  *(undefined1 *)((int)param_1 + 0x2b6) = 0;
  *(undefined1 *)((int)param_1 + 0x2ba) = 0;
  *(undefined1 *)(param_1 + 0xaf) = 0;
  *(undefined1 *)((int)param_1 + 0x2bd) = 0;
  *(undefined1 *)((int)param_1 + 0x2c3) = 0;
  *(undefined1 *)(param_1 + 0xb2) = 0;
  DAT_80168f44 = 0;
  DAT_80168f45 = 0;
  DAT_80168f46 = 0;
  DAT_80168f48 = 0;
  DAT_80168f4a = 0;
  DAT_80168f4c = 0;
  DAT_80168f4e = 0;
  DAT_80168f4f = 0;
  *(undefined2 *)(param_1 + 0x4d) = 0xfa24;
  *(undefined2 *)(param_1 + 0xae) = 0;
  param_1[0xa1] = 1;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  *(undefined2 *)((int)param_1 + 0x136) = 800;
  *(undefined2 *)((int)param_1 + 0x13a) = 0x5dc;
  *(undefined2 *)(param_1 + 0x4e) = 800;
  *(undefined2 *)(param_1 + 0x4b) = 800;
  *(undefined2 *)((int)param_1 + 0x12e) = 800;
  *(undefined2 *)((int)param_1 + 0x28a) = 500;
  param_1[0x7a] = 0;
  *param_1 = *param_1 | 0xc000000;
  func_0x80089d54(param_1,param_2,param_3,0x100);
  func_0x800339dc(param_1 + 0x82,0,0x2bc0320,0,param_1[0x8d] + 0x4c);
  *(code **)((*(byte *)(param_1 + 2) - 0x10) * 4 + -0x7ff206b8) = FUN_80167e68;
  *(code **)((*(byte *)(param_1 + 2) - 0x10) * 4 + -0x7ff205b8) = FUN_8016816c;
  *param_1 = *param_1 | 4;
  *(uint *)(param_1[0x8d] + 0x1780) = *(uint *)(param_1[0x8d] + 0x1780) | 0x4000;
  uVar3 = param_1[0x8d];
  *(undefined4 *)(uVar3 + 0x18f8) = 0;
  *(uint *)(uVar3 + 0x195c) = uVar3 + 0x908;
  *(undefined4 *)(uVar3 + 0x1918) = 0x86;
  *(undefined4 *)(uVar3 + 0x191c) = 0x1e;
  *(uint *)(uVar3 + 0x1a24) = uVar3 + 0x8d0;
  *(undefined4 *)(uVar3 + 0x1914) = 0xc;
  *(undefined2 *)(uVar3 + 0x1950) = 0xff38;
  *(undefined2 *)(uVar3 + 0x1952) = 0;
  *(undefined2 *)(uVar3 + 0x1954) = 0;
  func_0x80040e58(uVar3 + 0x1950,uVar3 + 0x1900);
  *(undefined4 *)(param_1[0x8d] + 0x1a70) = 0;
  uVar2 = *(ushort *)((int)param_1 + 0x1aa) & 0xfff;
  if (uVar2 == 1) {
    *(undefined1 *)((int)param_1 + 5) = 1;
  }
  else {
    if (uVar2 == 3) {
      uVar2 = *(ushort *)((int)param_1 + 0x1aa);
      *(undefined1 *)((int)param_1 + 5) = 0xc;
    }
    else {
      *(undefined1 *)((int)param_1 + 5) = 10;
      *(undefined2 *)((int)param_1 + 0x27a) = 0xeb8;
      *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x4000;
      *(undefined2 *)(*(int *)(param_1[0x8d] + 0x298) + 0xc) = 0x1000;
      func_0x80066288(param_1);
      uVar3 = param_1[0x8d];
      *(undefined2 *)(*(int *)(uVar3 + 0x410) + 0xc) = 0x1000;
      func_0x80066288(param_1,uVar3 + 0x2f0);
      uVar3 = param_1[0x8d];
      *(undefined2 *)(*(int *)(uVar3 + 0x700) + 0xc) = 0x1000;
      *(undefined2 *)(*(int *)(uVar3 + 0x700) + 0x10) = 0;
      func_0x80066288(param_1,uVar3 + 0x5e0);
      func_0x80066554(param_1,uVar3 + 0x5e0);
      uVar3 = param_1[0x8d];
      *(undefined2 *)(*(int *)(uVar3 + 0x878) + 0xc) = 0x1000;
      func_0x80066288(param_1,uVar3 + 0x758);
      iVar5 = 0x10;
      puVar7 = (uint *)param_1[0x8d];
      puVar8 = puVar7 + 0x4a;
      do {
        iVar5 = iVar5 + -1;
        *puVar7 = *puVar7 | 0x400;
        *(undefined2 *)(puVar8 + -1) = 0xc28;
        *(undefined2 *)((int)puVar8 + -2) = 0xeb8;
        *(undefined2 *)puVar8 = 0xc28;
        puVar8 = puVar8 + 0x5e;
        puVar7 = puVar7 + 0x5e;
      } while (iVar5 != 0);
      *(uint *)(param_1[0x8d] + 0x178) = *(uint *)(param_1[0x8d] + 0x178) & 0xfffffbff;
      *(uint *)(param_1[0x8d] + 0x2f0) = *(uint *)(param_1[0x8d] + 0x2f0) & 0xfffffbff;
      *(uint *)(param_1[0x8d] + 0x5e0) = *(uint *)(param_1[0x8d] + 0x5e0) & 0xfffffbff;
      *(uint *)(param_1[0x8d] + 0x758) = *(uint *)(param_1[0x8d] + 0x758) & 0xfffffbff;
      *(uint *)(param_1[0x8d] + 0x8d0) = *(uint *)(param_1[0x8d] + 0x8d0) & 0xfffffbff;
      uVar4 = param_1[0x8d];
      *(uint *)(uVar4 + 0x1780) = *(uint *)(uVar4 + 0x1780) | 0x4000;
      uVar3 = param_1[0x8d];
      uVar6 = *(undefined4 *)(uVar4 + 0x1828);
      *(undefined4 *)(uVar4 + 0x1828) = *(undefined4 *)(uVar3 + 0x978);
      *(undefined4 *)(uVar3 + 0x978) = uVar6;
      uVar6 = *(undefined4 *)(uVar4 + 0x182c);
      *(undefined4 *)(uVar4 + 0x182c) = *(undefined4 *)(uVar3 + 0x97c);
      *(undefined4 *)(uVar3 + 0x97c) = uVar6;
      uVar6 = *(undefined4 *)(uVar4 + 0x1830);
      *(undefined4 *)(uVar4 + 0x1830) = *(undefined4 *)(uVar3 + 0x980);
      *(undefined4 *)(uVar3 + 0x980) = uVar6;
      uVar6 = *(undefined4 *)(uVar4 + 0x1834);
      *(undefined4 *)(uVar4 + 0x1834) = *(undefined4 *)(uVar3 + 0x984);
      *(undefined4 *)(uVar3 + 0x984) = uVar6;
      uVar1 = *(undefined2 *)(uVar4 + 0x1844);
      *(undefined2 *)(uVar4 + 0x1844) = *(undefined2 *)(uVar3 + 0x994);
      *(undefined2 *)(uVar3 + 0x994) = uVar1;
      uVar1 = *(undefined2 *)(uVar4 + 0x1846);
      *(undefined2 *)(uVar4 + 0x1846) = *(undefined2 *)(uVar3 + 0x996);
      *(undefined2 *)(uVar3 + 0x996) = uVar1;
      uVar6 = *(undefined4 *)(uVar4 + 0x184c);
      *(undefined4 *)(uVar4 + 0x184c) = *(undefined4 *)(uVar3 + 0x99c);
      *(undefined4 *)(uVar3 + 0x99c) = uVar6;
      uVar6 = *(undefined4 *)(uVar4 + 0x1848);
      *(undefined4 *)(uVar4 + 0x1848) = *(undefined4 *)(uVar3 + 0x998);
      *(undefined4 *)(uVar3 + 0x998) = uVar6;
      if (*_DAT_800e13f0 != 0) {
        uVar3 = param_1[0x8d];
        iVar5 = _DAT_800e13f0[0x8d];
        *(int *)(uVar3 + 0x1ad4) = iVar5 + 0xbf8;
        *(undefined4 *)(uVar3 + 0x1a8c) = 0xeb;
        *(int *)(uVar3 + 0x1b9c) = iVar5 + 0xbc0;
        *(undefined4 *)(uVar3 + 0x1a90) = 0xffffff49;
        *(undefined4 *)(uVar3 + 0x1a94) = 0;
        if (*(char *)(_DAT_800e13f0 + 2) == 'D') {
          *(undefined4 *)(uVar3 + 0x1a8c) = 0xf6;
          *(undefined4 *)(uVar3 + 0x1a90) = 0xffffff05;
          *(undefined4 *)(uVar3 + 0x1a94) = 0;
        }
      }
      if ((*(ushort *)((int)param_1 + 0x1aa) & 0xfff) == 2) {
        uVar3 = param_1[0x8d];
        *(undefined4 *)(uVar3 + 0x18f8) = 1;
        *(undefined1 *)((int)param_1 + 5) = 0xb;
        *(uint *)(uVar3 + 0x18f8) = *(uint *)(uVar3 + 0x18f8) | 0x400;
        *(undefined2 *)(uVar3 + 0x1a1c) = 0x1000;
        *(undefined2 *)(uVar3 + 0x1a1e) = 0x1000;
        *(undefined2 *)(uVar3 + 0x1a20) = 0;
        uVar3 = param_1[0x8d];
        *(undefined4 *)(uVar3 + 0x1a70) = 0x4401;
        *(undefined2 *)(uVar3 + 0x1b94) = 0x1000;
        *(undefined2 *)(uVar3 + 0x1b96) = 0x1000;
        *(undefined2 *)(uVar3 + 0x1b98) = 0x1000;
        *(undefined1 *)((int)param_1 + 0x207) = 0;
        *(undefined2 *)(*(int *)(uVar3 + 0x1b90) + 0xc) = 0;
        *(undefined2 *)(*(int *)(uVar3 + 0x1b90) + 0x10) = 0x1000;
        param_1[0x7a] = 0x14000000;
        *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x4000;
        func_0x80089d54(param_1,param_2,param_3,0x100);
      }
      if ((*(ushort *)((int)param_1 + 0x1aa) & 0xfff) == 5) {
        uVar3 = param_1[0x8d];
        *(uint *)(uVar3 + 0x1ad4) = uVar3 + 0x38;
        *(uint *)(uVar3 + 0x1b9c) = param_1[0x8d];
        *(undefined4 *)(uVar3 + 0x1a70) = 1;
        *(undefined2 *)(*(int *)(uVar3 + 0x1b90) + 0xc) = 0x1000;
        *(undefined2 *)(*(int *)(uVar3 + 0x1b90) + 0x10) = 0;
        func_0x80066288(param_1,uVar3 + 0x1a70);
        *(undefined4 *)(uVar3 + 0x1a8c) = 0;
        *(undefined4 *)(uVar3 + 0x1a90) = 0;
        *(undefined4 *)(uVar3 + 0x1a94) = 0;
        iVar5 = 0x10;
        *(undefined1 *)((int)param_1 + 5) = 0;
        *param_1 = *param_1 | 10;
        *(undefined1 *)(param_1[0x82] + 0xe) = 0;
        puVar8 = (uint *)param_1[0x8d];
        do {
          iVar5 = iVar5 + -1;
          *puVar8 = *puVar8 | 0x4000;
          puVar8 = puVar8 + 0x5e;
        } while (iVar5 != 0);
      }
      if ((*(ushort *)((int)param_1 + 0x1aa) & 0xfff) != 4) {
        return;
      }
      uVar2 = *(ushort *)((int)param_1 + 0x1aa);
      *(undefined1 *)((int)param_1 + 5) = 0xd;
    }
    *(ushort *)((int)param_1 + 0x1aa) = uVar2 & 0xf000;
  }
  return;
}
