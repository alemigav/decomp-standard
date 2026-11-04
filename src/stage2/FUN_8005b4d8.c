/* FUN_8005b4d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005b4d8  body 0x8005b4d8..0x8005b527  size 80 B
 * body sha256 4e5d84e0bcf8ce71e4f95fb01c814f62dbefb006498e66c09886bebb69fa542b
 * provider record sha256 46b9815ac4bfd676b03da963e2dc8aeeae87fe7860cf23446fb74801eda55b1b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8005b4d8(int param_1,uint param_2,int *param_3,int *param_4)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_t0;
  
  iVar4 = 0;
  for (; (param_2 & 1) == 0; param_2 = (param_2 & 0xff) >> 1) {
    iVar4 = iVar4 + 1;
  }
  switch(iVar4) {
  case 0:
    in_t0 = ((int)*(short *)(param_1 + 0x10) - (int)*(short *)(param_1 + 0x12)) / 3;
    *param_3 = (int)*(short *)(param_1 + 0x10) + in_t0 * -2;
    iVar4 = (int)*(short *)(param_1 + 0x12) + in_t0 * -2;
    break;
  case 1:
    in_t0 = ((int)*(short *)(param_1 + 0x10) - (int)*(short *)(param_1 + 0x12)) / 3;
    *param_3 = *(short *)(param_1 + 0x10) - in_t0;
    iVar4 = *(short *)(param_1 + 0x12) - in_t0;
    break;
  case 2:
    sVar1 = *(short *)(param_1 + 0x10);
    sVar2 = *(short *)(param_1 + 0x12);
    *param_3 = (int)sVar1;
    iVar3 = (int)sVar1 - (int)sVar2;
    iVar5 = (int)*(short *)(param_1 + 0x12);
    iVar4 = iVar3 / 3 + (iVar3 >> 0x1f);
    goto LAB_8005b60c;
  case 3:
    sVar1 = *(short *)(param_1 + 0xc);
    sVar2 = *(short *)(param_1 + 0xe);
    *param_3 = (int)sVar1;
    iVar3 = (int)sVar1 - (int)sVar2;
    iVar5 = (int)*(short *)(param_1 + 0xe);
    iVar4 = iVar3 / 3 + (iVar3 >> 0x1f);
    goto LAB_8005b60c;
  case 4:
    sVar1 = *(short *)(param_1 + 8);
    sVar2 = *(short *)(param_1 + 10);
    *param_3 = (int)sVar1;
    iVar3 = (int)sVar1 - (int)sVar2;
    iVar4 = iVar3 / 3 + (iVar3 >> 0x1f);
    iVar5 = (int)*(short *)(param_1 + 10);
LAB_8005b60c:
    *param_4 = iVar5;
    return iVar4 - (iVar3 >> 0x1f);
  case 5:
    in_t0 = ((int)*(short *)(param_1 + 8) - (int)*(short *)(param_1 + 10)) / 3;
    *param_3 = *(short *)(param_1 + 8) + in_t0;
    iVar4 = *(short *)(param_1 + 10) + in_t0;
    break;
  case 6:
    in_t0 = ((int)*(short *)(param_1 + 8) - (int)*(short *)(param_1 + 10)) / 3;
    *param_3 = (int)*(short *)(param_1 + 8) + in_t0 * 2;
    iVar4 = (int)*(short *)(param_1 + 10) + in_t0 * 2;
    break;
  default:
    goto switchD_8005b520_default;
  }
  *param_4 = iVar4;
switchD_8005b520_default:
  return in_t0;
}
