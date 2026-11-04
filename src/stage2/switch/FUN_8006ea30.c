/* FUN_8006ea30
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006ea30  body 0x8006ea30..0x8006ea6b  size 60 B
 * body sha256 5988601591ed8763565720a4868dc8b40b3ae8e84366fecc9691f264b8b97f92
 * provider record sha256 0d6e6c66656281515d264b528fd7bf1d61ebd7ccd99dde012a7300f2fdc0701c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8006e9c4::caseD_4(short param_1)

{
  undefined2 uVar1;
  int unaff_s0;
  undefined2 *unaff_s1;
  
  if (unaff_s0 == 0) {
    trap(0x1c00);
  }
  if ((unaff_s0 == -1) && (param_1 == -0x80000000)) {
    trap(0x1800);
  }
  uVar1 = FUN_800844cc((int)(short)((int)param_1 % unaff_s0));
  *unaff_s1 = uVar1;
  DAT_80115120 = 0;
  return;
}
