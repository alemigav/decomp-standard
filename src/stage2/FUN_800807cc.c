/* FUN_800807cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800807cc  body 0x800807cc..0x80080af3  size 808 B
 * body sha256 eb67abd5400104d03dcb54a2d84de844e0bb2b47018cb771db4ffa75b99f683f
 * provider record sha256 3b2a0b43f97569b008fa0aa833e177c9021b2d30749623cf6db1213ebcc780e3
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800807cc(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *local_38;
  uint *local_34;
  uint *local_30;
  
  uVar9 = 0x7fffffff;
  uVar8 = 0x7fffffff;
  FUN_80082200(&local_38,0,0xc);
  DAT_8011b54c = (uint *)0x0;
  DAT_8011b550 = (uint *)0x0;
  DAT_8011b554 = (uint *)0x0;
  if (DAT_800e1126 != '\0') {
    puVar5 = &DAT_800e13f0;
    uVar6 = 0x7fffffff;
    do {
      puVar4 = (uint *)*puVar5;
      uVar7 = uVar6;
      if (((*puVar4 & 1) != 0) && ((*(ushort *)((int)puVar4 + 0x1aa) & 0xc000) == 0)) {
        iVar1 = puVar4[10] - *(int *)(param_1 + 0x28);
        iVar2 = puVar4[0xc] - *(int *)(param_1 + 0x30);
        uVar3 = FUN_80040bb4(iVar1 * iVar1 + iVar2 * iVar2);
        puVar4[0xa4] = uVar3;
        iVar1 = FUN_8006ab40(*(int *)(param_1 + 0x234) + (uint)*(byte *)(param_1 + 0x25d) * 0x178 +
                             0x4c,puVar4[0x8d] + (uint)*(byte *)((int)puVar4 + 0x25d) * 0x178 + 0x4c
                             ,0x2080);
        if ((iVar1 == 0) && (-1 < *(short *)((int)puVar4 + 0x1f2))) {
          if (uVar3 < uVar9) {
            local_30 = local_34;
            local_34 = local_38;
            uVar7 = uVar9;
            uVar8 = uVar6;
            uVar9 = uVar3;
            local_38 = puVar4;
          }
          else if (uVar3 < uVar6) {
            local_30 = local_34;
            uVar7 = uVar3;
            uVar8 = uVar6;
            local_34 = puVar4;
          }
          else if (uVar3 < uVar8) {
            uVar8 = uVar3;
            local_30 = puVar4;
          }
        }
      }
      puVar5 = puVar5 + 1;
      uVar6 = uVar7;
    } while (puVar5 != DAT_800df93c);
    DAT_8011b560 = (undefined2)uVar9;
    DAT_8011b562 = (undefined2)uVar7;
    DAT_8011b564 = (undefined2)uVar8;
    DAT_8011b54c = local_38;
    DAT_8011b550 = local_34;
    DAT_8011b554 = local_30;
    if (local_38 != (uint *)0x0) {
      DAT_8011b558 = FUN_80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                                  (int)*(short *)((int)local_38 + 0x2a),
                                  (int)*(short *)((int)local_38 + 0x32));
      local_38[0xa4] = local_38[0xa4] | 0x40000000;
      *(ushort *)(local_38 + 0xa5) = DAT_8011b558 + 0x800U & 0xfff;
    }
    if (local_34 != (uint *)0x0) {
      DAT_8011b55a = FUN_80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                                  (int)*(short *)((int)local_34 + 0x2a),
                                  (int)*(short *)((int)local_34 + 0x32));
      local_34[0xa4] = local_34[0xa4] | 0x80000000;
      *(ushort *)(local_34 + 0xa5) = DAT_8011b55a + 0x800U & 0xfff;
    }
    if (local_30 != (uint *)0x0) {
      DAT_8011b55c = FUN_80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                                  (int)*(short *)((int)local_30 + 0x2a),
                                  (int)*(short *)((int)local_30 + 0x32));
      local_30[0xa4] = local_30[0xa4] | 0xc0000000;
      *(ushort *)(local_30 + 0xa5) = DAT_8011b55c + 0x800U & 0xfff;
    }
  }
  return;
}
