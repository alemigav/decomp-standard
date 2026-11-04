/* FUN_800b53f4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b53f4  body 0x800b53f4..0x800b62bb  size 3784 B
 * body sha256 b568566ca3ebf60d70dce49b890e54a02b60bda07583e7e6359ec3620fbca442
 * provider record sha256 57125772d5d84076c63d50cb301814b6d53e53b2d8da4eb31529443f5cedc64d
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800b53f4(int param_1,undefined4 param_2)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  int iVar6;
  ushort *puVar7;
  ushort *puVar8;
  ushort *puVar9;
  ushort *puVar10;
  ushort *puVar11;
  ushort *puVar12;
  uint uVar13;
  uint uVar14;
  ushort *puVar15;
  int iVar16;
  ushort *puVar17;
  undefined1 *puVar18;
  ushort *puVar19;
  ushort *puVar20;
  ushort *puVar21;
  ushort *puVar22;
  ushort *puVar23;
  ushort local_130;
  ushort local_12e;
  ushort local_12c;
  ushort local_12a;
  ushort local_128;
  ushort local_126;
  ushort local_124;
  ushort local_122;
  ushort local_120 [4];
  ushort local_118 [4];
  ushort local_110 [4];
  ushort local_108 [4];
  undefined1 local_100 [2];
  ushort local_fe;
  ushort local_fc;
  ushort local_fa;
  ushort local_f8;
  ushort local_f6;
  ushort local_f4;
  ushort local_f2;
  ushort local_f0;
  ushort local_ee;
  ushort local_ec;
  ushort local_ea;
  ushort local_e8 [40];
  undefined1 auStack_98 [84];
  undefined4 local_44;
  ushort *local_3c;
  ushort *local_34;
  ushort *local_2c;
  
  local_44 = param_2;
  uVar14 = *(uint *)(param_1 + 0x11c8);
  iVar6 = param_1 + 0x1a0;
  iVar16 = -(uVar14 & 0x1f);
  uVar13 = iVar16 + 0x20;
  uVar4 = *(uint *)(((int)uVar14 >> 3 & 0xffcU) + iVar6) >> (uVar14 & 0x1f);
  if (*(short *)(param_1 + 0x18a) == 0) {
    if (*(short *)(param_1 + 0x18c) == 0) {
      if ((int)uVar13 < 2) {
        uVar3 = uVar4 & (1 << (uVar13 & 0x1f)) - 1U;
        uVar14 = uVar14 + 0x20;
        uVar4 = *(uint *)(((int)uVar14 >> 3 & 0xffcU) + iVar6);
        if (uVar13 != 1) {
          uVar3 = uVar3 | (uVar4 & (1 << (1 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f);
        }
        uVar4 = uVar4 >> (1 - uVar13 & 0x1f);
        uVar13 = iVar16 + 0x3f;
      }
      else {
        uVar3 = uVar4 & 1;
        uVar4 = uVar4 >> 1;
        uVar13 = iVar16 + 0x1f;
      }
      uVar5 = (ushort)uVar4;
      if (uVar3 == 0) {
        if ((int)uVar13 < 8) {
          uVar14 = uVar14 + 0x20;
          uVar5 = uVar5 & (short)(1 << (uVar13 & 0x1f)) - 1U;
          *(ushort *)(param_1 + 0x18a) = uVar5;
          uVar4 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
          if (uVar13 != 7) {
            *(ushort *)(param_1 + 0x18a) =
                 uVar5 | (ushort)((uVar4 & (1 << (7 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f));
          }
          uVar4 = uVar4 >> (7 - uVar13 & 0x1f);
          uVar13 = uVar13 + 0x19;
        }
        else {
          *(ushort *)(param_1 + 0x18a) = uVar5 & 0x7f;
          uVar4 = uVar4 >> 7;
          uVar13 = uVar13 - 7;
        }
        *(short *)(param_1 + 0x18a) = *(short *)(param_1 + 0x18a) + 1;
      }
      else {
        if ((int)uVar13 < 5) {
          uVar14 = uVar14 + 0x20;
          uVar5 = uVar5 & (short)(1 << (uVar13 & 0x1f)) - 1U;
          *(ushort *)(param_1 + 0x18c) = uVar5;
          uVar4 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
          if (uVar13 != 4) {
            *(ushort *)(param_1 + 0x18c) =
                 uVar5 | (ushort)((uVar4 & (1 << (4 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f));
          }
          uVar4 = uVar4 >> (4 - uVar13 & 0x1f);
          uVar13 = uVar13 + 0x1c;
        }
        else {
          *(ushort *)(param_1 + 0x18c) = uVar5 & 0xf;
          uVar4 = uVar4 >> 4;
          uVar13 = uVar13 - 4;
        }
        *(short *)(param_1 + 0x18c) = *(short *)(param_1 + 0x18c) + 1;
      }
      goto LAB_800b55d8;
    }
  }
  else {
LAB_800b55d8:
    if (*(short *)(param_1 + 0x18c) == 0) {
      if ((int)uVar13 < 7) {
        uVar14 = uVar14 + 0x20;
        local_130 = (ushort)uVar4 & (short)(1 << (uVar13 & 0x1f)) - 1U;
        uVar4 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
        if (uVar13 != 6) {
          local_130 = local_130 |
                      (ushort)((uVar4 & (1 << (6 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f));
        }
        uVar4 = uVar4 >> (6 - uVar13 & 0x1f);
        uVar13 = uVar13 + 0x1a;
      }
      else {
        local_130 = (ushort)uVar4 & 0x3f;
        uVar4 = uVar4 >> 6;
        uVar13 = uVar13 - 6;
      }
      if ((int)uVar13 < 7) {
        uVar14 = uVar14 + 0x20;
        local_12e = (ushort)uVar4 & (short)(1 << (uVar13 & 0x1f)) - 1U;
        uVar4 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
        if (uVar13 != 6) {
          local_12e = local_12e |
                      (ushort)((uVar4 & (1 << (6 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f));
        }
        uVar4 = uVar4 >> (6 - uVar13 & 0x1f);
        uVar13 = uVar13 + 0x1a;
      }
      else {
        local_12e = (ushort)uVar4 & 0x3f;
        uVar4 = uVar4 >> 6;
        uVar13 = uVar13 - 6;
      }
      if ((int)uVar13 < 6) {
        uVar14 = uVar14 + 0x20;
        local_12c = (ushort)uVar4 & (short)(1 << (uVar13 & 0x1f)) - 1U;
        uVar4 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
        if (uVar13 != 5) {
          local_12c = local_12c |
                      (ushort)((uVar4 & (1 << (5 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f));
        }
        uVar4 = uVar4 >> (5 - uVar13 & 0x1f);
        uVar13 = uVar13 + 0x1b;
      }
      else {
        local_12c = (ushort)uVar4 & 0x1f;
        uVar4 = uVar4 >> 5;
        uVar13 = uVar13 - 5;
      }
      if ((int)uVar13 < 6) {
        uVar14 = uVar14 + 0x20;
        local_12a = (ushort)uVar4 & (short)(1 << (uVar13 & 0x1f)) - 1U;
        uVar4 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
        if (uVar13 != 5) {
          local_12a = local_12a |
                      (ushort)((uVar4 & (1 << (5 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f));
        }
        uVar4 = uVar4 >> (5 - uVar13 & 0x1f);
        uVar13 = uVar13 + 0x1b;
      }
      else {
        local_12a = (ushort)uVar4 & 0x1f;
        uVar4 = uVar4 >> 5;
        uVar13 = uVar13 - 5;
      }
      if ((int)uVar13 < 5) {
        uVar14 = uVar14 + 0x20;
        local_128 = (ushort)uVar4 & (short)(1 << (uVar13 & 0x1f)) - 1U;
        uVar4 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
        if (uVar13 != 4) {
          local_128 = local_128 |
                      (ushort)((uVar4 & (1 << (4 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f));
        }
        uVar4 = uVar4 >> (4 - uVar13 & 0x1f);
        uVar13 = uVar13 + 0x1c;
      }
      else {
        local_128 = (ushort)uVar4 & 0xf;
        uVar4 = uVar4 >> 4;
        uVar13 = uVar13 - 4;
      }
      if ((int)uVar13 < 5) {
        uVar14 = uVar14 + 0x20;
        local_126 = (ushort)uVar4 & (short)(1 << (uVar13 & 0x1f)) - 1U;
        uVar4 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
        if (uVar13 != 4) {
          local_126 = local_126 |
                      (ushort)((uVar4 & (1 << (4 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f));
        }
        uVar4 = uVar4 >> (4 - uVar13 & 0x1f);
        uVar13 = uVar13 + 0x1c;
      }
      else {
        local_126 = (ushort)uVar4 & 0xf;
        uVar4 = uVar4 >> 4;
        uVar13 = uVar13 - 4;
      }
      if ((int)uVar13 < 4) {
        uVar14 = uVar14 + 0x20;
        local_124 = (ushort)uVar4 & (short)(1 << (uVar13 & 0x1f)) - 1U;
        uVar4 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
        if (uVar13 != 3) {
          local_124 = local_124 |
                      (ushort)((uVar4 & (1 << (3 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f));
        }
        uVar4 = uVar4 >> (3 - uVar13 & 0x1f);
        uVar13 = uVar13 + 0x1d;
      }
      else {
        local_124 = (ushort)uVar4 & 7;
        uVar4 = uVar4 >> 3;
        uVar13 = uVar13 - 3;
      }
      if ((int)uVar13 < 4) {
        uVar14 = uVar14 + 0x20;
        local_122 = (ushort)uVar4 & (short)(1 << (uVar13 & 0x1f)) - 1U;
        uVar4 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
        if (uVar13 != 3) {
          local_122 = local_122 |
                      (ushort)((uVar4 & (1 << (3 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f));
        }
        uVar4 = uVar4 >> (3 - uVar13 & 0x1f);
        uVar13 = uVar13 + 0x1d;
      }
      else {
        local_122 = (ushort)uVar4 & 7;
        uVar4 = uVar4 >> 3;
        uVar13 = uVar13 - 3;
      }
      puVar8 = local_e8;
      local_3c = puVar8;
      puVar23 = &local_ea;
      puVar22 = &local_ec;
      puVar21 = &local_ee;
      puVar20 = &local_f0;
      puVar19 = &local_f2;
      puVar17 = &local_f4;
      puVar15 = &local_f6;
      puVar12 = &local_f8;
      puVar11 = &local_fa;
      puVar10 = &local_fc;
      local_2c = &local_fe;
      puVar7 = &local_130;
      puVar9 = puVar7;
      do {
        if ((int)uVar13 < 8) {
          uVar14 = uVar14 + 0x20;
          uVar5 = (ushort)uVar4 & (short)(1 << (uVar13 & 0x1f)) - 1U;
          puVar7[8] = uVar5;
          uVar3 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
          if (uVar13 != 7) {
            puVar7[8] = uVar5 | (ushort)((uVar3 & (1 << (7 - uVar13 & 0x1f)) - 1U) <<
                                        (uVar13 & 0x1f));
          }
          uVar3 = uVar3 >> (7 - uVar13 & 0x1f);
          uVar13 = uVar13 + 0x19;
        }
        else {
          puVar7[8] = (ushort)uVar4 & 0x7f;
          uVar3 = uVar4 >> 7;
          uVar13 = uVar13 - 7;
        }
        if ((int)uVar13 < 3) {
          uVar14 = uVar14 + 0x20;
          uVar5 = (ushort)uVar3 & (short)(1 << (uVar13 & 0x1f)) - 1U;
          puVar7[0x10] = uVar5;
          uVar3 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
          if (uVar13 != 2) {
            puVar7[0x10] = uVar5 | (ushort)((uVar3 & (1 << (2 - uVar13 & 0x1f)) - 1U) <<
                                           (uVar13 & 0x1f));
          }
          uVar3 = uVar3 >> (2 - uVar13 & 0x1f);
          uVar13 = uVar13 + 0x1e;
        }
        else {
          puVar7[0x10] = (ushort)uVar3 & 3;
          uVar3 = uVar3 >> 2;
          uVar13 = uVar13 - 2;
        }
        if ((int)uVar13 < 3) {
          uVar14 = uVar14 + 0x20;
          uVar5 = (ushort)uVar3 & (short)(1 << (uVar13 & 0x1f)) - 1U;
          puVar7[0xc] = uVar5;
          uVar3 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
          if (uVar13 != 2) {
            puVar7[0xc] = uVar5 | (ushort)((uVar3 & (1 << (2 - uVar13 & 0x1f)) - 1U) <<
                                          (uVar13 & 0x1f));
          }
          uVar3 = uVar3 >> (2 - uVar13 & 0x1f);
          uVar13 = uVar13 + 0x1e;
        }
        else {
          puVar7[0xc] = (ushort)uVar3 & 3;
          uVar3 = uVar3 >> 2;
          uVar13 = uVar13 - 2;
        }
        if ((int)uVar13 < 7) {
          uVar14 = uVar14 + 0x20;
          uVar5 = (ushort)uVar3 & (short)(1 << (uVar13 & 0x1f)) - 1U;
          puVar7[0x14] = uVar5;
          uVar3 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
          if (uVar13 != 6) {
            puVar7[0x14] = uVar5 | (ushort)((uVar3 & (1 << (6 - uVar13 & 0x1f)) - 1U) <<
                                           (uVar13 & 0x1f));
          }
          uVar3 = uVar3 >> (6 - uVar13 & 0x1f);
          uVar13 = uVar13 + 0x1a;
        }
        else {
          puVar7[0x14] = (ushort)uVar3 & 0x3f;
          uVar3 = uVar3 >> 6;
          uVar13 = uVar13 - 6;
        }
        if ((int)uVar13 < 4) {
          uVar14 = uVar14 + 0x20;
          uVar5 = (ushort)uVar3 & (short)(1 << (uVar13 & 0x1f)) - 1U;
          puVar9[0x18] = uVar5;
          uVar3 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
          if (uVar13 != 3) {
            puVar9[0x18] = uVar5 | (ushort)((uVar3 & (1 << (3 - uVar13 & 0x1f)) - 1U) <<
                                           (uVar13 & 0x1f));
          }
          uVar3 = uVar3 >> (3 - uVar13 & 0x1f);
          uVar13 = uVar13 + 0x1d;
        }
        else {
          puVar9[0x18] = (ushort)uVar3 & 7;
          uVar3 = uVar3 >> 3;
          uVar13 = uVar13 - 3;
        }
        puVar2 = local_2c;
        if ((int)uVar13 < 4) {
          uVar14 = uVar14 + 0x20;
          uVar5 = (ushort)uVar3 & (short)(1 << (uVar13 & 0x1f)) - 1U;
          *local_2c = uVar5;
          uVar4 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
          if (uVar13 != 3) {
            *puVar2 = uVar5 | (ushort)((uVar4 & (1 << (3 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f))
            ;
          }
          uVar4 = uVar4 >> (3 - uVar13 & 0x1f);
          uVar13 = uVar13 + 0x1d;
        }
        else {
          uVar4 = uVar3 >> 3;
          uVar13 = uVar13 - 3;
          *local_2c = (ushort)uVar3 & 7;
        }
        if ((int)uVar13 < 4) {
          uVar14 = uVar14 + 0x20;
          uVar5 = (ushort)uVar4 & (short)(1 << (uVar13 & 0x1f)) - 1U;
          *puVar10 = uVar5;
          uVar4 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
          if (uVar13 != 3) {
            *puVar10 = uVar5 | (ushort)((uVar4 & (1 << (3 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f)
                                       );
          }
          uVar4 = uVar4 >> (3 - uVar13 & 0x1f);
          uVar13 = uVar13 + 0x1d;
        }
        else {
          *puVar10 = (ushort)uVar4 & 7;
          uVar4 = uVar4 >> 3;
          uVar13 = uVar13 - 3;
        }
        if ((int)uVar13 < 4) {
          uVar14 = uVar14 + 0x20;
          uVar5 = (ushort)uVar4 & (short)(1 << (uVar13 & 0x1f)) - 1U;
          *puVar11 = uVar5;
          uVar4 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
          if (uVar13 != 3) {
            *puVar11 = uVar5 | (ushort)((uVar4 & (1 << (3 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f)
                                       );
          }
          uVar4 = uVar4 >> (3 - uVar13 & 0x1f);
          uVar13 = uVar13 + 0x1d;
        }
        else {
          *puVar11 = (ushort)uVar4 & 7;
          uVar4 = uVar4 >> 3;
          uVar13 = uVar13 - 3;
        }
        if ((int)uVar13 < 4) {
          uVar14 = uVar14 + 0x20;
          uVar5 = (ushort)uVar4 & (short)(1 << (uVar13 & 0x1f)) - 1U;
          *puVar12 = uVar5;
          uVar4 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
          if (uVar13 != 3) {
            *puVar12 = uVar5 | (ushort)((uVar4 & (1 << (3 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f)
                                       );
          }
          uVar4 = uVar4 >> (3 - uVar13 & 0x1f);
          uVar13 = uVar13 + 0x1d;
        }
        else {
          *puVar12 = (ushort)uVar4 & 7;
          uVar4 = uVar4 >> 3;
          uVar13 = uVar13 - 3;
        }
        if ((int)uVar13 < 4) {
          uVar14 = uVar14 + 0x20;
          uVar5 = (ushort)uVar4 & (short)(1 << (uVar13 & 0x1f)) - 1U;
          *puVar15 = uVar5;
          uVar4 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
          if (uVar13 != 3) {
            *puVar15 = uVar5 | (ushort)((uVar4 & (1 << (3 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f)
                                       );
          }
          uVar4 = uVar4 >> (3 - uVar13 & 0x1f);
          uVar13 = uVar13 + 0x1d;
        }
        else {
          *puVar15 = (ushort)uVar4 & 7;
          uVar4 = uVar4 >> 3;
          uVar13 = uVar13 - 3;
        }
        if ((int)uVar13 < 4) {
          uVar14 = uVar14 + 0x20;
          uVar5 = (ushort)uVar4 & (short)(1 << (uVar13 & 0x1f)) - 1U;
          *puVar17 = uVar5;
          uVar4 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
          if (uVar13 != 3) {
            *puVar17 = uVar5 | (ushort)((uVar4 & (1 << (3 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f)
                                       );
          }
          uVar4 = uVar4 >> (3 - uVar13 & 0x1f);
          uVar13 = uVar13 + 0x1d;
        }
        else {
          *puVar17 = (ushort)uVar4 & 7;
          uVar4 = uVar4 >> 3;
          uVar13 = uVar13 - 3;
        }
        if ((int)uVar13 < 4) {
          uVar14 = uVar14 + 0x20;
          uVar5 = (ushort)uVar4 & (short)(1 << (uVar13 & 0x1f)) - 1U;
          *puVar19 = uVar5;
          uVar4 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
          if (uVar13 != 3) {
            *puVar19 = uVar5 | (ushort)((uVar4 & (1 << (3 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f)
                                       );
          }
          uVar4 = uVar4 >> (3 - uVar13 & 0x1f);
          uVar13 = uVar13 + 0x1d;
        }
        else {
          *puVar19 = (ushort)uVar4 & 7;
          uVar4 = uVar4 >> 3;
          uVar13 = uVar13 - 3;
        }
        if ((int)uVar13 < 4) {
          uVar14 = uVar14 + 0x20;
          uVar5 = (ushort)uVar4 & (short)(1 << (uVar13 & 0x1f)) - 1U;
          *puVar20 = uVar5;
          uVar4 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
          if (uVar13 != 3) {
            *puVar20 = uVar5 | (ushort)((uVar4 & (1 << (3 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f)
                                       );
          }
          uVar4 = uVar4 >> (3 - uVar13 & 0x1f);
          uVar13 = uVar13 + 0x1d;
        }
        else {
          *puVar20 = (ushort)uVar4 & 7;
          uVar4 = uVar4 >> 3;
          uVar13 = uVar13 - 3;
        }
        if ((int)uVar13 < 4) {
          uVar14 = uVar14 + 0x20;
          uVar5 = (ushort)uVar4 & (short)(1 << (uVar13 & 0x1f)) - 1U;
          *puVar21 = uVar5;
          uVar4 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
          if (uVar13 != 3) {
            *puVar21 = uVar5 | (ushort)((uVar4 & (1 << (3 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f)
                                       );
          }
          uVar4 = uVar4 >> (3 - uVar13 & 0x1f);
          uVar13 = uVar13 + 0x1d;
        }
        else {
          *puVar21 = (ushort)uVar4 & 7;
          uVar4 = uVar4 >> 3;
          uVar13 = uVar13 - 3;
        }
        if ((int)uVar13 < 4) {
          uVar14 = uVar14 + 0x20;
          uVar5 = (ushort)uVar4 & (short)(1 << (uVar13 & 0x1f)) - 1U;
          *puVar22 = uVar5;
          uVar4 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
          if (uVar13 != 3) {
            *puVar22 = uVar5 | (ushort)((uVar4 & (1 << (3 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f)
                                       );
          }
          uVar4 = uVar4 >> (3 - uVar13 & 0x1f);
          uVar13 = uVar13 + 0x1d;
        }
        else {
          *puVar22 = (ushort)uVar4 & 7;
          uVar4 = uVar4 >> 3;
          uVar13 = uVar13 - 3;
        }
        if ((int)uVar13 < 4) {
          uVar14 = uVar14 + 0x20;
          uVar5 = (ushort)uVar4 & (short)(1 << (uVar13 & 0x1f)) - 1U;
          *puVar23 = uVar5;
          uVar4 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
          if (uVar13 != 3) {
            *puVar23 = uVar5 | (ushort)((uVar4 & (1 << (3 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f)
                                       );
          }
          uVar4 = uVar4 >> (3 - uVar13 & 0x1f);
          uVar13 = uVar13 + 0x1d;
        }
        else {
          *puVar23 = (ushort)uVar4 & 7;
          uVar4 = uVar4 >> 3;
          uVar13 = uVar13 - 3;
        }
        if ((int)uVar13 < 4) {
          uVar14 = uVar14 + 0x20;
          uVar5 = (ushort)uVar4 & (short)(1 << (uVar13 & 0x1f)) - 1U;
          *puVar8 = uVar5;
          uVar4 = *(uint *)(((int)uVar14 >> 5 & 0x3ffU) * 4 + iVar6);
          if (uVar13 != 3) {
            *puVar8 = uVar5 | (ushort)((uVar4 & (1 << (3 - uVar13 & 0x1f)) - 1U) << (uVar13 & 0x1f))
            ;
          }
          uVar4 = uVar4 >> (3 - uVar13 & 0x1f);
          uVar13 = uVar13 + 0x1d;
        }
        else {
          *puVar8 = (ushort)uVar4 & 7;
          uVar4 = uVar4 >> 3;
          uVar13 = uVar13 - 3;
        }
        puVar8 = puVar8 + 0xd;
        puVar23 = puVar23 + 0xd;
        puVar22 = puVar22 + 0xd;
        puVar21 = puVar21 + 0xd;
        puVar20 = puVar20 + 0xd;
        puVar19 = puVar19 + 0xd;
        puVar17 = puVar17 + 0xd;
        puVar15 = puVar15 + 0xd;
        puVar12 = puVar12 + 0xd;
        puVar11 = puVar11 + 0xd;
        puVar10 = puVar10 + 0xd;
        local_2c = local_2c + 0xd;
        puVar9 = puVar9 + 0xd;
        puVar7 = puVar7 + 1;
      } while ((int)puVar8 < (int)(local_3c + 0x34));
      puVar10 = local_120;
      puVar8 = local_110;
      puVar7 = local_118;
      puVar9 = local_108;
      local_34 = &local_130;
      iVar16 = 0;
      *(short *)(param_1 + 0x18a) = *(short *)(param_1 + 0x18a) + -1;
      puVar18 = local_100;
      do {
        uVar5 = *puVar9;
        uVar1 = *puVar7;
        iVar16 = iVar16 + 1;
        puVar9 = puVar9 + 1;
        puVar7 = puVar7 + 1;
        FUN_800b62c0((int)(short)uVar5,(int)(short)uVar1,puVar18,auStack_98);
        uVar5 = *puVar10;
        uVar1 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar10 = puVar10 + 1;
        FUN_800b63b4(param_1,(int)(short)uVar5,(int)(short)uVar1,auStack_98);
        puVar18 = puVar18 + 0x1a;
      } while (iVar16 < 4);
      FUN_800b4dc0(param_1,local_34,param_1,local_44);
      goto LAB_800b6270;
    }
  }
  func_0x80006650(param_2,0x140);
  *(short *)(param_1 + 0x18c) = *(short *)(param_1 + 0x18c) + -1;
LAB_800b6270:
  *(uint *)(param_1 + 0x11c8) = ((uVar14 & 0xffffffe0) + 0x20) - uVar13;
  return 0;
}
