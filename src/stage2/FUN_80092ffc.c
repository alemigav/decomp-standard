/* FUN_80092ffc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80092ffc  body 0x80092ffc..0x800931c7  size 460 B
 * body sha256 dc05f122413e1fd22c6e700ae8aea44336d227fc0b5e7000f5c69c098d30a738
 * provider record sha256 0c4c67c0953e7fc6f3c87a19adfc72c488bb77b596a5a0c8268c39a79566f878
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80092ffc(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int unaff_s2;
  int unaff_s4;
  
  bVar1 = *(byte *)(unaff_s2 + 3);
  *(undefined1 *)(unaff_s2 + 0x16) = 0;
  *(byte *)(unaff_s2 + 3) = bVar1 + 1;
  if (bVar1 < 6) {
    *(char *)(unaff_s2 + 0x25) = *(char *)(unaff_s2 + 0x25) + -3;
  }
  else {
    if ((*(ushort *)(unaff_s4 + 0x1825c) & 0x4000) == 0) {
      *(undefined1 *)(unaff_s2 + 2) = 1;
    }
    else {
      FUN_80077adc(0x2140000,0);
    }
    *(undefined1 *)(unaff_s2 + 0x25) = 0;
    *(undefined1 *)(unaff_s2 + 3) = 0;
    uVar2 = *(byte *)(unaff_s2 + 0x24) + 1 & 0x3f;
    *(char *)(unaff_s2 + 0x24) = (char)uVar2;
    uVar3 = (uint)*(byte *)(unaff_s4 + (uVar2 + 5 & 0x3f) * 4 + 0x21844);
    uVar2 = DAT_800c52dc + 0x3bb64U;
    if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
      uVar2 = DAT_800c52dc + 0x3c004U;
    }
    FUN_8008ca0c(7,uVar3,uVar2 + uVar3 * 0x4b0 + 0xa64);
    iVar5 = 0;
    iVar6 = 10;
    do {
      uVar3 = (uint)*(byte *)(unaff_s4 + ((uint)*(byte *)(unaff_s2 + 0x24) + iVar5 & 0x3f) * 4 +
                             0x21844);
      uVar2 = DAT_800c52dc + 0x3bb64U;
      if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
        uVar2 = DAT_800c52dc + 0x3c004U;
      }
      FUN_8008ca0c(iVar6,uVar3,uVar2 + uVar3 * 0x4b0 + 0xa64);
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 3;
    } while (iVar5 < 5);
  }
  cVar4 = *(char *)(unaff_s4 + (*(byte *)(unaff_s2 + 0x24) + 5 & 0x3f) * 4 + 0x21844);
  if (cVar4 == '\0') {
    cVar4 = 'd';
  }
  FUN_8008c25c(*(short *)(unaff_s2 + 0x50) + 7,
               (int)*(short *)(unaff_s2 + 0x52) + DAT_8012bfbd + 0x81,6,cVar4);
  FUN_8008c25c(0x10,0xaf,6,*(undefined1 *)(unaff_s4 + (uint)*(byte *)(unaff_s2 + 0xc) * 4 + 0x21818)
              );
  return;
}
