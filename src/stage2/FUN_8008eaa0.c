/* FUN_8008eaa0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008eaa0  body 0x8008eaa0..0x8008ebf3  size 340 B
 * body sha256 20247883a5ef4049c245f8fa6ad53211e5e8654d8b9b2a939c1eba06db6ef7fd
 * provider record sha256 7af6efe4052c24d0849d5d4cdae895565246fd785c4e960fbc6b9c8a964f83f4
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008eaa0(void)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  int unaff_s2;
  int unaff_s3;
  
  func_0x80004cfc(0x14d6,DAT_800c52dc + 0x44800,0,"MIX ITP");
  iVar3 = unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xc) * 4;
  cVar1 = *(char *)(iVar3 + 0x21818);
  *(char *)(iVar3 + 0x21818) =
       *(char *)(unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xd) * 4 + 0x21818) + -0xf;
  if ((uint)*(byte *)(unaff_s2 + 8) == (uint)*(byte *)(unaff_s2 + 0xc)) {
    *(undefined1 *)(unaff_s2 + 10) =
         *(undefined1 *)(unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xc) * 4 + 0x21818);
  }
  *(char *)(unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xd) * 4 + 0x21818) = cVar1 + '\x0f';
  iVar3 = unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xc) * 4;
  uVar2 = *(undefined1 *)(iVar3 + 0x21819);
  *(undefined1 *)(iVar3 + 0x21819) =
       *(undefined1 *)(unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xd) * 4 + 0x21819);
  *(undefined1 *)(unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xd) * 4 + 0x21819) = uVar2;
  uVar4 = (uint)*(byte *)(unaff_s2 + 0xd);
  if (*(char *)(unaff_s3 + uVar4 * 4 + 0x21819) == '\0') {
    FUN_8008c314(uVar4,0,0,0);
    FUN_8008cc1c((uint)(*(byte *)(unaff_s2 + 0xd) >> 1) + (uint)*(byte *)(unaff_s2 + 0xd));
  }
  else {
    FUN_8008c970((*(byte *)(unaff_s2 + 0xd) >> 1) + uVar4,
                 DAT_800c52dc + (uint)*(byte *)(unaff_s2 + 0x27) * 0x4b0 + 0x44800);
  }
  *(undefined1 *)(unaff_s2 + 4) = 1;
  *(undefined1 *)(unaff_s2 + 6) = 0;
  *(undefined1 *)(unaff_s2 + 5) = 0;
  FUN_8008d160(0);
  return;
}
