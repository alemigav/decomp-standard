/* FUN_80037780
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80037780  body 0x80037780..0x80037c4f  size 1232 B
 * body sha256 75626cf355ec546c7d6b93415ddfe593cb573a1e487ff726636202e29e47ea40
 * provider record sha256 7708b3b90dac9e454ef143c3e1569c69e7a551756b23be9c41575154997e9d36
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_80037780(uint param_1,undefined2 param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  short sVar4;
  undefined4 uVar2;
  undefined2 uVar5;
  int iVar3;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  short *psVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  short *psVar15;
  uint uVar16;
  undefined2 uStackX_2;
  
  uVar12 = param_1 >> 0x18;
  if ((DAT_800e9012 & 0xc) == 0) {
    if (uVar12 == 0) {
      return DAT_800e9012 & 0xc;
    }
    if (uVar12 == 8) {
      return 8;
    }
    if (uVar12 == 9) {
      return 9;
    }
    if (uVar12 == 0x1f) {
      return 0x1f;
    }
    if (uVar12 == 0x26) {
      return 0x26;
    }
  }
  iVar14 = *(int *)(&DAT_800ebca8 + uVar12 * 4);
  uVar16 = param_1 >> 0x10 & 0xff;
  uVar13 = 0x60;
  iVar1 = FUN_800844cc((int)*(short *)((param_1 >> 0x10 & 7) * 2 + iVar14));
  psVar15 = (short *)(iVar14 + ((iVar1 << 0x10) >> 0xe));
  sVar4 = FUN_800844cc((int)*psVar15);
  psVar11 = *(short **)(&DAT_800ebba8 + uVar12 * 4);
  iVar1 = (int)sVar4;
  iVar14 = FUN_800844cc((int)*psVar11);
  puVar6 = (undefined4 *)&DAT_800eebac;
  while (uVar13 = uVar13 - 1, *(short *)(puVar6 + 6) != 0) {
    puVar6 = puVar6 + -0x1f;
    if (uVar13 == 0) {
      return 0xffffffff;
    }
  }
  *(undefined2 *)(puVar6 + 6) = 0xa003;
  *(undefined1 *)((int)puVar6 + 0x1a) = 0;
  *(undefined1 *)((int)puVar6 + 0x1b) = 0;
  uVar2 = FUN_800844e4(uVar16 << 0x10 | uVar12);
  puVar6[7] = uVar2;
  uVar5 = FUN_800844cc(*(undefined1 *)(psVar11 + 5));
  *(undefined2 *)(puVar6 + 8) = uVar5;
  *(undefined2 *)((int)puVar6 + 0x22) = param_2;
  puVar6[9] = 0;
  iVar3 = FUN_800844cc((int)psVar11[3]);
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
  sVar4 = psVar11[2];
  puVar6[0xd] = 0;
  *(undefined2 *)(puVar6 + 0xe) = 0;
  uStackX_2 = (undefined2)param_1;
  puVar6[0x10] = 0x100;
  puVar6[0xf] = 0;
  puVar6[0x11] = 0;
  puVar6[0x12] = 0;
  *(undefined2 *)((int)puVar6 + 0x3a) = uStackX_2;
  *(short *)((int)puVar6 + 0x32) = sVar4 + (short)(uVar16 >> 3) * 0x40;
  uVar10 = param_3[1];
  uVar2 = param_3[2];
  uVar9 = param_3[3];
  puVar6[0x13] = *param_3;
  puVar6[0x14] = uVar10;
  puVar6[0x15] = uVar2;
  puVar6[0x16] = uVar9;
  uVar10 = param_3[5];
  uVar2 = param_3[6];
  uVar9 = param_3[7];
  puVar6[0x17] = param_3[4];
  puVar6[0x18] = uVar10;
  puVar6[0x19] = uVar2;
  puVar6[0x1a] = uVar9;
  puVar6[0x1b] = param_3;
  puVar6[0x1c] = psVar11 + 4;
  puVar6[0x1d] = psVar11 + ((iVar14 << 0x10) >> 0xe) + 4;
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
  uVar12 = uVar13;
  while( true ) {
    iVar1 = iVar1 + -1;
    if (iVar1 == 0) {
      return uVar13;
    }
    if (uVar12 == 0) break;
    puVar6 = (undefined4 *)(&UNK_800ebd2c + uVar12 * 0x7c);
    while (uVar12 = uVar12 - 1, *(short *)(puVar6 + 6) != 0) {
      puVar6 = puVar6 + -0x1f;
      if (uVar12 == 0) {
        return 0xfffffffe;
      }
    }
    puVar8 = puVar6 + 6;
    puVar7 = (undefined4 *)(&DAT_800ebdc0 + uVar13 * 0x3e);
    *(undefined2 *)(puVar6 + 6) = 0xa003;
    *(undefined1 *)((int)puVar6 + 0x1b) = 0;
    do {
      uVar10 = puVar7[1];
      uVar2 = puVar7[2];
      uVar9 = puVar7[3];
      *puVar8 = *puVar7;
      puVar8[1] = uVar10;
      puVar8[2] = uVar2;
      puVar8[3] = uVar9;
      puVar7 = puVar7 + 4;
      puVar8 = puVar8 + 4;
    } while (puVar7 != (undefined4 *)(&UNK_800ebe20 + uVar13 * 0x7c));
    *puVar8 = *puVar7;
    *(char *)((int)puVar6 + 0x1a) = (char)uVar13;
    psVar11 = psVar15 + 2;
    iVar14 = iVar1;
    do {
      iVar14 = iVar14 + -1;
      sVar4 = FUN_800844cc((int)*psVar11);
      psVar11 = psVar11 + sVar4 * 0xc + 2;
    } while (iVar14 != 0);
    puVar6[0x1e] = psVar11 + 2;
    *puVar6 = *(undefined4 *)(psVar11 + 2);
    uVar5 = FUN_800844cc((int)psVar11[4]);
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
  return 0xfffffffe;
}
