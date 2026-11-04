/* FUN_80046ec4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80046ec4  body 0x80046ec4..0x80046f97  size 212 B
 * body sha256 d392c38ed18d1e2a7e0d28e52759fb2b77012643a1507208304ca0771cd7456e
 * provider record sha256 b49fe42cfe69721aa1132284c3fc5b6bbddc4bfa1471c06286667fbae44610f0
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 * FUN_80046ec4(undefined4 *param_1)

{
  func_0x80009170(0x80139aa0);
  param_1[1] = &DAT_800efdf0;
  *param_1 = 0xde000000;
  param_1[2] = 0xe200001c;
  param_1[3] = 0x5049d8;
  param_1[4] = 0xfa000000;
  param_1[5] = 0xffffff00;
  param_1[7] = 0xfffff3f9;
  param_1[6] = 0xfc11fe23;
  param_1[8] = 0xde000000;
  param_1[9] = &DAT_800efe68;
  DAT_800effa0 = 100;
  param_1[10] = 0xd9c0f9fa;
  param_1[0xb] = 0;
  return param_1 + 0xc;
}
