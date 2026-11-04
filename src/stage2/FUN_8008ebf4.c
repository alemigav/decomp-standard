/* FUN_8008ebf4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008ebf4  body 0x8008ebf4..0x8008ed8f  size 412 B
 * body sha256 53c382e2ed6165537574c2e7d838e1f4a1e9904c257c73e90b1baa74676f4370
 * provider record sha256 824b02462f83146f4951397e239560182f8801fcd9f69f16ea1337929ffe2ad1
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008ebf4(void)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  int unaff_s2;
  int unaff_s3;
  
  func_0x80004cfc(0x14d6,DAT_800c52dc + 0x44800,0,"MIX ITP");
  FUN_8008c970((uint)(*(byte *)(unaff_s2 + 0xc) >> 1) + (uint)*(byte *)(unaff_s2 + 0xc),
               DAT_800c52dc + (uint)*(byte *)(unaff_s2 + 0x27) * 0x4b0 + 0x44800);
  iVar3 = unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xd) * 4;
  cVar1 = *(char *)(iVar3 + 0x21818);
  *(char *)(iVar3 + 0x21818) =
       *(char *)(unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xc) * 4 + 0x21818) + -0xf;
  if ((uint)*(byte *)(unaff_s2 + 8) == (uint)*(byte *)(unaff_s2 + 0xd)) {
    *(undefined1 *)(unaff_s2 + 10) =
         *(undefined1 *)(unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xd) * 4 + 0x21818);
  }
  *(char *)(unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xc) * 4 + 0x21818) = cVar1 + '\x0f';
  iVar3 = unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xc) * 4;
  uVar2 = *(undefined1 *)(iVar3 + 0x21819);
  *(undefined1 *)(iVar3 + 0x21819) =
       *(undefined1 *)(unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xd) * 4 + 0x21819);
  *(undefined1 *)(unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xd) * 4 + 0x21819) = uVar2;
  uVar4 = (uint)*(byte *)(unaff_s2 + 0xc);
  if (*(char *)(unaff_s3 + uVar4 * 4 + 0x21819) == '\0') {
    FUN_8008c314(uVar4,0,0,0);
    FUN_8008cc1c((uint)(*(byte *)(unaff_s2 + 0xc) >> 1) + (uint)*(byte *)(unaff_s2 + 0xc));
  }
  else {
    FUN_8008c970((*(byte *)(unaff_s2 + 0xc) >> 1) + uVar4,
                 DAT_800c52dc + (uint)*(byte *)(unaff_s2 + 0x27) * 0x4b0 + 0x44800);
  }
  *(undefined1 *)(unaff_s2 + 4) = 1;
  *(undefined1 *)(unaff_s2 + 6) = 0;
  *(undefined1 *)(unaff_s2 + 5) = 0;
  FUN_8008d160();
  return;
}
