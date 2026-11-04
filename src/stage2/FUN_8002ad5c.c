/* FUN_8002ad5c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002ad5c  body 0x8002ad5c..0x8002aedb  size 384 B
 * body sha256 fee126eb8f0cf7c00cc459cb89c82959054476296d7d134d43c10bc74043ad5c
 * provider record sha256 2f242cb9d538bde6096d49eeb35afbca24e18c2ef80491c4014b06e363573cba
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002ad5c(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  puVar3 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x54);
  param_1[0x5a] = (int)puVar3;
  *puVar3 = FUN_8002aa30;
  if (param_2 != 0) {
    *(undefined4 *)(*param_1 + 0x14) = 4;
    (**(code **)*param_1)(param_1);
  }
  if (param_1[0x10] == 0) {
    if (*(int *)(param_1[0x60] + 8) == 0) {
      iVar9 = param_1[0x43];
    }
    else {
      if (param_1[0x43] < 2) {
        *(undefined4 *)(*param_1 + 0x14) = 0x27;
        (**(code **)*param_1)(param_1);
      }
      iVar9 = param_1[0x43] + 2;
    }
    iVar8 = 0;
    if (0 < param_1[8]) {
      piVar7 = (int *)(param_1[0x2c] + 0x1c);
      do {
        piVar1 = piVar7 + 2;
        iVar2 = piVar7[-4] * *piVar1;
        iVar6 = param_1[0x43];
        if (iVar6 == 0) {
          trap(0x1c00);
        }
        if ((iVar6 == -1) && (iVar2 == -0x80000000)) {
          trap(0x1800);
        }
        iVar5 = *piVar7;
        iVar8 = iVar8 + 1;
        piVar7 = piVar7 + 0x14;
        uVar4 = (**(code **)(param_1[1] + 8))(param_1,1,iVar5 * *piVar1,(iVar2 / iVar6) * iVar9);
        puVar3[3] = uVar4;
        puVar3 = puVar3 + 1;
      } while (iVar8 < param_1[8]);
    }
  }
  return;
}
