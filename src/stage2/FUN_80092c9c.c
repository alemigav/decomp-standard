/* FUN_80092c9c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80092c9c  body 0x80092c9c..0x8009320b  size 392 B
 * body sha256 2588c610bf2660cfce892ff8a91c9f4fc960a27d06ecad86f6b3ac3752376c0f
 * provider record sha256 1fc1870c98679ac8f594600c18b8712a4caf6778145902e7f9f23f094aafeb9e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80092c9c(void)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  int unaff_s2;
  int unaff_s4;
  
  if (DAT_800e10ec < 0) {
    uVar3 = *(ushort *)(unaff_s4 + 0x1825c);
    if ((uVar3 & 0x1000) == 0) {
      if ((uVar3 & 0x4000) == 0) {
        if ((uVar3 & 4) == 0) {
          if ((uVar3 & 8) == 0) goto LAB_80092dd8;
          FUN_80077adc(0x4060000,0);
          bVar5 = *(char *)(unaff_s2 + 0x24) + 5;
        }
        else {
          FUN_80077adc(0x4060000,0);
          bVar5 = *(char *)(unaff_s2 + 0x24) - 5;
        }
        *(byte *)(unaff_s2 + 0x24) = bVar5 & 0x3f;
        uVar6 = (uint)*(byte *)(unaff_s4 + (*(byte *)(unaff_s2 + 0x24) - 1 & 0x3f) * 4 + 0x21844);
        uVar4 = DAT_800c52dc + 0x3bb64U;
        if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
          uVar4 = DAT_800c52dc + 0x3c004U;
        }
        FUN_8008ca0c(7,uVar6,uVar4 + uVar6 * 0x4b0 + 0xa64);
        iVar8 = 0;
        iVar9 = 10;
        do {
          uVar6 = (uint)*(byte *)(unaff_s4 + ((uint)*(byte *)(unaff_s2 + 0x24) + iVar8 & 0x3f) * 4 +
                                 0x21844);
          uVar4 = DAT_800c52dc + 0x3bb64U;
          if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
            uVar4 = DAT_800c52dc + 0x3c004U;
          }
          FUN_8008ca0c(iVar9,uVar6,uVar4 + uVar6 * 0x4b0 + 0xa64);
          iVar8 = iVar8 + 1;
          iVar9 = iVar9 + 3;
        } while (iVar8 < 5);
        cVar7 = *(char *)(unaff_s4 + (*(byte *)(unaff_s2 + 0x24) - 1 & 0x3f) * 4 + 0x21844);
        if (cVar7 == '\0') {
          cVar7 = 'd';
          sVar1 = *(short *)(unaff_s2 + 0x50);
          sVar2 = *(short *)(unaff_s2 + 0x52);
        }
        else {
          sVar1 = *(short *)(unaff_s2 + 0x50);
          sVar2 = *(short *)(unaff_s2 + 0x52);
        }
        FUN_8008c25c(sVar1 + 7,(int)sVar2 + DAT_8012bfbd + 9,6,cVar7);
        goto LAB_8009320c;
      }
      FUN_80077adc(0x2140000,0);
      *(undefined1 *)(unaff_s2 + 2) = 3;
      uVar4 = *(byte *)(unaff_s2 + 0x24) + 5;
    }
    else {
      FUN_80077adc(0x2140000,0);
      *(undefined1 *)(unaff_s2 + 2) = 2;
      uVar4 = *(byte *)(unaff_s2 + 0x24) - 1;
    }
    uVar6 = (uint)*(byte *)(unaff_s4 + (uVar4 & 0x3f) * 4 + 0x21844);
    uVar4 = DAT_800c52dc + 0x3bb64U;
    if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
      uVar4 = DAT_800c52dc + 0x3c004U;
    }
    FUN_8008ca0c(7,uVar6,uVar4 + uVar6 * 0x4b0 + 0xa64);
  }
  else {
LAB_80092dd8:
    if ((*(uint *)(unaff_s4 + 0x18268) & 0x2000) == 0) {
      if ((*(uint *)(unaff_s4 + 0x18268) & 0x1000) != 0) {
        FUN_80077adc(0x4060000,0);
        *(undefined1 *)(unaff_s2 + 2) = 4;
      }
    }
    else {
      FUN_80077adc(0x4050000,0);
      *(undefined1 *)(unaff_s2 + 2) = 0;
    }
  }
LAB_8009320c:
  FUN_8008c25c(0x10,0xaf,6,*(undefined1 *)(unaff_s4 + (uint)*(byte *)(unaff_s2 + 0xc) * 4 + 0x21818)
              );
  return;
}
