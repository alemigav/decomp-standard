/* FUN_80047bf8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047bf8  body 0x80047bf8..0x80047cc7  size 208 B
 * body sha256 a09b39817ff90d980946f476b1b12eb224adee94c199a0342c7c0f1b1172bfb8
 * provider record sha256 46f8cbbf3d705dd1465c5091af3f9533c61f5972c34adb6f8576b793895c6c17
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80047bf8(int param_1,short *param_2,short *param_3)

{
  short sVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  
  iVar6 = 0;
  puVar5 = (undefined2 *)
           (*(int *)(param_1 + 0x18) + *(int *)(param_1 + 4) * (int)param_2[1] * 2 + (int)*param_2);
  if (0 < param_2[3]) {
    do {
      iVar2 = (int)param_2[2];
      iVar4 = 0;
      if (0 < iVar2) {
        do {
          sVar1 = *param_3;
          param_3 = param_3 + 1;
          iVar4 = iVar4 + 2;
          uVar3 = FUN_800844cc((int)sVar1);
          *puVar5 = uVar3;
          puVar5 = puVar5 + 1;
        } while (iVar4 < param_2[2]);
        iVar2 = (int)param_2[2];
      }
      iVar6 = iVar6 + 1;
      puVar5 = (undefined2 *)((int)puVar5 + (*(int *)(param_1 + 4) - iVar2));
    } while (iVar6 < param_2[3]);
  }
  return;
}
