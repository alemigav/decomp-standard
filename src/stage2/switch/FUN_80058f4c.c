/* FUN_80058f4c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80058f4c  body 0x80058f4c..0x80058f5f  size 20 B
 * body sha256 b2e5b3f1d17dad3e3756a858619c8a9e45b3cf2472ae5ca01ec9b8d61f06ac4e
 * provider record sha256 568f5080f1b6b888933e0b262f4485a9bf8224711708433e2f56030d4294ba52
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80058e58::caseD_3(void)

{
  char cVar1;
  int unaff_s0;
  
  cVar1 = FUN_80089d54();
  *(char *)(unaff_s0 + 6) = *(char *)(unaff_s0 + 6) + cVar1;
  return;
}
