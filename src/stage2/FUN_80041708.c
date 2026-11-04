/* FUN_80041708
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80041708  body 0x80041708..0x80041a27  size 800 B
 * body sha256 a413e09d04f5bbf2d00641854eefb15df2846b56f76a5d57af2d6044c266ae44
 * provider record sha256 1a55b6bd809df7a298d28cc8c628c84d2da92b87107e9c99ae7ea6082b292881
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80041880) */
/* WARNING: Removing unreachable block (ram,0x800417d0) */
/* WARNING: Removing unreachable block (ram,0x8004191c) */

void FUN_80041708(short *param_1,undefined2 *param_2)

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
  fVar5 = fVar5 * fVar6;
  *param_2 = (short)(int)(fVar5 * 4096.0);
  fVar8 = fVar8 * fVar6;
  param_2[1] = (short)(int)(fVar8 * 4096.0);
  fVar4 = fVar4 * fVar6;
  param_2[2] = (short)(int)(fVar4 * 4096.0);
  fVar7 = 1.0 / SQRT(fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3);
  fVar6 = fVar8 * fVar3 * fVar7 - fVar4 * fVar2 * fVar7;
  fVar3 = fVar4 * fVar1 * fVar7 - fVar5 * fVar3 * fVar7;
  fVar1 = fVar5 * fVar2 * fVar7 - fVar8 * fVar1 * fVar7;
  fVar2 = 1.0 / SQRT(fVar6 * fVar6 + fVar3 * fVar3 + fVar1 * fVar1);
  fVar6 = fVar6 * fVar2;
  param_2[6] = (short)(int)(fVar6 * 4096.0);
  fVar3 = fVar3 * fVar2;
  param_2[7] = (short)(int)(fVar3 * 4096.0);
  fVar1 = fVar1 * fVar2;
  param_2[8] = (short)(int)(fVar1 * 4096.0);
  param_2[3] = (short)(int)((fVar4 * fVar3 - fVar8 * fVar1) * 4096.0);
  param_2[4] = (short)(int)((fVar5 * fVar1 - fVar4 * fVar6) * 4096.0);
  param_2[5] = (short)(int)((fVar8 * fVar6 - fVar5 * fVar3) * 4096.0);
  return;
}
