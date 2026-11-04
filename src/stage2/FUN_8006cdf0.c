/* FUN_8006cdf0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006cdf0  body 0x8006cdf0..0x8006d0ab  size 700 B
 * body sha256 dde09078e9a0ae924dcf0f6eaaacdef2b26c81bde866761e69885644396b2794
 * provider record sha256 a3966c195d91e107c6ed7f2788cd4f8da0db174652b1443d43c18ffd00dab16c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006cdf0(uint param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,undefined4 param_9,undefined4 param_10,int param_11,
                 int param_12)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int local_60 [7];
  uint local_44;
  int local_40;
  int local_38;
  undefined4 local_34 [9];
  
  piVar3 = local_60;
  piVar4 = local_60;
  DAT_801137d8 = (param_1 - param_3) - param_4;
  DAT_801137e4 = param_5;
  DAT_801137ec = param_6;
  DAT_801137dc = (param_2 - param_5) - param_6;
  iVar2 = param_12 * 4 + param_11 * 8;
  if (0xf0 < param_2) {
    iVar2 = iVar2 + 0x10;
  }
  if (_DAT_80000300 != 2) {
    iVar2 = iVar2 + 0x20;
  }
  iVar2 = *(int *)(&UNK_80112800 + iVar2);
  puVar1 = (undefined4 *)(iVar2 * 0x50 + -0x7ffed510);
  do {
    uVar5 = puVar1[1];
    uVar6 = puVar1[2];
    uVar7 = puVar1[3];
    *piVar3 = *puVar1;
    piVar3[1] = uVar5;
    piVar3[2] = uVar6;
    piVar3[3] = uVar7;
    puVar1 = puVar1 + 4;
    piVar3 = piVar3 + 4;
  } while (puVar1 != (undefined4 *)(iVar2 * 0x50 + -0x7ffed4c0));
  local_60[2] = DAT_801137d8;
  local_38 = DAT_801137d8 * 2 + -8;
  if (param_1 == 0) {
    trap(0x1c00);
  }
  if (param_1 == 0) {
    trap(0x1c00);
  }
  if (param_2 == 0) {
    trap(0x1c00);
    trap(0x1c00);
  }
  puVar1 = &DAT_801129c8;
  local_40 = (int)(param_1 << 10) / 0x280;
  local_44 = (param_7 + (uint)(param_3 * 0x280) / param_1) * 0x10000 |
             param_8 - (uint)(param_4 * 0x280) / param_1;
  DAT_801137e0 = param_3;
  DAT_801137e8 = param_4;
  do {
    uVar5 = piVar4[1];
    uVar6 = piVar4[2];
    uVar7 = piVar4[3];
    *puVar1 = *piVar4;
    puVar1[1] = uVar5;
    puVar1[2] = uVar6;
    puVar1[3] = uVar7;
    piVar4 = piVar4 + 4;
    puVar1 = puVar1 + 4;
  } while (piVar4 != local_34 + 9);
  return;
}
