/* FUN_80180020
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x80180020  body 0x80180020..0x801801e3  size 452 B
 * body sha256 4980a11e9bb7a2485f6e5aee4e72be1403e33dddf18999e04134f63594cfc0b6
 * provider record sha256 73893b767fd137c63f0a58096a92232099679e1515a39fdfc73e6f75e79d6787
 * callees 5 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80180020(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  
  DAT_80180adc = 6;
  DAT_80180af0 = param_1 >> 4;
  DAT_80180ae0 = &DAT_80180af0;
  DAT_80180af4 = &DAT_80180ad8;
  DAT_80180d38 = &DAT_80181f94;
  if (DAT_80180af0 != 0) {
    func_0x800879a0(&DAT_80180adc);
    return 1;
  }
  if (_DAT_800c52d0 == 0) {
    uVar1 = (uint)(_DAT_800c52d4 != 0);
  }
  else {
    uVar1 = func_0x8009bf04(&DAT_80181fc0);
  }
  if (uVar1 != 0) {
    if ((int)uVar1 < 1) {
      if (-4 < (int)uVar1) {
        DAT_80180ad8 = 10;
      }
      goto LAB_801801a0;
    }
    if (uVar1 != 1) goto LAB_801801a0;
    _DAT_800c52d4 = 0;
  }
  puVar9 = &DAT_80180b38;
  puVar6 = &DAT_80181fcc;
  puVar8 = &DAT_80181fc8;
  puVar7 = &DAT_80181fc0;
  for (iVar10 = 0; iVar10 < 0xf; iVar10 = iVar10 + 1) {
    iVar2 = func_0x8009c28c(puVar6,0x820);
    if (iVar2 != *(int *)(puVar7 + 8)) {
      func_0x80006650(puVar8,0x824);
    }
    uVar3 = puVar6[1];
    uVar4 = puVar6[2];
    uVar5 = puVar6[3];
    *puVar9 = *puVar6;
    puVar9[1] = uVar3;
    puVar9[2] = uVar4;
    puVar9[3] = uVar5;
    uVar3 = puVar6[5];
    uVar4 = puVar6[6];
    uVar5 = puVar6[7];
    puVar9[4] = puVar6[4];
    puVar9[5] = uVar3;
    puVar9[6] = uVar4;
    puVar9[7] = uVar5;
    puVar9 = puVar9 + 8;
    puVar6 = puVar6 + 0x209;
    puVar8 = puVar8 + 0x209;
    puVar7 = puVar7 + 0x824;
  }
  DAT_80180ad8 = 0;
LAB_801801a0:
  osSendMesg(DAT_80180d38,0,0);
  return 1;
}
