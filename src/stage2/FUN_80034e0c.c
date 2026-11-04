/* FUN_80034e0c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80034e0c  body 0x80034e0c..0x800350e7  size 732 B
 * body sha256 726bcf2ed02183f41f30f2e39f8e6b649ef0c8fd760146abc4fd0c39a1f4c874
 * provider record sha256 398131888bf7916c20fc1cc5183d90cff1822ec9bc918c3c7e64b274478ff0f4
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80034e0c(int param_1,int param_2,short param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  short sVar6;
  float fVar7;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  short local_80;
  short local_7e;
  short local_7c;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  short local_50;
  short local_4e;
  undefined2 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  short local_38;
  short local_36;
  short local_34;
  int local_30;
  int local_2c;
  
  psVar5 = (short *)(&PTR_DAT_800eb2e0)[param_2];
  iVar1 = *(int *)(param_1 + 0x234);
  iVar4 = iVar1 + param_2 * 0x178 + 0x1608;
  if (psVar5[6] == 0) {
    iVar3 = iVar1 + 0xbc0;
    sVar6 = *(short *)(iVar1 + 0x5c) + *(short *)(iVar1 + 0xc1c);
  }
  else {
    iVar3 = iVar1 + param_2 * 0x178 + 0x1490;
    sVar6 = *(short *)(iVar3 + 0x5c);
  }
  local_50 = *psVar5 << 4;
  local_4c = 0;
  local_4e = psVar5[1] << 4;
  FUN_80042824(iVar4 + 0x38,&local_50,&local_48);
  local_48 = (local_48 >> 4) + *(int *)(iVar4 + 0x4c);
  local_44 = (local_44 >> 4) + *(int *)(iVar4 + 0x50);
  local_40 = (local_40 >> 4) + *(int *)(iVar4 + 0x54);
  local_80 = *(short *)(iVar4 + 0x1e) << 4;
  local_7e = *(short *)(iVar4 + 0x22) << 4;
  local_7c = *(short *)(iVar4 + 0x26) << 4;
  FUN_80042824(iVar3 + 0x38,&local_80,&local_90);
  local_90 = (local_90 >> 4) + *(int *)(iVar3 + 0x4c);
  *(int *)(iVar4 + 0x4c) = local_90;
  local_8c = (local_8c >> 4) + *(int *)(iVar3 + 0x50);
  *(int *)(iVar4 + 0x50) = local_8c;
  local_88 = (local_88 >> 4) + *(int *)(iVar3 + 0x54);
  *(int *)(iVar4 + 0x54) = local_88;
  local_38 = (local_48._2_2_ - local_90._2_2_) * 0x10;
  local_36 = (local_44._2_2_ - local_8c._2_2_) * 0x10;
  local_34 = (local_40._2_2_ - local_88._2_2_) * 0x10;
  local_70 = 0x10000000;
  local_6c = 0;
  local_68 = 0x10000000;
  local_64 = 0;
  local_60 = 0x10000000;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  FUN_80041454(-(int)param_3,&local_70);
  FUN_80042824(&local_70,&local_38,&local_30);
  fVar7 = (float)FUN_80047d70((float)local_2c,(float)local_30);
  uVar2 = ((int)psVar5[2] + (int)sVar6) - (int)(fVar7 * 651.8986) & 0xfff;
  if (0x800 < uVar2) {
    uVar2 = uVar2 - 0x1000;
  }
  if ((int)psVar5[3] < (int)uVar2) {
    uVar2 = (int)psVar5[3];
  }
  if ((int)uVar2 < (int)psVar5[4]) {
    uVar2 = (int)psVar5[4];
  }
  *(short *)(iVar4 + 0x5c) = (sVar6 - (short)uVar2) + (short)((int)uVar2 >> 4);
  *(undefined2 *)(iVar4 + 0x58) = 0;
  *(short *)(iVar4 + 0x5a) = param_3;
  FUN_80041018(iVar4 + 0x58,iVar4 + 0x38);
  return;
}
