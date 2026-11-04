/* FUN_80037264
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80037264  body 0x80037264..0x80037273  size 16 B
 * body sha256 b495a31f40c79350e86f1579cb79866345256d8aae35fb1e8ad6a2aa0a553d07
 * provider record sha256 73da2114e8922657581ff4655731e0dfdaec628b8f4707a08ca50b17e2210dcc
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8003722c::caseD_3(void)

{
  short sVar1;
  uint uVar2;
  int unaff_s0;
  int unaff_s1;
  short unaff_s2;
  short in_stack_00000012;
  short sStack00000014;
  
  sVar1 = FUN_80032d14(0,0,(int)sStack00000014,(int)in_stack_00000012);
  uVar2 = (sVar1 - unaff_s0) + (int)unaff_s2 & 0xfff;
  if ((int)unaff_s2 << 1 <= (int)uVar2) {
    if (uVar2 < 0x801) {
      sVar1 = *(short *)(unaff_s1 + 0x66) + unaff_s2;
    }
    else {
      sVar1 = *(short *)(unaff_s1 + 0x66) - unaff_s2;
    }
    *(short *)(unaff_s1 + 0x66) = sVar1;
  }
  return;
}
