/* FUN_80082674
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80082674  body 0x80082674..0x80082893  size 544 B
 * body sha256 f404bf7bf5a331a8ce2471966431b9eae4854b84529112d3cf0e4629f73574f5
 * provider record sha256 b9d3906976f85e8e25a424ff1039ef5b57ec7fc2b1e45251fbf07cf6a859a630
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80082674(int param_1,int param_2,int *param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int *piVar10;
  short *psVar11;
  int iVar12;
  int *piVar13;
  
  *(undefined4 *)(param_2 + 0xb8) = *(undefined4 *)(param_1 + 0xb8);
  *(undefined4 *)(param_2 + 0xbc) = *(undefined4 *)(param_1 + 0xbc);
  *(undefined2 *)(param_2 + 0xd4) = *(undefined2 *)(param_1 + 0xd4);
  *(undefined2 *)(param_2 + 0xd6) = *(undefined2 *)(param_1 + 0xd6);
  *(undefined4 *)(param_2 + 0xdc) = *(undefined4 *)(param_1 + 0xdc);
  *(undefined4 *)(param_2 + 0xd8) = *(undefined4 *)(param_1 + 0xd8);
  puVar8 = *(undefined4 **)(param_1 + 0xc4);
  iVar12 = puVar8[1];
  iVar3 = puVar8[2];
  iVar2 = 0;
  while (iVar12 = iVar12 + -1, iVar12 != -1) {
    if (*(int *)(iVar3 + 0xc) != 0) {
      iVar2 = iVar2 + 1;
    }
    iVar3 = iVar3 + 0x10;
  }
  if (iVar2 == 0) {
    *(undefined4 *)(param_2 + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  }
  else {
    puVar9 = (undefined4 *)((int)param_3 + 7U & 0xfffffff8);
    uVar4 = puVar8[2];
    uVar7 = puVar8[1];
    uVar5 = puVar8[2];
    uVar6 = puVar8[3];
    *puVar9 = *puVar8;
    puVar9[1] = uVar7;
    puVar9[2] = uVar5;
    puVar9[3] = uVar6;
    uVar5 = puVar8[5];
    puVar9[4] = puVar8[4];
    puVar9[5] = uVar5;
    piVar13 = puVar9 + 6;
    func_0x8000de9c(piVar13,uVar4,puVar8[1] << 4);
    iVar12 = puVar9[1];
    iVar3 = puVar8[1];
    puVar8 = puVar9 + 7;
    puVar9[2] = piVar13;
    param_3 = piVar13 + iVar3 * 4;
    while (iVar12 = iVar12 + -1, iVar12 != -1) {
      piVar10 = param_3;
      if (puVar8[2] != 0) {
        iVar3 = *piVar13;
        uVar4 = *puVar8;
        *puVar8 = param_3;
        piVar10 = param_3 + iVar3 * 4;
        func_0x8000de9c(param_3,uVar4);
        iVar3 = iVar3 + -1;
        if (iVar3 != -1) {
          psVar11 = (short *)((int)param_3 + 0xe);
          do {
            iVar3 = iVar3 + -1;
            func_0x8000de9c(piVar10,*param_3,(int)*psVar11 << 4);
            *param_3 = (int)piVar10;
            sVar1 = *psVar11;
            psVar11 = psVar11 + 8;
            param_3 = param_3 + 4;
            piVar10 = piVar10 + sVar1 * 4;
          } while (iVar3 != -1);
        }
      }
      puVar8 = puVar8 + 4;
      piVar13 = piVar13 + 4;
      param_3 = piVar10;
    }
    *(undefined4 **)(param_2 + 0xc4) = puVar9;
  }
  FUN_80031b80(param_2 + 0x78,param_3);
  return;
}
