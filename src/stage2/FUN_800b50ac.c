/* FUN_800b50ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b50ac  body 0x800b50ac..0x800b53f3  size 840 B
 * body sha256 4d1d00378f486c055b8015e494b6cb9278d230cad5aa9473e56ef227dafe8c57
 * provider record sha256 57ed191df5c4b48d4ef6f000d432d3bb90a2fe6b012b59a85c5d4e0025d1e6d6
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800b50ac(undefined4 param_1,byte *param_2,undefined4 param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  ushort *puVar6;
  int iVar7;
  undefined1 *puVar8;
  ushort *puVar9;
  ushort *puVar10;
  ushort local_110;
  ushort local_10e;
  ushort local_10c;
  ushort local_10a;
  ushort local_108;
  ushort local_106;
  ushort local_104;
  ushort local_102;
  ushort local_100 [4];
  ushort local_f8 [4];
  ushort local_f0 [4];
  ushort local_e8 [4];
  undefined1 local_e0 [2];
  ushort local_de [51];
  undefined1 auStack_78 [80];
  
  local_110 = (ushort)(param_2[1] >> 6) | (*param_2 & 0xf) << 2;
  local_10e = param_2[1] & 0x3f;
  local_10c = (ushort)(param_2[2] >> 3);
  local_10a = (ushort)(param_2[3] >> 6) | (param_2[2] & 7) << 2;
  local_108 = param_2[3] >> 2 & 0xf;
  iVar7 = 0;
  local_106 = (ushort)(param_2[4] >> 6) | (param_2[3] & 3) << 2;
  puVar5 = &local_110;
  iVar4 = 0;
  local_104 = param_2[4] >> 3 & 7;
  local_102 = param_2[4] & 7;
  puVar6 = puVar5;
  do {
    puVar5[8] = (ushort)(param_2[5] >> 1);
    puVar5[0x10] = (ushort)(param_2[6] >> 7) | (param_2[5] & 1) << 1;
    puVar5[0xc] = param_2[6] >> 5 & 3;
    puVar5[0x14] = (ushort)(param_2[7] >> 7) | (param_2[6] & 0x1f) << 1;
    iVar3 = iVar4 + 0x16;
    iVar7 = iVar7 + 1;
    puVar6[0x18] = param_2[7] >> 4 & 7;
    *(ushort *)((int)local_de + iVar4) = param_2[7] >> 1 & 7;
    *(ushort *)((int)local_de + iVar4 + 2) = (ushort)(param_2[8] >> 6) | (param_2[7] & 1) << 2;
    *(ushort *)((int)local_de + iVar4 + 4) = param_2[8] >> 3 & 7;
    *(ushort *)((int)local_de + iVar4 + 6) = param_2[8] & 7;
    *(ushort *)((int)local_de + iVar4 + 8) = (ushort)(param_2[9] >> 5);
    *(ushort *)((int)local_de + iVar4 + 10) = param_2[9] >> 2 & 7;
    *(ushort *)((int)local_de + iVar4 + 0xc) = (ushort)(param_2[10] >> 7) | (param_2[9] & 3) << 1;
    *(ushort *)((int)local_de + iVar4 + 0xe) = param_2[10] >> 4 & 7;
    *(ushort *)((int)local_de + iVar4 + 0x10) = param_2[10] >> 1 & 7;
    *(ushort *)((int)local_de + iVar4 + 0x12) = (ushort)(param_2[0xb] >> 6) | (param_2[10] & 1) << 2
    ;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 0xd;
    *(ushort *)((int)local_de + iVar4 + 0x14) = param_2[0xb] >> 3 & 7;
    iVar4 = iVar4 + 0x1a;
    *(ushort *)((int)local_de + iVar3) = param_2[0xb] & 7;
    param_2 = param_2 + 7;
  } while (iVar7 < 4);
  puVar10 = local_100;
  puVar9 = local_f0;
  puVar5 = local_f8;
  puVar6 = local_e8;
  iVar4 = 0;
  puVar8 = local_e0;
  do {
    uVar1 = *puVar6;
    uVar2 = *puVar5;
    iVar4 = iVar4 + 1;
    puVar6 = puVar6 + 1;
    puVar5 = puVar5 + 1;
    FUN_800b62c0((int)(short)uVar1,(int)(short)uVar2,puVar8,auStack_78);
    uVar1 = *puVar10;
    uVar2 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar10 = puVar10 + 1;
    FUN_800b63b4(param_1,(int)(short)uVar1,(int)(short)uVar2,auStack_78);
    puVar8 = puVar8 + 0x1a;
  } while (iVar4 < 4);
  FUN_800b4dc0(param_1,&local_110,param_1,param_3);
  return 0;
}
