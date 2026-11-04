/* FUN_8007ea90
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ea90  body 0x8007ea90..0x8007eb87  size 248 B
 * body sha256 75ad3fa8b2c585f657c86041249422176aec9e30793d85b790e235519581510b
 * provider record sha256 8dd11b826fc93e615b774d5c6b0d0d9d69346baeada6f908466fe08187a106e0
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007e960::caseD_3(void)

{
  short sVar1;
  undefined2 uVar2;
  int unaff_s1;
  
  sVar1 = *(short *)(unaff_s1 + 500);
  *(short *)(unaff_s1 + 500) = sVar1 + 1;
  *(int *)(unaff_s1 + 0x2c) = *(int *)(unaff_s1 + 0x2c) + sVar1 * 0x1e;
  uVar2 = FUN_80069f1c(unaff_s1 + 0x28,400,0x8000);
  *(undefined2 *)(unaff_s1 + 0x25e) = uVar2;
  *(undefined2 *)(unaff_s1 + 0x1b6) = *(undefined2 *)(unaff_s1 + 0x32);
  *(undefined2 *)(unaff_s1 + 0x38) = *(undefined2 *)(unaff_s1 + 0x32);
  *(undefined2 *)(unaff_s1 + 0x1b4) = *(undefined2 *)(unaff_s1 + 0x2a);
  *(undefined2 *)(unaff_s1 + 0x34) = *(undefined2 *)(unaff_s1 + 0x2a);
  *(undefined2 *)(unaff_s1 + 0x36) = *(undefined2 *)(unaff_s1 + 0x2e);
  *(char *)(unaff_s1 + 0x1a2) = -(char)(*(int *)(unaff_s1 + 0x2c) / 0x708);
  FUN_800667d4(unaff_s1 + 0x28,400,1 << (-(*(int *)(unaff_s1 + 0x2c) / 0x708) & 0x1fU),0x8000);
  FUN_80089d54();
  if (*(short *)(unaff_s1 + 0x25e) + -300 < *(int *)(unaff_s1 + 0x2c)) {
    *(undefined1 *)(unaff_s1 + 7) = 4;
  }
  return;
}
