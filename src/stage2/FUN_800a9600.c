/* FUN_800a9600
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a9600  body 0x800a9600..0x800a9a97  size 1176 B
 * body sha256 725b409f75eedf289e86b31dd9aa344437d8e5a815579de9600270e3242d2442
 * provider record sha256 352b26b81a293eff34ab74a987cf81683da3ae9559e884999348ab216bf1d3cd
 * callees 3 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x800a96e4) */
/* WARNING: Removing unreachable block (ram,0x800a97cc) */
/* WARNING: Removing unreachable block (ram,0x800a9884) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a9600(int param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float *param_6)

{
  int *piVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  double dVar10;
  undefined8 uVar11;
  float local_70;
  float local_6c;
  float local_68;
  float local_60;
  float local_5c;
  float local_58;
  
  uVar8 = 0x3c888889;
  *param_2 = 0.0;
  *param_3 = 1.0;
  iVar2 = 0;
  local_58 = 0.0;
  local_5c = 0.0;
  local_60 = 0.0;
  if (_DAT_80148bd8 != (int *)0x0) {
    uVar11 = 0x3f800000;
    uVar9 = 0;
    dVar10 = 0.0;
    piVar1 = _DAT_80148bd8;
    do {
      fVar3 = *(float *)(param_1 + 0xc) - (float)piVar1[3];
      fVar4 = *(float *)(param_1 + 0x10) - (float)piVar1[4];
      fVar5 = *(float *)(param_1 + 0x14) - (float)piVar1[5];
      fVar3 = SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar5 * fVar5);
      if (fVar3 <= *(float *)(param_1 + 0x24)) {
        fVar4 = fVar3 / *(float *)(param_1 + 0x24);
        *param_2 = *param_2 +
                   (float)piVar1[0x21] *
                   (*(float *)(param_1 + 0x2c) +
                   (*(float *)(param_1 + 0x28) - *(float *)(param_1 + 0x2c)) *
                   ((float)uVar11 -
                   (((float)uVar11 - *(float *)(param_1 + 0x30)) * fVar4 +
                   *(float *)(param_1 + 0x30) * fVar4 * fVar4)));
        if ((*(uint *)(param_1 + 8) & 0x80000) == 0) {
          if ((((*(uint *)(param_1 + 8) & 8) != 0) || ((piVar1[2] & 1U) != 0)) &&
             (fVar4 = (float)piVar1[6] - *(float *)(param_1 + 0x18),
             fVar5 = (float)piVar1[7] - *(float *)(param_1 + 0x1c),
             fVar6 = (float)piVar1[8] - *(float *)(param_1 + 0x20),
             fVar4 = SQRT(fVar4 * fVar4 + fVar5 * fVar5 + fVar6 * fVar6), (float)uVar9 < fVar4)) {
            fVar5 = (float)uVar8;
            fVar7 = (*(float *)(param_1 + 0xc) + *(float *)(param_1 + 0x18) * fVar5) -
                    ((float)piVar1[3] + (float)piVar1[6] * fVar5);
            fVar6 = (*(float *)(param_1 + 0x10) + *(float *)(param_1 + 0x1c) * fVar5) -
                    ((float)piVar1[4] + (float)piVar1[7] * fVar5);
            fVar5 = (*(float *)(param_1 + 0x14) + *(float *)(param_1 + 0x20) * fVar5) -
                    ((float)piVar1[5] + (float)piVar1[8] * fVar5);
            if (SQRT(fVar7 * fVar7 + fVar6 * fVar6 + fVar5 * fVar5) < fVar3) {
              fVar5 = (float)piVar1[0x20];
              fVar4 = fVar5 - fVar4;
            }
            else {
              fVar5 = (float)piVar1[0x20];
              fVar4 = fVar5 + fVar4;
            }
            *param_3 = fVar5 / fVar4;
          }
          if (fVar3 != (float)uVar9) {
            FUN_800ab1a0(piVar1 + 0x12,param_1 + 0xc,&local_70);
            if ((float)uVar9 <= local_68) {
              if (local_68 < (float)piVar1[0x1e]) {
                fVar3 = local_68 / (float)piVar1[0x1e];
                goto LAB_800a994c;
              }
              local_58 = local_58 + 1.0;
            }
            else {
              if (-(float)piVar1[0x1f] < local_68) {
                fVar3 = local_68 / (float)piVar1[0x1f];
              }
              else {
                fVar3 = -1.0;
              }
LAB_800a994c:
              local_58 = local_58 + fVar3;
            }
            if ((((double)local_70 != dVar10) || ((double)local_6c != dVar10)) ||
               (local_68 != (float)uVar9)) {
              FUN_800ab24c(&local_70);
            }
            local_60 = local_60 + local_70;
            local_5c = local_5c + local_6c;
          }
        }
      }
      piVar1 = (int *)*piVar1;
      iVar2 = iVar2 + 1;
    } while (piVar1 != (int *)0x0);
  }
  if (iVar2 != 0) {
    fVar3 = (float)iVar2;
    if (iVar2 < 0) {
      fVar3 = fVar3 + 4.2949673e+09;
    }
    fVar4 = (float)iVar2;
    *param_4 = local_60 / fVar3;
    if (iVar2 < 0) {
      fVar4 = fVar4 + 4.2949673e+09;
    }
    fVar3 = (float)iVar2;
    *param_5 = local_5c / fVar4;
    if (iVar2 < 0) {
      fVar3 = fVar3 + 4.2949673e+09;
    }
    *param_6 = local_58 / fVar3;
  }
  return;
}
