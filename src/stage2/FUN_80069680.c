/* FUN_80069680
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80069680  body 0x80069680..0x80069853  size 468 B
 * body sha256 bb4cc10a50c385c6e4906e099e1c2fb7df133fd44988bde971107f155b18c0ac
 * provider record sha256 1d9ed3265ede1f6a5dc9c3cdd868f69cac6d8a089383b121046e981bf5dc8303
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80069680(int param_1,int param_2,short *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  FUN_80069c60(*(undefined4 *)(param_1 + 0x120),*(undefined4 *)(param_1 + 0x128),param_2,param_3);
  if ((param_3[5] & 0x20U) == 0) {
    iVar4 = (int)*(short *)(param_1 + 0x1b6) + (int)*(short *)(param_1 + 0x13e);
    if ((iVar4 < param_3[1] - param_2) ||
       ((int)((int)param_3[1] + (uint)(ushort)param_3[3] + param_2) < iVar4)) goto LAB_80069750;
    iVar4 = *(int *)(param_1 + 0x120);
    if (iVar4 < *param_3) goto LAB_8006978c;
    iVar2 = (int)*param_3 + (uint)(ushort)param_3[2];
  }
  else {
    if (((int)*(short *)(param_1 + 0x1b4) < *param_3 - param_2) ||
       ((int)((int)*param_3 + (uint)(ushort)param_3[2] + param_2) < (int)*(short *)(param_1 + 0x1b4)
       )) {
LAB_80069750:
      uVar3 = FUN_80066ec8(param_1,param_2,param_3);
      return uVar3;
    }
    iVar4 = *(int *)(param_1 + 0x128);
    if (iVar4 < param_3[1]) goto LAB_8006978c;
    iVar2 = (int)param_3[1] + (uint)(ushort)param_3[3];
  }
  if (iVar4 <= iVar2) {
    iVar4 = FUN_80069c60(*(undefined4 *)(param_1 + 0x120),*(undefined4 *)(param_1 + 0x128),param_2,
                         param_3);
    iVar4 = iVar4 + ((ushort)param_3[5] >> 6 & 0x1f) * -0x708;
    *(int *)(param_1 + 0x2c) = iVar4;
    *(char *)(param_1 + 0x1a2) = -(char)(iVar4 / 0x708);
    return 1;
  }
LAB_8006978c:
  uVar1 = -((*(int *)(param_1 + 0x2c) + -900) / 0x708);
  *(char *)(param_1 + 0x1a2) = (char)uVar1;
  *(uint *)(param_1 + 0x2c) = (uVar1 & 0xff) * -0x708;
  return 1;
}
