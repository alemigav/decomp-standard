/* FUN_8000add0
 * image   boot (boot), base 0x80000480
 * address 0x8000add0  body 0x8000add0..0x8000b21b  size 1100 B
 * body sha256 b733d422e4c3367a6c5d5f4b6599f8825baba538b80f387c465479f7ff6c7aa0
 * provider record sha256 684cadd7ea3bec2a73681ec65d77d0f4e567d978d01cba0d517836c156413d23
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8000af50) */

int FUN_8000add0(uint *param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  ushort *puVar6;
  ushort *puVar7;
  byte *pbVar8;
  uint uVar9;
  int iVar10;
  ushort uVar11;
  byte bVar12;
  int iVar13;
  ushort local_488 [128];
  ushort local_388 [128];
  int local_288;
  short local_284;
  ushort local_282;
  undefined1 local_280;
  undefined2 local_27e;
  undefined2 local_268;
  undefined1 auStack_248 [544];
  
  iVar13 = 0;
  iVar3 = FUN_8000a2d0();
  if (iVar3 == 2) {
    iVar3 = FUN_8000a0f0(param_1);
  }
  if ((iVar3 == 0) && (iVar3 = FUN_8000b21c(param_1,auStack_248), iVar3 == 0)) {
    iVar10 = 0;
    if (0 < (int)param_1[0x14]) {
      do {
        iVar3 = FUN_800087a0(param_1[1],param_1[2],param_1[0x17] + iVar10 & 0xffff,&local_288);
        if (iVar3 != 0) {
          return iVar3;
        }
        if (local_284 == 0) {
          if (local_288 != 0) goto LAB_8000af80;
        }
        else {
          if (local_288 != 0) {
            iVar3 = 0;
            uVar4 = param_1[0x18];
            uVar11 = 0xff;
            uVar2 = local_282;
            while( true ) {
              uVar9 = (uint)uVar2;
              if ((int)uVar9 < (int)uVar4) break;
              if (((ushort)*(byte *)(param_1 + 0x19) <= uVar2 >> 8) ||
                 ((uVar2 & 0xff) == 0 || 0x7f < (uVar9 & 0xff))) break;
              if (uVar11 != uVar2 >> 8) {
                iVar5 = FUN_8000a394(param_1,local_388,0);
                uVar11 = uVar2 >> 8;
                if (iVar5 != 0 && iVar5 != 3) {
                  return iVar5;
                }
              }
              iVar5 = FUN_8000b374(param_1,uVar9 << 0x10,auStack_248);
              if (iVar5 != iVar3) goto LAB_8000af80;
              uVar2 = local_388[uVar9 & 0xff];
              uVar4 = param_1[0x18];
              iVar3 = 1;
            }
            if (uVar9 == 1) goto LAB_8000afe0;
          }
LAB_8000af80:
          local_284 = 0;
          local_288 = 0;
          local_282 = 0;
          local_280 = 0;
          local_27e = 0;
          if (*(char *)((int)param_1 + 0x65) != '\0') {
            *(undefined1 *)((int)param_1 + 0x65) = 0;
            iVar3 = FUN_8000a66c(param_1);
            if (iVar3 != 0) {
              return iVar3;
            }
          }
          iVar3 = FUN_80008b70(param_1[1],param_1[2],param_1[0x17] + iVar10 & 0xffff,&local_288,0);
          iVar13 = iVar13 + 1;
          if (iVar3 != 0) goto LAB_8000b1f0;
        }
LAB_8000afe0:
        iVar10 = iVar10 + 1;
      } while (iVar10 < (int)param_1[0x14]);
    }
    iVar3 = 0;
    if (0 < (int)param_1[0x14]) {
      puVar7 = &local_268;
      do {
        iVar10 = FUN_800087a0(param_1[1],param_1[2],param_1[0x17] + iVar3 & 0xffff,&local_288);
        if (iVar10 != 0) {
          return iVar10;
        }
        if (local_284 == 0) {
          *puVar7 = 0;
        }
        else if (local_288 == 0) {
          *puVar7 = 0;
        }
        else if (local_282 < *(ushort *)((int)param_1 + 0x62)) {
          *puVar7 = 0;
        }
        else {
          *puVar7 = local_282;
        }
        iVar3 = iVar3 + 1;
        puVar7 = puVar7 + 1;
      } while (iVar3 < (int)param_1[0x14]);
    }
    bVar12 = 0;
    if (*(char *)(param_1 + 0x19) != '\0') {
      do {
        iVar3 = FUN_8000a394(param_1,local_388,0,bVar12);
        if (iVar3 != 0 && iVar3 != 3) {
          return iVar3;
        }
        uVar4 = 1;
        if (bVar12 == 0) {
          uVar4 = param_1[0x18];
        }
        iVar3 = 0;
        if (0 < (int)uVar4) {
          puVar7 = local_388;
          puVar6 = local_488;
          do {
            uVar2 = *puVar7;
            puVar7 = puVar7 + 1;
            iVar3 = iVar3 + 1;
            *puVar6 = uVar2;
            puVar6 = puVar6 + 1;
          } while (iVar3 < (int)uVar4);
        }
        if (iVar3 < 0x80) {
          puVar7 = local_488 + iVar3;
          do {
            *puVar7 = 3;
            iVar3 = iVar3 + 1;
            puVar7 = puVar7 + 1;
          } while (iVar3 < 0x80);
        }
        iVar3 = 0;
        if (0 < (int)param_1[0x14]) {
          iVar10 = 0;
          pbVar8 = (byte *)&local_268;
          do {
            bVar1 = *pbVar8;
            while ((bVar1 == bVar12 &&
                   (puVar7 = (ushort *)((int)&local_268 + iVar10),
                   *(ushort *)((int)param_1 + 0x62) <= *puVar7))) {
              bVar1 = auStack_248[iVar10 + -0x1f];
              local_488[bVar1] = local_388[bVar1];
              *(ushort *)(auStack_248 + iVar10 + -0x20) = local_388[bVar1];
              bVar1 = *(byte *)puVar7;
            }
            iVar10 = iVar10 + 2;
            iVar3 = iVar3 + 1;
            pbVar8 = pbVar8 + 2;
          } while (iVar3 < (int)param_1[0x14]);
        }
        iVar3 = FUN_8000a394(param_1,local_488,1,bVar12);
        bVar12 = bVar12 + 1;
        if (iVar3 != 0) goto LAB_8000b1f0;
      } while (bVar12 < *(byte *)(param_1 + 0x19));
    }
    if (iVar13 == 0) {
      uVar4 = *param_1 & 0xfffffffd;
    }
    else {
      uVar4 = *param_1 | 2;
    }
    *param_1 = uVar4;
    iVar3 = 0;
  }
LAB_8000b1f0:
  return iVar3;
}
