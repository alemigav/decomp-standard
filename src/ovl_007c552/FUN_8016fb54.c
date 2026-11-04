/* FUN_8016fb54
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x8016fb54  body 0x8016fb54..0x8016fe2f  size 732 B
 * body sha256 a5443036625bca0ea8a988f2d2c221b82aff5512f464726d90975b4095053a1e
 * provider record sha256 b02de72473470070d20c505a6e381a9ef93a6e9460e37967de167fd320c964ee
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8016fdf8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016fb54(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  short sVar5;
  byte *pbVar6;
  short *psVar7;
  byte *pbVar8;
  int iVar9;
  undefined4 local_60;
  short local_5c;
  short local_5a;
  undefined1 local_58;
  undefined1 local_57;
  short local_56;
  short local_54;
  short local_52;
  char local_50;
  undefined1 local_4f;
  ushort local_4e;
  short local_4c;
  short local_4a;
  undefined1 local_48;
  char local_47;
  undefined2 local_46;
  short local_44;
  short local_42;
  char local_40;
  char local_3f;
  undefined *local_3c;
  int local_38;
  uint local_30;
  
  pbVar8 = &DAT_80171aac;
  local_30 = 0xff;
  psVar7 = (short *)&UNK_80171ab2;
  local_46 = 0;
  local_38 = 0x1f;
  do {
    local_38 = local_38 + -1;
    if ((*(byte *)((int)psVar7 + -5) & 0x20) != 0) {
      *pbVar8 = 0;
    }
    if ((*pbVar8 & 1) != 0) {
      pbVar6 = &DAT_80171c20;
      uVar4 = 0;
      if (*(byte *)((int)psVar7 + -3) != 0) {
        do {
          if (*pbVar6 == local_30) {
            uVar4 = uVar4 + 1;
          }
          pbVar6 = pbVar6 + 1;
        } while (*(byte *)((int)psVar7 + -3) != uVar4);
      }
      iVar9 = 0x2c;
      if ((*pbVar8 & 8) != 0) {
        iVar9 = 0x2e;
        uVar4 = *(int *)(psVar7 + 1) - DAT_80171df0;
        *(uint *)(psVar7 + 1) = uVar4;
        if (0x80807fff < uVar4) {
          *pbVar8 = 0;
          psVar7[1] = 0;
          psVar7[2] = 0;
        }
      }
      if ((*pbVar8 & 4) != 0) {
        iVar9 = 0x2e;
        uVar4 = *(int *)(psVar7 + 1) + DAT_80171df0;
        *(uint *)(psVar7 + 1) = uVar4;
        if (0x80807fff < uVar4) {
          iVar9 = 0x2c;
          *pbVar8 = *pbVar8 & 0xfb;
          psVar7[1] = -0x7f80;
          psVar7[2] = -0x8000;
        }
      }
      sVar5 = psVar7[-1];
      iVar9 = iVar9 + *(int *)(psVar7 + 1);
      sVar1 = *psVar7;
      if (*pbVar6 != local_30) {
        do {
          func_0x80043620();
          iVar3 = (uint)*pbVar6 * 10;
          local_50 = (&DAT_80171874)[iVar3] + (&DAT_80171876)[iVar3];
          local_47 = (&DAT_80171875)[iVar3] + (&DAT_80171877)[iVar3];
          local_54 = sVar5 + (ushort)(byte)(&DAT_80171878)[iVar3];
          local_60._2_1_ = (char)((uint)iVar9 >> 8);
          local_4a = sVar1 + (ushort)(byte)(&DAT_80171879)[iVar3];
          iVar2 = iVar9;
          if (local_60._2_1_ != '\0') {
            local_60._0_2_ = (undefined2)((uint)iVar9 >> 0x10);
            local_60 = (uint)CONCAT21(local_60._0_2_,(local_60._2_1_ + -1) * '\x02') << 8;
            iVar2 = local_60;
          }
          local_60 = iVar2;
          local_58 = (&DAT_80171874)[iVar3];
          local_57 = (&DAT_80171875)[iVar3];
          local_56 = *(short *)(&DAT_80171872 + iVar3) << 3;
          local_4f = (&DAT_80171875)[iVar3];
          pbVar6 = pbVar6 + 1;
          local_4e = *(short *)(&DAT_80171870 + iVar3) + 0x80;
          local_48 = (&DAT_80171874)[iVar3];
          local_3c = (&PTR_DAT_80171cc8)[(int)(local_4e - 0x88) >> 1];
          local_60 = CONCAT31(local_60._0_3_,4);
          local_5c = sVar5;
          local_5a = sVar1;
          local_52 = sVar1;
          local_4c = sVar5;
          local_44 = local_54;
          local_42 = local_4a;
          local_40 = local_50;
          local_3f = local_47;
          _DAT_800df8b4 = func_0x80044fdc(_DAT_800df8b4,&local_60,0);
          sVar5 = sVar5 + (ushort)(byte)(&DAT_80171878)[iVar3];
        } while (*pbVar6 != local_30);
      }
    }
    psVar7 = psVar7 + 6;
    pbVar8 = pbVar8 + 0xc;
  } while (local_38 != 0);
  return;
}
