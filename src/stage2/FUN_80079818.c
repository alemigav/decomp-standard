/* FUN_80079818
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80079818  body 0x80079818..0x80079caf  size 1176 B
 * body sha256 f89f449a0aadf67fced1e0d6239ab21afc518341e902bb2852d7ddd39872efb7
 * provider record sha256 4095928ae8fe0d3cc26258794b1c8c12213f2e8672fe98e0bf937e328a6b15c6
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80079998) */
/* WARNING: Removing unreachable block (ram,0x800799e4) */
/* WARNING: Removing unreachable block (ram,0x8007983c) */
/* WARNING: Removing unreachable block (ram,0x80079840) */
/* WARNING: Removing unreachable block (ram,0x8007988c) */
/* WARNING: Removing unreachable block (ram,0x800798f8) */
/* WARNING: Removing unreachable block (ram,0x800798fc) */
/* WARNING: Removing unreachable block (ram,0x80079948) */

void FUN_80079818(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined2 uVar2;
  short sVar3;
  ushort uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  short *psVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 local_120 [14];
  short local_e8 [2];
  undefined4 local_e4 [13];
  undefined2 auStack_b0 [28];
  short local_78 [2];
  undefined4 local_74 [13];
  short asStack_40 [28];
  
  puVar8 = &DAT_800b9a9c;
  puVar5 = local_120;
  do {
    puVar9 = puVar5;
    puVar7 = puVar8;
    uVar11 = puVar7[1];
    uVar12 = puVar7[2];
    uVar13 = puVar7[3];
    *puVar9 = *puVar7;
    puVar9[1] = uVar11;
    puVar9[2] = uVar12;
    puVar9[3] = uVar13;
    puVar8 = puVar7 + 4;
    puVar5 = puVar9 + 4;
  } while (puVar7 + 4 != (undefined4 *)&UNK_800b9acc);
  uVar11 = puVar7[5];
  puVar9[4] = 0x10001000;
  puVar9[5] = uVar11;
  puVar8 = &DAT_800b9ad4;
  psVar10 = local_e8;
  do {
    uVar11 = puVar8[1];
    uVar12 = puVar8[2];
    uVar13 = puVar8[3];
    *(undefined4 *)psVar10 = *puVar8;
    *(undefined4 *)(psVar10 + 2) = uVar11;
    *(undefined4 *)(psVar10 + 4) = uVar12;
    *(undefined4 *)(psVar10 + 6) = uVar13;
    puVar8 = puVar8 + 4;
    psVar10 = psVar10 + 8;
  } while (puVar8 != &DAT_800b9b44);
  psVar10 = local_78;
  puVar8 = &DAT_800b9b44;
  do {
    uVar11 = puVar8[1];
    uVar12 = puVar8[2];
    uVar13 = puVar8[3];
    *(undefined4 *)psVar10 = *puVar8;
    *(undefined4 *)(psVar10 + 2) = uVar11;
    *(undefined4 *)(psVar10 + 4) = uVar12;
    *(undefined4 *)(psVar10 + 6) = uVar13;
    puVar8 = puVar8 + 4;
    psVar10 = psVar10 + 8;
  } while (puVar8 != (undefined4 *)&UNK_800b9bb4);
  *(undefined4 *)(param_1 + 4) = 0x1000000;
  uVar2 = *(undefined2 *)((int)local_120 + (*(byte *)(param_1 + 8) - 0x40) * 2);
  *(undefined2 *)(param_1 + 0x26c) = 0;
  *(undefined2 *)(param_1 + 0x268) = 0;
  *(undefined2 *)(param_1 + 0x278) = 0;
  *(undefined2 *)(param_1 + 0x264) = 0;
  *(undefined1 *)(param_1 + 0x26f) = 0;
  *(int *)(param_1 + 0x250) = param_1;
  *(int *)(param_1 + 0x254) = param_1;
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  *(undefined2 *)(param_1 + 0x27a) = uVar2;
  FUN_80089d54(param_1,param_2,param_3,0x100);
  if (*(char *)(param_1 + 8) != 'K') {
    iVar6 = *(int *)(param_1 + 0x234);
    *(undefined1 *)(param_1 + 0x25d) = 8;
    *(undefined1 *)(param_1 + 0x25c) = 0;
    *(undefined2 *)(iVar6 + 0xcf4) = 0x60;
    *(undefined2 *)(iVar6 + 0xcf6) = 0x60;
    *(undefined2 *)(iVar6 + 0xcf8) = 0x200;
    *(undefined2 *)(iVar6 + 0xcf0) = 0;
    *(undefined2 *)(iVar6 + 0xcf2) = 0;
    *(undefined2 *)(iVar6 + 0xcfa) = 0x138;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 0x92;
  }
  *(undefined4 *)(param_1 + 0x284) = 1;
  *(undefined2 *)(param_1 + 0x130) = 0;
  sVar3 = local_e8[*(byte *)(param_1 + 8) - 0x40];
  *(undefined2 *)(param_1 + 0x132) = 0;
  *(short *)(param_1 + 0x134) = sVar3 * -0x12;
  *(undefined2 *)(param_1 + 0x136) = auStack_b0[*(byte *)(param_1 + 8) - 0x40];
  *(short *)(param_1 + 0x13a) = local_e8[*(byte *)(param_1 + 8) - 0x40] * 0x12;
  *(undefined2 *)(param_1 + 0x138) = auStack_b0[*(byte *)(param_1 + 8) - 0x40];
  *(undefined2 *)(param_1 + 300) = auStack_b0[*(byte *)(param_1 + 8) - 0x40];
  iVar6 = *(byte *)(param_1 + 8) - 0x40;
  *(undefined2 *)(param_1 + 0x12e) = auStack_b0[*(byte *)(param_1 + 8) - 0x40];
  FUN_800339dc(param_1 + 0x208,0,(int)local_78[iVar6] | (int)asStack_40[iVar6] << 0x10,0,
               *(int *)(param_1 + 0x234) + 0x4c);
  uVar4 = *(ushort *)(param_1 + 0x1aa);
  *(ushort *)(param_1 + 0x1aa) = uVar4 | 0x1000;
  if ((uVar4 & 0x400) == 0) {
    cVar1 = *(char *)(param_1 + 8);
    *(ushort *)(param_1 + 0x1aa) = uVar4 | 0x5000;
    *(undefined2 *)(param_1 + 0x1f2) = 0xffff;
    *(undefined2 *)(param_1 + 0x1fe) = 0xffff;
    if ((((cVar1 == 'A') || (cVar1 == 'C')) || (cVar1 == 'E')) || (cVar1 == 'O')) {
      DAT_800e110c = DAT_800e110c & 0xefffffff;
    }
  }
  else {
    DAT_800e110c = DAT_800e110c | 0x10000000;
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xefff;
  }
  if ((*(ushort *)(param_1 + 0x1aa) & 0x4000) != 0) {
    *(undefined1 *)(param_1 + 4) = 4;
    *(undefined1 *)(param_1 + 5) = 6;
  }
  (*(code *)(&PTR_FUN_8011a904)[*(byte *)(param_1 + 8) - 0x40])(param_1);
  return;
}
