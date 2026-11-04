/* FUN_80035a7c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80035a7c  body 0x80035a7c..0x80035b83  size 264 B
 * body sha256 31f71e088093d32d8f86f179566e80349b29c663cca0d97361335e9759e20413
 * provider record sha256 17e2b5ec71ada91ff93e4f6f314f9d48e8dea5e300bd87af337c6b3d85016a5b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80035a7c(void)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  int *piVar8;
  char cVar9;
  
  piVar6 = *(int **)(DAT_800df92c + 0x60);
  if (piVar6 != (int *)0x0) {
    cVar9 = *(char *)((int)piVar6 + 7);
    piVar8 = (int *)((int)piVar6 + *piVar6);
    piVar5 = piVar8 + 1;
    do {
      uVar7 = 0;
      puVar3 = (uint *)((int)piVar6 + *piVar8);
      uVar4 = *puVar3;
      uVar1 = uVar4 & 0x80000000;
      if ((DAT_800e110c & 0x2000000) == 0) {
        uVar1 = uVar4 & 1;
      }
      if (uVar1 != 0) {
        DAT_800e1360 = (int)piVar6 + *piVar5;
        DAT_800e135c = puVar3 + 1;
      }
      uVar4 = uVar4 >> 1;
      if (uVar4 != 0) {
        do {
          if ((uVar4 & 1) != 0) {
            iVar2 = (uVar7 & 0xff) + 1;
            if ((*(uint *)(&DAT_800e13e8)[iVar2] & 1) != 0) {
              ((uint *)(&DAT_800e13e8)[iVar2])[0x8b] = (uint)(puVar3 + 1);
              *(int *)((&DAT_800e13e8)[iVar2] + 0x230) = (int)piVar6 + *piVar5;
            }
          }
          uVar4 = uVar4 >> 1;
          uVar7 = uVar7 + 1;
        } while (uVar4 != 0);
      }
      piVar5 = piVar5 + 2;
      piVar8 = piVar8 + 2;
      cVar9 = cVar9 + -1;
    } while (cVar9 != '\0');
  }
  return;
}
