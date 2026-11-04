/* FUN_800494c4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800494c4  body 0x800494c4..0x8004953b  size 120 B
 * body sha256 06d3ad4807096fe6db944f48727013cc314d71f9dc93af371dc355d2a5a4e5e5
 * provider record sha256 ec4a682299808dece966d95c9e75ccd6f1573c6d42abcf29d6fcbd6d2d36bf28
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800494c4(undefined4 *param_1,undefined4 param_2)

{
  float fVar1;
  undefined4 uVar2;
  
  fVar1 = (float)func_0x8000d050(param_2);
  uVar2 = func_0x80006be0(param_2);
  param_1[1] = fVar1;
  *param_1 = uVar2;
  param_1[2] = 0;
  param_1[3] = -fVar1;
  param_1[4] = uVar2;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0x3f800000;
  return;
}
