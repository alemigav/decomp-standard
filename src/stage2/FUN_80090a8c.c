/* FUN_80090a8c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80090a8c  body 0x80090a8c..0x80090b3b  size 176 B
 * body sha256 21c5bed10f1d41f09c7ad93b924e1a59a621db0b31e2912719f7282a7059d544
 * provider record sha256 9173288465cfcdbb1fe98ed9ba130f2c80e8dcec7a21eda79286fe54a83208d5
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80090a8c(void)

{
  int unaff_s0;
  undefined2 uStack00000010;
  undefined2 uStack00000014;
  
  FUN_800479c8(DAT_800c52dc + 0x44807U & 0xfffffff8,&DAT_8012f5a0,
               *(undefined2 *)
                (&DAT_8012f8ec +
                (uint)*(ushort *)(&DAT_80130cba + (uint)*(byte *)(unaff_s0 + 0x1a) * 8) * 2));
  uStack00000010 = 0x1c0;
  uStack00000014 = 0x40;
  FUN_80090e10();
  *(undefined1 *)(unaff_s0 + 0x28) = 4;
  *(undefined1 *)(unaff_s0 + 0x29) = 0;
  *(undefined1 *)(unaff_s0 + 2) = 3;
  FUN_80097fd0();
  return;
}
