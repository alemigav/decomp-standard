/* FUN_800736b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800736b0  body 0x800736b0..0x80073ac3  size 1044 B
 * body sha256 4f65cd69bd385257d01ffdcf2b6e68a41d5fa0365c77b065405d229bdb83ac08
 * provider record sha256 881946bc6a3e6133b010656fa5ccf982a2093e770563358b428551ecd173dcf0
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800736b0(int param_1,uint param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  byte *pbVar5;
  byte *pbVar6;
  short sVar7;
  uint uVar8;
  undefined4 *puVar9;
  short local_60 [2];
  short local_5c;
  int local_58 [2];
  int local_50;
  short local_48;
  short sStack_46;
  short local_44;
  short local_42;
  short local_40;
  short local_3e;
  short local_3c;
  short local_3a;
  short local_38;
  short local_36;
  uint local_30;
  
  uVar8 = 0;
  local_60[0] = 0x26c;
  local_5c = 0;
  FUN_800837d0((int)*(short *)(param_1 + 0x66),local_60,local_60);
  local_58[0] = (int)local_60[0] + *(int *)(param_1 + 0x28);
  local_30 = (uint)DAT_800e8604;
  local_50 = (int)local_5c + *(int *)(param_1 + 0x30);
  DAT_800df938 = param_1;
  if (local_30 != 0) {
    sVar7 = 0;
    puVar9 = &DAT_800c76b0;
    do {
      pbVar6 = (byte *)puVar9[0x612c];
      DAT_801152cc = pbVar6;
      if (pbVar6 != (byte *)0x0) {
        DAT_801152d0 = (int)DAT_800e8c78;
        DAT_801152d4 = (int)DAT_800e8c7a;
        uVar8 = uVar8 + 1;
        if ((((pbVar6[1] & param_2) != 0) && ((pbVar6[1] & 0x10) == param_3)) &&
           (((pbVar6[2] & 0x80) != 0 || (*(byte *)(param_1 + 0x1a2) == pbVar6[2])))) {
          bVar1 = pbVar6[3];
          if ((bVar1 & 0x80) == 0) {
            sStack_46 = 0;
            local_48 = 0;
          }
          else if ((bVar1 & 0x40) == 0) {
            local_48 = (&DAT_800e1922)[(bVar1 & 0x3f) * 0x1b4];
            sStack_46 = (&DAT_800e192a)[(pbVar6[3] & 0x3f) * 0x1b4];
          }
          else {
            local_48 = *(short *)((&DAT_800e13e8)[bVar1 & 0x3f] + 0x2a);
            sStack_46 = *(short *)((&DAT_800e13e8)[pbVar6[3] & 0x3f] + 0x32);
          }
          if ((pbVar6[1] & 0x80) == 0) {
            local_44 = *(short *)(pbVar6 + 4);
            local_42 = *(short *)(pbVar6 + 6);
            local_40 = *(short *)(pbVar6 + 8);
            local_3e = *(short *)(pbVar6 + 10);
          }
          else {
            local_44 = *(short *)(pbVar6 + 4);
            local_42 = *(short *)(pbVar6 + 6);
            local_40 = local_48 + *(short *)(pbVar6 + 8);
            local_3e = sStack_46 + *(short *)(pbVar6 + 10);
            local_3c = local_48 + *(short *)(pbVar6 + 0xc);
            local_3a = sStack_46 + *(short *)(pbVar6 + 0xe);
            local_38 = local_48 + *(short *)(pbVar6 + 0x10);
            local_36 = sStack_46 + *(short *)(pbVar6 + 0x12);
          }
          local_42 = sStack_46 + local_42;
          local_44 = local_48 + local_44;
          bVar1 = pbVar6[1];
          if ((bVar1 & 0x40) == 0) {
LAB_80073998:
            if ((bVar1 & 0x20) != 0) {
              if ((bVar1 & 0x80) == 0) {
                iVar2 = FUN_80083e14(local_58,&local_44);
              }
              else {
                iVar2 = FUN_80083d2c(local_58,&local_48);
              }
              if (iVar2 != 0) {
                DAT_800e8c78 = sVar7;
                goto LAB_800739d0;
              }
            }
          }
          else {
            if ((bVar1 & 0x80) == 0) {
              iVar2 = FUN_80083e14(param_1 + 0x28,&local_44);
            }
            else {
              iVar2 = FUN_80083d2c(param_1 + 0x28,&local_48);
            }
            if (iVar2 == 0) {
              bVar1 = pbVar6[1];
              goto LAB_80073998;
            }
            DAT_800e8c7a = sVar7;
LAB_800739d0:
            if (param_3 == 0) {
              *(char *)(param_1 + 0xb) = (char)sVar7;
              pbVar5 = pbVar6 + 0x14;
              if ((pbVar6[1] & 0x80) == 0) {
                pcVar4 = (code *)(&PTR_LAB_80115290)[*pbVar6];
                pbVar5 = pbVar6 + 0xc;
              }
              else {
                pcVar4 = (code *)(&PTR_LAB_80115290)[*pbVar6];
              }
              (*pcVar4)(pbVar5);
            }
            else if (*pbVar6 != 0) {
              *(char *)(param_1 + 0xb) = (char)sVar7;
              if ((pbVar6[1] & 0x80) == 0) {
                uVar3 = (*(code *)(&PTR_LAB_80115290)[*pbVar6])(pbVar6 + 0xc);
                return uVar3;
              }
              uVar3 = (*(code *)(&PTR_LAB_80115290)[*pbVar6])(pbVar6 + 0x14);
              return uVar3;
            }
          }
        }
      }
      sVar7 = sVar7 + 1;
      puVar9 = puVar9 + 1;
    } while (uVar8 < local_30);
  }
  return 0;
}
