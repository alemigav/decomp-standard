/* FUN_80041d6c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80041d6c  body 0x80041d6c..0x80041f6b  size 512 B
 * body sha256 4b3f85ad898dc7922b72a3d49c68ed89ddf5ecf48da332c660a0c337fc14f443
 * provider record sha256 e4be4018f7aa858e41da2bd4f2e5f4b3a61b337b6784aa5778956decdbde2fd1
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80041e34) */
/* WARNING: Removing unreachable block (ram,0x80041ee4) */

void FUN_80041d6c(short *param_1,undefined2 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar5 = (float)(int)*param_1 * 0.00024414062;
  fVar7 = (float)(int)param_1[1] * 0.00024414062;
  fVar4 = (float)(int)param_1[2] * 0.00024414062;
  fVar1 = (float)(int)param_1[6] * 0.00024414062;
  fVar2 = (float)(int)param_1[7] * 0.00024414062;
  fVar3 = (float)(int)param_1[8] * 0.00024414062;
  fVar6 = 1.0 / SQRT(fVar5 * fVar5 + fVar7 * fVar7 + fVar4 * fVar4);
  *param_2 = (short)(int)(fVar5 * fVar6 * 4096.0);
  param_2[1] = (short)(int)(fVar7 * fVar6 * 4096.0);
  param_2[2] = (short)(int)(fVar4 * fVar6 * 4096.0);
  fVar4 = 1.0 / SQRT(fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3);
  param_2[6] = (short)(int)(fVar1 * fVar4 * 4096.0);
  param_2[7] = (short)(int)(fVar2 * fVar4 * 4096.0);
  param_2[8] = (short)(int)(fVar3 * fVar4 * 4096.0);
  return;
}
