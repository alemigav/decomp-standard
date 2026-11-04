/* FUN_8004dd50
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004dd50  body 0x8004dd50..0x8004e0ff  size 944 B
 * body sha256 c86ec36a56afee58d86a0651ba35de83674ddf5dd9fb56b98e0f8560a72527ab
 * provider record sha256 60bc28619482b8bd356b368ae1e3017fe002e846cdd9e48b4ae78a3a279f0bad
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8004dd50(uint *param_1,uint *param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  if (((*param_1 & 0x40) == 0) && ((*param_2 & 2) == 0)) {
    iVar6 = (uint)*(ushort *)((int)param_1 + 0x136) + (uint)*(ushort *)(param_2 + 0x4b);
    iVar5 = (uint)*(ushort *)((int)param_1 + 0x136) + (uint)*(ushort *)((int)param_2 + 0x12e);
    iVar8 = param_2[0x48] - param_1[0x48];
    iVar7 = param_2[0x4a] - param_1[0x4a];
    if (((uint)(iVar8 + iVar6) <= (uint)(iVar6 * 2)) && ((uint)(iVar7 + iVar5) <= (uint)(iVar5 * 2))
       ) {
      iVar4 = param_2[0x49] - param_1[0x49];
      iVar3 = (uint)*(ushort *)((int)param_1 + 0x13a) + (uint)*(ushort *)((int)param_2 + 0x13a);
      uVar9 = iVar3 * 2;
      if ((uint)(iVar4 + iVar3) < uVar9) {
        if (param_3 != 2) {
          *(char *)((int)param_1 + 10) = (char)((int)(param_2 + 0x1ffc79c2) * -0x2593f69b >> 3);
          *(undefined1 *)((int)param_2 + 0xd) = *(undefined1 *)(param_1 + 3);
          bVar1 = (uint)(((int)*(short *)(param_2 + 0xf) - (int)*(short *)(param_1 + 0xf)) + iVar3)
                  < uVar9;
          _DAT_80139bb0 = (uint)bVar1;
          if (!bVar1) {
            if (param_3 == 0) {
              if (iVar4 < 0) {
                uVar9 = (param_2[0x49] - (int)*(short *)(param_1 + 0x4d)) + 1 + iVar3;
              }
              else {
                uVar9 = (param_2[0x49] - (int)*(short *)(param_1 + 0x4d)) - iVar3;
              }
              param_1[0xb] = uVar9;
              param_1[0x49] = uVar9 + (int)*(short *)(param_1 + 0x4d);
            }
            else {
              if (iVar4 < 0) {
                iVar3 = -iVar3;
              }
              uVar9 = (param_1[0x49] - (int)*(short *)(param_2 + 0x4d)) + iVar3;
              param_2[0xb] = uVar9;
              param_2[0x49] = uVar9 + (int)*(short *)(param_2 + 0x4d);
            }
            return 1;
          }
          uVar9 = param_2[0x48];
          if ((uint)(iVar6 * 2) < (uVar9 - (int)*(short *)((int)param_1 + 0x3a)) + iVar6) {
            uVar2 = param_1[0x48];
            iVar6 = iVar6 + 1;
            iVar5 = uVar2 - (int)*(short *)((int)param_1 + 0x3a);
            if (param_3 == 0) {
              iVar7 = -iVar6;
              if (iVar5 < 0) {
                iVar7 = iVar6;
              }
              iVar6 = (uVar9 + iVar7) - uVar2;
              param_1[0x48] = param_1[0x48] + iVar6;
              param_1[10] = param_1[10] + iVar6;
            }
            else {
              if (iVar5 < 0) {
                iVar6 = -iVar6;
              }
              iVar6 = (uVar2 + iVar6) - uVar9;
              param_2[0x48] = param_2[0x48] + iVar6;
              param_2[10] = param_2[10] + iVar6;
            }
          }
          else {
            uVar2 = param_2[0x4a];
            iVar3 = iVar8 * iVar5;
            if ((uVar2 - (int)*(short *)((int)param_1 + 0x3e)) + iVar5 <= (uint)(iVar5 * 2)) {
              if (iVar3 < 0) {
                iVar3 = -iVar3;
              }
              iVar4 = iVar7 * iVar6;
              if (iVar4 < 0) {
                iVar4 = -iVar4;
              }
              if (iVar4 < iVar3) {
                iVar6 = iVar6 + 1;
                if (param_3 == 0) {
                  iVar5 = -iVar6;
                  if (iVar8 < 0) {
                    iVar5 = iVar6;
                  }
                  iVar6 = (uVar9 + iVar5) - param_1[0x48];
                  param_1[0x48] = param_1[0x48] + iVar6;
                  param_1[10] = param_1[10] + iVar6;
                  return 1;
                }
                if (iVar8 < 0) {
                  iVar6 = -iVar6;
                }
                iVar6 = (param_1[0x48] + iVar6) - uVar9;
                param_2[0x48] = param_2[0x48] + iVar6;
                param_2[10] = param_2[10] + iVar6;
                return 1;
              }
              iVar5 = iVar5 + 1;
              if (param_3 == 0) {
                if (-1 < iVar7) {
                  iVar5 = -iVar5;
                }
                iVar6 = (uVar2 + iVar5) - param_1[0x4a];
                param_1[0x4a] = param_1[0x4a] + iVar6;
                param_1[0xc] = param_1[0xc] + iVar6;
                return 1;
              }
              if (iVar7 < 0) {
                iVar5 = -iVar5;
              }
              iVar6 = (param_1[0x4a] + iVar5) - uVar2;
              param_2[0x4a] = param_2[0x4a] + iVar6;
              param_2[0xc] = param_2[0xc] + iVar6;
              return 1;
            }
            uVar9 = param_1[0x4a];
            iVar5 = iVar5 + 1;
            iVar6 = uVar9 - (int)*(short *)((int)param_1 + 0x3e);
            if (param_3 == 0) {
              iVar7 = -iVar5;
              if (iVar6 < 0) {
                iVar7 = iVar5;
              }
              iVar6 = (uVar2 + iVar7) - uVar9;
              param_1[0x4a] = param_1[0x4a] + iVar6;
              param_1[0xc] = param_1[0xc] + iVar6;
            }
            else {
              if (iVar6 < 0) {
                iVar5 = -iVar5;
              }
              iVar6 = (uVar9 + iVar5) - uVar2;
              param_2[0x4a] = param_2[0x4a] + iVar6;
              param_2[0xc] = param_2[0xc] + iVar6;
            }
          }
        }
        return 1;
      }
    }
  }
  return 0;
}
