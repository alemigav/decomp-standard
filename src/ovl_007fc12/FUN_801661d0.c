/* FUN_801661d0
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x801661d0  body 0x801661d0..0x801665c7  size 1016 B
 * body sha256 7553b2cc5fec970635f0c47d5ade0857a03c34c6b95424115c223cc8ac2d442a
 * provider record sha256 99f6df3e8b2cf5d0bbcd7a0cb435ccbe37611f209746b9f1d6da0c20474d9c36
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801661d0(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  byte bVar6;
  undefined2 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined2 *puVar11;
  undefined2 *puVar12;
  int iVar13;
  undefined4 *puVar14;
  uint unaff_s1;
  undefined4 local_28;
  undefined4 local_24;
  
  local_28 = 0x20002;
  local_24 = 0x20002;
  param_1[1] = 0x1000000;
  func_0x8008940c(param_1,param_1[0x69]);
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  *(undefined1 *)((int)param_1 + 0x26f) = 0;
  uVar5 = func_0x80033604();
  uVar2 = *(undefined2 *)(&DAT_8016df90 + (uVar5 & 0xf) * 2);
  *(undefined1 *)((int)param_1 + 0x1ed) = 0xd;
  *(undefined1 *)((int)param_1 + 0x1ee) = 0xd;
  *(undefined1 *)((int)param_1 + 0x1ef) = 0xd;
  *(undefined2 *)((int)param_1 + 0x1f2) = uVar2;
  uVar5 = func_0x80033604();
  uVar1 = *(undefined1 *)((int)&local_28 + (uVar5 & 7));
  *(undefined2 *)((int)param_1 + 0x2b6) = 0;
  *(undefined1 *)((int)param_1 + 0x2b5) = 0;
  *(undefined1 *)((int)param_1 + 0x2be) = 0;
  *(undefined1 *)(param_1 + 0xad) = uVar1;
  bVar6 = func_0x80033604();
  *(undefined2 *)((int)param_1 + 0x136) = 500;
  *(undefined2 *)(param_1 + 0x4e) = 500;
  *(undefined2 *)(param_1 + 0x4b) = 500;
  *(undefined2 *)((int)param_1 + 0x12e) = 500;
  *(byte *)((int)param_1 + 0x2bf) = (bVar6 & 0xf) + 0x10;
  param_1[0xa1] = 1;
  *(undefined2 *)(param_1 + 0x4d) = 0xfa24;
  *(undefined2 *)((int)param_1 + 0x13a) = 0x5dc;
  *(undefined1 *)(param_1 + 0xb3) = 0;
  *(undefined1 *)((int)param_1 + 0x2cd) = 0;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  *param_1 = 0xc000001;
  if (*(char *)(param_1 + 2) == '\x13') {
    *(undefined2 *)((int)param_1 + 0x27a) = 0xe66;
  }
  if (*(char *)(param_1 + 2) == '\x1e') {
    *(undefined2 *)((int)param_1 + 0x27a) = 0xe66;
  }
  param_1[0x7a] = 0x1000000;
  func_0x80089d54(param_1,param_2,param_3,0x100);
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0x3f) == 6) {
    param_1[1] = 0x1010000;
  }
  if (*(char *)(param_1 + 2) == '\x1f') {
    if ((*(byte *)((int)param_1 + 0x26b) & 0xc0) == 0) {
      uVar5 = func_0x80033604();
      unaff_s1 = (uVar5 & 0xff) % 3;
    }
    if ((*(byte *)((int)param_1 + 0x26b) & 0x3f) != 0) {
      unaff_s1 = (*(byte *)((int)param_1 + 0x26b) & 0x3f) - 1;
    }
    func_0x8008794c(param_1,param_1[0x8d],unaff_s1);
    func_0x8008794c(param_1,param_1[0x8d] + 0x178,unaff_s1);
    func_0x8008794c(param_1,param_1[0x8d] + 0x2f0,unaff_s1);
    func_0x8008794c(param_1,param_1[0x8d] + 0x468,unaff_s1);
    func_0x8008794c(param_1,param_1[0x8d] + 0x5e0,unaff_s1);
    func_0x8008794c(param_1,param_1[0x8d] + 0x758,unaff_s1);
    func_0x8008794c(param_1,param_1[0x8d] + 0x8d0,unaff_s1);
    func_0x8008794c(param_1,param_1[0x8d] + 0xa48,unaff_s1);
    func_0x8008794c(param_1,param_1[0x8d] + 0xd38,unaff_s1);
    func_0x8008794c(param_1,param_1[0x8d] + 0xeb0,unaff_s1);
    func_0x8008794c(param_1,param_1[0x8d] + 0x11a0,unaff_s1);
    func_0x8008794c(param_1,param_1[0x8d] + 0x1318,unaff_s1);
    func_0x8008794c(param_1,param_1[0x8d] + 0x1780,unaff_s1);
  }
  puVar9 = (undefined4 *)param_1[0x8d];
  uVar5 = (uint)*(byte *)((int)param_1 + 0x1a3);
  puVar11 = (undefined2 *)((int)puVar9 + 0x13a);
  do {
    uVar4 = _DAT_800e9030;
    uVar3 = _DAT_800e902c;
    *(undefined4 *)(puVar11 + -0x81) = _DAT_800e9028;
    *(undefined4 *)(puVar11 + -0x7f) = uVar3;
    *(undefined4 *)(puVar11 + -0x7d) = uVar4;
    uVar4 = _DAT_800e903c;
    uVar3 = _DAT_800e9038;
    *(undefined4 *)(puVar11 + -0x7b) = _DAT_800e9034;
    *(undefined4 *)(puVar11 + -0x79) = uVar3;
    *(undefined4 *)(puVar11 + -0x77) = uVar4;
    uVar3 = _DAT_800e9044;
    *(undefined4 *)(puVar11 + -0x75) = _DAT_800e9040;
    *(undefined4 *)(puVar11 + -0x73) = uVar3;
    puVar14 = puVar9 + 2;
    iVar13 = 2;
    puVar12 = (undefined2 *)&DAT_800e9048;
    do {
      iVar8 = 2;
      puVar7 = puVar12;
      puVar10 = puVar14;
      do {
        uVar2 = *puVar7;
        puVar7 = puVar7 + 1;
        iVar8 = iVar8 + -1;
        *(undefined2 *)puVar10 = uVar2;
        puVar10 = (undefined4 *)((int)puVar10 + 2);
      } while (iVar8 != -1);
      puVar14 = (undefined4 *)((int)puVar14 + 6);
      iVar13 = iVar13 + -1;
      puVar12 = puVar12 + 3;
    } while (iVar13 != -1);
    *(undefined4 *)(puVar11 + -0x9b) = 0;
    *(undefined4 *)(puVar11 + -0x71) = 0;
    puVar11[-0x6f] = 0;
    *puVar9 = 1;
    *(undefined4 *)(puVar11 + -0x6d) = 0x808080;
    puVar11[-5] = 0;
    puVar11[-4] = 0;
    puVar11[-3] = 0;
    puVar11[-2] = 0;
    puVar11[-1] = 0;
    *puVar11 = 0;
    puVar11 = puVar11 + 0xbc;
    uVar5 = uVar5 - 1;
    puVar9 = puVar9 + 0x5e;
  } while (uVar5 != 0);
  *(undefined4 *)(param_1[0x8d] + 0x1608) = 0;
  *(undefined4 *)(param_1[0x8d] + 0x1780) = 0;
  return;
}
