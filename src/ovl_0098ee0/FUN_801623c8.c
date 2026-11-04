/* FUN_801623c8
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x801623c8  body 0x801623c8..0x80162567  size 416 B
 * body sha256 fecab50b2bfcb54c16187e87642072fa285cc9c47755780ca7caace4fd10364d
 * provider record sha256 1e49a64d72194ea7a5471e25aaa73aac69c94be4dbaa47e93bb88d6b4d594809
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801623c8(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  *(undefined1 *)(param_1 + 0x2c4) = 0;
  switch(*(undefined1 *)(param_1 + 0x2c5)) {
  default:
    goto switchD_80162400_caseD_1;
  case 2:
  case 3:
  case 4:
    uVar3 = 1;
    uVar4 = 0;
    uVar5 = 6;
    uVar1 = 0x1000;
    break;
  case 5:
  case 6:
    uVar3 = 1;
    uVar4 = 0;
    uVar5 = 6;
    goto LAB_80162534;
  case 7:
    FUN_80162568(param_1,4,0,6,0x1500,3);
    uVar3 = 2;
    uVar4 = 0;
    uVar5 = 6;
    uVar1 = 0x1400;
    uVar2 = 2;
    goto LAB_80162540;
  case 8:
    FUN_80162568(param_1,4,0,6,0x1500,3);
    uVar3 = 4;
    uVar4 = 0;
    uVar5 = 6;
    uVar1 = 0x1400;
    uVar2 = 2;
    goto LAB_80162540;
  case 9:
    uVar3 = 5;
    uVar4 = 5;
    uVar5 = 4;
    uVar1 = 0x1000;
    break;
  case 10:
    FUN_80162910(param_1);
    return;
  case 0xb:
    uVar3 = 5;
    uVar4 = 4;
    uVar5 = 9;
    uVar1 = 0x1500;
    break;
  case 0xd:
    uVar3 = 1;
    uVar4 = 0;
    uVar5 = 6;
    uVar1 = 0x1000;
    break;
  case 0xe:
    FUN_801629bc(param_1);
    return;
  case 0xf:
  case 0x12:
    FUN_801626f0(param_1);
    return;
  case 0x10:
    uVar3 = 5;
    uVar4 = 5;
    uVar5 = 4;
LAB_80162534:
    uVar1 = 0x1600;
  }
  uVar2 = 3;
LAB_80162540:
  FUN_80162568(param_1,uVar3,uVar4,uVar5,uVar1,uVar2);
switchD_80162400_caseD_1:
  return;
}
