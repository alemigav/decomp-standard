/* FUN_8006eaa4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006eaa4  body 0x8006eaa4..0x8006eadf  size 60 B
 * body sha256 5361ee7266ad214cb94f738eb3d1e1459b02f85578d022b021aae16d90502f1e
 * provider record sha256 44bdbd1d547a4c72e274b930d33b0989fabc3171c584520c38251df22761dc9e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8006e9c4::caseD_b(short param_1)

{
  undefined2 uVar1;
  uint unaff_s0;
  undefined2 *unaff_s1;
  
  uVar1 = FUN_800844cc((int)(short)((int)param_1 >> (unaff_s0 & 0x1f)));
  *unaff_s1 = uVar1;
  DAT_80115120 = 0;
  return;
}
