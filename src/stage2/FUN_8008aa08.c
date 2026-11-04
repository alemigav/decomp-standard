/* FUN_8008aa08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008aa08  body 0x8008aa08..0x8008aeeb  size 1252 B
 * body sha256 d879b23e36ca594cd7638685d26d30fcbed5a25a5a38c0cad92e03cce9ce6069
 * provider record sha256 dc5d0dd0599b414f5f6d235c9fe21a0012bf61eba009d072acb07cc9379c0737
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_8008aa08(ushort *param_1,int param_2,uint *param_3,uint param_4)

{
  ushort uVar1;
  bool bVar2;
  uint *puVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  short *psVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  int iVar13;
  undefined4 *puVar14;
  int iVar15;
  uint uVar16;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined1 auStack_c8 [160];
  
  iVar4 = DAT_800df938;
  iVar15 = *(int *)(DAT_800df938 + 0x234);
  psVar9 = (short *)((int)param_1 +
                    (*(uint *)(param_1 + 2) >> 0x12) * (*param_3 & 0xfff) * 4 + (uint)*param_1);
  iVar13 = (int)*psVar9 * (int)*(short *)(DAT_800df938 + 0x27a);
  uVar1 = *(ushort *)((uint)*(byte *)(DAT_800df938 + 0x1e8) * 4 + param_2 + 2);
  *(int *)(iVar15 + 0x1c) = (int)psVar9[1];
  *(int *)(iVar15 + 0x20) = iVar13 >> 0xc;
  *(int *)(iVar15 + 0x24) = (int)psVar9[3];
  uVar12 = (uint)*(byte *)(iVar4 + 0x1ea);
  uVar16 = (uint)param_1[3];
  if (uVar12 != 0) {
    DAT_8012bd70 = (int)*(short *)(iVar15 + 0x28);
    iVar13 = (param_4 & 0xffff) * uVar12;
    DAT_8012bd74 = (int)*(short *)(iVar15 + 0x2a);
    DAT_8012bd78 = (int)*(short *)(iVar15 + 0x2c);
    iVar7 = 0x1000 - iVar13;
    *(int *)(iVar15 + 0x1c) = *(int *)(iVar15 + 0x1c) * iVar7 + DAT_8012bd70 * iVar13 >> 0xc;
    *(int *)(iVar15 + 0x20) = *(int *)(iVar15 + 0x20) * iVar7 + DAT_8012bd74 * iVar13 >> 0xc;
    *(int *)(iVar15 + 0x24) = *(int *)(iVar15 + 0x24) * iVar7 + DAT_8012bd78 * iVar13 >> 0xc;
  }
  puVar8 = (ushort *)(iVar15 + 0x290);
  *(undefined2 *)(iVar15 + 0x28) = *(undefined2 *)(iVar15 + 0x1e);
  *(undefined2 *)(iVar15 + 0x2a) = *(undefined2 *)(iVar15 + 0x22);
  *(undefined2 *)(iVar15 + 0x2c) = *(undefined2 *)(iVar15 + 0x26);
  uVar6 = *(uint *)(psVar9 + 6);
  *(uint *)(iVar15 + 0x114) = (uVar6 & 0xfff) << 0x10 | (uVar6 & 0xfff000) >> 0xc;
  *(ushort *)(iVar15 + 0x118) = (ushort)*(byte *)(psVar9 + 6) | (psVar9[9] & 0xfU) << 8;
  puVar3 = (uint *)(psVar9 + 8);
  for (iVar7 = uVar16 - 1; iVar7 != 0; iVar7 = iVar7 + -8) {
    *(uint *)(puVar8 + -2) = (*puVar3 & 0xfff0) << 0xc | (*puVar3 & 0xfff0000) >> 0x10;
    *puVar8 = (ushort)(*puVar3 >> 0x1c) | (ushort)*(byte *)((int)puVar3 + 7) << 4;
    if (iVar7 == 1) break;
    *(uint *)(puVar8 + 0xba) = (puVar3[1] & 0xfff00) << 8 | puVar3[1] >> 0x14;
    puVar8[0xbc] = *(ushort *)((int)puVar3 + 10) & 0xfff;
    if (iVar7 == 2) break;
    puVar10 = puVar3 + 3;
    *(uint *)(puVar8 + 0x176) =
         (puVar3[2] & 0xfff000) << 4 | puVar3[2] >> 0x18 | (*puVar10 & 0xf) << 8;
    puVar8[0x178] = (ushort)((*puVar10 & 0xfff0) >> 4);
    if (iVar7 == 3) break;
    *(uint *)(puVar8 + 0x232) =
         *puVar10 & 0xfff0000 | *puVar10 >> 0x1c | (uint)*(byte *)((int)puVar3 + 0x13) << 4;
    puVar8[0x234] = (ushort)(puVar3[4] >> 8) & 0xfff;
    if (iVar7 == 4) break;
    puVar10 = puVar3 + 5;
    *(uint *)(puVar8 + 0x2ee) = puVar3[4] >> 4 & 0xfff0000 | *puVar10 & 0xfff;
    puVar8[0x2f0] = (ushort)((*puVar10 & 0xfff000) >> 0xc);
    if (iVar7 == 5) break;
    puVar11 = puVar3 + 6;
    *(uint *)(puVar8 + 0x3aa) =
         *puVar10 >> 8 & 0xfff0000 | (*puVar11 & 0xf) << 0x18 | (*puVar11 & 0xfff0) >> 4;
    puVar8[0x3ac] = (ushort)(*puVar11 >> 0x10) & 0xfff;
    if (iVar7 == 6) break;
    uVar6 = puVar3[7];
    *(uint *)(puVar8 + 0x466) =
         *puVar11 >> 0xc & 0xfff0000 | (uVar6 & 0xff) << 0x14 | (uVar6 & 0xfff00) >> 8;
    puVar8[0x468] = (ushort)(puVar3[7] >> 0x14);
    if (iVar7 == 7) break;
    uVar6 = puVar3[8];
    *(uint *)(puVar8 + 0x522) = (uVar6 & 0xfff) << 0x10 | (uVar6 & 0xfff000) >> 0xc;
    puVar8[0x524] = (ushort)*(byte *)(puVar3 + 8) | (*(ushort *)((int)puVar3 + 0x26) & 0xf) << 8;
    puVar8 = puVar8 + 0x5e0;
    puVar3 = puVar3 + 9;
  }
  if (uVar12 == 0) {
    do {
      iVar13 = iVar15 + 8;
      FUN_80040e58(iVar15 + 0x114,iVar13);
      FUN_80041d6c(iVar13,iVar13);
      uVar16 = uVar16 - 1;
      iVar15 = iVar15 + 0x178;
    } while (uVar16 != 0);
  }
  else {
    puVar14 = (undefined4 *)(iVar15 + 8);
    *(char *)(iVar4 + 0x1ea) = *(char *)(iVar4 + 0x1ea) + -1;
    do {
      local_e8 = *puVar14;
      local_e4 = puVar14[1];
      iVar7 = iVar15 + 0x114;
      local_e0 = puVar14[2];
      local_dc = puVar14[3];
      iVar15 = iVar15 + 0x178;
      local_d8 = puVar14[4];
      uVar16 = uVar16 - 1;
      FUN_80040e58(iVar7,auStack_c8);
      FUN_80089c3c(&local_e8,auStack_c8,puVar14,0xfff - iVar13);
      puVar14 = puVar14 + 0x5e;
    } while (uVar16 != 0);
  }
  bVar5 = *(char *)(iVar4 + 0x1e9) + 1;
  *(byte *)(iVar4 + 0x1e9) = bVar5;
  bVar2 = uVar1 <= bVar5;
  if (bVar2) {
    *(undefined1 *)(iVar4 + 0x1e9) = 0;
  }
  return bVar2;
}
