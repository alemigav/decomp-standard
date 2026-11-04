/* FUN_80097174
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80097174  body 0x80097174..0x80097363  size 496 B
 * body sha256 309108ee17aefeef0c7806435123cbdd0551b95e7cae7e6562f0f100f5fe39aa
 * provider record sha256 d87e8cc910630ca3fae6fff720aef5124e01bcc0ad091c8e25d2c347ec4e7aac
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80097174(void)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  short *psVar7;
  uint uVar8;
  uint uVar9;
  undefined2 *puVar10;
  
  sVar3 = DAT_8012bfde;
  sVar2 = DAT_8012bfdc;
  uVar4 = DAT_800c52dc + 0x3bb64U;
  if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
    uVar4 = DAT_800c52dc + 0x3c004U;
  }
  uVar9 = 8;
  psVar7 = (short *)&DAT_80131364;
  uVar4 = uVar4 + 0x8ac;
  do {
    uVar8 = uVar4;
    uVar9 = uVar9 - 1;
    FUN_800478b8(uVar8,psVar7[-2] + sVar2,psVar7[-1] + sVar3);
    psVar7 = psVar7 + -2;
    uVar4 = uVar8 + 0x14;
  } while (4 < uVar9);
  puVar10 = (undefined2 *)(uVar8 + 0x1e);
  psVar7 = (short *)(&UNK_80131344 + uVar9 * 4);
  do {
    uVar8 = uVar4;
    uVar9 = uVar9 - 1;
    if ((DAT_8012bfa8 == '\0') && (DAT_8012bfa6 == uVar9)) {
      uVar5 = 0x80;
      if (DAT_8012bf99 < 3) goto LAB_8009728c;
      uVar6 = 0x40;
    }
    else {
      uVar5 = 0x28;
LAB_8009728c:
      uVar6 = uVar5;
    }
    FUN_8004786c(uVar8,uVar5,uVar6,uVar6);
    FUN_800478b8(uVar8,psVar7[-2] + sVar2,psVar7[-1] + sVar3);
    *(undefined **)(puVar10 + 1) = &DAT_8012f584;
    *puVar10 = 0xc0;
    puVar10 = puVar10 + 10;
    psVar7 = psVar7 + -2;
    uVar4 = uVar8 + 0x14;
    if (uVar9 == 0) {
      do {
        DAT_800df8b4 = FUN_80043988(DAT_800df8b4,uVar8,0,0);
        uVar4 = DAT_800c52dc + 0x3bb64U;
        if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
          uVar4 = DAT_800c52dc + 0x3c004U;
        }
        bVar1 = uVar4 + 0x8ac < uVar8;
        uVar8 = uVar8 - 0x14;
      } while (bVar1);
      return;
    }
  } while( true );
}
