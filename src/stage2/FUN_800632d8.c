/* FUN_800632d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800632d8  body 0x800632d8..0x800635af  size 728 B
 * body sha256 9a97d12420026e61c5515336f6debe02120212fa564720326dd959b89539ebba
 * provider record sha256 041a72670afd04c3fabb0970d6d084a8d9ca1ee79e47672297883628101ea639
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800632d8(undefined2 *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined2 *puVar13;
  byte *pbVar14;
  byte *pbVar15;
  byte *pbVar16;
  short *psVar17;
  short *psVar18;
  uint uVar19;
  uint uVar20;
  short sVar21;
  uint uVar22;
  
  bVar5 = false;
  puVar13 = (undefined2 *)((uint)((int)param_1 + param_2 + 7) & 0xfffffff8);
  *puVar13 = *param_1;
  puVar13[1] = param_1[1];
  uVar22 = (uint)(ushort)param_1[2];
  pbVar16 = (byte *)(param_1 + 3);
  puVar13[2] = param_1[2];
  pbVar15 = (byte *)(puVar13 + 3);
  psVar17 = param_1 + -1;
  while( true ) {
    uVar22 = uVar22 - 1;
    psVar18 = psVar17 + 4;
    if (uVar22 == 0xffffffff) break;
    pbVar16 = pbVar16 + 8;
    pbVar14 = pbVar15 + 0xc;
    uVar12 = (uint)(ushort)psVar17[6];
    bVar1 = *(byte *)(psVar17 + 7);
    bVar2 = *(byte *)((int)psVar17 + 0xf);
    uVar10 = (uint)*(byte *)(psVar17 + 5) | (uVar12 & 0xc000) >> 6;
    uVar8 = (uint)*(byte *)((int)psVar17 + 0xb) | (uVar12 & 0x2000) >> 5;
    uVar19 = bVar1 + uVar10;
    sVar21 = *psVar18;
    *(short *)(pbVar15 + 2) = (short)uVar10;
    *(short *)(pbVar15 + 4) = (short)uVar8;
    *(short *)(pbVar15 + 6) = (short)(uVar12 & 0x1fff);
    *(ushort *)(pbVar15 + 8) = (ushort)bVar1;
    *(ushort *)(pbVar15 + 10) = (ushort)bVar2;
    *(short *)pbVar15 = sVar21;
    uVar20 = bVar2 + uVar8;
    if (((int)*psVar18 & 0x8000U) == 0) {
      uVar7 = (uint)pbVar16 & 1;
      uVar12 = uVar10;
      uVar6 = uVar10;
      if (uVar8 < uVar20) {
        do {
          while (uVar6 != uVar19) {
            psVar18 = (short *)((int)psVar18 + 1);
            bVar1 = *pbVar16;
            bVar2 = *pbVar16;
            pbVar16 = pbVar16 + 1;
            *pbVar14 = bVar2;
            uVar12 = uVar12 + (bVar1 & 0x7f);
            pbVar14 = pbVar14 + 1;
            uVar6 = uVar12 & 0xffff;
          }
          uVar8 = uVar8 + 1;
          uVar12 = uVar10;
          uVar6 = uVar10;
        } while ((uVar8 & 0xffff) < uVar20);
        uVar7 = (uint)pbVar16 & 1;
      }
    }
    else {
      iVar9 = (uVar12 & 0x1fff) << 5;
      bVar5 = true;
      if ((double)iVar9 < 512.0) {
        iVar9 = 0x200;
      }
      pbVar14 = (byte *)((uint)(pbVar15 + 0x13) & 0xfffffff8);
      *(short *)(pbVar15 + 6) =
           (short)(int)((((float)-iVar9 * DAT_800efc54 + DAT_800efc58) / (float)iVar9) * 16352.0 +
                       16352.0);
      uVar7 = (uint)pbVar16 & 1;
      uVar12 = uVar10;
      uVar6 = uVar10;
      if (uVar8 < uVar20) {
        do {
          while (uVar6 != uVar19) {
            psVar18 = (short *)((int)psVar18 + 1);
            bVar1 = *pbVar16;
            pbVar16 = pbVar16 + 1;
            uVar12 = uVar12 + 1;
            *pbVar14 = bVar1;
            pbVar14 = pbVar14 + 1;
            uVar6 = uVar12 & 0xffff;
          }
          uVar8 = uVar8 + 1;
          uVar12 = uVar10;
          uVar6 = uVar10;
        } while ((uVar8 & 0xffff) < uVar20);
        uVar7 = (uint)pbVar16 & 1;
      }
    }
    pbVar15 = pbVar14;
    psVar17 = psVar18;
    if (uVar7 != 0) {
      pbVar16 = pbVar16 + 1;
      pbVar15 = pbVar14 + 1;
      psVar17 = (short *)((int)psVar18 + 1);
    }
  }
  if (bVar5) {
    sVar21 = 0x100;
    pbVar15 = (byte *)((uint)(pbVar15 + 7) & 0xfffffff8);
    do {
      uVar4 = *(undefined2 *)pbVar16;
      pbVar16 = pbVar16 + 2;
      sVar21 = sVar21 + -1;
      *(undefined2 *)pbVar15 = uVar4;
      pbVar15 = pbVar15 + 2;
    } while (sVar21 != 0);
  }
  iVar11 = (int)pbVar15 - (int)puVar13;
  iVar9 = iVar11 + -1;
  if (iVar11 != 0) {
    do {
      uVar3 = *(undefined1 *)puVar13;
      puVar13 = (undefined2 *)((int)puVar13 + 1);
      iVar9 = iVar9 + -1;
      *(undefined1 *)param_1 = uVar3;
      param_1 = (undefined2 *)((int)param_1 + 1);
    } while (iVar9 != -1);
  }
  return iVar11;
}
