/* FUN_80162ba4
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80162ba4  body 0x80162ba4..0x80162d03  size 352 B
 * body sha256 5a3c4640ed92ae71dd6a9710912d8d5a271b2c2d6f1c95333146567ca80360df
 * provider record sha256 9b90768c4634eb1d58127a1077e8c651b8a4c3078166e95f7d6595f785e05f2a
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162ba4(int param_1,byte *param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = (uint)*param_2;
  iVar6 = *(int *)(param_1 + 0x234);
  bVar1 = param_2[3];
  if (param_3 == 0) {
    bVar2 = param_2[1];
  }
  else {
    bVar2 = param_2[2];
  }
  if (uVar5 != 0) {
    do {
      uVar5 = uVar5 - 1;
      uVar3 = func_0x80033604();
      func_0x80037780((uint)param_2[4] << 0x18 | (uint)param_2[5] << 0x10 |
                      (uint)*(ushort *)(param_2 + 6),0,
                      iVar6 + *(short *)(&DAT_80168a56 +
                                        ((uint)bVar2 + (uVar3 & bVar1 - 1 & 0xff)) * 8) * 0x178 +
                      0x38);
    } while (uVar5 != 0);
  }
  *(undefined1 *)(param_1 + 0x2cf) = 0;
  switch(*(undefined1 *)(param_1 + 0x2cb)) {
  default:
    goto switchD_80162c98_caseD_1;
  case 0xb:
    if (*(char *)(iVar6 + 99) == 'H') {
      return;
    }
    uVar4 = 0x58;
    break;
  case 0xe:
    FUN_80162d04(param_1);
  case 10:
  case 0x10:
  case 0x11:
  case 0x13:
    uVar4 = 0x48;
  }
  FUN_80162f08(param_1,0x16,uVar4,uVar4,uVar4);
switchD_80162c98_caseD_1:
  return;
}
