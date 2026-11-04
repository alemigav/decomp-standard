/* FUN_800424ec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800424ec  body 0x800424ec..0x800426c3  size 472 B
 * body sha256 1a8fa31ed1822dc4ca0fb844576377d6adf0016eb6cd8b56a218eee445286d79
 * provider record sha256 00191389b29a2aebb28874f7613e05411fa6adbadff2bd025f7dccb876dcfdd7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Control flow encountered bad instruction data */

void FUN_800424ec(short *param_1,short *param_2,undefined2 *param_3)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  
  iVar14 = (int)*param_1;
  iVar9 = (int)*param_2;
  iVar15 = (int)param_1[1];
  iVar11 = (int)param_2[3];
  iVar16 = (int)param_1[2];
  iVar13 = (int)param_2[6];
  iVar17 = (int)param_1[3];
  iVar7 = (int)param_1[4];
  iVar8 = (int)param_1[5];
  *param_3 = (short)(iVar15 * iVar11 + iVar14 * iVar9 + iVar16 * iVar13 >> 0xc);
  sVar1 = param_1[6];
  sVar2 = param_1[7];
  sVar3 = param_1[8];
  param_3[3] = (short)(iVar7 * iVar11 + iVar17 * iVar9 + iVar8 * iVar13 >> 0xc);
  iVar10 = (int)param_2[1];
  iVar12 = (int)param_2[4];
  param_3[6] = (short)(sVar2 * iVar11 + sVar1 * iVar9 + sVar3 * iVar13 >> 0xc);
  iVar9 = (int)param_2[7];
  param_3[1] = (short)(iVar15 * iVar12 + iVar14 * iVar10 + iVar16 * iVar9 >> 0xc);
  param_3[4] = (short)(iVar7 * iVar12 + iVar17 * iVar10 + iVar8 * iVar9 >> 0xc);
  sVar4 = param_2[2];
  sVar5 = param_2[5];
  sVar6 = param_2[8];
  param_3[7] = (short)(sVar2 * iVar12 + sVar1 * iVar10 + sVar3 * iVar9 >> 0xc);
  param_3[2] = (short)(iVar15 * sVar5 + iVar14 * sVar4 + iVar16 * sVar6 >> 0xc);
  param_3[5] = (short)(iVar7 * sVar5 + iVar17 * sVar4 + iVar8 * sVar6 >> 0xc);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
