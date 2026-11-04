/* FUN_8002d330
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002d330  body 0x8002d330..0x8002d70f  size 992 B
 * body sha256 55f76e9412b052625300f3e94f6fb57470abbbb2bb88a039d117a0d97494fb62
 * provider record sha256 8f815d06a63fec11178f25c1a1609ace4260a08238386512507cf656605711c4
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002d330(int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  
  iVar7 = 0;
  param_1[0x41] = 1;
  param_1[0x42] = 1;
  if (0 < param_1[8]) {
    piVar5 = (int *)(param_1[0x2c] + 0xc);
    do {
      if (((3 < piVar5[-1] - 1U) || (*piVar5 < 1)) || (4 < *piVar5)) {
        *(undefined4 *)(*param_1 + 0x14) = 0xd;
        (**(code **)*param_1)(param_1);
      }
      iVar4 = piVar5[-1];
      if (piVar5[-1] < param_1[0x41]) {
        iVar4 = param_1[0x41];
      }
      param_1[0x41] = iVar4;
      iVar4 = *piVar5;
      if (*piVar5 < param_1[0x42]) {
        iVar4 = param_1[0x42];
      }
      iVar7 = iVar7 + 1;
      piVar5 = piVar5 + 0x14;
      param_1[0x42] = iVar4;
    } while (iVar7 < param_1[8]);
  }
  iVar7 = param_1[0xb];
  uVar2 = param_1[0xc];
  if (uVar2 < (uint)(iVar7 << 3)) {
    if (uVar2 < (uint)(iVar7 << 2)) {
      if (uVar2 < (uint)(iVar7 << 1)) {
        param_1[0x43] = 8;
        param_1[0x17] = param_1[6];
        param_1[0x18] = param_1[7];
      }
      else {
        iVar7 = FUN_80030ea0(param_1[6],2);
        param_1[0x17] = iVar7;
        iVar7 = FUN_80030ea0(param_1[7],2);
        param_1[0x18] = iVar7;
        param_1[0x43] = 4;
      }
    }
    else {
      iVar7 = FUN_80030ea0(param_1[6],4);
      param_1[0x17] = iVar7;
      iVar7 = FUN_80030ea0(param_1[7],4);
      param_1[0x18] = iVar7;
      param_1[0x43] = 2;
    }
  }
  else {
    iVar7 = FUN_80030ea0(param_1[6],8);
    param_1[0x17] = iVar7;
    iVar7 = FUN_80030ea0(param_1[7],8);
    param_1[0x18] = iVar7;
    param_1[0x43] = 1;
  }
  iVar7 = 0;
  piVar5 = (int *)(param_1[0x2c] + 0x24);
  do {
    if (param_1[8] <= iVar7) {
      switch(param_1[10]) {
      case 1:
        iVar7 = 1;
        break;
      case 2:
      case 3:
        iVar7 = 3;
        break;
      case 4:
      case 5:
        iVar7 = 4;
        break;
      default:
        iVar7 = param_1[8];
      }
      param_1[0x19] = iVar7;
      iVar7 = 1;
      if (param_1[0x11] == 0) {
        iVar7 = param_1[0x19];
      }
      param_1[0x1a] = iVar7;
      iVar7 = FUN_8002d260(param_1);
      if (iVar7 == 0) {
        param_1[0x1b] = 1;
      }
      else {
        param_1[0x1b] = param_1[0x42];
      }
      iVar7 = 0;
      if (0 < param_1[8]) {
        puVar6 = (undefined4 *)(param_1[0x2c] + 0x30);
        do {
          uVar1 = FUN_80030ea0(param_1[6] * puVar6[-10],param_1[0x41] << 3);
          puVar6[-5] = uVar1;
          uVar1 = FUN_80030ea0(param_1[7] * puVar6[-9],param_1[0x42] << 3);
          puVar6[-4] = uVar1;
          uVar1 = FUN_80030ea0(param_1[6] * puVar6[-10] * puVar6[-3],param_1[0x41] << 3);
          puVar6[-2] = uVar1;
          iVar7 = iVar7 + 1;
          uVar1 = FUN_80030ea0(param_1[7] * puVar6[-9] * puVar6[-3],param_1[0x42] << 3);
          puVar6[-1] = uVar1;
          *puVar6 = 1;
          puVar6 = puVar6 + 0x14;
        } while (iVar7 < param_1[8]);
      }
      iVar7 = FUN_80030ea0(param_1[7],param_1[0x42] << 3);
      param_1[0x44] = iVar7;
      return;
    }
    iVar3 = param_1[0x43];
    iVar4 = iVar3;
    if (iVar3 < 8) {
      if (piVar5[-7] * iVar3 * 2 <= param_1[0x41] * iVar3) {
        while (piVar5[-6] * iVar4 * 2 <= param_1[0x42] * iVar3) {
          iVar4 = iVar4 * 2;
          if ((7 < iVar4) || (param_1[0x41] * iVar3 < piVar5[-7] * iVar4 * 2)) break;
        }
        goto LAB_8002d580;
      }
      *piVar5 = iVar3;
    }
    else {
LAB_8002d580:
      *piVar5 = iVar4;
    }
    iVar7 = iVar7 + 1;
    piVar5 = piVar5 + 0x14;
  } while( true );
}
