/* FUN_8006ea9c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006ea9c  body 0x8006ea9c..0x8006eaa3  size 8 B
 * body sha256 8dfba18e2e5628c2e72f87ab4204523de800960f92684c1ff07bcf581bfb2d8c
 * provider record sha256 920ec8159a7f119ef215c67a1a85a883eed181b7d7ac52022e1ca76fceb9fb0c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8006e9c4::caseD_a(uint param_1)

{
  undefined2 uVar1;
  uint unaff_s0;
  undefined2 *unaff_s1;
  
  uVar1 = FUN_800844cc((int)(short)((int)(param_1 & 0xffff) >> (unaff_s0 & 0x1f)));
  *unaff_s1 = uVar1;
  DAT_80115120 = 0;
  return;
}
