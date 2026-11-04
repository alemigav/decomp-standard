/* FUN_80084a84
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80084a84  body 0x80084a84..0x80084e03  size 896 B
 * body sha256 af50ce79a7e95b4662e570a6390b9a877bb7f6fe0c249bc2c70acdbe416897fb
 * provider record sha256 5f5dd57bcc0a0bafd2e872ec3760f0645afb8f9bc6e6b9f9c3f4addddd4c5eab
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4
FUN_80084a84(int param_1,int param_2,uint param_3,uint param_4,int param_5,undefined4 param_6,
            undefined4 param_7,int param_8)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined2 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined2 uVar9;
  uint uVar10;
  byte *pbVar11;
  uint uVar12;
  int iVar13;
  uint local_resc;
  uint local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  int local_34;
  uint local_30;
  uint local_2c;
  
  uVar12 = (uint)*(byte *)(param_2 + 0x1c);
  FUN_80042de0(param_2 + 0x34);
  local_3c = param_3 << 8;
  param_5 = param_3 * *(ushort *)(param_2 + 0x3a) * param_5;
  pbVar11 = (byte *)(*(int *)(param_2 + 0x74) + param_8 * 4);
  uVar10 = (*(ushort *)(param_2 + 0x32) >> 1) - 0x20 & 0x60;
  local_44 = param_4;
  iVar3 = FUN_800434b8();
  if (iVar3 << 0x10 < 0) {
    return 0;
  }
  FUN_80043398(&local_48);
  if ((int)local_48 >> 9 == 0) {
    return 0;
  }
  if (0x7fff < local_48) {
    local_48 = 0x7fff;
  }
  FUN_8004341c(&local_44);
  iVar3 = local_48 << 4;
  iVar13 = param_5 / iVar3;
  if (iVar3 == 0) {
    trap(0x1c00);
  }
  if ((iVar3 == -1) && (param_5 == -0x80000000)) {
    trap(0x1800);
  }
  local_40 = iVar13 * (uint)*(ushort *)(param_2 + 4);
  local_30 = local_40 / param_3;
  if (param_3 == 0) {
    trap(0x1c00);
  }
  uVar2 = iVar13 * (uint)*(ushort *)(param_2 + 6);
  local_38 = local_44 & 0xffff0000;
  local_2c = uVar2 / param_3;
  if (param_3 == 0) {
    trap(0x1c00);
  }
  local_34 = local_44 << 0x10;
  if (0x1ffff < local_30) {
    param_3 = param_3 - 1;
  }
  if (0x1ffff < local_2c) {
    local_3c = local_3c + -0x100;
  }
  bVar1 = *(byte *)(param_2 + 0x1e);
  local_resc = param_4;
  if (uVar12 - 3 < 2) {
    if ((bVar1 & 1) == 0) {
      uVar9 = 0x21;
      if (bVar1 != 0x12) {
        uVar9 = 0x22;
        uVar10 = 0;
      }
    }
    else {
      uVar9 = 2;
      if (bVar1 == 0x1d) {
        uVar9 = 0x10;
      }
    }
  }
  else if ((uVar12 == 2) && (bVar1 == 0xd)) {
    uVar9 = 2;
  }
  else if ((uVar12 != 0x1a) || (uVar9 = 0x10, bVar1 != 9)) {
    uVar9 = *(undefined2 *)(&DAT_8011c862 + uVar12 * 4);
  }
  do {
    *(char *)(param_1 + 3) = (char)uVar9;
    uVar6 = local_38 + (int)(char)pbVar11[2] * local_30;
    uVar8 = uVar6 + local_40 & 0xffff0000;
    uVar6 = uVar6 & 0xffff0000;
    uVar4 = local_34 + (int)(char)pbVar11[3] * local_2c;
    uVar7 = uVar4 + uVar2 >> 0x10;
    uVar4 = uVar4 >> 0x10;
    *(uint *)(param_1 + 0xc) = uVar8 | uVar4;
    *(uint *)(param_1 + 0x1c) = uVar8 | uVar7;
    *(uint *)(param_1 + 4) = uVar6 | uVar4;
    *(uint *)(param_1 + 0x14) = uVar6 | uVar7;
    local_44 = (uint)*pbVar11 * 0x1000000;
    uVar6 = local_44 + param_3 * 0x1000000;
    bVar1 = pbVar11[1];
    pbVar11 = pbVar11 + 4;
    *(undefined4 **)(param_1 + 0x24) = &DAT_80124128 + uVar12 * 7;
    local_48 = (uint)bVar1 * 0x10000;
    uVar4 = local_48 + local_3c * 0x100;
    *(uint *)(param_1 + 8) = local_44 | local_48 | uVar10;
    *(uint *)(param_1 + 0x20) = uVar6 | uVar4;
    *(uint *)(param_1 + 0x10) = local_44 | uVar4;
    *(uint *)(param_1 + 0x18) = uVar6 | local_48;
    *(undefined2 *)(param_1 + 0x22) = 1;
    uVar5 = FUN_800434b8();
    *(undefined2 *)(param_1 + 0x1a) = uVar5;
    param_1 = param_1 + 0x28;
    local_resc = local_resc - 1;
  } while (local_resc != 0);
  return 1;
}
