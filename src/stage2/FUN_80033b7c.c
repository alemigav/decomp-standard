/* FUN_80033b7c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80033b7c  body 0x80033b7c..0x800341db  size 1632 B
 * body sha256 18ba5c4eaed4a18c6d6ba41d12026834f70f124ba179e1e8bfae18a755a3f60a
 * provider record sha256 5d24051043176f813e040537ccc4c3ff5732e5ea020b4365c57ed03344ca44b9
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80033b7c(void)

{
  byte bVar1;
  short sVar2;
  uint *puVar3;
  undefined4 *puVar4;
  uint *puVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  byte bVar10;
  uint uVar11;
  byte bVar12;
  byte bVar13;
  byte *pbVar14;
  uint *puVar15;
  short *psVar16;
  uint uVar17;
  int iVar18;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  int local_6c;
  int local_68;
  int local_64;
  undefined4 local_60;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  puVar5 = DAT_800df8b4;
  if (((DAT_800e1130 & 0x80000) == 0) || ((DAT_800e10ec & 0x100) != 0)) {
    uVar17 = 0x80136d90;
    psVar16 = (short *)0x80137a10;
    local_30 = DAT_800df940;
    puVar3 = DAT_800df8b4 + 2;
    *DAT_800df8b4 = 0xe7000000;
    DAT_800df8b4 = puVar3;
    puVar5[1] = 0;
    puVar6 = (undefined4 *)FUN_80042af4(DAT_800df8b4);
    DAT_800df8b4 = puVar6 + 2;
    *puVar6 = 0xd9fdffff;
    puVar6[1] = 0;
    puVar6 = DAT_800df8b4;
    puVar4 = DAT_800df8b4 + 2;
    *DAT_800df8b4 = 0xe2001d00;
    DAT_800df8b4 = puVar4;
    puVar6[1] = 0;
    puVar6 = DAT_800df8b4;
    puVar4 = DAT_800df8b4 + 2;
    *DAT_800df8b4 = 0xd7000002;
    DAT_800df8b4 = puVar4;
    puVar6[1] = 0x80008000;
    puVar6 = DAT_800df8b4;
    puVar4 = DAT_800df8b4 + 2;
    *DAT_800df8b4 = 0xe200001c;
    DAT_800df8b4 = puVar4;
    puVar6[1] = 0x504a50;
    puVar6 = DAT_800df8b4;
    puVar4 = DAT_800df8b4 + 2;
    *DAT_800df8b4 = 0xfc119623;
    DAT_800df8b4 = puVar4;
    puVar6[1] = 0xff2fffff;
    puVar6 = DAT_800df8b4;
    puVar4 = DAT_800df8b4 + 2;
    *DAT_800df8b4 = 0xe3001001;
    DAT_800df8b4 = puVar4;
    puVar6[1] = 0;
    puVar6 = DAT_800df8b4;
    puVar4 = DAT_800df8b4 + 2;
    *DAT_800df8b4 = 0xfd900000;
    DAT_800df8b4 = puVar4;
    puVar6[1] = DAT_800eb974;
    puVar6 = DAT_800df8b4;
    puVar4 = DAT_800df8b4 + 2;
    *DAT_800df8b4 = 0xf5900000;
    DAT_800df8b4 = puVar4;
    puVar6[1] = 0x7080200;
    puVar6 = DAT_800df8b4;
    puVar4 = DAT_800df8b4 + 2;
    *DAT_800df8b4 = 0xe6000000;
    DAT_800df8b4 = puVar4;
    puVar6[1] = 0;
    puVar6 = DAT_800df8b4;
    iVar18 = 0x32;
    puVar4 = DAT_800df8b4 + 2;
    *DAT_800df8b4 = 0xf3000000;
    DAT_800df8b4 = puVar4;
    uVar9 = DAT_800eb964 >> 3;
    uVar11 = 0x800;
    if (uVar9 != 0) {
      uVar11 = uVar9 + 0x7ff;
    }
    uVar8 = (DAT_800eb964 * DAT_800eb968 + 1 >> 1) - 1;
    if (0x7ff < uVar8) {
      uVar8 = 0x7ff;
    }
    if ((uVar9 != 0) && (uVar11 = uVar11 / uVar9, uVar9 == 0)) {
      trap(0x1c00);
    }
    puVar6[1] = (uVar8 & 0xfff) << 0xc | 0x7000000 | uVar11 & 0xfff;
    puVar6 = DAT_800df8b4;
    pbVar14 = (byte *)&DAT_800dfc2c;
    puVar5 = DAT_800df8b4 + 2;
    *DAT_800df8b4 = 0xe7000000;
    DAT_800df8b4 = puVar5;
    puVar6[1] = 0;
    puVar5 = DAT_800df8b4;
    puVar3 = DAT_800df8b4 + 2;
    *DAT_800df8b4 = (DAT_800eb964 + 7 >> 3 & 0x1ff) << 9 | 0xf5880000;
    DAT_800df8b4 = puVar3;
    puVar5[1] = 0x80200;
    puVar5 = DAT_800df8b4;
    puVar15 = (uint *)0x80137a4c;
    puVar3 = DAT_800df8b4 + 2;
    *DAT_800df8b4 = 0xf2000000;
    DAT_800df8b4 = puVar3;
    puVar5[1] = ((DAT_800eb964 - 1) * 4 & 0xfff) << 0xc | (DAT_800eb968 + -1) * 4 & 0xfffU;
    do {
      if (((pbVar14[-10] & 4) != 0) && ((pbVar14[-10] & 8) == 0)) {
        local_80 = 0x10000000;
        local_7c = 0;
        local_78 = 0x10000000;
        local_74 = 0;
        local_70 = 0x10000000;
        local_6c = 0;
        local_68 = 0;
        local_64 = 0;
        FUN_80041320(0,&local_80);
        FUN_80041454(0,&local_80);
        FUN_80041588(0,&local_80);
        FUN_80041454((int)*(short *)(pbVar14 + -8),&local_80);
        local_6c = (int)*(short *)(pbVar14 + -0x10);
        local_68 = *(short *)(pbVar14 + -0xe) + -6;
        local_64 = (int)*(short *)(pbVar14 + -0xc);
        sVar2 = *(short *)(pbVar14 + -0x14);
        *psVar16 = -sVar2;
        *(short *)(puVar15 + -0xb) = sVar2;
        *(short *)(puVar15 + -7) = sVar2;
        *(short *)(puVar15 + -3) = -sVar2;
        *(short *)(puVar15 + -0xe) = -*(short *)(pbVar14 + -0x12);
        *(short *)(puVar15 + -10) = -*(short *)(pbVar14 + -0x12);
        *(undefined2 *)(puVar15 + -6) = *(undefined2 *)(pbVar14 + -0x12);
        *(undefined2 *)(puVar15 + -2) = *(undefined2 *)(pbVar14 + -0x12);
        puVar5 = DAT_800df8b4;
        if (pbVar14[3] == 0) {
          bVar10 = *pbVar14;
          if (bVar10 < 0xc1) {
            bVar13 = 0x80 - bVar10;
            if (0x80 < bVar10) {
              bVar13 = 0xc0 - bVar10;
            }
          }
          else {
            bVar13 = 0xff - bVar10;
          }
          bVar10 = pbVar14[1];
          if (bVar10 < 0xc1) {
            bVar12 = 0x80 - bVar10;
            if (0x80 < bVar10) {
              bVar12 = 0xc0 - bVar10;
            }
          }
          else {
            bVar12 = 0xff - bVar10;
          }
          bVar1 = pbVar14[2];
          if (bVar1 < 0xc1) {
            bVar10 = 0x80 - bVar1;
            if (0x80 < bVar1) {
              bVar10 = 0xc0 - bVar1;
            }
          }
          else {
            bVar10 = 0xff - bVar1;
          }
        }
        else {
          bVar13 = -*pbVar14 - 0x38;
          bVar10 = -pbVar14[2] - 0x38;
          bVar12 = -pbVar14[1] - 0x38;
        }
        uVar11 = (uint)bVar13 << 0x18 | (uint)bVar12 << 0x10 | (uint)bVar10 << 8;
        uVar9 = uVar11 | 0xff;
        if (pbVar14[3] == 0) {
          puVar3 = DAT_800df8b4 + 2;
          *DAT_800df8b4 = 0xfa000000;
          DAT_800df8b4 = puVar3;
          uVar11 = uVar11 | 0x80;
        }
        else {
          puVar3 = DAT_800df8b4 + 2;
          *DAT_800df8b4 = 0xfa000000;
          DAT_800df8b4 = puVar3;
          uVar11 = uVar11 | *pbVar14;
        }
        puVar5[1] = uVar11;
        puVar15[-0xc] = uVar9;
        puVar15[-8] = uVar9;
        puVar15[-4] = uVar9;
        *puVar15 = uVar9;
        local_34 = local_60;
        local_40 = local_6c;
        local_3c = local_68;
        local_38 = local_64;
        iVar7 = FUN_80083d2c(&local_40,local_30);
        if (iVar7 != 0) {
          FUN_800411b8(&local_80,uVar17);
          puVar5 = DAT_800df8b4;
          puVar3 = DAT_800df8b4 + 2;
          *DAT_800df8b4 = 0xda380003;
          DAT_800df8b4 = puVar3;
          puVar5[1] = uVar17;
          puVar5 = DAT_800df8b4;
          puVar3 = DAT_800df8b4 + 2;
          *DAT_800df8b4 = 0x1004008;
          DAT_800df8b4 = puVar3;
          puVar5[1] = (uint)psVar16;
          puVar5 = DAT_800df8b4;
          puVar3 = DAT_800df8b4 + 2;
          *DAT_800df8b4 = 0x7000204;
          DAT_800df8b4 = puVar3;
          puVar5[1] = 0x406;
        }
      }
      uVar17 = uVar17 + 0x40;
      psVar16 = psVar16 + 0x20;
      puVar15 = puVar15 + 0x10;
      pbVar14 = pbVar14 + 0x68;
      iVar18 = iVar18 + -1;
    } while (iVar18 != 0);
  }
  return;
}
