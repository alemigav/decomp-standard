/* FUN_800aa008
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aa008  body 0x800aa008..0x800aa1ab  size 420 B
 * body sha256 5c76adcf02553352d581c7ca2fb61b0d773f702682df0872fb78f83297e61b18
 * provider record sha256 0ebe6dafa5fe721234b1a41e88208782ec38e0f6744cfd993423f5290af27f2e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800aa008(void)

{
  ushort uVar2;
  int iVar1;
  int iVar3;
  int *piVar4;
  undefined1 *puVar5;
  int iVar6;
  float fVar7;
  
  iVar6 = 0;
  if (DAT_801486b0 != 0) {
    puVar5 = &DAT_80148530;
    do {
      for (piVar4 = *(int **)(puVar5 + 4); piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
        if (*(int *)(puVar5 + 8) == 0) {
LAB_800aa0d0:
          iVar3 = piVar4[6];
          iVar1 = FUN_800a83b4(*(undefined2 *)(iVar3 + 0x3c),0x7f,0x40);
          *(int *)(iVar3 + 0x34) = iVar1;
          if (iVar1 == -1) {
            if ((*(uint *)(iVar3 + 8) & 2) == 0) {
              *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) & 0xfffdffff | 0x40000;
            }
          }
          else {
            *(undefined4 *)(iVar3 + 0x40) = 0;
            *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) | 0x100000;
            FUN_800a9a98(iVar3,piVar4[1],piVar4[2],piVar4[3],piVar4[4],piVar4[5]);
            *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) & 0xfffdffff;
            if (*(undefined4 **)(puVar5 + 8) != (undefined4 *)0x0) {
              *(undefined4 *)(puVar5 + 8) = **(undefined4 **)(puVar5 + 8);
            }
          }
        }
        else {
          fVar7 = (float)piVar4[1] - *(float *)(*(int *)(puVar5 + 8) + 4);
          if (0.08 < fVar7) {
            if (fVar7 <= 0.15) {
              uVar2 = *(short *)(piVar4[6] + 0x3e) + 1;
              *(ushort *)(piVar4[6] + 0x3e) = uVar2;
              if (uVar2 < 0x14) goto LAB_800aa168;
            }
            else {
              *(undefined2 *)(piVar4[6] + 0x3e) = 0;
            }
            goto LAB_800aa0d0;
          }
        }
LAB_800aa168:
      }
      iVar6 = iVar6 + 1;
      puVar5 = puVar5 + 0xc;
    } while (iVar6 < (int)(uint)DAT_801486b0);
  }
  return;
}
