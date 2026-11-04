/* FUN_8005f5a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005f5a0  body 0x8005f5a0..0x8005f807  size 616 B
 * body sha256 d30b57f4a63ec1f07bbca5f9b9731b39592e3dda7372d69f5d095fceb796844a
 * provider record sha256 3504a7db3033888d38aba9a15b694e82fc3d193d1a32f2287b9f0cfc84e5107d
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005f5a0(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint local_38;
  undefined4 local_34;
  uint local_30;
  
  iVar6 = 2;
  uVar4 = 0;
  uVar8 = (uint)DAT_800e1126;
  iVar12 = 0;
  if (uVar8 != 0) {
    if ((*DAT_800e13f0 & 1) == 0) {
      uVar9 = uVar8 - 1;
      while (iVar6 = iVar6 + 1, uVar9 != 0) {
        if ((*(uint *)(&DAT_800e13e8)[iVar6] & 1) == 0) {
          uVar9 = uVar9 - 1;
        }
        else {
          uVar4 = uVar4 + 1;
          if (*(uint **)(param_1 + 0x250) == (uint *)(&DAT_800e13e8)[iVar6]) break;
LAB_8005f624:
          uVar9 = uVar9 - 1;
        }
      }
    }
    else {
      uVar4 = 1;
      uVar9 = uVar8;
      if (*(uint **)(param_1 + 0x250) != DAT_800e13f0) goto LAB_8005f624;
    }
    iVar7 = iVar6 + 1;
    if (uVar8 == uVar4) {
      iVar7 = 2;
    }
    iVar10 = 0;
    do {
      puVar5 = (uint *)(&DAT_800e13e8)[iVar7];
      iVar11 = iVar10;
      if ((*puVar5 & 1) != 0) {
        local_38 = puVar5[0x48];
        local_34 = *(undefined4 *)((uint)*(byte *)(param_1 + 0x25d) * 0x178 + puVar5[0x8d] + 0x50);
        local_30 = puVar5[0x4a];
        bVar1 = false;
        if (-1 < *(short *)((int)puVar5 + 0x1f2)) {
          iVar2 = FUN_80032e74(param_1,puVar5[10],puVar5[0xc],0x400);
          if (iVar2 == 0) {
            iVar2 = FUN_8006ab40(*(int *)(param_1 + 0x234) +
                                 (uint)*(byte *)(param_1 + 0x25d) * 0x178 + 0x4c,&local_38,0x80);
            bVar1 = iVar2 == 0;
          }
        }
        if ((bVar1) && ((*(ushort *)((int)puVar5 + 0x1aa) & 0xc000) == 0)) {
          iVar11 = iVar7;
          iVar12 = iVar10;
        }
      }
      puVar3 = &DAT_800e13e8 + iVar7;
      iVar7 = iVar7 + 1;
      if (puVar3 == DAT_800df93c) {
        iVar7 = 2;
      }
      uVar8 = uVar8 - 1;
      iVar10 = iVar11;
    } while (uVar8 != 0);
    if (iVar11 != 0) {
      if ((iVar6 == iVar11) && (iVar12 != 0)) {
        iVar11 = iVar12;
      }
      *(undefined4 *)(param_1 + 0x250) = (&DAT_800e13e8)[iVar11];
      return;
    }
  }
  *(int *)(param_1 + 0x250) = param_1;
  return;
}
