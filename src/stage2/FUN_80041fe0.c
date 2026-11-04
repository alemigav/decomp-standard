/* FUN_80041fe0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80041fe0  body 0x80041fe0..0x800421b3  size 468 B
 * body sha256 00d014611874c5fae0bd3e567e84a34ad93e619c42812395696f9e2c0a68d74a
 * provider record sha256 6895e79a6b231ad3db9c3e7f625f6518eac0c7e3476acd4664e001cae040671d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
short * FUN_80041fe0(short *param_1,short *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  iVar12 = (int)*param_1;
  iVar6 = (int)*param_2;
  iVar13 = (int)param_1[1];
  iVar8 = (int)param_2[3];
  iVar14 = (int)param_1[2];
  iVar10 = (int)param_2[6];
  iVar15 = (int)param_1[3];
  iVar4 = (int)param_1[4];
  iVar5 = (int)param_1[5];
  *param_1 = (short)(iVar13 * iVar8 + iVar12 * iVar6 + iVar14 * iVar10 >> 0xc);
  iVar2 = (int)param_1[6];
  iVar3 = (int)param_1[7];
  iVar1 = (int)param_1[8];
  param_1[3] = (short)(iVar4 * iVar8 + iVar15 * iVar6 + iVar5 * iVar10 >> 0xc);
  iVar7 = (int)param_2[1];
  iVar9 = (int)param_2[4];
  param_1[6] = (short)(iVar3 * iVar8 + iVar2 * iVar6 + iVar1 * iVar10 >> 0xc);
  iVar10 = (int)param_2[7];
  param_1[1] = (short)(iVar13 * iVar9 + iVar12 * iVar7 + iVar14 * iVar10 >> 0xc);
  param_1[4] = (short)(iVar4 * iVar9 + iVar15 * iVar7 + iVar5 * iVar10 >> 0xc);
  iVar6 = (int)param_2[2];
  iVar8 = (int)param_2[5];
  iVar11 = (int)param_2[8];
  param_1[7] = (short)(iVar3 * iVar9 + iVar2 * iVar7 + iVar1 * iVar10 >> 0xc);
  param_1[2] = (short)(iVar13 * iVar8 + iVar12 * iVar6 + iVar14 * iVar11 >> 0xc);
  param_1[5] = (short)(iVar4 * iVar8 + iVar15 * iVar6 + iVar5 * iVar11 >> 0xc);
  param_1[8] = (short)(iVar3 * iVar8 + iVar2 * iVar6 + iVar1 * iVar11 >> 0xc);
  return param_1;
}
