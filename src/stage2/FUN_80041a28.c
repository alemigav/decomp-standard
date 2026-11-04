/* FUN_80041a28
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80041a28  body 0x80041a28..0x80041d4f  size 808 B
 * body sha256 04fe48e7d736eae70b5000d94142ad90d6037e3941291aed98681bd81608afaf
 * provider record sha256 8ab7b5ee33f2111700860899b9f33cb5e95fbd5d34a8ffeb2c0f93742af778da
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80041b5c) */
/* WARNING: Removing unreachable block (ram,0x80041af0) */
/* WARNING: Removing unreachable block (ram,0x80041c44) */

void FUN_80041a28(short *param_1,undefined2 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar5 = (float)(int)*param_1 * 0.00024414062;
  fVar8 = (float)(int)param_1[1] * 0.00024414062;
  fVar4 = (float)(int)param_1[2] * 0.00024414062;
  fVar1 = (float)(int)param_1[3] * 0.00024414062;
  fVar2 = (float)(int)param_1[4] * 0.00024414062;
  fVar3 = (float)(int)param_1[5] * 0.00024414062;
  fVar6 = 1.0 / SQRT(fVar5 * fVar5 + fVar8 * fVar8 + fVar4 * fVar4);
  fVar7 = 1.0 / SQRT(fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3);
  fVar1 = fVar1 * fVar7;
  param_2[3] = (short)(int)(fVar1 * 4096.0);
  fVar2 = fVar2 * fVar7;
  param_2[4] = (short)(int)(fVar2 * 4096.0);
  fVar3 = fVar3 * fVar7;
  param_2[5] = (short)(int)(fVar3 * 4096.0);
  fVar7 = fVar8 * fVar6 * fVar3 - fVar4 * fVar6 * fVar2;
  fVar4 = fVar4 * fVar6 * fVar1 - fVar5 * fVar6 * fVar3;
  fVar5 = fVar5 * fVar6 * fVar2 - fVar8 * fVar6 * fVar1;
  fVar6 = 1.0 / SQRT(fVar7 * fVar7 + fVar4 * fVar4 + fVar5 * fVar5);
  fVar7 = fVar7 * fVar6;
  param_2[6] = (short)(int)(fVar7 * 4096.0);
  fVar4 = fVar4 * fVar6;
  param_2[7] = (short)(int)(fVar4 * 4096.0);
  fVar5 = fVar5 * fVar6;
  param_2[8] = (short)(int)(fVar5 * 4096.0);
  *param_2 = (short)(int)((fVar2 * fVar5 - fVar3 * fVar4) * 4096.0);
  param_2[1] = (short)(int)((fVar3 * fVar7 - fVar1 * fVar5) * 4096.0);
  param_2[2] = (short)(int)((fVar1 * fVar4 - fVar2 * fVar7) * 4096.0);
  return;
}
