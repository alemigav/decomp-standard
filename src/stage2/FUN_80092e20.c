/* FUN_80092e20
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80092e20  body 0x80092e20..0x80092ffb  size 476 B
 * body sha256 6dd62b26fe5f68af5e371f3892b993cc7daba170c91321b9313b5a0ab4f08f0b
 * provider record sha256 89223743f217cdb8675ddd0e4ecf5985e1d2e8f319c73e0f75739fa713f92c1a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80092e20(void)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int unaff_s2;
  int unaff_s4;
  
  bVar1 = *(byte *)(unaff_s2 + 3);
  *(undefined1 *)(unaff_s2 + 0x16) = 0;
  *(byte *)(unaff_s2 + 3) = bVar1 + 1;
  if (bVar1 < 6) {
    *(char *)(unaff_s2 + 0x25) = *(char *)(unaff_s2 + 0x25) + '\x03';
  }
  else {
    if ((*(ushort *)(unaff_s4 + 0x1825c) & 0x1000) == 0) {
      *(undefined1 *)(unaff_s2 + 2) = 1;
    }
    else {
      FUN_80077adc(0x2140000,0);
    }
    *(undefined1 *)(unaff_s2 + 0x25) = 0;
    *(undefined1 *)(unaff_s2 + 3) = 0;
    *(byte *)(unaff_s2 + 0x24) = *(char *)(unaff_s2 + 0x24) - 1U & 0x3f;
    uVar4 = (uint)*(byte *)(unaff_s4 + (*(byte *)(unaff_s2 + 0x24) - 1 & 0x3f) * 4 + 0x21844);
    uVar5 = DAT_800c52dc + 0x3bb64U;
    if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
      uVar5 = DAT_800c52dc + 0x3c004U;
    }
    FUN_8008ca0c(7,uVar4,uVar5 + uVar4 * 0x4b0 + 0xa64);
    iVar7 = 0;
    iVar8 = 10;
    do {
      uVar4 = (uint)*(byte *)(unaff_s4 + ((uint)*(byte *)(unaff_s2 + 0x24) + iVar7 & 0x3f) * 4 +
                             0x21844);
      uVar5 = DAT_800c52dc + 0x3bb64U;
      if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
        uVar5 = DAT_800c52dc + 0x3c004U;
      }
      FUN_8008ca0c(iVar8,uVar4,uVar5 + uVar4 * 0x4b0 + 0xa64);
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + 3;
    } while (iVar7 < 5);
  }
  cVar6 = *(char *)(unaff_s4 + (*(byte *)(unaff_s2 + 0x24) - 1 & 0x3f) * 4 + 0x21844);
  if (cVar6 == '\0') {
    cVar6 = 'd';
    sVar2 = *(short *)(unaff_s2 + 0x50);
    sVar3 = *(short *)(unaff_s2 + 0x52);
  }
  else {
    sVar2 = *(short *)(unaff_s2 + 0x50);
    sVar3 = *(short *)(unaff_s2 + 0x52);
  }
  FUN_8008c25c(sVar2 + 7,(int)sVar3 + DAT_8012bfbd + 9,6,cVar6);
  FUN_8008c25c(0x10,0xaf,6,*(undefined1 *)(unaff_s4 + (uint)*(byte *)(unaff_s2 + 0xc) * 4 + 0x21818)
              );
  return;
}
