/* FUN_8007e9d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e9d8  body 0x8007e9d8..0x8007ea8f  size 184 B
 * body sha256 0964b02be0a73555681d7ff1991b2ada05c92f37cde85c72711bfd8aab28de9b
 * provider record sha256 e1ebc6b203f97a8be04045951e97c3f044ce38be07d49bcadbb5e20d89d26ae7
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007e960::caseD_2(void)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  int unaff_s1;
  
  *(undefined1 *)(unaff_s1 + 7) = 3;
  *(undefined1 *)(unaff_s1 + 0x1e8) = 8;
  *(undefined1 *)(unaff_s1 + 0x1e9) = 0;
  *(undefined1 *)(unaff_s1 + 0x1ea) = 0;
  *(undefined2 *)(unaff_s1 + 500) = 0;
  *(byte *)(unaff_s1 + 0x26f) = *(byte *)(unaff_s1 + 0x26f) | 0x80;
  if (*(byte *)(unaff_s1 + 8) < 0x10) {
    iVar3 = *(byte *)(unaff_s1 + 8) + 0x10;
  }
  else {
    iVar3 = *(byte *)(unaff_s1 + 8) - 0x40;
  }
  *(undefined2 *)(unaff_s1 + 0x1e0) = *(undefined2 *)(&DAT_8010bab8 + iVar3 * 2);
  *(undefined2 *)(unaff_s1 + 0x1e4) = 0;
  FUN_80032b5c();
  *(undefined2 *)(unaff_s1 + 500) = 5;
  *(int *)(unaff_s1 + 0x2c) = *(int *)(unaff_s1 + 0x2c) + 0x226;
  *(undefined2 *)(unaff_s1 + 0x1b4) = *(undefined2 *)(unaff_s1 + 0x2a);
  *(undefined2 *)(unaff_s1 + 0x34) = *(undefined2 *)(unaff_s1 + 0x2a);
  *(undefined2 *)(unaff_s1 + 0x1b6) = *(undefined2 *)(unaff_s1 + 0x32);
  *(undefined2 *)(unaff_s1 + 0x38) = *(undefined2 *)(unaff_s1 + 0x32);
  *(char *)(unaff_s1 + 0x1a2) = *(char *)(unaff_s1 + 0x1a2) + -1;
  *(undefined2 *)(unaff_s1 + 0x36) = *(undefined2 *)(unaff_s1 + 0x2e);
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
