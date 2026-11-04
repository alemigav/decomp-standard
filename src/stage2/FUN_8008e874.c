/* FUN_8008e874
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008e874  body 0x8008e874..0x8008e977  size 260 B
 * body sha256 2ff164b3c38e25b0a93a0dc796c2745da6e6170a3fafd45e320417ac104732b1
 * provider record sha256 ba8856a125215c15919bae725645ddfd1de1cb63996ac342fb08188d76e37587
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008e874(void)

{
  int iVar1;
  int in_a3;
  uint unaff_s1;
  int unaff_s2;
  int unaff_s3;
  
  iVar1 = unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xc) * 4;
  if (((*(char *)(iVar1 + 0x21819) == (&DAT_8012ffa8)[in_a3 * 8]) &&
      (*(byte *)(iVar1 + 0x21818) < 0x14)) ||
     ((iVar1 = unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xc) * 4, *(char *)(iVar1 + 0x21818) == '\x0f'
      && (*(char *)(iVar1 + 0x21819) == -1)))) {
    *(undefined1 *)(unaff_s2 + 4) = 3;
    *(undefined1 *)(unaff_s2 + 5) = 0;
  }
  else {
    if ((byte)(&DAT_8012ffa8)[in_a3 * 8] < unaff_s1) {
      FUN_8008c33c(*(undefined1 *)(unaff_s2 + 0xc));
      *(char *)(unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xd) * 4 + 0x21819) =
           (char)unaff_s1 - (&DAT_8012ffa8)[in_a3 * 8];
    }
    else {
      FUN_8008c33c(*(undefined1 *)(unaff_s2 + 0xc));
      FUN_8008c314(*(undefined1 *)(unaff_s2 + 0xd),0,0,0);
      FUN_8008cc1c((uint)(*(byte *)(unaff_s2 + 0xd) >> 1) + (uint)*(byte *)(unaff_s2 + 0xd));
    }
    *(undefined1 *)(unaff_s2 + 4) = 1;
    *(undefined1 *)(unaff_s2 + 6) = 0;
    *(undefined1 *)(unaff_s2 + 5) = 0;
    FUN_8008d160(0);
  }
  return;
}
