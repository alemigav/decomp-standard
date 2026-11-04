/* FUN_80092a78
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80092a78  body 0x80092a78..0x80092c9b  size 548 B
 * body sha256 bb11d798498a0ecc36d2c8165b399fda85b92672cd036833f35159900e33a1d8
 * provider record sha256 425e553e2db6f66d571acf798df013cb0042215be8c9dc23d8b1f019f824e1ce
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80092a78(void)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int unaff_s2;
  int unaff_s4;
  
  uVar4 = (uint)*(byte *)(unaff_s2 + 0xc);
  if (-1 < DAT_800e10ec) goto LAB_80092c10;
  if (((*(ushort *)(unaff_s4 + 0x1825c) & 0x2000) != 0) &&
     ((int)uVar4 < (int)(*(byte *)(unaff_s4 + 0x21488) - 1))) {
    if (*(char *)(unaff_s4 + uVar4 * 4 + 0x2181a) == '\x01') {
      *(byte *)(unaff_s2 + 0xc) = *(byte *)(unaff_s2 + 0xc) + 1;
    }
    *(char *)(unaff_s2 + 0xc) = *(char *)(unaff_s2 + 0xc) + '\x01';
  }
  if ((*(ushort *)(unaff_s4 + 0x1825c) & 0x8000) != 0) {
    bVar1 = *(byte *)(unaff_s2 + 0xc);
    uVar3 = (uint)bVar1;
    if ((uVar3 != 0) && (uVar3 != 10)) {
      if (*(char *)(unaff_s4 + uVar3 * 4 + 0x2181a) == '\x02') {
        if (uVar3 == 1) {
          cVar2 = bVar1 + 1;
        }
        else {
          cVar2 = bVar1 - 1;
        }
        *(char *)(unaff_s2 + 0xc) = cVar2;
      }
      *(char *)(unaff_s2 + 0xc) = *(char *)(unaff_s2 + 0xc) + -1;
    }
  }
  if ((*(ushort *)(unaff_s4 + 0x1825c) & 0x4000) != 0) {
    bVar1 = *(byte *)(unaff_s2 + 0xc);
    cVar2 = bVar1 + 2;
    if ((int)(*(byte *)(unaff_s4 + 0x21488) - 2) <= (int)(uint)bVar1) {
      if (bVar1 != 10) goto LAB_80092bac;
      cVar2 = '\x01';
    }
    *(char *)(unaff_s2 + 0xc) = cVar2;
  }
LAB_80092bac:
  if ((*(ushort *)(unaff_s4 + 0x1825c) & 0x1000) != 0) {
    bVar1 = *(byte *)(unaff_s2 + 0xc);
    if ((bVar1 < 2) || (bVar1 == 10)) {
      uVar4 = 10;
      *(char *)(unaff_s2 + 1) = *(char *)(unaff_s2 + 1) + -1;
    }
    else {
      *(byte *)(unaff_s2 + 0xc) = bVar1 - 2;
    }
  }
  if (uVar4 != *(byte *)(unaff_s2 + 0xc)) {
    FUN_80077adc(0x4040000,0);
  }
LAB_80092c10:
  cVar2 = DAT_8012bfae;
  if ((*(uint *)(unaff_s4 + 0x18268) & 0x1000) == 0) {
    if ((*(uint *)(unaff_s4 + 0x18268) & 0x2000) == 0) {
      if (((DAT_800df918 & 0x4000) != 0) && (DAT_8012bfae == '\x01')) {
        FUN_80077adc(0x4050000,0);
        DAT_8012bf99 = cVar2;
      }
    }
    else {
      FUN_80077adc(0x4050000,0);
      *(undefined1 *)(unaff_s2 + 1) = 0;
    }
  }
  else {
    FUN_80077adc(0x4060000,0);
    *(undefined1 *)(unaff_s2 + 2) = 1;
  }
  FUN_8008c25c(0x10,0xaf,6,*(undefined1 *)(unaff_s4 + (uint)*(byte *)(unaff_s2 + 0xc) * 4 + 0x21818)
              );
  return;
}
