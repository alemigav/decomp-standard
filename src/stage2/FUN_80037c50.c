/* FUN_80037c50
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80037c50  body 0x80037c50..0x800380ef  size 1184 B
 * body sha256 fb62b26fa2eb51c5a803bf9e12a9e7584ca06202b509c8a490238bc50e995954
 * provider record sha256 038b9602bb34f57bba7974a62b06ae0bf51ac5b5ccca0a2dd5853304e8f1f9c2
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80037c50(uint param_1,undefined2 param_2,undefined4 *param_3,undefined4 *param_4,
                undefined4 *param_5)

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
  int iVar11;
  short *psVar12;
  uint uVar13;
  int iVar14;
  short *psVar15;
  
  iVar11 = (param_1 >> 0x18) * 4;
  iVar14 = *(int *)(&DAT_800ebca8 + iVar11);
  uVar13 = param_1 >> 0x10 & 0xff;
  iVar1 = FUN_800844cc((int)*(short *)((param_1 >> 0x10 & 7) * 2 + iVar14));
  psVar15 = (short *)(iVar14 + ((iVar1 << 0x10) >> 0xe));
  iVar14 = 0x60;
  sVar4 = FUN_800844cc((int)*psVar15);
  psVar12 = *(short **)(&DAT_800ebba8 + iVar11);
  iVar1 = (int)sVar4;
  iVar11 = FUN_800844cc((int)*psVar12);
  puVar6 = (undefined4 *)&DAT_800eebac;
  while (iVar14 = iVar14 + -1, *(short *)(puVar6 + 6) != 0) {
    puVar6 = puVar6 + -0x1f;
    if (iVar14 == 0) {
      return -1;
    }
  }
  *(undefined2 *)(puVar6 + 6) = 0xa003;
  *(undefined1 *)((int)puVar6 + 0x1a) = 0;
  *(undefined1 *)((int)puVar6 + 0x1b) = 0;
  uVar2 = FUN_800844e4(uVar13 << 0x10 | param_1 >> 0x18);
  puVar6[7] = uVar2;
  uVar5 = FUN_800844cc(*(undefined1 *)(psVar12 + 5));
  *(undefined2 *)(puVar6 + 8) = uVar5;
  *(undefined2 *)((int)puVar6 + 0x22) = param_2;
  puVar6[9] = 0;
  iVar3 = FUN_800844cc((int)psVar12[3]);
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
  sVar4 = psVar12[2];
  puVar6[0x10] = 0x100;
  puVar6[0xd] = 0;
  *(undefined2 *)(puVar6 + 0xe) = 0;
  *(short *)((int)puVar6 + 0x3a) = (short)param_1;
  puVar6[0xf] = 0;
  puVar6[0x11] = 0;
  puVar6[0x12] = 0;
  *(short *)((int)puVar6 + 0x32) = sVar4 + (short)(uVar13 >> 3) * 0x40;
  uVar9 = param_3[1];
  uVar10 = param_3[2];
  uVar2 = param_3[3];
  puVar6[0x13] = *param_3;
  puVar6[0x14] = uVar9;
  puVar6[0x15] = uVar10;
  puVar6[0x16] = uVar2;
  uVar9 = param_3[5];
  uVar10 = param_3[6];
  uVar2 = param_3[7];
  puVar6[0x17] = param_3[4];
  puVar6[0x18] = uVar9;
  puVar6[0x19] = uVar10;
  puVar6[0x1a] = uVar2;
  puVar6[0x1b] = param_3;
  puVar6[0x1c] = psVar12 + 4;
  puVar6[0x1d] = psVar12 + ((iVar11 << 0x10) >> 0xe) + 4;
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
  puVar6[0x11] = *param_5;
  *(undefined2 *)(puVar6 + 0x12) = *(undefined2 *)(param_5 + 1);
  iVar11 = iVar14;
  while( true ) {
    iVar1 = iVar1 + -1;
    if (iVar1 == 0) {
      return iVar14;
    }
    if (iVar11 == 0) break;
    puVar6 = (undefined4 *)(&UNK_800ebd2c + iVar11 * 0x7c);
    while (iVar11 = iVar11 + -1, *(short *)(puVar6 + 6) != 0) {
      puVar6 = puVar6 + -0x1f;
      if (iVar11 == 0) {
        return -2;
      }
    }
    puVar8 = puVar6 + 6;
    puVar7 = (undefined4 *)(&DAT_800ebdc0 + iVar14 * 0x3e);
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
    } while (puVar7 != (undefined4 *)(&UNK_800ebe20 + iVar14 * 0x7c));
    *puVar8 = *puVar7;
    *(char *)((int)puVar6 + 0x1a) = (char)iVar14;
    psVar12 = psVar15 + 2;
    iVar3 = iVar1;
    do {
      iVar3 = iVar3 + -1;
      sVar4 = FUN_800844cc((int)*psVar12);
      psVar12 = psVar12 + sVar4 * 0xc + 2;
    } while (iVar3 != 0);
    puVar6[0x1e] = psVar12 + 2;
    *puVar6 = *(undefined4 *)(psVar12 + 2);
    uVar5 = FUN_800844cc((int)psVar12[4]);
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
    puVar6[0x11] = *param_5;
    *(undefined2 *)(puVar6 + 0x12) = *(undefined2 *)(param_5 + 1);
  }
  return -2;
}
