/* FUN_8004e100
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004e100  body 0x8004e100..0x8004e2cb  size 460 B
 * body sha256 444385464ea448015b834aa3196282e52afbd45832f020ed459e0a3e9f3f3dd3
 * provider record sha256 0d0ba8d75cf532e0022aa5a54104935381cd883b97ccddb82870b7f77556e555
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8004e100(uint *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if (((*param_1 | *param_2) & 0x40) == 0) {
    if ((*param_1 & *param_2 & 0x200000) != 0) {
      return 0;
    }
    iVar8 = param_2[0x48] - param_1[0x48];
    iVar7 = param_2[0x4a] - param_1[0x4a];
    iVar6 = (uint)*(ushort *)(param_1 + 0x4b) + (uint)*(ushort *)(param_2 + 0x4b);
    iVar5 = (uint)*(ushort *)((int)param_1 + 0x12e) + (uint)*(ushort *)((int)param_2 + 0x12e);
    if ((uint)(iVar6 * 2) < (uint)(iVar8 + iVar6)) {
      return 0;
    }
    if ((uint)(iVar5 * 2) < (uint)(iVar7 + iVar5)) {
      return 0;
    }
    iVar4 = (uint)*(ushort *)((int)param_1 + 0x13a) + (uint)*(ushort *)((int)param_2 + 0x13a);
    if ((param_2[0x49] - param_1[0x49]) + iVar4 <= (uint)(iVar4 * 2)) {
      iVar2 = iVar8 * iVar5;
      if ((uint)(iVar4 * 2) <
          (uint)((((int)*(short *)((int)param_2 + 0x36) + (int)*(short *)(param_2 + 0x4d)) -
                 ((int)*(short *)((int)param_1 + 0x36) + (int)*(short *)(param_1 + 0x4d))) + iVar4))
      {
        iVar5 = (param_1[0xb] + (int)*(short *)(param_1 + 0x4d)) - (int)*(short *)(param_2 + 0x4d);
        if ((int)(param_2[0x49] - param_1[0x49]) < 0) {
          uVar1 = (iVar5 + -1) - iVar4;
        }
        else {
          uVar1 = iVar5 + 1 + iVar4;
        }
        param_2[0xb] = uVar1;
      }
      else {
        if (iVar2 < 0) {
          iVar2 = -iVar2;
        }
        iVar4 = iVar7 * iVar6;
        if (iVar4 < 0) {
          iVar4 = -iVar4;
        }
        if (iVar4 < iVar2) {
          uVar1 = param_2[10];
          if (iVar8 < 0) {
            uVar3 = (param_1[10] - 1) - iVar6;
          }
          else {
            uVar3 = param_1[10] + 1 + iVar6;
          }
          param_2[10] = uVar3;
          param_2[0x48] = param_2[0x48] + (uVar3 - uVar1);
        }
        else {
          uVar1 = param_2[0xc];
          if (iVar7 < 0) {
            uVar3 = (param_1[0xc] - 1) - iVar5;
          }
          else {
            uVar3 = param_1[0xc] + 1 + iVar5;
          }
          param_2[0xc] = uVar3;
          param_2[0x4a] = param_2[0x4a] + (uVar3 - uVar1);
        }
      }
      return 1;
    }
  }
  return 0;
}
