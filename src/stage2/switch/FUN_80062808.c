/* FUN_80062808
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80062808  body 0x80062808..0x8006289b  size 148 B
 * body sha256 e8d9b722842d24e0deb11044a847c0a2cc8d1ff2b8c8995ebdb9b856d7468c72
 * provider record sha256 2f320cf05f4bd4668b187cec9ed188dc0ee78cc39aa60026b7605f2e34904f02
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void switchD_800625a4::caseD_4(void)

{
  char cVar2;
  int iVar1;
  int unaff_s0;
  uint unaff_s3;
  
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
