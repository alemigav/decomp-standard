/* FUN_80097578
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80097578  body 0x80097578..0x80097763  size 492 B
 * body sha256 b2b1987a9fdebf5a7640e1922215834d308965dd4617c5179704964435a00812
 * provider record sha256 717eadd255046dcda42bb29d0a3aeeab186e66677b2f147a6c772b3581574c5f
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80097578(int param_1)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  undefined4 uVar5;
  short *psVar6;
  uint uVar7;
  uint uVar8;
  undefined2 *puVar9;
  uint uVar10;
  
  sVar3 = DAT_8012bfe2;
  sVar2 = DAT_8012bfe0;
  uVar4 = DAT_800c52dc + 0x3bb64U;
  if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
    uVar4 = DAT_800c52dc + 0x3c004U;
  }
  uVar10 = (uint)DAT_8012bfa7;
  FUN_80043620();
  if (param_1 == 0) {
    DAT_8013138a = 0x38;
    uVar7 = 8;
  }
  else {
    DAT_8013138a = 0x4d;
    uVar7 = 9;
  }
  psVar6 = (short *)(&UNK_80131388 + uVar7 * 4);
  uVar4 = uVar4 + 0x94c;
  do {
    uVar8 = uVar4;
    uVar7 = uVar7 - 1;
    FUN_800478b8(uVar8,psVar6[-2] + sVar2,psVar6[-1] + sVar3);
    psVar6 = psVar6 + -2;
    uVar4 = uVar8 + 0x14;
  } while (4 < uVar7);
  puVar9 = (undefined2 *)(uVar8 + 0x1e);
  psVar6 = (short *)(&UNK_80131388 + uVar7 * 4);
  do {
    uVar8 = uVar4;
    uVar7 = uVar7 - 1;
    if (uVar7 == uVar10) {
      uVar5 = 0x40;
    }
    else {
      uVar5 = 0x80;
    }
    FUN_8004786c(uVar8,uVar5,uVar5,0x80);
    FUN_800478b8(uVar8,psVar6[-2] + sVar2,psVar6[-1] + sVar3);
    *(undefined **)(puVar9 + 1) = &DAT_8012f584;
    *puVar9 = 0;
    puVar9 = puVar9 + 10;
    psVar6 = psVar6 + -2;
    uVar4 = uVar8 + 0x14;
  } while (uVar7 != 0);
  do {
    DAT_800df8b0 = FUN_80043988(DAT_800df8b0,uVar8,0,0);
    uVar4 = DAT_800c52dc + 0x3bb64U;
    if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
      uVar4 = DAT_800c52dc + 0x3c004U;
    }
    bVar1 = uVar4 + 0x94c < uVar8;
    uVar8 = uVar8 - 0x14;
  } while (bVar1);
  return;
}
