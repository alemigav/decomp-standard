/* FUN_80040a14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040a14  body 0x80040a14..0x80040a57  size 68 B
 * body sha256 368f517447e385e14e49655575554931af71ed1991276008c2f2c8c6d5141a6b
 * provider record sha256 ac410fd560d99f6f7c0dfe07a8d189d3522933d90d6a675481d40ca285853a71
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80040a14(int param_1)

{
  float fVar1;
  
  fVar1 = (float)FUN_800482e0((float)param_1 * 0.00024414062);
  return (int)(fVar1 * 651.8986);
}
