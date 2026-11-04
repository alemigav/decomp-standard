/* FUN_800493d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800493d4  body 0x800493d4..0x8004944b  size 120 B
 * body sha256 f7a34d5cfcec9ffdde92d437a16fb130c713f7c26290214a465794326cd2fe99
 * provider record sha256 ec79b6500cf358ba509f16235bb4f9595697bfb93402ab83e1d31d5ce2ceb216
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800493d4(undefined4 *param_1,undefined4 param_2)

{
  float fVar1;
  undefined4 uVar2;
  
  fVar1 = (float)func_0x8000d050(param_2);
  uVar2 = func_0x80006be0(param_2);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = 0x3f800000;
  param_1[4] = uVar2;
  param_1[5] = fVar1;
  param_1[6] = 0;
  param_1[7] = -fVar1;
  param_1[8] = uVar2;
  return;
}
