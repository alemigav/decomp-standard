/* FUN_80002bc0
 * image   boot (boot), base 0x80000480
 * address 0x80002bc0  body 0x80002bc0..0x80002f7b  size 956 B
 * body sha256 c1ab7775015ad826c04d632fb93e0b55272888919fabb9b884c405171829b318
 * provider record sha256 b5c63cf46323f650c3d55cece3458e6eba882bd9ca8ccfe8dce9eabf7ef29088
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80002bc0(int param_1,int param_2,int param_3,int param_4,int param_5,int *param_6)

{
  byte bVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  uint uVar14;
  byte *pbVar15;
  byte *pbVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  byte *pbVar21;
  
  pbVar16 = (byte *)*param_6;
  uVar18 = param_6[1];
  uVar14 = *(uint *)(param_5 + 0x20);
  pbVar15 = *(byte **)(param_5 + 0x30);
  uVar11 = *(uint *)(param_5 + 0x1c);
  if (pbVar15 < *(byte **)(param_5 + 0x2c)) {
    pbVar21 = *(byte **)(param_5 + 0x2c) + (-1 - (int)pbVar15);
  }
  else {
    pbVar21 = (byte *)(*(int *)(param_5 + 0x28) - (int)pbVar15);
  }
  uVar20 = *(uint *)(param_1 * 4 + -0x7ffed830);
  uVar10 = *(uint *)(param_2 * 4 + -0x7ffed830);
  bVar2 = uVar11 < 0x14;
LAB_80002c88:
  while (bVar2) {
    uVar18 = uVar18 - 1;
    bVar1 = *pbVar16;
    pbVar16 = pbVar16 + 1;
    uVar14 = uVar14 | (uint)bVar1 << (uVar11 & 0x1f);
    uVar11 = uVar11 + 8;
    bVar2 = uVar11 < 0x14;
  }
  pbVar13 = (byte *)(param_3 + (uVar14 & uVar20) * 8);
  uVar9 = (uint)*pbVar13;
  if (uVar9 != 0) {
LAB_80002cc8:
    uVar14 = uVar14 >> (pbVar13[1] & 0x1f);
    uVar11 = uVar11 - pbVar13[1];
    if ((uVar9 & 0x10) != 0) {
      uVar9 = uVar9 & 0xf;
      uVar12 = *(int *)(pbVar13 + 4) + (uVar14 & *(uint *)(uVar9 * 4 + -0x7ffed830));
      uVar14 = uVar14 >> uVar9;
      for (uVar11 = uVar11 - uVar9; uVar11 < 0xf; uVar11 = uVar11 + 8) {
        uVar18 = uVar18 - 1;
        uVar14 = uVar14 | (uint)*pbVar16 << (uVar11 & 0x1f);
        pbVar16 = pbVar16 + 1;
      }
      pbVar13 = (byte *)(param_4 + (uVar14 & uVar10) * 8);
      while( true ) {
        bVar1 = *pbVar13;
        uVar14 = uVar14 >> (pbVar13[1] & 0x1f);
        uVar11 = uVar11 - pbVar13[1];
        if ((bVar1 & 0x10) != 0) break;
        if ((bVar1 & 0x40) != 0) {
          iVar19 = uVar18 + (uVar11 >> 3);
          iVar17 = (int)pbVar16 - (uVar11 >> 3);
          param_6[6] = -0x7ffee920;
          *(uint *)(param_5 + 0x20) = uVar14;
          *(uint *)(param_5 + 0x1c) = uVar11 & 7;
          iVar8 = *param_6;
          iVar6 = param_6[2];
          uVar3 = 0xfffffffd;
          goto LAB_80002f4c;
        }
        pbVar13 = (byte *)(*(int *)(pbVar13 + 4) +
                          (uVar14 & *(uint *)((uint)bVar1 * 4 + -0x7ffed830)) * 8);
      }
      uVar9 = bVar1 & 0xf;
      if (uVar11 < uVar9) {
        do {
          uVar18 = uVar18 - 1;
          uVar14 = uVar14 | (uint)*pbVar16 << (uVar11 & 0x1f);
          uVar11 = uVar11 + 8;
          pbVar16 = pbVar16 + 1;
        } while (uVar11 < uVar9);
        uVar11 = uVar11 - uVar9;
      }
      else {
        uVar11 = uVar11 - uVar9;
      }
      pbVar21 = pbVar21 + -uVar12;
      uVar7 = *(int *)(pbVar13 + 4) + (uVar14 & *(uint *)(uVar9 * 4 + -0x7ffed830));
      uVar4 = (int)pbVar15 - *(int *)(param_5 + 0x24);
      uVar14 = uVar14 >> uVar9;
      if (uVar4 < uVar7) {
        uVar7 = uVar7 - uVar4;
        pbVar13 = (byte *)(*(int *)(param_5 + 0x28) - uVar7);
        if (uVar7 < uVar12) {
          uVar12 = uVar12 - uVar7;
          do {
            bVar1 = *pbVar13;
            pbVar13 = pbVar13 + 1;
            uVar7 = uVar7 - 1;
            *pbVar15 = bVar1;
            pbVar15 = pbVar15 + 1;
          } while (uVar7 != 0);
          pbVar13 = *(byte **)(param_5 + 0x24);
        }
      }
      else {
        pbVar5 = pbVar15 + -uVar7;
        uVar12 = uVar12 - 2;
        *pbVar15 = *pbVar5;
        pbVar13 = pbVar5 + 2;
        pbVar15[1] = pbVar5[1];
        pbVar15 = pbVar15 + 2;
      }
      do {
        bVar1 = *pbVar13;
        pbVar13 = pbVar13 + 1;
        uVar12 = uVar12 - 1;
        *pbVar15 = bVar1;
        pbVar15 = pbVar15 + 1;
      } while (uVar12 != 0);
      goto LAB_80002f18;
    }
    if ((uVar9 & 0x40) == 0) goto code_r0x80002e94;
    uVar10 = uVar11 >> 3;
    if ((uVar9 & 0x20) == 0) {
      iVar19 = uVar18 + uVar10;
      iVar17 = (int)pbVar16 - uVar10;
      param_6[6] = -0x7ffee908;
      *(uint *)(param_5 + 0x20) = uVar14;
      *(uint *)(param_5 + 0x1c) = uVar11 & 7;
      iVar8 = *param_6;
      iVar6 = param_6[2];
      uVar3 = 0xfffffffd;
    }
    else {
      iVar19 = uVar18 + uVar10;
      iVar17 = (int)pbVar16 - uVar10;
      *(uint *)(param_5 + 0x20) = uVar14;
      *(uint *)(param_5 + 0x1c) = uVar11 & 7;
      iVar8 = *param_6;
      iVar6 = param_6[2];
      uVar3 = 1;
    }
    goto LAB_80002f4c;
  }
  uVar14 = uVar14 >> (pbVar13[1] & 0x1f);
  uVar11 = uVar11 - pbVar13[1];
  *pbVar15 = pbVar13[7];
  goto LAB_80002f14;
code_r0x80002e94:
  pbVar13 = (byte *)(*(int *)(pbVar13 + 4) + (uVar14 & *(uint *)(uVar9 * 4 + -0x7ffed830)) * 8);
  uVar9 = (uint)*pbVar13;
  if (uVar9 == 0) goto code_r0x80002ebc;
  goto LAB_80002cc8;
code_r0x80002ebc:
  uVar14 = uVar14 >> (pbVar13[1] & 0x1f);
  uVar11 = uVar11 - pbVar13[1];
  *pbVar15 = pbVar13[7];
LAB_80002f14:
  pbVar21 = pbVar21 + -1;
  pbVar15 = pbVar15 + 1;
LAB_80002f18:
  if ((pbVar21 < (byte *)0x102) || (bVar2 = uVar11 < 0x14, uVar18 < 10)) {
    iVar19 = uVar18 + (uVar11 >> 3);
    iVar17 = (int)pbVar16 - (uVar11 >> 3);
    *(uint *)(param_5 + 0x20) = uVar14;
    *(uint *)(param_5 + 0x1c) = uVar11 & 7;
    iVar8 = *param_6;
    iVar6 = param_6[2];
    uVar3 = 0;
LAB_80002f4c:
    param_6[1] = iVar19;
    *param_6 = iVar17;
    param_6[2] = iVar6 + (iVar17 - iVar8);
    *(byte **)(param_5 + 0x30) = pbVar15;
    return uVar3;
  }
  goto LAB_80002c88;
}
