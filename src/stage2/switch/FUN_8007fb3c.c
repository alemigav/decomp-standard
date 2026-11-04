/* FUN_8007fb3c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007fb3c  body 0x8007fb3c..0x8007fb5f  size 36 B
 * body sha256 4337c4996f48b2daedcf142cbb9db0f264900e63ae128c9fe5ba559348aba76a
 * provider record sha256 c3f7bd4e53484d2bd1f993e2ed8739f34d1a2e4e7643b7d7d56339a4a201f1e3
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007f9a8::caseD_6(void)

{
  char cVar1;
  int unaff_s0;
  
  cVar1 = FUN_80089d54();
  *(char *)(unaff_s0 + 6) = *(char *)(unaff_s0 + 6) + cVar1;
  return;
}
