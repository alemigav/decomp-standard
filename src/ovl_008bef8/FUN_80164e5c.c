/* FUN_80164e5c
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80164e5c  body 0x80164e5c..0x8016500f  size 436 B
 * body sha256 0adb427bb50d8289cde5ebeb86444e8478f909d826e1d11a64a41f0a3ec709c0
 * provider record sha256 40e80d63b2f2e60a0ce5f5e14a804bebc8873469e9661698bf02cb556babd7c9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164e5c(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 local_90;
  ushort uStack_8a;
  undefined4 local_88;
  int local_84 [3];
  undefined4 auStack_78 [22];
  
  puVar1 = &DAT_80165fbc;
  puVar2 = &local_90;
  do {
    puVar4 = puVar2;
    puVar3 = puVar1;
    uVar5 = puVar3[1];
    uVar6 = puVar3[2];
    uVar7 = puVar3[3];
    *puVar4 = *puVar3;
    puVar4[1] = uVar5;
    puVar4[2] = uVar6;
    puVar4[3] = uVar7;
    puVar1 = puVar3 + 4;
    puVar2 = puVar4 + 4;
  } while (puVar3 + 4 != (undefined4 *)&UNK_8016601c);
  iVar8 = param_1 * 0x24;
  iVar10 = (int)local_84 + (param_1 * 9 + -3) * 4;
  uVar5 = puVar3[5];
  uVar6 = puVar3[6];
  puVar4[4] = 0xff380258;
  puVar4[5] = uVar5;
  puVar4[6] = uVar6;
  iVar9 = _DAT_800e1364 + *(int *)((int)local_84 + (param_1 * 9 + -1) * 4) * 0x178;
  func_0x80037780(0x11800,(int)*(short *)((int)local_84 + iVar8 + 0xfffffffaU),iVar9 + 0x38,iVar10);
  iVar11 = (int)local_84 + param_1 * 0x24;
  func_0x80037780(0x21000,(int)*(short *)((int)local_84 + iVar8 + 0xfffffffaU),iVar9 + 0x1b0,iVar11)
  ;
  iVar12 = (int)auStack_78 + param_1 * 0x24;
  func_0x80037780(0x11800,(int)*(short *)((int)local_84 + iVar8 + 0xfffffffaU),iVar9 + 0x328,iVar12)
  ;
  func_0x80037780(0x22000,(int)((*(ushort *)((int)local_84 + iVar8 + 0xfffffffaU) + 0x400) * 0x10000
                               ) >> 0x10,iVar9 + 0x38,iVar10);
  func_0x80037780(0x1800,(int)((*(ushort *)((int)local_84 + iVar8 + 0xfffffffaU) + 0x400) * 0x10000)
                         >> 0x10,iVar9 + 0x1b0,iVar11);
  func_0x80037780(0x1000,(int)((*(ushort *)((int)local_84 + iVar8 + 0xfffffffaU) + 0x400) * 0x10000)
                         >> 0x10,iVar9 + 0x328,iVar12);
  return;
}
