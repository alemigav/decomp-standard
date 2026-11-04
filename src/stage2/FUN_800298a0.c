/* FUN_800298a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800298a0  body 0x800298a0..0x800299fb  size 348 B
 * body sha256 fc1ee5ba200d3bbda2c47e25dddb868f928dc2acffac216ae8c3607682e044c9
 * provider record sha256 d37501c503f8a50f2f4536b59428b14f602b4e1317c7cb3ae511623c30c15b4d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800298a0(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  iVar3 = param_1[0x5e];
  iVar4 = 0;
  if (0 < param_1[0x46]) {
    piVar5 = param_1;
    iVar6 = iVar3;
    do {
      uVar1 = *(uint *)(piVar5[0x47] + 0x14);
      uVar2 = *(uint *)(piVar5[0x47] + 0x18);
      if ((3 < uVar1) || (param_1[uVar1 + 0x23] == 0)) {
        *(undefined4 *)(*param_1 + 0x14) = 0x2a;
        *(uint *)(*param_1 + 0x18) = uVar1;
        (**(code **)*param_1)(param_1);
      }
      if ((3 < uVar2) || (param_1[uVar2 + 0x27] == 0)) {
        *(undefined4 *)(*param_1 + 0x14) = 0x2a;
        *(uint *)(*param_1 + 0x18) = uVar2;
        (**(code **)*param_1)(param_1);
      }
      piVar5 = piVar5 + 1;
      iVar4 = iVar4 + 1;
      FUN_800299fc(param_1,param_1[uVar1 + 0x23],iVar3 + uVar1 * 4 + 0x28);
      FUN_800299fc(param_1,param_1[uVar2 + 0x27],iVar3 + uVar2 * 4 + 0x38);
      *(undefined4 *)(iVar6 + 0x10) = 0;
      iVar6 = iVar6 + 4;
    } while (iVar4 < param_1[0x46]);
  }
  *(undefined4 *)(iVar3 + 0xc) = 0;
  *(undefined4 *)(iVar3 + 0x24) = 0;
  *(int *)(iVar3 + 0x20) = param_1[0x3a];
  return;
}
