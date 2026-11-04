/* FUN_80069854
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80069854  body 0x80069854..0x80069aa7  size 596 B
 * body sha256 3ac52bd09bbccf18e05fcadcfc6c70d4e6764bee3e5a447be1eedfb23276aee5
 * provider record sha256 879dcbafece2dbb38d9544cb5f2a06668b45b03dbe27e81826f735d44f053a9e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80069854(uint *param_1,int param_2,short *param_3)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  uVar3 = (ushort)param_3[5] >> 4;
  if ((uVar3 & 2) == 0) {
    if ((ushort)param_3[3] - 500 < param_1[0x4a] - (param_3[1] + 0xfa)) {
      return 0;
    }
    sVar1 = *param_3;
    uVar7 = param_1[0x48];
    uVar2 = param_3[2];
  }
  else {
    if ((ushort)param_3[2] - 500 < param_1[0x48] - (*param_3 + 0xfa)) {
      return 0;
    }
    sVar1 = param_3[1];
    uVar7 = param_1[0x4a];
    uVar2 = param_3[3];
  }
  uVar4 = 0;
  if (uVar7 - (sVar1 + -0x28a) <= uVar2 + 0x514) {
    iVar5 = FUN_8006b220(param_3);
    iVar6 = FUN_8006b264(param_3);
    *(undefined1 *)((int)param_1 + 5) = 7;
    if (*(char *)(param_1 + 1) == '\x04') {
      *(undefined1 *)((int)param_1 + 5) = 0x1a;
    }
    *(short *)((int)param_1 + 0x1f6) = -1 - (short)((iVar5 - iVar6) / 0x708);
    *(undefined1 *)((int)param_1 + 6) = 0;
    *(undefined1 *)((int)param_1 + 0x206) = 0;
    if ((uVar3 & 2) == 0) {
      if ((int)(param_1[0x48] - (int)*param_3) < (int)(uint)((ushort)param_3[2] >> 1)) {
        *(undefined2 *)(param_1 + 0x7d) = 0;
        if ((uVar3 & 1) != 0) {
          *(undefined1 *)((int)param_1 + 0x206) = 1;
        }
        uVar7 = *param_3 - param_2;
      }
      else {
        *(undefined2 *)(param_1 + 0x7d) = 0x800;
        if ((uVar3 & 1) == 0) {
          *(undefined1 *)((int)param_1 + 0x206) = 1;
        }
        uVar7 = (int)*param_3 + (uint)(ushort)param_3[2] + param_2;
      }
      param_1[0x48] = uVar7;
    }
    else if ((int)(param_1[0x4a] - (int)param_3[1]) < (int)(uint)((ushort)param_3[3] >> 1)) {
      *(undefined2 *)(param_1 + 0x7d) = 0xc00;
      if ((uVar3 & 1) != 0) {
        *(undefined1 *)((int)param_1 + 0x206) = 1;
      }
      param_1[0x4a] = param_3[1] - param_2;
    }
    else {
      *(undefined2 *)(param_1 + 0x7d) = 0x400;
      if ((uVar3 & 1) == 0) {
        *(undefined1 *)((int)param_1 + 0x206) = 1;
      }
      param_1[0x4a] = (int)param_3[1] + (uint)(ushort)param_3[3] + param_2;
    }
    *param_1 = *param_1 | 8;
    uVar4 = 1;
    DAT_800e110c = DAT_800e110c | 0x40;
  }
  return uVar4;
}
