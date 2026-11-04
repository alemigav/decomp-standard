/* FUN_8006e838
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e838  body 0x8006e838..0x8006e9cb  size 132 B
 * body sha256 7bac219a76ddebfc84391837939a20edf183284f8deea4f3c2da367979878e8e
 * provider record sha256 57ee1fb7363cff42dd6df9bef2b51ab19d96f8263a2c304a8a73e20729b0614d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006e838(undefined4 param_1,ushort *param_2,uint param_3)

{
  uint uVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  
  if (DAT_80115120 != 0) {
    uVar1 = FUN_800844cc((int)(short)*param_2);
    sVar2 = (short)uVar1;
    switch(param_1) {
    case 0:
      uVar1 = uVar1 + param_3;
      break;
    case 1:
      uVar1 = uVar1 - param_3;
      break;
    case 2:
      iVar4 = (int)sVar2 * param_3 * 0x10000;
      goto LAB_8006eab4;
    case 3:
      uVar1 = (int)sVar2 / (int)param_3;
      if (param_3 == 0) {
        trap(0x1c00);
      }
      if ((param_3 == 0xffffffff) && (sVar2 == -0x80000000)) {
        trap(0x1800);
      }
      break;
    case 4:
      uVar1 = (int)sVar2 % (int)param_3;
      if (param_3 == 0) {
        trap(0x1c00);
      }
      if ((param_3 == 0xffffffff) && (sVar2 == -0x80000000)) {
        trap(0x1800);
      }
      break;
    case 5:
      uVar1 = uVar1 | param_3;
      break;
    case 6:
      uVar1 = uVar1 & param_3;
      break;
    case 7:
      uVar1 = uVar1 ^ param_3;
      break;
    case 8:
      uVar1 = ~(uint)*param_2;
      break;
    case 9:
      uVar1 = (uVar1 & 0xffff) << (param_3 & 0x1f);
      break;
    case 10:
      uVar1 = uVar1 & 0xffff;
      goto LAB_8006eaac;
    case 0xb:
      uVar1 = (uint)sVar2;
LAB_8006eaac:
      uVar1 = (int)uVar1 >> (param_3 & 0x1f);
    }
    iVar4 = uVar1 << 0x10;
LAB_8006eab4:
    uVar3 = FUN_800844cc(iVar4 >> 0x10);
    *param_2 = uVar3;
    DAT_80115120 = 0;
    return;
  }
  uVar3 = (ushort)param_3;
  switch(param_1) {
  case 0:
    *param_2 = *param_2 + uVar3;
    break;
  case 1:
    *param_2 = *param_2 - uVar3;
    break;
  case 2:
    *param_2 = *param_2 * uVar3;
    break;
  case 3:
    if (param_3 == 0) {
      trap(0x1c00);
    }
    if ((param_3 == 0xffffffff) && ((short)*param_2 == -0x80000000)) {
      trap(0x1800);
    }
    *param_2 = (ushort)((int)(short)*param_2 / (int)param_3);
    break;
  case 4:
    if (param_3 == 0) {
      trap(0x1c00);
    }
    if ((param_3 == 0xffffffff) && ((short)*param_2 == -0x80000000)) {
      trap(0x1800);
    }
    *param_2 = (ushort)((int)(short)*param_2 % (int)param_3);
    break;
  case 5:
    *param_2 = *param_2 | uVar3;
    break;
  case 6:
    *param_2 = *param_2 & uVar3;
    break;
  case 7:
    *param_2 = *param_2 ^ uVar3;
    break;
  case 8:
    *param_2 = ~*param_2;
    break;
  case 9:
    *param_2 = *param_2 << (param_3 & 0x1f);
    break;
  case 10:
    uVar3 = (ushort)((int)(uint)*param_2 >> (param_3 & 0x1f));
    goto LAB_8006e990;
  case 0xb:
    uVar3 = (ushort)((int)(short)*param_2 >> (param_3 & 0x1f));
LAB_8006e990:
    *param_2 = uVar3;
  }
  return;
}
