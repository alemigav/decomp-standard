/* FUN_8007fac4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007fac4  body 0x8007fac4..0x8007faff  size 60 B
 * body sha256 d97e4c6f74bb0515149c1727ae12afae212d1924fed2127a38cb5af5c037fc5c
 * provider record sha256 ba49704bab09bc6b199321a58d36a5ce37ad2f15f4bdd76b782c16b364b4be53
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007f9a8::caseD_3(void)

{
  int iVar1;
  int unaff_s0;
  
  iVar1 = FUN_80089d54();
  if ((iVar1 != 0) && (*(char *)(unaff_s0 + 0x207) == '\0')) {
    *(undefined1 *)(unaff_s0 + 0x207) = 1;
    *(char *)(unaff_s0 + 0x1e8) = *(char *)(unaff_s0 + 0x1e8) + '\x01';
  }
  return;
}
