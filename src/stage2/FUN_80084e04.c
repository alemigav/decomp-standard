/* FUN_80084e04
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80084e04  body 0x80084e04..0x800850a3  size 672 B
 * body sha256 f46e46f99815488c06c4caef48cb311d499f377ed3cf573c0539f3f31dc9324c
 * provider record sha256 ee1d8fbc7415eb7b5c26b7f701790eab96f358e8ed78c8fc22876679d7a5c514
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80084e04(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,uint param_6,
                 int param_7)

{
  ushort uVar1;
  short sVar3;
  int iVar2;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  int local_res8;
  undefined4 local_88;
  uint local_80;
  undefined1 auStack_7c [4];
  uint local_78;
  undefined1 auStack_74 [4];
  ushort local_70;
  short sStack_6e;
  undefined1 auStack_6c [4];
  undefined4 local_68;
  undefined4 *local_64;
  short local_60;
  short local_5e;
  undefined2 local_5c;
  short local_58;
  short local_56;
  undefined2 local_54;
  short local_50;
  short local_4e;
  undefined2 local_4c;
  short local_48;
  short local_46;
  undefined2 local_44;
  int local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  undefined2 local_30;
  
  iVar2 = (uint)*(ushort *)(param_1 + 0x3a) * (param_4 >> 4);
  pbVar8 = (byte *)(*(int *)(param_1 + 0x74) + param_7 * 4);
  uVar1 = *(ushort *)(param_1 + 0x32);
  local_40 = (int)(iVar2 * (uint)*(ushort *)(param_1 + 4)) >> 0xc;
  local_30 = *(undefined2 *)(&DAT_8011c862 + (uint)*(byte *)(param_1 + 0x1c) * 4);
  local_5c = 0;
  local_54 = 0;
  local_4c = 0;
  local_44 = 0;
  local_3c = (int)(iVar2 * (uint)*(ushort *)(param_1 + 6)) >> 0xc;
  local_38 = (uint)(param_2 * local_40) >> 0xc;
  local_34 = (uint)(param_2 * local_3c) >> 0xc;
  local_res8 = param_3;
  do {
    local_60 = (short)((char)pbVar8[2] * local_40 >> 0xc);
    local_58 = local_60 + (short)local_38;
    local_5e = (short)((char)pbVar8[3] * local_3c >> 0xc);
    local_4e = local_5e + (short)local_34;
    uVar5 = (uint)*pbVar8 * 0x1000000;
    uVar4 = (uint)pbVar8[1] * 0x10000;
    uVar7 = uVar5 + (param_2 + -1) * 0x1000000;
    uVar6 = uVar4 + (param_2 + -1) * 0x10000;
    local_56 = local_5e;
    local_50 = local_60;
    local_48 = local_58;
    local_46 = local_4e;
    FUN_80042de0(&local_60);
    FUN_8004341c((uint)&local_88 | 4);
    sVar3 = FUN_800434b8();
    iVar2 = FUN_800434b8();
    if (iVar2 << 0x10 < 0) {
      return;
    }
    FUN_80042f9c(&local_58,&local_50,&local_48);
    if ((uint)(int)sVar3 >> 9 == 0) {
      return;
    }
    if (0x7fff < (uint)(int)sVar3) {
      return;
    }
    local_80 = uVar5 | uVar4 | (uVar1 >> 1) - 0x20 & 0x60;
    local_78 = uVar7 | uVar4;
    local_68 = uVar7 | uVar6;
    _local_70 = CONCAT22((ushort)(uVar5 >> 0x10) | (ushort)(uVar6 >> 0x10),sVar3);
    local_88 = param_6 | 0xffffff00;
    FUN_80043460(auStack_7c,auStack_74,auStack_6c);
    local_68 = CONCAT22(local_68._0_2_,1);
    local_64 = &DAT_80124128 + (uint)*(byte *)(param_1 + 0x1c) * 7;
    local_88 = CONCAT31(local_88._0_3_,(undefined1)local_30);
    DAT_800df8b4 = FUN_80044fdc(DAT_800df8b4,&local_88,0);
    pbVar8 = pbVar8 + 4;
    local_res8 = local_res8 + -1;
  } while (local_res8 != 0);
  return;
}
