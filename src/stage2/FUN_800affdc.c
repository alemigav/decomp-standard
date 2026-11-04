/* FUN_800affdc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800affdc  body 0x800affdc..0x800b0253  size 632 B
 * body sha256 19d7779dbae1a81b790ecc7f12860c8cf0bc2c8505760d352c8974a56e37f143
 * provider record sha256 0b594ffa1b612ee374a5ef77574d1d61a49c109de7773885df2349cc24bea760
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800affdc(int param_1,uint *param_2,char param_3)

{
  short sVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int unaff_s0;
  
  if (*(char *)param_2 == '\0') {
    uVar4 = *(byte *)((int)param_2 + 7) & 0x1f;
    if (uVar4 < 0x10) {
      sVar1 = *(short *)(param_1 + uVar4 * 2 + 0x180);
    }
    else {
      sVar1 = *(short *)((uVar4 - 0x10) * 2 + -0x7feb8050);
    }
  }
  else {
    sVar1 = FUN_800aca08();
  }
  if (param_3 == '\x04') {
    sVar2 = (short)(param_2[1] >> 8);
  }
  else {
    uVar4 = param_2[1] >> 0x10;
    if ((param_2[1] >> 8 & 0xff) == 0) {
      uVar4 = uVar4 & 0x1f;
      if (uVar4 < 0x10) {
        sVar2 = *(short *)(param_1 + uVar4 * 2 + 0x180);
      }
      else {
        sVar2 = *(short *)((uVar4 - 0x10) * 2 + -0x7feb8050);
      }
    }
    else {
      sVar2 = FUN_800aca08(param_1,uVar4 & 0xff);
    }
  }
  switch(param_3) {
  case '\0':
  case '\x04':
    unaff_s0 = (int)sVar1 + (int)sVar2;
    break;
  case '\x01':
    unaff_s0 = (int)sVar1 - (int)sVar2;
    break;
  case '\x02':
    unaff_s0 = (int)sVar1 * (int)sVar2;
    break;
  case '\x03':
    iVar3 = (int)sVar2;
    if (iVar3 == 0) {
      unaff_s0 = 0;
    }
    else {
      unaff_s0 = (int)sVar1 / iVar3;
      if (iVar3 == 0) {
        trap(0x1c00);
      }
      if ((iVar3 == -1) && (sVar1 == -0x80000000)) {
        trap(0x1800);
      }
    }
  }
  uVar4 = *param_2 >> 0x10;
  iVar3 = -0x8000;
  if ((-0x8001 < unaff_s0) && (iVar3 = 0x7fff, unaff_s0 < 0x8000)) {
    iVar3 = unaff_s0;
  }
  sVar1 = (short)iVar3;
  if ((*param_2 >> 8 & 0xff) == 0) {
    uVar4 = uVar4 & 0x1f;
    if (uVar4 < 0x10) {
      *(short *)(param_1 + uVar4 * 2 + 0x180) = sVar1;
    }
    else {
      *(short *)((uVar4 - 0x10) * 2 + -0x7feb8050) = sVar1;
    }
  }
  else {
    FUN_800acae4(param_1,uVar4 & 0xff,(int)sVar1);
  }
  return 0;
}
