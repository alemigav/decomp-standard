/* FUN_8006a4d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006a4d0  body 0x8006a4d0..0x8006a6c7  size 504 B
 * body sha256 19fd5506ca7af6ae0c2fdde5d0794226c745e93946a2bc80a232bd4aff9fc1fc
 * provider record sha256 35c1976a4abd93c8bf4b57a0558c6258896f05a690bb92cde193b2cae0336d84
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
ushort FUN_8006a4d0(undefined4 *param_1,short *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  short sVar5;
  int iVar4;
  ushort uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  
  iVar12 = (int)*param_2;
  iVar1 = FUN_8006b220(param_2);
  iVar11 = (int)param_2[1];
  uVar10 = (uint)(ushort)param_2[2];
  iVar2 = FUN_8006b264(param_2);
  uVar8 = (uint)(ushort)param_2[3];
  uVar9 = iVar2 - iVar1;
  iVar2 = iVar12;
  uVar13 = uVar10;
  if (param_4 == 0) {
    iVar4 = FUN_8006a75c(param_3);
    if (iVar4 == 1) goto LAB_8006a658;
    if (iVar4 != 0) {
      if (iVar4 == 2) {
        uVar6 = FUN_8006a6c8(param_1[1],*param_1,iVar1,iVar12,uVar9,uVar10);
        return uVar6;
      }
      return 2;
    }
    uVar3 = *param_1;
    uVar7 = param_1[2];
    goto LAB_8006a66c;
  }
  uVar3 = FUN_8006a7ec(param_3);
  uVar6 = 0;
  switch(uVar3) {
  case 0:
    uVar3 = *param_1;
    uVar7 = param_1[2];
    break;
  case 1:
    uVar3 = *param_1;
    uVar7 = param_1[2];
    goto LAB_8006a5f0;
  case 2:
LAB_8006a658:
    uVar3 = param_1[2];
    uVar7 = param_1[1];
    iVar2 = iVar11;
    iVar11 = iVar1;
    uVar13 = uVar8;
    uVar8 = uVar9;
    break;
  case 3:
    uVar3 = param_1[2];
    uVar7 = param_1[1];
    iVar2 = iVar11;
    iVar11 = iVar1;
    uVar13 = uVar8;
    uVar8 = uVar9;
    goto LAB_8006a5f0;
  case 4:
    uVar3 = param_1[1];
    uVar7 = *param_1;
    iVar2 = iVar1;
    iVar11 = iVar12;
    uVar13 = uVar9;
    uVar8 = uVar10;
    break;
  case 5:
    uVar3 = param_1[1];
    uVar7 = *param_1;
    iVar2 = iVar1;
    iVar11 = iVar12;
    uVar13 = uVar9;
    uVar8 = uVar10;
LAB_8006a5f0:
    sVar5 = FUN_8006a6c8(uVar3,uVar7,iVar2,iVar11,uVar13,uVar8);
    uVar6 = -sVar5 & 3;
  default:
    goto switchD_8006a560_default;
  }
LAB_8006a66c:
  uVar6 = FUN_8006a6c8(uVar3,uVar7,iVar2,iVar11,uVar13,uVar8);
switchD_8006a560_default:
  return uVar6;
}
