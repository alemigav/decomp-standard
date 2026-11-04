/* FUN_80163638
 * image   ovl_0097e42 (ovl), base 0x80161cf0
 * address 0x80163638  body 0x80163638..0x801636e3  size 172 B
 * body sha256 ff166183c80a573ac9057aeb8218283d9dd808a3afdbba10365b850998e0e510
 * provider record sha256 98741e5c6075f10ac586d8a9cf138b55e2a92297ed3e04fe09ed5939b379d2d0
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163638(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  switch(param_2) {
  default:
    goto switchD_80163660_caseD_1;
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
    uVar1 = 0;
    uVar2 = 0x10;
    uVar3 = 0x1000;
    break;
  case 9:
  case 10:
  case 0x10:
  case 0x11:
  case 0x13:
    uVar1 = 5;
    uVar2 = 4;
    uVar3 = 0x1300;
    break;
  case 0xb:
    uVar1 = 4;
    uVar2 = 9;
    uVar3 = 0x800;
    break;
  case 0xd:
    uVar1 = 0;
    uVar2 = 0x10;
    uVar3 = 0x1000;
    break;
  case 0xe:
    *(undefined1 *)(param_1 + 0x2c4) = 7;
    return;
  case 0xf:
    uVar1 = 0;
    uVar2 = 0x10;
    uVar3 = 0x1000;
    break;
  case 0x12:
    uVar1 = 0;
    uVar2 = 0x10;
    uVar3 = 0x1000;
  }
  FUN_801636e4(param_1,uVar1,uVar2,uVar3);
switchD_80163660_caseD_1:
  return;
}
