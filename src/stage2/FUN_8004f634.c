/* FUN_8004f634
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004f634  body 0x8004f634..0x8004f773  size 320 B
 * body sha256 1738a0f4656776e04a8018eb1d856ca99edbcfa5c1ea0cc54df127d6849d1975
 * provider record sha256 4ea01cfe53348f66334bb1c2addc3062e3b3048ab38ca0b455b51687c72c9966
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004f634(uint *param_1,uint *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (((*param_1 & 0x40) == 0) && ((*param_2 & 2) == 0)) {
    iVar5 = param_2[0x48] - param_1[0x48];
    iVar3 = param_2[0x4a] - param_1[0x4a];
    iVar7 = -(uint)(*(ushort *)(param_1 + 0x4b) >> 1) + (uint)*(ushort *)(param_2 + 0x4b);
    iVar6 = -(uint)(*(ushort *)(param_1 + 0x4b) >> 1) + (uint)*(ushort *)((int)param_2 + 0x12e);
    bVar4 = (uint)(iVar7 * 2) < (uint)(iVar5 + iVar7);
    if ((uint)(iVar6 * 2) < (uint)(iVar3 + iVar6)) {
      bVar4 = bVar4 | 2;
    }
    if (bVar4 != 0) {
      if ((bVar4 & 1) != 0) {
        iVar1 = iVar5;
        if (iVar5 < 0) {
          iVar1 = -iVar5;
        }
        uVar2 = param_4;
        if ((uint)(iVar1 - iVar7) < param_4) {
          iVar1 = iVar5;
          if (iVar5 < 0) {
            iVar1 = -iVar5;
          }
          uVar2 = iVar1 - iVar7;
        }
        if (-1 < iVar5) {
          uVar2 = -uVar2;
        }
        param_1[10] = param_1[10] - uVar2;
        param_1[0x48] = param_1[0x48] - uVar2;
      }
      if ((bVar4 & 2) != 0) {
        iVar5 = iVar3;
        if (iVar3 < 0) {
          iVar5 = -iVar3;
        }
        if ((uint)(iVar5 - iVar6) < param_4) {
          iVar5 = iVar3;
          if (iVar3 < 0) {
            iVar5 = -iVar3;
          }
          param_4 = iVar5 - iVar6;
        }
        if (-1 < iVar3) {
          param_4 = -param_4;
        }
        param_1[0xc] = param_1[0xc] - param_4;
        param_1[0x4a] = param_1[0x4a] - param_4;
      }
    }
  }
  return;
}
