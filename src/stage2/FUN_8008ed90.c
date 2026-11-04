/* FUN_8008ed90
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008ed90  body 0x8008ed90..0x8008ee9b  size 268 B
 * body sha256 43e37ff54066dc0fc7109f9794a1ca5c9948d318bc0de1a6884f549503afadd0
 * provider record sha256 30d2b1ab964fd5a2eb981dbb5dd1b7a844dcf8056e1d014a872eba4b8f14a289
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008ed90(void)

{
  char cVar1;
  int iVar2;
  undefined1 unaff_s0;
  int unaff_s2;
  int unaff_s3;
  
  func_0x80004cfc(0x14d6,DAT_800c52dc + 0x44800,0,"MIX ITP");
  cVar1 = *(char *)(unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xd) * 4 + 0x21818);
  if (cVar1 == '$') {
    unaff_s0 = 0x19;
  }
  if (cVar1 == '%') {
    unaff_s0 = 0x1a;
  }
  iVar2 = unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xc) * 4;
  if (*(byte *)(iVar2 + 0x21819) < 7) {
    *(undefined1 *)(iVar2 + 0x21818) = unaff_s0;
    FUN_8008c970((uint)(*(byte *)(unaff_s2 + 0xc) >> 1) + (uint)*(byte *)(unaff_s2 + 0xc),
                 DAT_800c52dc + (uint)*(byte *)(unaff_s2 + 0x27) * 0x4b0 + 0x44800);
    FUN_8008c314(*(undefined1 *)(unaff_s2 + 0xd),0,0,0);
    FUN_8008cc1c((uint)(*(byte *)(unaff_s2 + 0xd) >> 1) + (uint)*(byte *)(unaff_s2 + 0xd));
  }
  else {
    *(byte *)(iVar2 + 0x21819) = *(byte *)(iVar2 + 0x21819) - 6;
    *(undefined1 *)(unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xd) * 4 + 0x21818) = unaff_s0;
    *(undefined1 *)(unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xd) * 4 + 0x21819) = 6;
    FUN_8008c970((uint)(*(byte *)(unaff_s2 + 0xd) >> 1) + (uint)*(byte *)(unaff_s2 + 0xd),
                 DAT_800c52dc + (uint)*(byte *)(unaff_s2 + 0x27) * 0x4b0 + 0x44800);
  }
  FUN_8008d160(0);
  *(undefined1 *)(unaff_s2 + 4) = 1;
  *(undefined1 *)(unaff_s2 + 6) = 0;
  *(undefined1 *)(unaff_s2 + 5) = 0;
  return;
}
