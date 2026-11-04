/* FUN_8005bc04
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005bc04  body 0x8005bc04..0x8005bdf3  size 496 B
 * body sha256 46b26f37b282e8d56593badcdd755edfa0d9a1ebfbcf39112c5073c74a2c3590
 * provider record sha256 9cd778cb283f09264f0c3327c686154960a5ff9da80bcc781df1a987246a3d8b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8005bc04(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  uint local_38;
  undefined4 local_34;
  uint local_30;
  
  uVar10 = 0x7fffffff;
  puVar9 = (uint *)0x0;
  if (DAT_800e1126 == '\0') {
LAB_8005bdb4:
    *(int *)(param_1 + 0x250) = param_1;
    uVar4 = 0;
  }
  else {
    uVar7 = 0x7fffffff;
    if (param_2 != 0) {
      uVar7 = param_2;
    }
    puVar6 = &DAT_800e13f0;
    puVar11 = (uint *)0x0;
    do {
      puVar5 = (uint *)*puVar6;
      uVar8 = uVar7;
      puVar12 = puVar11;
      if (((*puVar5 & 1) != 0) && ((*(ushort *)((int)puVar5 + 0x1aa) & 0xc000) == 0)) {
        iVar1 = *(int *)(param_1 + 0x28) - puVar5[10];
        iVar2 = *(int *)(param_1 + 0x30) - puVar5[0xc];
        uVar3 = FUN_80040bb4(iVar1 * iVar1 + iVar2 * iVar2);
        local_38 = puVar5[0x48];
        local_34 = *(undefined4 *)((uint)*(byte *)(param_1 + 0x25d) * 0x178 + puVar5[0x8d] + 0x50);
        local_30 = puVar5[0x4a];
        if ((-1 < *(short *)((int)puVar5 + 0x1f2)) &&
           (iVar1 = FUN_8006ab40(*(int *)(param_1 + 0x234) +
                                 (uint)*(byte *)(param_1 + 0x25d) * 0x178 + 0x4c,&local_38,0x80,1),
           iVar1 == 0)) {
          if ((*(ushort *)((int)puVar5 + 0x1aa) & 0x2000) == 0) {
            uVar8 = uVar3;
            puVar12 = puVar5;
            if (uVar7 <= uVar3) {
              uVar8 = uVar7;
              puVar12 = puVar11;
            }
          }
          else if (uVar3 < uVar10) {
            puVar9 = puVar5;
            uVar10 = uVar3;
          }
        }
      }
      puVar6 = puVar6 + 1;
      uVar7 = uVar8;
      puVar11 = puVar12;
    } while (puVar6 != DAT_800df93c);
    if (puVar12 == (uint *)0x0) {
      if (puVar9 == (uint *)0x0) goto LAB_8005bdb4;
      *(uint **)(param_1 + 0x250) = puVar9;
    }
    else {
      *(uint **)(param_1 + 0x250) = puVar12;
    }
    uVar4 = 1;
  }
  return uVar4;
}
