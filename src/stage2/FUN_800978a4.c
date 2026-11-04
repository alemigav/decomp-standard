/* FUN_800978a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800978a4  body 0x800978a4..0x80097b67  size 708 B
 * body sha256 41b442e945c238b37dfe2697f0d5ce8b03c660f3b1f2e4d2a29e14d6ab28f05a
 * provider record sha256 e0b0ee2824f88893064494fe7ce1baec85aa05d8a00bbdc9fdf66524852ed54e
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800978a4(void)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  short *psVar8;
  uint uVar9;
  undefined2 *puVar10;
  
  sVar4 = DAT_8012bfce;
  sVar3 = DAT_8012bfcc;
  bVar2 = DAT_800e8b38;
  uVar5 = DAT_800c52dc + 0x3bb64U;
  if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
    uVar5 = DAT_800c52dc + 0x3c004U;
  }
  uVar9 = 7;
  bVar1 = DAT_800e8b38 >> 1;
  DAT_801313da = (DAT_800e8b38 - 6) * 0xf + 0x5d;
  psVar8 = &DAT_801313e0;
  iVar7 = uVar5 + 0x6cc;
  do {
    uVar9 = uVar9 - 1;
    FUN_800479bc(iVar7,5,(uint)bVar1 * 0x1e);
    FUN_800478b8(iVar7,*psVar8 + sVar3,psVar8[1] + sVar4);
    FUN_80043620();
    iVar6 = iVar7 + 0x14;
    DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar7,0,0);
    psVar8 = psVar8 + -2;
    iVar7 = iVar6;
  } while (5 < uVar9);
  psVar8 = (short *)(&UNK_801313c8 + uVar9 * 4);
  do {
    iVar7 = iVar6;
    FUN_800478b8(iVar7,psVar8[-2] + sVar3,psVar8[-1] + sVar4);
    uVar9 = uVar9 - 1;
    if ((DAT_8012bfa8 != '\x01') || (uVar9 != 2)) {
      DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar7,0,0);
    }
    iVar6 = iVar7 + 0x14;
    psVar8 = psVar8 + -2;
  } while (2 < uVar9);
  puVar10 = (undefined2 *)(iVar7 + 0x1e);
  iVar7 = iVar7 + 0x14;
  psVar8 = (short *)(&UNK_801313c8 + uVar9 * 4);
  do {
    uVar9 = uVar9 - 1;
    FUN_800478b8(iVar7,psVar8[-2] + sVar3,psVar8[-1] + sVar4);
    if (uVar9 == 0) {
      if (DAT_800e8ef0 == 'N') {
        FUN_800478ac(iVar7,0x50,0x5a);
      }
      if (DAT_800e8ef0 == 'R') {
        FUN_800478ac(iVar7,0x50,0x78);
      }
    }
    else {
      FUN_800479bc(iVar7,0x50,(uint)(bVar2 >> 1) * 0x1e);
    }
    *(undefined **)(puVar10 + 1) = &DAT_8012f530;
    *puVar10 = 0x200;
    puVar10 = puVar10 + 10;
    DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar7,0,0);
    iVar7 = iVar7 + 0x14;
    psVar8 = psVar8 + -2;
  } while (uVar9 != 0);
  return;
}
