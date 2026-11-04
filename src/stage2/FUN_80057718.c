/* FUN_80057718
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80057718  body 0x80057718..0x8005791b  size 516 B
 * body sha256 9b7620a885440bc9eda0923b344633df5bc94db5bcf804df0b6434cffec2bc31
 * provider record sha256 86cf5f683fa1773e73cd3abbd83e7ae08f16cad19fc4cd806d15c358e9bd4b76
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80057718(int param_1,uint param_2,short param_3)

{
  bool bVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  
  uVar7 = 0x7fffffff;
  puVar8 = (uint *)0x0;
  if (((*(byte *)(param_1 + 0x25c) & 1) == 0) &&
     (DAT_8010dc00 = DAT_8010dc00 + -1, DAT_8010dc00 == -1)) {
    DAT_8010dc00 = '-';
    if ((DAT_800e1126 == '\0') && ((DAT_800e110c & 0x10000000) == 0)) {
      *(int *)(param_1 + 0x254) = param_1;
    }
    else {
      puVar5 = &DAT_800e13ec;
      puVar9 = (uint *)0x0;
      do {
        puVar3 = (uint *)*puVar5;
        uVar6 = param_2;
        puVar10 = puVar9;
        if (((*puVar3 & 1) != 0) && ((*(ushort *)((int)puVar3 + 0x1aa) & 0xc000) == 0)) {
          bVar1 = false;
          uVar4 = puVar3[0xa3];
          iVar2 = FUN_8006ab40(*(int *)(param_1 + 0x234) + (uint)*(byte *)(param_1 + 0x25d) * 0x178
                               + 0x4c,puVar3[0x8d] + (uint)*(byte *)((int)puVar3 + 0x25d) * 0x178 +
                                      0x4c,0x2080);
          if (iVar2 == 0) {
            iVar2 = FUN_80032e74(param_1,puVar3[10],puVar3[0xc],(int)param_3);
            bVar1 = iVar2 == 0;
          }
          if (bVar1) {
            if ((*(ushort *)((int)puVar3 + 0x1aa) & 0x2000) == 0) {
              uVar6 = uVar4;
              puVar10 = puVar3;
              if (param_2 <= uVar4) {
                uVar6 = param_2;
                puVar10 = puVar9;
              }
            }
            else if (uVar4 < uVar7) {
              uVar7 = uVar4;
              puVar8 = puVar3;
            }
          }
        }
        puVar5 = puVar5 + 1;
        param_2 = uVar6;
        puVar9 = puVar10;
      } while (puVar5 != DAT_800df93c);
      if (puVar10 == (uint *)0x0) {
        if (puVar8 == (uint *)0x0) {
          *(int *)(param_1 + 0x254) = param_1;
        }
        else {
          *(uint **)(param_1 + 0x254) = puVar8;
        }
      }
      else {
        *(uint **)(param_1 + 0x254) = puVar10;
      }
    }
  }
  return;
}
