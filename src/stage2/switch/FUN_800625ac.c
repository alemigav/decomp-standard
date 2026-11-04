/* FUN_800625ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800625ac  body 0x800625ac..0x8006267b  size 208 B
 * body sha256 4d0286100a4dcef479ce7c291d117328d7d913c270cb6990e73496d75b89aaa2
 * provider record sha256 1ec9544e3e1acfca3fc0f3de4cfb0fc29cbddc33f9b64547327e6d88d0b33fce
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void switchD_800625a4::caseD_0(void)

{
  char cVar1;
  int iVar2;
  int unaff_s0;
  uint unaff_s3;
  
  *(undefined4 *)(unaff_s0 + 0x1e8) = 0xa000700;
  *(ushort *)(unaff_s0 + 0x1f0) = *(ushort *)(unaff_s0 + 0x1f0) | 0x4000;
  (*(code *)(&PTR_LAB_8011102c)[(*(ushort *)(unaff_s0 + 0x1aa) & 0xfff) - 1])();
  FUN_8005ab10();
  *(undefined1 *)(unaff_s0 + 7) = 1;
  FUN_80077adc(0x10b0001,unaff_s0 + 0x28);
  FUN_80052d10(0xf,0,(&DAT_80110f6e)[((*(ushort *)(unaff_s0 + 0x1aa) & 0xfff) - 2) * 6],0);
  FUN_8005c308();
  iVar2 = FUN_80089d54();
  if (iVar2 != 0) {
    *(undefined4 *)(unaff_s0 + 0x1e8) = 0xb000700;
    *(undefined1 *)(unaff_s0 + 7) = 2;
  }
  cVar1 = DAT_800df8c0;
  if (((unaff_s3 & 8) != 0) || (DAT_800df8c0 < -0x19)) {
    *(short *)(unaff_s0 + 0x66) = *(short *)(unaff_s0 + 0x66) + -8;
  }
  if (((unaff_s3 & 2) != 0) || ('\x19' < cVar1)) {
    *(short *)(unaff_s0 + 0x66) = *(short *)(unaff_s0 + 0x66) + 8;
  }
  return;
}
