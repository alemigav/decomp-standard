/* FUN_8006ea90
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006ea90  body 0x8006ea90..0x8006ea9b  size 12 B
 * body sha256 ef41b33a1823108953db9f84c44d37988fc1fdfe9f7699d221b16c3058a24bf2
 * provider record sha256 7b734bee5ccb74c87e400906e58b25e654f4f293d9ab819b5c9ccfdc54b646bd
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8006e9c4::caseD_9(uint param_1)

{
  undefined2 uVar1;
  uint unaff_s0;
  undefined2 *unaff_s1;
  
  uVar1 = FUN_800844cc((int)(short)((param_1 & 0xffff) << (unaff_s0 & 0x1f)));
  *unaff_s1 = uVar1;
  DAT_80115120 = 0;
  return;
}
