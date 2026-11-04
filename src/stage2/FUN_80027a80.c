/* FUN_80027a80
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80027a80  body 0x80027a80..0x800282e7  size 2152 B
 * body sha256 563bdb8c92a1c3dfbeca96b4f72f5316c940f2869409f8a9b69620c36a6d0b29
 * provider record sha256 9bb834597fa647de8d3a28cb103a46ba25669ea32a5d67128c4b7da79ec427bc
 * callees 17 direct (17 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80027a80(void)

{
  int iVar1;
  undefined1 *puVar2;
  float *pfVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  undefined1 uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  float fVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  ulonglong uVar17;
  float fVar18;
  float fVar19;
  undefined8 uVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  undefined1 auStack_c8 [6];
  ushort local_c2;
  ushort local_be;
  ushort local_a8;
  ushort local_a6;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  float local_80 [9];
  float local_5c;
  float local_58;
  
  FUN_800274e4(0,0);
  DAT_800e923f = 1;
  iVar1 = FUN_8004d138(DAT_8010b6d0,0);
  if (iVar1 == 0) {
    uVar12 = 0;
    uVar20 = 0x3c887a8d;
    uVar16 = 0x3f000000;
    uVar15 = 0x3f800000;
    do {
      uVar12 = (ulonglong)(uint)((float)uVar12 + (float)uVar20);
      FUN_800274e4(2,0);
      if ((float)uVar12 < (float)uVar16) {
        FUN_8004a7c8(0x69,0x6e,2,0x4000,"No Controller");
      }
      else if ((float)uVar12 < (float)uVar15) {
        FUN_8004a7a0(0x73,0x6e,2,0x4000,"No Controller");
      }
      else {
        uVar12 = 0;
      }
      FUN_8004afbc();
      FUN_8004cd88(1);
    } while( true );
  }
  FUN_800274e4(0,0);
  DAT_800e923f = 1;
  FUN_80026910(0xfdb);
  FUN_800274f8(0x200,0xfffffc00,7,0);
  while( true ) {
    iVar1 = FUN_8002767c(0);
    uVar5 = 0;
    if (iVar1 != 0) break;
    FUN_8004cd88(1);
  }
  do {
    FUN_8004cd88(1);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x50);
  FUN_800274f8(0x200,0x400,7,0);
  while (iVar1 = FUN_8002767c(0), iVar1 == 0) {
    FUN_8004cd88(1);
  }
  FUN_800274e4(2,0);
  DAT_800e923f = 0;
  puVar2 = (undefined1 *)FUN_800479c8(DAT_800c52d8 + 0x52c38,auStack_c8,0x15d8,0);
  FUN_80043620();
  puVar2[2] = 0xff;
  puVar2[1] = 0xff;
  *puVar2 = 0xff;
  puVar2[3] = 4;
  *(undefined2 *)(puVar2 + 0x12) = 0;
  *(undefined2 *)(puVar2 + 10) = 0;
  *(undefined2 *)(puVar2 + 0x22) = 0;
  *(undefined2 *)(puVar2 + 0x1a) = 0;
  *(undefined1 **)(puVar2 + 0x24) = auStack_c8;
  uVar7 = (uint)local_c2;
  fVar8 = (float)(int)(0x140 - uVar7) * 0.5;
  uVar5 = (uint)local_be;
  if (fVar8 < 2.1474836e+09) {
    local_a8 = (ushort)(int)fVar8;
  }
  else {
    local_a8 = (ushort)(int)(fVar8 - 2.1474836e+09);
  }
  fVar8 = (float)(int)(0xf0 - uVar5) * 0.5;
  if (fVar8 < 2.1474836e+09) {
    local_a6 = (ushort)(int)fVar8;
  }
  else {
    local_a6 = (ushort)(int)(fVar8 - 2.1474836e+09);
  }
  FUN_8004794c(puVar2,0,0,*(short *)(*(int *)(puVar2 + 0x24) + 6) + -1,0,0,
               *(short *)(*(int *)(puVar2 + 0x24) + 10) + -1,
               *(short *)(*(int *)(puVar2 + 0x24) + 6) + -1,
               *(short *)(*(int *)(puVar2 + 0x24) + 10) + -1);
  uVar4 = (uint)local_a8;
  FUN_800478dc(puVar2,uVar4,local_a6,uVar4 + uVar7 & 0xffff,local_a6,uVar4,local_a6 + uVar5 & 0xffff
               ,local_a8 + uVar7 & 0xffff,local_a6 + uVar5 & 0xffff);
  local_a0 = *(undefined4 *)(puVar2 + 4);
  local_9c = *(undefined4 *)(puVar2 + 0xc);
  local_98 = *(undefined4 *)(puVar2 + 0x14);
  local_94 = *(undefined4 *)(puVar2 + 0x1c);
  local_90 = local_a0;
  local_8c = local_9c;
  local_88 = local_98;
  local_84 = local_94;
  FUN_800274f8(0x200,0xfffffc00,7,0);
  while( true ) {
    iVar1 = FUN_8002767c(0);
    if (iVar1 != 0) break;
    FUN_8004cd88(1);
  }
  DAT_800e9241 = 0;
  FUN_80082200(local_80,0,0x28);
  iVar1 = 1;
  uVar17 = 0;
  uVar12 = 0;
  uVar22 = 0;
  uVar21 = 0;
  local_58 = 255.0;
  do {
    fVar8 = (float)uVar12;
    if (iVar1 == 0) {
      FUN_800274e4(0,0);
      DAT_800e923f = 1;
      FUN_80026910(0x14b9);
      FUN_800274f8(0x200,0xfffffc00,7,0);
      while( true ) {
        iVar1 = FUN_8002767c(0);
        uVar5 = 0;
        if (iVar1 != 0) break;
        FUN_8004cd88(1);
      }
      do {
        FUN_8004cd88(1);
        uVar5 = uVar5 + 1;
      } while (uVar5 < 0x50);
      DAT_800e9241 = '\x01';
      do {
        FUN_8004cd88(1);
      } while (DAT_800e9241 != '\x02');
      FUN_800274f8(0x200,0x400,7,0);
      while (iVar1 = FUN_8002767c(0), iVar1 == 0) {
        FUN_8004cd88(1);
      }
      FUN_800274e4(2,0);
      DAT_800e923f = 0;
      DAT_800e9241 = 0;
      FUN_8004cdd4();
      return;
    }
    if (iVar1 == 1) {
      if (2.0 < fVar8) {
        iVar1 = 2;
      }
      DAT_800df8b4 = FUN_80044fdc(DAT_800df8b4,puVar2,0);
    }
    else if (iVar1 == 2) {
      fVar9 = 1.0;
      fVar18 = (float)uVar17;
      if (fVar8 - 2.0 <= 0.6) {
        fVar9 = (fVar8 - 2.0) / 0.6;
      }
      uVar17 = (ulonglong)(uint)(fVar18 + fVar9 * 0.5235988 + (float)uVar21);
      FUN_800274e4(2,0);
      fVar8 = (float)uVar12;
      fVar9 = (float)uVar21;
      uVar13 = uVar21 & 0xffffffff;
      if (2.0 < fVar8) {
        local_58 = ((4.65 - fVar8) * 255.0) / 2.65;
      }
      iVar6 = 0;
      pfVar3 = local_80;
      do {
        fVar14 = (float)uVar13 + 1.0;
        uVar13 = (ulonglong)(uint)fVar14;
        fVar19 = (float)uVar17;
        if (*pfVar3 == fVar9) {
          *pfVar3 = fVar19;
          break;
        }
        iVar6 = iVar6 + 1;
        pfVar3 = pfVar3 + 1;
      } while (iVar6 < 10);
      iVar6 = 0;
      if (fVar14 == 10.0) {
        uVar22 = (ulonglong)(uint)local_80[0];
        local_5c = fVar19;
      }
      pfVar3 = local_80;
      for (; (float)iVar6 < fVar14 - 1.0; iVar6 = iVar6 + 1) {
        fVar10 = ((fVar14 - 1.0) - (float)iVar6) / fVar14;
        if (fVar10 < fVar9) {
          fVar10 = fVar9;
        }
        *pfVar3 = fVar19 - (fVar19 - fVar18) * fVar10 * (fVar8 / 4.65) * 6.5;
        pfVar3 = pfVar3 + 1;
      }
      iVar6 = 0;
      pfVar3 = local_80;
      do {
        if (*pfVar3 != (float)uVar21) {
          FUN_80027930(puVar2,&local_a0,*pfVar3);
          fVar8 = ((float)(iVar6 + 1) / (float)uVar13) * local_58;
          if (fVar8 < 2.1474836e+09) {
            uVar11 = (undefined1)(int)fVar8;
          }
          else {
            uVar11 = (undefined1)(int)(fVar8 - 2.1474836e+09);
          }
          puVar2[2] = uVar11;
          DAT_800df8b4 = FUN_80044fdc(DAT_800df8b4,puVar2,0);
        }
        fVar8 = (float)uVar22;
        if (fVar8 != (float)uVar21) {
          uVar22 = uVar21 & 0xffffffff;
          FUN_80027930(puVar2,&local_a0,fVar8);
          puVar2[2] = 0;
          DAT_800df8b4 = FUN_80044fdc(DAT_800df8b4,puVar2,0);
        }
        fVar8 = (float)uVar12;
        iVar6 = iVar6 + 1;
        pfVar3 = pfVar3 + 1;
      } while (iVar6 < 10);
      if (4.6167 < fVar8) {
        iVar1 = 0;
      }
    }
    uVar12 = (ulonglong)(uint)(fVar8 + 0.016666);
    FUN_8004cd88(1);
  } while( true );
}
