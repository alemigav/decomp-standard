/* FUN_80166f84
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80166f84  body 0x80166f84..0x801670b7  size 308 B
 * body sha256 8996487f2c9d0086e641600a92dc9800d87a2e33a5138411c01ce377b696d1e2
 * provider record sha256 04a29c0d3c7cf8ca50e9319986f808f94676c1ee11b9aa40cf1b077f5857d986
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80166f84(int param_1,uint param_2,short param_3,undefined4 *param_4)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar7 = *(undefined4 *)(param_1 + 0x28);
  uVar6 = *(undefined4 *)(param_1 + 0x30);
  uVar1 = *(undefined2 *)(param_1 + 0x66);
  iVar5 = *(int *)(param_1 + 0x234) + param_2 * 0x178;
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(iVar5 + 0x4c);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(iVar5 + 0x54);
  if (8 < param_2) {
    *(short *)(param_1 + 0x66) =
         *(short *)(param_1 + 0x66) +
         *(short *)(*(int *)(param_1 + 0x234) + (uint)*(byte *)(param_1 + 0x25d) * 0x178 + 0x130);
  }
  iVar5 = *(int *)(param_1 + 0x28) - _DAT_800e1158;
  iVar2 = *(int *)(param_1 + 0x30) - _DAT_800e1160;
  uVar3 = func_0x80040bb4(iVar5 * iVar5 + iVar2 * iVar2);
  *param_4 = uVar3;
  sVar4 = FUN_80166d64(param_1,_DAT_800e1158,_DAT_800e1160,(int)param_3);
  *(undefined4 *)(param_1 + 0x28) = uVar7;
  *(undefined4 *)(param_1 + 0x30) = uVar6;
  *(undefined2 *)(param_1 + 0x66) = uVar1;
  return (int)sVar4;
}
