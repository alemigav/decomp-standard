/* FUN_8002d710
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002d710  body 0x8002d710..0x8002d917  size 520 B
 * body sha256 dad098fdb87f971ad1e25c455b1317e46c4a0c88eee7d9fa237c3cbc5ba42285
 * provider record sha256 e84fb76642e3571c1147b29a40af610a29e9bef32f70c678feddf7a638447028
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002d710(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  
  if (param_1[0x46] == 1) {
    iVar1 = param_1[0x47];
    param_1[0x4b] = *(int *)(iVar1 + 0x1c);
    param_1[0x4c] = *(int *)(iVar1 + 0x20);
    *(undefined4 *)(iVar1 + 0x34) = 1;
    *(undefined4 *)(iVar1 + 0x38) = 1;
    *(undefined4 *)(iVar1 + 0x3c) = 1;
    *(undefined4 *)(iVar1 + 0x44) = 1;
    *(undefined4 *)(iVar1 + 0x48) = 1;
    *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)(iVar1 + 0x24);
    param_1[0x4d] = 1;
    param_1[0x4e] = 0;
  }
  else {
    if (3 < param_1[0x46] - 1U) {
      *(undefined4 *)(*param_1 + 0x14) = 0x13;
      *(int *)(*param_1 + 0x18) = param_1[0x46];
      *(undefined4 *)(*param_1 + 0x1c) = 4;
      (**(code **)*param_1)(param_1);
    }
    iVar1 = FUN_80030ea0(param_1[6],param_1[0x41] << 3);
    param_1[0x4b] = iVar1;
    iVar1 = FUN_80030ea0(param_1[7],param_1[0x42] << 3);
    iVar4 = 0;
    param_1[0x4c] = iVar1;
    param_1[0x4d] = 0;
    if (0 < param_1[0x46]) {
      piVar5 = param_1;
      do {
        iVar1 = piVar5[0x47];
        *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(iVar1 + 8);
        uVar2 = *(uint *)(iVar1 + 0x34);
        uVar6 = *(uint *)(iVar1 + 0x1c) % uVar2;
        if (uVar2 == 0) {
          trap(0x1c00);
        }
        *(int *)(iVar1 + 0x38) = *(int *)(iVar1 + 0xc);
        *(uint *)(iVar1 + 0x3c) = uVar2 * *(int *)(iVar1 + 0xc);
        *(uint *)(iVar1 + 0x40) = uVar2 * *(int *)(iVar1 + 0x24);
        if (uVar6 == 0) {
          uVar6 = uVar2;
        }
        uVar2 = *(uint *)(iVar1 + 0x38);
        *(uint *)(iVar1 + 0x44) = uVar6;
        uVar6 = *(uint *)(iVar1 + 0x20) % uVar2;
        if (uVar2 == 0) {
          trap(0x1c00);
        }
        if (uVar6 == 0) {
          uVar6 = uVar2;
        }
        iVar3 = *(int *)(iVar1 + 0x3c);
        *(uint *)(iVar1 + 0x48) = uVar6;
        if (10 < param_1[0x4d] + iVar3) {
          *(undefined4 *)(*param_1 + 0x14) = 10;
          (**(code **)*param_1)(param_1);
        }
        for (; 0 < iVar3; iVar3 = iVar3 + -1) {
          iVar1 = param_1[0x4d];
          param_1[iVar1 + 0x4e] = iVar4;
          param_1[0x4d] = iVar1 + 1;
        }
        iVar4 = iVar4 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar4 < param_1[0x46]);
    }
  }
  return;
}
