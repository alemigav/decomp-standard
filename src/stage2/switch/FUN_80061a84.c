/* FUN_80061a84
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80061a84  body 0x80061a84..0x80061b17  size 148 B
 * body sha256 eeca6516f7816a2eee4af17575def9c9637bd70b315dc16d0972087641214f73
 * provider record sha256 0d18abee5776e5983f2cd7d157bb9e4c390d0eb75f5929fb5b914440db85fd89
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80061694::caseD_4(void)

{
  char cVar2;
  int iVar1;
  int unaff_s0;
  uint unaff_s2;
  
  cVar2 = FUN_80089d54();
  *(char *)(unaff_s0 + 7) = *(char *)(unaff_s0 + 7) + cVar2;
  if ((unaff_s2 & 0x40) != 0) {
    iVar1 = FUN_8008cce4(*(ushort *)(unaff_s0 + 0x1aa) & 0xfff);
    if (iVar1 != 0) {
      *(undefined2 *)(unaff_s0 + 6) = 0x201;
      return;
    }
    if ((DAT_800df918 & 0x40) != 0) {
      cVar2 = FUN_8008d00c();
      if (cVar2 == '\0') {
        FUN_80077adc(0x1010001,unaff_s0 + 0x28);
      }
      else {
        *(undefined2 *)(unaff_s0 + 6) = 0x400;
      }
    }
  }
  cVar2 = DAT_800df8c0;
  if (((unaff_s2 & 8) != 0) || (DAT_800df8c0 < -0x19)) {
    *(short *)(unaff_s0 + 0x66) = *(short *)(unaff_s0 + 0x66) + -0x20;
  }
  if (((unaff_s2 & 2) != 0) || ('\x19' < cVar2)) {
    *(short *)(unaff_s0 + 0x66) = *(short *)(unaff_s0 + 0x66) + 0x20;
  }
  return;
}
