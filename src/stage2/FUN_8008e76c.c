/* FUN_8008e76c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008e76c  body 0x8008e76c..0x8008e873  size 264 B
 * body sha256 b42c7363b8f29c959bb2aac748a5612c71ffe2cbabc239cea8bb1703d856ce11
 * provider record sha256 0f06e4210b2be2386bf6fa322943fb94efe5df9c36fa92ddf993ff9de50f4827
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008e76c(void)

{
  int unaff_s2;
  int unaff_s3;
  
  func_0x80004cfc(0x14d6,DAT_800c52dc + 0x44800,0,"MIX ITP");
  FUN_8008c970((uint)(*(byte *)(unaff_s2 + 0xc) >> 1) + (uint)*(byte *)(unaff_s2 + 0xc),
               DAT_800c52dc + (uint)*(byte *)(unaff_s2 + 0x27) * 0x4b0 + 0x44800);
  *(undefined1 *)(unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xc) * 4 + 0x21818) =
       *(undefined1 *)(unaff_s2 + 0x26);
  *(undefined *)(unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xc) * 4 + 0x21819) =
       (&DAT_8012ffa8)[(uint)*(byte *)(unaff_s2 + 0x26) * 8];
  if (*(char *)(unaff_s2 + 0xc) == *(char *)(unaff_s2 + 8)) {
    *(undefined1 *)(unaff_s2 + 10) = *(undefined1 *)(unaff_s2 + 0x26);
  }
  if (*(char *)(unaff_s2 + 0xd) == *(char *)(unaff_s2 + 8)) {
    *(undefined1 *)(unaff_s2 + 8) = *(undefined1 *)(unaff_s2 + 0xc);
    *(undefined1 *)(unaff_s2 + 10) = *(undefined1 *)(unaff_s2 + 0x26);
  }
  FUN_8008c314(*(undefined1 *)(unaff_s2 + 0xd),0,0,0);
  FUN_8008cc1c((uint)(*(byte *)(unaff_s2 + 0xd) >> 1) + (uint)*(byte *)(unaff_s2 + 0xd));
  *(undefined1 *)(unaff_s2 + 4) = 1;
  *(undefined1 *)(unaff_s2 + 6) = 0;
  *(undefined1 *)(unaff_s2 + 5) = 0;
  FUN_8008d160(0);
  return;
}
