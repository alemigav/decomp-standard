/* FUN_800a9ce4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a9ce4  body 0x800a9ce4..0x800a9e57  size 372 B
 * body sha256 2593280c9ba464476af9497ee073fad2174489dcd70c99d697f3746c7076a7e2
 * provider record sha256 25b1497816af749d167d1bb51686118fa0dcb1af6d0515ad810986264d39ddb8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a9ce4(int param_1,float param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  uVar5 = 0;
  if (DAT_801486b0 != 0) {
    piVar4 = (int *)&DAT_80148530;
    do {
      if (*(int *)(param_1 + 0x38) == *piVar4) break;
      uVar5 = uVar5 + 1;
      piVar4 = piVar4 + 3;
    } while ((int)uVar5 < (int)(uint)DAT_801486b0);
  }
  if (uVar5 == DAT_801486b0) {
    iVar3 = uVar5 * 0xc;
    *(undefined4 *)(&DAT_80148534 + iVar3) = 0;
    *(undefined4 *)(&DAT_80148538 + iVar3) = 0;
    DAT_801486b0 = (char)uVar5 + 1;
    *(undefined4 *)(&DAT_80148530 + iVar3) = *(undefined4 *)(param_1 + 0x38);
  }
  piVar2 = (int *)*(int *)(&DAT_80148538 + uVar5 * 0xc);
  piVar4 = (int *)0x0;
  while ((piVar1 = piVar2, piVar1 != (int *)0x0 && ((float)piVar1[1] <= param_2))) {
    piVar4 = piVar1;
    piVar2 = (int *)*piVar1;
  }
  if (piVar4 == (int *)0x0) {
    *(uint *)(&DAT_80148538 + uVar5 * 0xc) = (uint)DAT_80148bd0 * 0xc + -0x7feb75b0;
  }
  else {
    *piVar4 = (uint)DAT_80148bd0 * 0xc + -0x7feb75b0;
  }
  uVar5 = (uint)DAT_80148bd0;
  iVar3 = uVar5 * 0xc;
  *(int **)(iVar3 + -0x7feb75b0) = piVar1;
  *(int *)(iVar3 + -0x7feb75a8) = param_1;
  DAT_80148bd0 = DAT_80148bd0 + 1;
  *(float *)(uVar5 * 0xc + -0x7feb75ac) = param_2;
  return;
}
