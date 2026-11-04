/* FUN_800990d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800990d4  body 0x800990d4..0x800995d7  size 1284 B
 * body sha256 7582da77e2399a93d6caf5fe3a71967003f242309685896b98f7a1e06446265a
 * provider record sha256 bd4327a1315ec67874219f7f92e8b19eab9e69aa0fd2ae2236c2360aed40529c
 * callees 7 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x800994e4) */

void FUN_800990d4(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  short local_68;
  short local_66;
  short local_64;
  undefined2 local_60;
  short local_5e;
  undefined2 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_48;
  short local_44;
  
  local_a8 = 0x10000000;
  local_a4 = 0;
  local_a0 = 0x10000000;
  local_9c = 0;
  local_98 = 0x10000000;
  local_94 = 0;
  local_90 = 0;
  local_8c = 0;
  if (param_2 == 1) {
    local_68 = 0;
    local_60 = 0;
    local_66 = 0;
    local_5e = 0;
    local_64 = 0;
    local_5c = 0;
    FUN_80040e58(&local_60,&local_a8);
    FUN_80042824(&local_a8,&local_68,&local_58);
    *(uint *)(param_1 + 0x18) = (local_68 + -0x17) - param_3;
    *(uint *)(param_1 + 0x1c) = (int)local_66 + param_3 * 0x3e + -0xde;
    *(int *)(param_1 + 0x20) = local_64 + 0xe9;
  }
  else if (param_2 == 2) {
    local_68 = 0;
    local_60 = 0;
    local_66 = 0;
    local_5e = 0;
    local_64 = 0;
    local_5c = 0;
    FUN_80040e58(&local_60,&local_a8);
    FUN_80042824(&local_a8,&local_68,&local_58);
    local_48 = 0;
    local_44 = 0xe9;
    if (7 < param_3) {
      param_3 = param_3 - 8;
      local_48 = 0xfff6000c;
      local_44 = 0xff;
    }
    *(int *)(param_1 + 0x18) = ((local_68 + -0x17) - (int)(short)param_3) + (int)local_48._0_2_;
    *(int *)(param_1 + 0x1c) = (int)local_66 + (short)param_3 * 0x3e + local_48._2_2_ + -0xde;
    *(int *)(param_1 + 0x20) = (int)local_64 + (int)local_44;
  }
  else {
    local_60 = 0;
    local_5c = 0;
    local_5e = ((short)DAT_8012bfa9 - (short)param_3) * -0x400;
    FUN_80040e58(&local_60,&local_a8);
    local_68 = 0x1ae;
    local_66 = 0;
    local_64 = 0;
    FUN_80042824(&local_a8,&local_68,&local_58);
    *(undefined4 *)(param_1 + 0x18) = local_58;
    *(undefined4 *)(param_1 + 0x1c) = local_54;
    *(undefined4 *)(param_1 + 0x20) = local_50;
    if (DAT_8012bf9a == 8) {
      *(short *)(param_1 + 0x56) = *(short *)(param_1 + 0x56) + 0x26;
    }
    if (DAT_8012bf9a == 9) {
      *(short *)(param_1 + 0x56) = *(short *)(param_1 + 0x56) + -0x26;
    }
    if (DAT_8012bf9a == 0xb) {
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 0x26;
    }
    if (DAT_8012bf9a == 0xc) {
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -0x26;
    }
    if (DAT_8012bf9a < 9) {
      if (-1 < *(int *)(param_1 + 0x18)) {
        iVar5 = *(int *)(param_1 + 0x18) + -4;
        *(int *)(param_1 + 0x18) = iVar5;
        if (0 < iVar5) goto LAB_800993ec;
        *(undefined4 *)(param_1 + 0x18) = 0;
      }
      iVar5 = *(int *)(param_1 + 0x18) + 4;
      *(int *)(param_1 + 0x18) = iVar5;
      if (-1 < iVar5) {
        *(undefined4 *)(param_1 + 0x18) = 0;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
  }
LAB_800993ec:
  FUN_80040e58(param_1 + 0x54,param_1 + 4);
  iVar8 = 0;
  iVar9 = 0;
  FUN_800424ec(*(undefined4 *)(param_1 + 0x60),param_1 + 4,param_1 + 0x34);
  FUN_800411b8(param_1 + 0x34,param_1 + 0xd0);
  iVar7 = param_1 + 0x68;
  psVar4 = &DAT_800e905c;
  iVar5 = iVar7;
  for (iVar6 = 0; iVar3 = 0, iVar6 < 3; iVar6 = iVar6 + 1) {
    iVar2 = iVar9;
    do {
      iVar1 = iVar7 + iVar3 + iVar8;
      *(char *)(iVar1 + 0x10) = (char)((ushort)*(undefined2 *)((int)&DAT_800e905c + iVar2) >> 8);
      *(char *)(iVar1 + 8) = (char)(*(ushort *)((int)&DAT_800e907c + iVar2) >> 4);
      iVar3 = iVar3 + 1;
      *(char *)(iVar1 + 0xc) = (char)(*(ushort *)((int)&DAT_800e907c + iVar2) >> 4);
      iVar2 = iVar2 + 6;
    } while (iVar3 < 3);
    fVar12 = (float)(int)*psVar4;
    fVar11 = (float)(int)psVar4[3];
    fVar13 = (float)(int)psVar4[6];
    fVar10 = SQRT(fVar12 * fVar12 + fVar11 * fVar11 + fVar13 * fVar13);
    if (1.0 < fVar10) {
      fVar10 = 120.0 / fVar10;
    }
    else {
      fVar10 = 0.0;
    }
    iVar8 = iVar8 + 0x10;
    psVar4 = psVar4 + 1;
    iVar9 = iVar9 + 2;
    *(char *)(iVar5 + 0x10) = (char)(int)(fVar10 * fVar12);
    *(char *)(iVar5 + 0x11) = (char)(int)(fVar10 * fVar11);
    *(char *)(iVar5 + 0x12) = (char)(int)(fVar10 * fVar13);
    iVar5 = iVar5 + 0x10;
    *(undefined1 *)(iVar7 + iVar6) = 0x7d;
    ((undefined1 *)(iVar7 + iVar6))[4] = 0x7d;
  }
  *(undefined4 *)(param_1 + 0xa0) = 3;
  FUN_80083748(param_1 + 0x48);
  *(undefined4 *)(param_1 + 200) = *(undefined4 *)(*(int *)(param_1 + 0xb4) + 8);
  FUN_800855d8(param_1 + 0x68);
  return;
}
