/* FUN_800627e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800627e0  body 0x800627e0..0x80062807  size 40 B
 * body sha256 e17b9db37e09f9af5f5d82a283e835cfc15080b720fb39e75dcd9dbaa94cdc69
 * provider record sha256 dfda28afe21691e72a05240108123380b475a936ea4c839b8d169b03a1479c37
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_800625a4::caseD_3(void)

{
  char cVar2;
  int iVar1;
  int unaff_s0;
  uint unaff_s3;
  
  *(undefined4 *)(unaff_s0 + 0x1e8) = 0xd000700;
  *(undefined1 *)(unaff_s0 + 7) = 4;
  *(undefined2 *)(unaff_s0 + 0x1e0) = 0;
  FUN_80077adc(0x10c0001,unaff_s0 + 0x28);
  cVar2 = FUN_80089d54();
  *(char *)(unaff_s0 + 7) = *(char *)(unaff_s0 + 7) + cVar2;
  if ((unaff_s3 & 0x40) != 0) {
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
  if (((unaff_s3 & 8) != 0) || (DAT_800df8c0 < -0x19)) {
    *(short *)(unaff_s0 + 0x66) = *(short *)(unaff_s0 + 0x66) + -8;
  }
  if (((unaff_s3 & 2) != 0) || ('\x19' < cVar2)) {
    *(short *)(unaff_s0 + 0x66) = *(short *)(unaff_s0 + 0x66) + 8;
  }
  return;
}
