/* FUN_8004bbf4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004bbf4  body 0x8004bbf4..0x8004bf6b  size 888 B
 * body sha256 0414939dd6721b3a376554a53e921f7ed23c1c865eda3e8aa58eb5fa5042d5ce
 * provider record sha256 4d77a12ddae79f7ba318b083e0f3592f77124e7c7c999264968b1114dd12e12e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004bbf4(int param_1)

{
  ushort uVar1;
  short sVar2;
  char cVar3;
  byte bVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  short sVar11;
  byte *unaff_s8;
  
  puVar10 = DAT_8010aa88;
  sVar11 = 0;
  *(undefined2 *)(param_1 + 0xd022) = *(undefined2 *)(param_1 + 0xd026);
  uVar9 = CONCAT22(*(undefined2 *)(param_1 + 0xd026),*(undefined2 *)(param_1 + 0xd024));
  uVar1 = *(ushort *)(param_1 + 0xd028);
  if (*(byte **)(param_1 + 0xd014) != *(byte **)(param_1 + 0xd018)) {
    puVar8 = puVar10 + 4;
    pbVar5 = *(byte **)(param_1 + 0xd014);
    do {
      iVar7 = 0xe;
      if (*pbVar5 == 0) {
        if ((uVar1 & 0x4000) != 0) {
          iVar7 = 8;
        }
switchD_8004bcb8_caseD_f5:
        goto LAB_8004bee0;
      }
      switch(*pbVar5) {
      case 0xee:
        pbVar5 = pbVar5 + 1;
        cVar3 = (*pbVar5 / 0x12) * '\x0e' + -0x2e;
        goto LAB_8004bdec;
      case 0xef:
        pbVar5 = pbVar5 + 1;
        cVar3 = (*pbVar5 / 0x12) * '\x0e';
        goto LAB_8004bdec;
      case 0xf0:
        pbVar5 = pbVar5 + 1;
        cVar3 = (*pbVar5 / 0x12) * '\x0e' + -0x3c;
        goto LAB_8004bdec;
      default:
        cVar3 = (*pbVar5 / 0x12) * '\x0e' + '\x1c';
LAB_8004bdec:
        *(char *)((int)puVar8 + -7) = cVar3;
        if ((((uVar1 & 0x4000) != 0) && (*pbVar5 < 0x57)) && (2 < pbVar5[-1] - 0xee)) {
          iVar7 = (uint)*pbVar5 * 2;
          uVar9 = uVar9 - (int)(char)(&DAT_800f9ec0)[iVar7];
          iVar7 = (int)(char)(&DAT_800f9ec1)[iVar7] + (int)(char)(&DAT_800f9ec0)[iVar7];
        }
        puVar8[-3] = uVar9 << 0x10 | uVar9 >> 0x10;
        *puVar10 = 0x64808080;
        puVar10 = puVar10 + 5;
        bVar4 = *pbVar5;
        *(short *)((int)puVar8 + -6) = sVar11;
        *(undefined1 *)((int)puVar8 + -0xd) = 0;
        puVar8[-1] = &DAT_8010b2bc;
        *puVar8 = 0xe000e;
        *(byte *)(puVar8 + -2) = (bVar4 % 0x12) * '\x0e';
        puVar8 = puVar8 + 5;
        if (puVar10 == (undefined4 *)&UNK_800ff688) goto LAB_8004bef0;
LAB_8004bee0:
        pbVar6 = pbVar5 + 1;
        uVar9 = uVar9 + iVar7;
        break;
      case 0xf5:
        goto switchD_8004bcb8_caseD_f5;
      case 0xf7:
        pbVar6 = unaff_s8 + 2;
        break;
      case 0xf8:
        bVar4 = pbVar5[1];
        if (bVar4 == 0) {
          bVar4 = *(byte *)(param_1 + 0xd00f);
        }
        pbVar6 = (byte *)FUN_8004bad8(bVar4);
        unaff_s8 = pbVar5;
        break;
      case 0xf9:
        pbVar6 = pbVar5 + 2;
        sVar11 = (pbVar5[1] & 0xf) << 7;
        break;
      case 0xfc:
        pbVar6 = pbVar5 + 1;
        sVar2 = *(short *)(param_1 + 0xd022);
        *(short *)(param_1 + 0xd022) = sVar2 + 0x10;
        uVar9 = CONCAT22(sVar2 + 0x10,*(undefined2 *)(param_1 + 0xd024));
        break;
      case 0xfd:
        *(undefined2 *)(param_1 + 0xd022) = *(undefined2 *)(param_1 + 0xd026);
      case 0xfa:
        pbVar5 = pbVar5 + 1;
      case 0xfe:
        pbVar6 = pbVar5 + 1;
        *(undefined2 *)(param_1 + 0xd022) = *(undefined2 *)(param_1 + 0xd026);
      }
      pbVar5 = pbVar6;
    } while (pbVar6 != *(byte **)(param_1 + 0xd018));
  }
LAB_8004bef0:
  if (DAT_8010aa88 != puVar10) {
    DAT_800df8b4 = FUN_80043868(DAT_800df8b4,DAT_8010aa88,puVar10);
  }
  DAT_8010aa88 = puVar10;
  *(short *)(param_1 + 0xd020) = (short)uVar9;
  return;
}
