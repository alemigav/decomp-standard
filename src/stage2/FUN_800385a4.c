/* FUN_800385a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800385a4  body 0x800385a4..0x80038a1f  size 1148 B
 * body sha256 7ea139c8b17a88fa896d3ccd351d52d06abaac4987eb382807c09c6532f16a2a
 * provider record sha256 a1549a6d15393634f0d8de3aa70e72e744573b2ae05c66d53131835e745bd5a7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800385a4(uint param_1,uint param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  short sVar4;
  undefined4 uVar2;
  undefined2 uVar5;
  int iVar3;
  undefined4 *puVar6;
  undefined4 *puVar7;
  ushort *puVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  short *psVar13;
  int iVar14;
  short *psVar15;
  uint uVar16;
  
  iVar12 = (param_1 >> 0x18) * 4;
  iVar14 = *(int *)(&DAT_800ebca8 + iVar12);
  uVar16 = param_1 >> 0x10 & 0xff;
  iVar1 = FUN_800844cc((int)*(short *)((param_1 >> 0x10 & 7) * 2 + iVar14));
  psVar15 = (short *)(iVar14 + ((iVar1 << 0x10) >> 0xe));
  iVar14 = 0x60;
  sVar4 = FUN_800844cc((int)*psVar15);
  psVar13 = *(short **)(&DAT_800ebba8 + iVar12);
  iVar1 = (int)sVar4;
  iVar12 = FUN_800844cc((int)*psVar13);
  puVar6 = (undefined4 *)&DAT_800eebac;
  while (iVar14 = iVar14 + -1, *(short *)(puVar6 + 6) != 0) {
    puVar6 = puVar6 + -0x1f;
    if (iVar14 == 0) {
      return -1;
    }
  }
  *(undefined1 *)((int)puVar6 + 0x1a) = 0;
  *(undefined1 *)((int)puVar6 + 0x1b) = 0;
  *(undefined2 *)(puVar6 + 6) = 0xa003;
  uVar2 = FUN_800844e4((param_1 >> 0x18) + (param_2 & 0xff) * 0x100 + uVar16 * 0x10000);
  puVar6[7] = uVar2;
  uVar5 = FUN_800844cc(*(undefined1 *)(psVar13 + 5));
  *(undefined2 *)(puVar6 + 8) = uVar5;
  *(short *)((int)puVar6 + 0x22) = (short)(param_2 >> 0x10);
  puVar6[9] = 0;
  iVar3 = FUN_800844cc((int)psVar13[3]);
  uVar2 = FUN_800844e4(iVar3 << 0x10);
  puVar6[10] = uVar2;
  if (param_4 == (undefined4 *)0x0) {
    puVar6[0xb] = 0;
    puVar6[0xc] = 0;
  }
  else {
    puVar6[0xb] = *param_4;
    puVar6[0xc] = param_4[1];
  }
  sVar4 = psVar13[2];
  puVar6[0x10] = 0x100;
  puVar6[0xd] = 0;
  *(undefined2 *)(puVar6 + 0xe) = 0;
  *(short *)((int)puVar6 + 0x3a) = (short)param_1;
  puVar6[0xf] = 0;
  puVar6[0x11] = 0;
  puVar6[0x12] = 0;
  *(short *)((int)puVar6 + 0x32) = sVar4 + (short)(uVar16 >> 3) * 0x40;
  uVar11 = param_3[1];
  uVar2 = param_3[2];
  uVar10 = param_3[3];
  puVar6[0x13] = *param_3;
  puVar6[0x14] = uVar11;
  puVar6[0x15] = uVar2;
  puVar6[0x16] = uVar10;
  uVar11 = param_3[5];
  uVar2 = param_3[6];
  uVar10 = param_3[7];
  puVar6[0x17] = param_3[4];
  puVar6[0x18] = uVar11;
  puVar6[0x19] = uVar2;
  puVar6[0x1a] = uVar10;
  puVar6[0x1b] = param_3;
  puVar6[0x1c] = psVar13 + 4;
  puVar6[0x1d] = psVar13 + ((iVar12 << 0x10) >> 0xe) + 4;
  puVar6[0x1e] = psVar15 + 4;
  *puVar6 = *(undefined4 *)(psVar15 + 4);
  uVar5 = FUN_800844cc((int)*(short *)(puVar6[0x1e] + 4));
  *(undefined2 *)(puVar6 + 1) = uVar5;
  uVar5 = FUN_800844cc((int)*(short *)(puVar6[0x1e] + 6));
  *(undefined2 *)((int)puVar6 + 6) = uVar5;
  puVar6[2] = *(undefined4 *)(puVar6[0x1e] + 8);
  uVar5 = FUN_800844cc((int)*(short *)(puVar6[0x1e] + 0xc));
  *(undefined2 *)(puVar6 + 3) = uVar5;
  uVar5 = FUN_800844cc((int)*(short *)(puVar6[0x1e] + 0xe));
  *(undefined2 *)((int)puVar6 + 0xe) = uVar5;
  uVar5 = FUN_800844cc((int)*(short *)(puVar6[0x1e] + 0x10));
  *(undefined2 *)(puVar6 + 4) = uVar5;
  uVar5 = FUN_800844cc((int)*(short *)(puVar6[0x1e] + 0x12));
  *(undefined2 *)((int)puVar6 + 0x12) = uVar5;
  uVar5 = FUN_800844cc((int)*(short *)(puVar6[0x1e] + 0x14));
  *(undefined2 *)(puVar6 + 5) = uVar5;
  uVar5 = FUN_800844cc((int)*(short *)(puVar6[0x1e] + 0x16));
  *(undefined2 *)((int)puVar6 + 0x16) = uVar5;
  iVar12 = iVar14;
  while( true ) {
    iVar1 = iVar1 + -1;
    if (iVar1 == 0) {
      return iVar14;
    }
    if (iVar12 == 0) break;
    puVar6 = (undefined4 *)(&UNK_800ebd2c + iVar12 * 0x7c);
    while (iVar12 = iVar12 + -1, *(short *)(puVar6 + 6) != 0) {
      puVar6 = puVar6 + -0x1f;
      if (iVar12 == 0) {
        return -2;
      }
    }
    puVar9 = puVar6 + 6;
    puVar7 = (undefined4 *)(&DAT_800ebdc0 + iVar14 * 0x3e);
    *(undefined2 *)(puVar6 + 6) = 0xa003;
    *(undefined1 *)((int)puVar6 + 0x1b) = 0;
    do {
      uVar11 = puVar7[1];
      uVar2 = puVar7[2];
      uVar10 = puVar7[3];
      *puVar9 = *puVar7;
      puVar9[1] = uVar11;
      puVar9[2] = uVar2;
      puVar9[3] = uVar10;
      puVar7 = puVar7 + 4;
      puVar9 = puVar9 + 4;
    } while (puVar7 != (undefined4 *)(&UNK_800ebe20 + iVar14 * 0x7c));
    *puVar9 = *puVar7;
    *(char *)((int)puVar6 + 0x1a) = (char)iVar14;
    puVar8 = (ushort *)(psVar15 + 2);
    iVar3 = iVar1;
    do {
      iVar3 = iVar3 + -1;
      puVar8 = puVar8 + (uint)*puVar8 * 0xc + 2;
    } while (iVar3 != 0);
    puVar6[0x1e] = puVar8 + 2;
    *puVar6 = *(undefined4 *)(puVar8 + 2);
    uVar5 = FUN_800844cc((int)(short)puVar8[4]);
    *(undefined2 *)(puVar6 + 1) = uVar5;
    uVar5 = FUN_800844cc((int)*(short *)(puVar6[0x1e] + 6));
    *(undefined2 *)((int)puVar6 + 6) = uVar5;
    puVar6[2] = *(undefined4 *)(puVar6[0x1e] + 8);
    uVar5 = FUN_800844cc((int)*(short *)(puVar6[0x1e] + 0xc));
    *(undefined2 *)(puVar6 + 3) = uVar5;
    uVar5 = FUN_800844cc((int)*(short *)(puVar6[0x1e] + 0xe));
    *(undefined2 *)((int)puVar6 + 0xe) = uVar5;
    uVar5 = FUN_800844cc((int)*(short *)(puVar6[0x1e] + 0x10));
    *(undefined2 *)(puVar6 + 4) = uVar5;
    uVar5 = FUN_800844cc((int)*(short *)(puVar6[0x1e] + 0x12));
    *(undefined2 *)((int)puVar6 + 0x12) = uVar5;
    uVar5 = FUN_800844cc((int)*(short *)(puVar6[0x1e] + 0x14));
    *(undefined2 *)(puVar6 + 5) = uVar5;
    uVar5 = FUN_800844cc((int)*(short *)(puVar6[0x1e] + 0x16));
    *(undefined2 *)((int)puVar6 + 0x16) = uVar5;
  }
  return -2;
}
