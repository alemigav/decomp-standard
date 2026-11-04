/* FUN_80047cc8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047cc8  body 0x80047cc8..0x80047d67  size 160 B
 * body sha256 cbb53d8074dbe92b6ddc28fe7185c9f88d35328d83b758003149a18ff3e97c86
 * provider record sha256 120b9d18e7dabca69ef82117db7074b0ca936f96b8edb7e7abf84b880114d3ec
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80047cc8(int param_1,short *param_2,uint param_3,uint param_4)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  int iVar6;
  
  iVar6 = 0;
  puVar5 = (undefined2 *)
           (*(int *)(param_1 + 0x14) + *(int *)(param_1 + 4) * (param_4 & 0xffff) +
           (param_3 & 0xffff));
  puVar4 = (undefined2 *)
           (*(int *)(param_1 + 0x14) + *(int *)(param_1 + 4) * (int)param_2[1] + (int)*param_2);
  if (0 < param_2[3]) {
    do {
      iVar2 = (int)param_2[2];
      iVar3 = 0;
      if (0 < iVar2) {
        do {
          uVar1 = *puVar4;
          puVar4 = puVar4 + 1;
          iVar3 = iVar3 + 2;
          *puVar5 = uVar1;
          puVar5 = puVar5 + 1;
        } while (iVar3 < param_2[2]);
        iVar2 = (int)param_2[2];
      }
      iVar6 = iVar6 + 1;
      iVar2 = *(int *)(param_1 + 4) - iVar2;
      puVar5 = (undefined2 *)((int)puVar5 + iVar2);
      puVar4 = (undefined2 *)((int)puVar4 + iVar2);
    } while (iVar6 < param_2[3]);
  }
  return;
}
