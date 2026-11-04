/* FUN_80083d2c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80083d2c  body 0x80083d2c..0x80083e13  size 232 B
 * body sha256 f22cab4a27b34e66aa5961c330495c17f05fada6f97602fe137e99b5d1930386
 * provider record sha256 0cf98023ac435a108d38490a8d21286712e96041d13b467839d2aa03938ae19f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80083d2c(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = (int)*(short *)(param_2 + 4);
  iVar5 = (int)*(short *)(param_2 + 6);
  iVar6 = param_1[2] - iVar5;
  iVar7 = *(short *)(param_2 + 8) - iVar8;
  iVar1 = *param_1 - iVar8;
  iVar2 = *(short *)(param_2 + 10) - iVar5;
  iVar3 = *(short *)(param_2 + 0x10) - iVar8;
  iVar4 = *(short *)(param_2 + 0x12) - iVar5;
  if ((iVar7 * iVar6 <= iVar2 * iVar1) && (iVar4 * iVar1 <= iVar3 * iVar6)) {
    iVar5 = *(short *)(param_2 + 0xe) - iVar5;
    iVar8 = *(short *)(param_2 + 0xc) - iVar8;
    if (((iVar2 - iVar5) * (iVar1 - iVar8) <= (iVar7 - iVar8) * (iVar6 - iVar5)) &&
       ((iVar3 - iVar8) * (iVar6 - iVar5) <= (iVar4 - iVar5) * (iVar1 - iVar8))) {
      return 1;
    }
  }
  return 0;
}
