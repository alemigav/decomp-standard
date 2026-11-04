/* FUN_80039738
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80039738  body 0x80039738..0x8003994b  size 532 B
 * body sha256 5e1f423dbd47a7d909bbae27eae7aa5118cb4b5f812d86864e121c0a2b93a573
 * provider record sha256 d60734d7e8e172fac38fcde7aaea9ad9b2099d4dade74401eadaf291bde7c562
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80039738(void)

{
  undefined2 *puVar1;
  short *psVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  short local_28;
  short local_26;
  short local_24;
  undefined1 auStack_20 [2];
  short local_1e;
  short local_1a;
  short local_16;
  
  iVar4 = DAT_800ebb94;
  if ((*(ushort *)(DAT_800ebb94 + 0x18) & 0x800) != 0) {
    puVar3 = *(undefined4 **)(DAT_800ebb94 + 0x6c);
    uVar5 = puVar3[1];
    uVar6 = puVar3[2];
    uVar7 = puVar3[3];
    *(undefined4 *)(DAT_800ebb94 + 0x4c) = *puVar3;
    *(undefined4 *)(iVar4 + 0x50) = uVar5;
    *(undefined4 *)(iVar4 + 0x54) = uVar6;
    *(undefined4 *)(iVar4 + 0x58) = uVar7;
    uVar5 = puVar3[5];
    uVar6 = puVar3[6];
    uVar7 = puVar3[7];
    *(undefined4 *)(iVar4 + 0x5c) = puVar3[4];
    *(undefined4 *)(iVar4 + 0x60) = uVar5;
    *(undefined4 *)(iVar4 + 100) = uVar6;
    *(undefined4 *)(iVar4 + 0x68) = uVar7;
  }
  iVar4 = DAT_800ebb94;
  local_48 = 0x10000000;
  local_44 = 0;
  local_40 = 0x10000000;
  local_3c = 0;
  local_38 = 0x10000000;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  puVar1 = (undefined2 *)(DAT_800ebb94 + 0x38);
  *(undefined4 *)(DAT_800ebb94 + 0x3c) = *(undefined4 *)(DAT_800ebb94 + 0x34);
  *(undefined2 *)(iVar4 + 0x40) = *puVar1;
  if ((*(ushort *)(iVar4 + 0x18) & 0x400) == 0) {
    FUN_80041454((int)*(short *)(iVar4 + 0x22),&local_48);
    FUN_80042824(&local_48,DAT_800ebb94 + 0x24,auStack_20);
    iVar4 = DAT_800ebb94;
    *(short *)(DAT_800ebb94 + 0x34) = local_1e;
    *(short *)(iVar4 + 0x36) = local_1a;
    *(short *)(iVar4 + 0x38) = local_16;
    FUN_80042824(iVar4 + 0x4c,iVar4 + 0x2c,auStack_20);
    iVar4 = DAT_800ebb94;
    psVar2 = (short *)(DAT_800ebb94 + 0x66);
    *(short *)(DAT_800ebb94 + 0x34) =
         *(short *)(DAT_800ebb94 + 0x34) + *(short *)(DAT_800ebb94 + 0x62) + local_1e;
    *(short *)(iVar4 + 0x36) = *(short *)(iVar4 + 0x36) + *psVar2 + local_1a;
    local_16 = *(short *)(iVar4 + 0x38) + *(short *)(iVar4 + 0x6a) + local_16;
  }
  else {
    FUN_80042824(&local_48,iVar4 + 0x24,auStack_20);
    local_28 = local_1e + *(short *)(DAT_800ebb94 + 0x2c);
    local_26 = local_1a + *(short *)(DAT_800ebb94 + 0x2e);
    local_24 = local_16 + *(short *)(DAT_800ebb94 + 0x30);
    FUN_80042824(DAT_800ebb94 + 0x4c,&local_28,auStack_20);
    iVar4 = DAT_800ebb94;
    *(short *)(DAT_800ebb94 + 0x34) = *(short *)(DAT_800ebb94 + 0x62) + local_1e;
    *(short *)(iVar4 + 0x36) = *(short *)(iVar4 + 0x66) + local_1a;
    local_16 = *(short *)(iVar4 + 0x6a) + local_16;
  }
  *(short *)(iVar4 + 0x38) = local_16;
  return;
}
