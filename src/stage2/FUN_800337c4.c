/* FUN_800337c4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800337c4  body 0x800337c4..0x800339db  size 536 B
 * body sha256 c200073af8efeaf6de12447bf96b70392be962d9143fb3dc00551cacdb4d2a6d
 * provider record sha256 8e8f541b5969f49d02d57325a7eeb6027cb16cca2a2379c3009d599e6dbbe53e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800337c4(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  undefined2 *puVar8;
  undefined4 *puVar9;
  undefined *puVar10;
  
  func_0x80004cfc(0x1ec2,&DAT_801386a0,1,&DAT_800b86ac);
  DAT_800eb974 = &DAT_801386b8;
  uVar7 = (uint)(_DAT_801386a4 * _DAT_801386a8) >> 1;
  iVar4 = _DAT_801386ac * _DAT_801386b0 * 2;
  DAT_800eb960 = _DAT_801386a0;
  DAT_800eb964 = _DAT_801386a4;
  DAT_800eb968 = _DAT_801386a8;
  DAT_800eb96c = _DAT_801386ac;
  DAT_800eb970 = _DAT_801386b0;
  iVar6 = uVar7 + iVar4;
  while (iVar6 + -1 != -1) {
    *(undefined1 *)(iVar6 + -0x7fec794a) = *(undefined1 *)(iVar6 + -0x7fec794e);
    iVar6 = iVar6 + -1;
  }
  puVar5 = DAT_800eb974 + uVar7;
  puVar2 = (undefined1 *)((uint)(puVar5 + 7) & 0xfffffff8);
  DAT_800eb978 = puVar2;
  if ((puVar5 != puVar2) && (iVar6 = iVar4 + -1, iVar4 != 0)) {
    do {
      iVar4 = iVar6 + -1;
      puVar2[iVar6 + -1] = puVar5[iVar6 + -1];
      iVar6 = iVar4;
    } while (iVar4 != -1);
  }
  puVar10 = &UNK_800dfc14;
  iVar6 = 0x32;
  puVar8 = (undefined2 *)&DAT_80137a42;
  puVar9 = &DAT_800dfc2c;
  do {
    puVar3 = puVar10 + 0x40;
    *(undefined1 *)((int)puVar9 + -10) = 0;
    *puVar9 = 0x80808000;
    puVar8[-0x15] = (DAT_800eb964._2_2_ + -1) * 0x40;
    sVar1 = DAT_800eb968._2_2_;
    puVar8[-0xd] = 0;
    puVar8[-0x14] = (sVar1 + -1) * 0x40;
    sVar1 = DAT_800eb968._2_2_;
    puVar10 = puVar10 + 0x68;
    puVar8[-5] = 0;
    puVar8[-4] = 0;
    puVar8[-0xc] = (sVar1 + -1) * 0x40;
    sVar1 = DAT_800eb964._2_2_;
    iVar6 = iVar6 + -1;
    puVar8[4] = 0;
    puVar8[-0x18] = 0;
    puVar8[-0x10] = 0;
    puVar8[-8] = 0;
    *puVar8 = 0;
    puVar8[3] = (sVar1 + -1) * 0x40;
    FUN_80082474(puVar3,puVar9,0x28);
    puVar8 = puVar8 + 0x20;
    puVar9 = puVar9 + 0x1a;
  } while (iVar6 != 0);
  return;
}
