/* FUN_8017cf0c
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017cf0c  body 0x8017cf0c..0x8017e0cb  size 4544 B
 * body sha256 80337ed217588124f428870c785a8fca6cec4d1d3a7667d78b18bf218aa39da3
 * provider record sha256 71d11aac5bfdff9a236fdfe4baa5f27e68ee611b9d256b82c0380272eb26960b
 * callees 26 direct (25 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017cf0c(void)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  char cVar7;
  short sVar6;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  uint uVar14;
  byte bVar15;
  byte unaff_s5;
  uint unaff_s7;
  undefined4 auStack_270 [4];
  char acStack_25e [312];
  char local_126;
  int local_124;
  undefined1 auStack_e0 [72];
  undefined1 auStack_98 [48];
  undefined1 auStack_68 [31];
  char local_49;
  byte local_41;
  byte local_40;
  undefined1 local_3f;
  char local_31;
  byte local_30;
  
  iVar13 = 0;
  uVar14 = 0;
  local_41 = 0;
  osCreateMesgQueue(&DAT_80181f94,&DAT_80181ef4,0x1e);
  DAT_80181fac = _DAT_800e924c;
  func_0x80026910(0xfda);
  local_31 = (_DAT_800e10ec & 0x400) != 0;
  _DAT_800e10ec = _DAT_800e10ec & 0xfffffbff;
  func_0x8004cd88(1);
  FUN_8017e0cc();
  DAT_80180d8f = '\x01';
  DAT_80180d94 = '\0';
  DAT_80180d96 = 0;
LAB_8017cfcc:
  if ((local_31 != '\0') && (iVar4 = FUN_8017b630(), iVar4 != 0)) {
    unaff_s5 = 1;
LAB_8017e00c:
    if ((local_31 == '\0') && ((_DAT_800e10ec & 0x200000) != 0)) {
      uVar14 = 1;
      iVar13 = 0x14;
      goto switchD_8017d2d4_default;
    }
    if (local_31 == '\x01') {
      _DAT_800e10ec = _DAT_800e10ec | 0x400;
    }
    goto LAB_8017e090;
  }
  DAT_80180d95 = 0;
  if (DAT_80180d8f == '\0') {
    if ((_DAT_800df90e & 0x5000) == 0) {
      if (local_49 != '\0') {
        local_49 = local_49 + -1;
        goto LAB_8017d280;
      }
      local_49 = '\x02';
    }
    else {
      local_49 = '\x06';
    }
    if (iVar13 == 2) {
      if ((_DAT_800df90c & 0x1000) != 0) {
        local_41 = 0;
        uVar14 = uVar14 - 1;
        func_0x80077adc(0x4040000,0);
      }
      if ((_DAT_800df90c & 0x4000) != 0) {
        local_41 = 0;
        uVar14 = uVar14 + 1;
        func_0x80077adc(0x4040000,0);
      }
      if ((int)(uVar14 << 0x18) < 0) {
        uVar14 = unaff_s7;
      }
      if ((unaff_s7 & 0xff) < (uVar14 & 0xff)) {
        uVar14 = 0;
      }
    }
    else {
      if (iVar13 == 6) {
        if (((_DAT_800df90c & 0x1000) == 0) || ((uVar14 & 0xff) != 0)) {
LAB_8017d14c:
          if (((_DAT_800df90c & 0x4000) == 0) || ((uVar14 & 0xff) != 4)) goto LAB_8017d1d4;
          if (DAT_80180d8d < 10) {
            iVar13 = 0x11;
            DAT_80180d8d = DAT_80180d8d + 1;
          }
          else {
            if ((_DAT_800df90e & 0x4000) == 0) goto LAB_8017d1d4;
            iVar13 = 0x12;
            uVar14 = 0;
            DAT_80180d8d = 0;
            DAT_80180d8f = '\x01';
          }
        }
        else if (DAT_80180d8d == 0) {
          if ((_DAT_800df90e & 0x1000) == 0) goto LAB_8017d14c;
          iVar13 = 0x12;
          uVar14 = 4;
          DAT_80180d8d = 10;
          DAT_80180d8f = '\x01';
        }
        else {
          iVar13 = 0x10;
          DAT_80180d92 = -0x14;
          DAT_80180d8d = DAT_80180d8d - 1;
        }
      }
      else {
LAB_8017d1d4:
        if (((_DAT_800df90c & 0x1000) != 0) && ((uVar14 & 0xff) != 0)) {
          local_41 = 0;
          uVar14 = uVar14 - 1;
          func_0x80077adc(0x4040000,0);
        }
        if (((_DAT_800df90c & 0x4000) == 0) || ((unaff_s7 & 0xff) <= (uVar14 & 0xff)))
        goto LAB_8017d258;
        uVar14 = uVar14 + 1;
      }
      local_41 = 0;
      func_0x80077adc(0x4040000,0);
    }
LAB_8017d258:
    if (((unaff_s7 & 0xff) != 0) && ((unaff_s7 & 0xff) < (uVar14 & 0xff))) {
      uVar14 = unaff_s7;
    }
  }
LAB_8017d280:
  bVar1 = local_30;
  if ((uVar14 & 0xff) != (uint)local_40) {
    local_41 = 0;
  }
  uVar9 = local_41 + 1 & 0x1f;
  local_41 = (byte)uVar9;
  DAT_80180d79 = (undefined1)(uVar9 >> 4);
  bVar15 = (byte)uVar14;
  DAT_80180ad0 = iVar13;
  local_40 = bVar15;
  switch(iVar13) {
  case 0:
    iVar4 = FUN_8017f3bc();
    if (iVar4 - 1U < 2) {
      iVar13 = 4;
      DAT_80180d78 = (byte)iVar4 & 1;
    }
    else {
      iVar13 = 2;
      if (iVar4 != 3) {
        DAT_80180d8f = '\0';
        uVar14 = 0;
        break;
      }
LAB_8017deec:
      DAT_80180d78 = 0;
LAB_8017def4:
      unaff_s5 = 4;
      iVar13 = 3;
    }
    break;
  case 1:
    unaff_s7 = 1;
    if (((_DAT_800df918 & 0x1000) != 0) || ((_DAT_800df908 & 0x800) != 0)) {
      if ((uVar14 & 0xff) == 1) goto LAB_8017dff8;
      func_0x80077adc(0x4060000,0);
      iVar13 = 0;
      DAT_80180d8f = '\x01';
      uVar14 = 0;
      break;
    }
LAB_8017d3d8:
    if ((_DAT_800df918 & 0x2000) != 0) goto LAB_8017dff8;
    uVar9 = uVar14 & 0xff;
    goto LAB_8017dfd4;
  case 2:
    unaff_s7 = 2;
    if (((_DAT_800df918 & 0x1000) == 0) && ((_DAT_800df908 & 0x800) == 0)) goto LAB_8017d3d8;
    if ((uVar14 & 0xff) == 2) goto LAB_8017dff8;
    func_0x80077adc(0x4060000,0);
    iVar13 = 4;
    DAT_80180d8f = '\x01';
    DAT_80180d78 = bVar15;
    break;
  case 3:
    unaff_s7 = 0;
    uVar14 = 0;
    if (((_DAT_800df918 & 0x3000) != 0) || ((_DAT_800df908 & 0x800) != 0)) {
      func_0x80077adc(0x4050000,0);
      iVar13 = 1;
      DAT_80180d8f = '\0';
      DAT_80180d92 = 0;
      DAT_80180d8d = 0;
      break;
    }
    goto LAB_8017dfd0;
  case 4:
    sVar6 = FUN_8017b4c8(7);
    iVar13 = 5;
    func_0x8004c21c((int)sVar6,0xc0,&DAT_80180458,0x4002);
    func_0x8004cd88(1);
    goto LAB_8017dfd0;
  case 5:
    DAT_80180d8f = '\0';
    DAT_80180ad4 = 1;
    unaff_s7 = 5;
    unaff_s5 = FUN_8017fdbc(DAT_80180d78);
    DAT_80180ad4 = 2;
    if (unaff_s5 == 0) {
      DAT_80180ad4 = 3;
      unaff_s5 = FUN_8017fe54(DAT_80180d78);
      if (unaff_s5 == 0) {
        DAT_80180ad4 = 4;
        unaff_s5 = FUN_8017f210(&DAT_80180d7c);
        DAT_80180ad4 = 5;
        FUN_8017fc34(DAT_80180d78,auStack_270,0,0);
        DAT_80180d98 = local_124;
      }
      DAT_80180ad4 = 6;
      if (unaff_s5 != 1) {
        if (unaff_s5 < 2) {
          if (unaff_s5 == 0) {
            if (local_31 == '\x01') {
              iVar13 = 3;
              unaff_s5 = 3;
            }
            else if ((local_31 == '\0') && (DAT_80180d98 == 0x1e000)) {
              unaff_s5 = 2;
              iVar13 = 3;
            }
            else {
              iVar13 = 6;
              uVar14 = DAT_800e10f8 & 0xf;
              DAT_80180d8d = DAT_800e10f8 >> 4;
            }
            break;
          }
          uVar9 = uVar14 & 0xff;
        }
        else {
          if (unaff_s5 == 2) {
            if (local_31 == '\x01') {
              iVar13 = 3;
              unaff_s5 = 9;
            }
            else {
              uVar14 = 1;
              iVar13 = 0xc;
            }
            break;
          }
          if (unaff_s5 == 3) goto LAB_8017d620;
          uVar9 = uVar14 & 0xff;
        }
        goto LAB_8017dfd4;
      }
      goto LAB_8017def4;
    }
    if (unaff_s5 != 0) {
      if (unaff_s5 < 3) goto LAB_8017def4;
      if (unaff_s5 != 3) goto LAB_8017dfd0;
LAB_8017d620:
      iVar13 = 3;
      unaff_s5 = 1;
    }
    break;
  case 6:
    unaff_s7 = 4;
    DAT_800e10f8 = bVar15 | DAT_80180d8d << 4;
    if (((_DAT_800df918 & 0x1000) == 0) && ((_DAT_800df908 & 0x800) == 0)) {
      if ((_DAT_800df918 & 0x2000) == 0) goto LAB_8017ded8;
      func_0x80077adc(0x4050000,0);
      iVar13 = 0x13;
    }
    else {
      func_0x80077adc(0x4060000,0);
      FUN_8017fc34(DAT_80180d78,auStack_270,0xfeed,0xdeadbeef);
      local_30 = bVar15;
      if (local_126 == '\0') {
        cVar7 = FUN_8017fdbc(DAT_80180d78);
        unaff_s5 = 0;
        if (cVar7 != '\0') goto LAB_8017def4;
      }
      DAT_80180d8f = '\x01';
      iVar13 = 7;
    }
    break;
  case 7:
    uVar14 = (uint)local_30;
    if (local_31 == '\0') {
      func_0x800823b0(auStack_68,(int)auStack_270 + (uVar14 + DAT_80180d8d) * 0x16);
      bVar15 = 0;
      do {
        uVar9 = (uint)bVar15;
        bVar15 = bVar15 + 1;
        *(undefined1 *)((int)auStack_270 + uVar9 + (uVar14 + DAT_80180d8d) * 0x16) = 0;
      } while (bVar15 < 0x16);
      iVar13 = (uVar14 + DAT_80180d8d) * 0x16;
      *(undefined4 *)((int)auStack_270 + iVar13) = 0x1a1b1c1d;
      *(undefined4 *)((int)auStack_270 + iVar13 + 4) = 0x1e1f2021;
      *(undefined4 *)((int)auStack_270 + iVar13 + 8) = 0x22232425;
      *(undefined4 *)((int)auStack_270 + iVar13 + 0xc) = 0x26272829;
      *(undefined4 *)((int)auStack_270 + iVar13 + 0x10) = 0x2a2b1a1a;
      acStack_25e[iVar13 + 2] = '\0';
      iVar13 = (uVar14 + DAT_80180d8d) * 0x16;
      acStack_25e[iVar13] = acStack_25e[iVar13] + (char)((uVar14 + DAT_80180d8d) / 10);
      uVar9 = uVar14 + DAT_80180d8d;
      acStack_25e[uVar9 * 0x16 + 1] =
           acStack_25e[uVar9 * 0x16 + 1] + (char)uVar9 + (char)(uVar9 / 10) * -10;
      acStack_25e[(uVar14 + DAT_80180d8d) * 0x16 + 2] = '\0';
      if ((byte)(&DAT_80180d7c)[uVar14 + DAT_80180d8d] < 0xf) {
        DAT_80180d97 = bVar1;
        uVar14 = 1;
        DAT_80180d8f = '\0';
        iVar13 = 0xf;
      }
      else {
        iVar13 = 8;
        if (DAT_80180d98 == 0x1e000) {
          unaff_s5 = 2;
          DAT_80180d97 = bVar1;
          iVar13 = 0xe;
        }
      }
    }
    else {
      if ((&DAT_80180d7c)[uVar14 + DAT_80180d8d] != '\x0f') {
        sVar6 = FUN_8017b4c8(0x10);
        iVar13 = 10;
        func_0x8004c21c((int)sVar6,0xca,&DAT_801804d1,0x4002);
        goto LAB_8017dfd0;
      }
      unaff_s5 = 3;
      DAT_80180d8f = '\0';
      DAT_80180d97 = local_30;
      iVar13 = 0xe;
    }
    break;
  case 8:
    func_0x80082474(auStack_98,0x800e8ec8,0x2c);
    local_3f = DAT_800e8b49;
    iVar13 = func_0x8008c51c(0x1e);
    iVar13 = iVar13 * 4;
    uVar14 = (uint)local_30;
    cVar7 = *(char *)(iVar13 + -0x7ff17137) + -1;
    *(char *)(iVar13 + -0x7ff17137) = cVar7;
    if (cVar7 == '\0') {
      *(undefined1 *)(iVar13 + -0x7ff17138) = 0;
      *(undefined1 *)(iVar13 + -0x7ff17136) = 0;
      func_0x8008c568();
    }
    _DAT_800e8b50 = _DAT_800e8b50 + 1;
    FUN_8017f61c();
    func_0x80082474(&DAT_8018176c + (uVar14 + DAT_80180d8d) * 0x80,&DAT_800e8b30,0x80);
    FUN_8017f430(auStack_e0,&DAT_800e8930,uVar14 + DAT_80180d8d & 0xff);
    cVar7 = FUN_8017f85c(&DAT_800e8930,DAT_80180d78,
                         (int)auStack_270 + (uVar14 + DAT_80180d8d) * 0x16,0xfeed,0xdeadbeef,
                         auStack_e0,0x800);
    if (cVar7 == '\0') {
      (&DAT_80180d7c)[uVar14 + DAT_80180d8d] = 0;
      DAT_80180d7b = 0xff;
      DAT_80180d8c = 0;
      iVar13 = 9;
      DAT_80180d7a = 5;
      unaff_s5 = 0;
      goto switchD_8017d2d4_caseD_9;
    }
    unaff_s5 = 5;
    _DAT_800e8b50 = _DAT_800e8b50 + -1;
    func_0x80082474(0x800e8ec8,auStack_98,0x2c);
    DAT_800e8b49 = local_3f;
    DAT_80180d8f = '\0';
    iVar13 = 3;
    break;
  case 9:
switchD_8017d2d4_caseD_9:
    DAT_80180d7a = DAT_80180d7a - 1;
    if (DAT_80180d7a == 0) {
      DAT_80180d7b = DAT_80180d7b + 1;
      if (-1 < (int)((uint)DAT_80180d7b << 0x18)) {
        DAT_80180d8c = DAT_80180d8c + 1;
        DAT_80180d7a = (byte)(&DAT_8018074c)[DAT_80180d8c] >> 1;
        goto LAB_8017dfd0;
      }
      goto LAB_8017e090;
    }
    goto LAB_8017dfd0;
  case 10:
    iVar13 = 0xb;
    break;
  case 0xb:
    uVar14 = (uint)local_30;
    cVar7 = FUN_8017facc(&DAT_80180f6c,
                         &DAT_80180da4 + (uint)(byte)(&DAT_80180d7c)[uVar14 + DAT_80180d8d] * 0x16,
                         0xfeed,0xdeadbeef,0x800,0);
    unaff_s5 = 6;
    if (cVar7 == '\0') {
      puVar2 = (undefined4 *)&DAT_800e8930;
      puVar3 = &DAT_80180f6c;
      do {
        puVar8 = puVar3;
        puVar5 = puVar2;
        uVar10 = puVar8[1];
        uVar11 = puVar8[2];
        uVar12 = puVar8[3];
        *puVar5 = *puVar8;
        puVar5[1] = uVar10;
        puVar5[2] = uVar11;
        puVar5[3] = uVar12;
        puVar2 = puVar5 + 4;
        puVar3 = puVar8 + 4;
      } while (puVar8 + 4 != (undefined4 *)&UNK_8018164c);
      uVar10 = puVar8[5];
      uVar11 = puVar8[6];
      puVar5[4] = 0;
      puVar5[5] = uVar10;
      puVar5[6] = uVar11;
      if (DAT_800e8b3a - 0xc < 2) {
        uVar14 = _DAT_800e10ec & 0xfffffffe;
        _DAT_800e10ec = uVar14 | 8;
        unaff_s5 = 1;
        if (DAT_800e8b3a == 0xd) {
          _DAT_800e10ec = uVar14 | 9;
        }
        goto LAB_8017e00c;
      }
      FUN_8017f770();
LAB_8017e090:
      FUN_8017e248(local_31);
      return;
    }
    DAT_80180d97 = bVar1;
    DAT_80180d8f = '\0';
    iVar13 = 0xe;
    break;
  case 0xc:
    unaff_s7 = 1;
    if (((_DAT_800df918 & 0x1000) == 0) && ((_DAT_800df908 & 0x800) == 0)) {
      if ((_DAT_800df918 & 0x2000) != 0) {
        func_0x80077adc(0x4050000,0);
        iVar13 = 0;
        DAT_80180d8f = '\x01';
        uVar14 = 0;
      }
      goto LAB_8017ded8;
    }
    if ((uVar14 & 0xff) == 0) {
      func_0x80077adc(0x4060000,0);
      iVar13 = 0xd;
    }
    else {
      func_0x80077adc(0x4050000,0);
      uVar14 = 0;
      iVar13 = 1;
    }
    break;
  case 0xd:
    cVar7 = FUN_8017fdbc(DAT_80180d78);
    if (cVar7 == '\0') {
      cVar7 = FUN_8017fe54(DAT_80180d78);
      if ((cVar7 == '\x02') && (iVar13 = FUN_8017feb8(DAT_80180d78), iVar13 == 0)) {
        DAT_800e10f8 = 0;
        DAT_80180d8f = '\x01';
        unaff_s5 = 2;
        iVar13 = 4;
      }
      else {
        unaff_s5 = 0;
        iVar13 = 3;
      }
    }
    else {
      unaff_s5 = (cVar7 == '\x01') << 2;
      uVar14 = 0;
      iVar13 = 3;
    }
    break;
  case 0xe:
    uVar14 = 0;
    if (((_DAT_800df918 & 0x3000) != 0) || ((_DAT_800df908 & 0x800) != 0)) {
      DAT_80180d8f = '\0';
      func_0x80077adc(0x4040000,0);
      iVar13 = 6;
      if (unaff_s5 == 2) {
        iVar13 = 1;
        DAT_80180d92 = 0;
        DAT_80180d8d = 0;
      }
      else {
        uVar14 = (uint)DAT_80180d97;
      }
    }
    sVar6 = FUN_8017b4c8(unaff_s5 + 0x14);
    func_0x8004c21c((int)sVar6,0xc4,&DAT_801803f0 + (ushort)(&DAT_801806dc)[unaff_s5 + 0x14],0x4012)
    ;
    unaff_s7 = uVar14;
LAB_8017ded8:
    iVar4 = FUN_8017f3b4(DAT_80180d78);
    if (iVar4 != 0) goto LAB_8017deec;
    goto LAB_8017dfd0;
  case 0xf:
    if (((_DAT_800df918 & 0x1000) == 0) && ((_DAT_800df908 & 0x800) == 0)) {
      unaff_s7 = 1;
      if ((_DAT_800df918 & 0x2000) != 0) {
        func_0x80077adc(0x4050000,0);
        uVar14 = (uint)DAT_80180d97;
        iVar13 = 6;
        unaff_s7 = uVar14;
      }
      goto LAB_8017ded8;
    }
    if ((uVar14 & 0xff) == 0) {
      func_0x80077adc(0x4060000,0);
      iVar13 = 8;
      local_41 = 0;
      DAT_80180d8f = '\x01';
    }
    else {
      func_0x80077adc(0x4050000,0);
      iVar13 = 6;
    }
    uVar14 = (uint)DAT_80180d97;
    unaff_s7 = uVar14;
    break;
  case 0x10:
    if (DAT_80180d92 == -0x14) {
      iVar13 = 6;
      DAT_80180d92 = DAT_80180d92 + 0x14;
      break;
    }
    DAT_80180d92 = DAT_80180d92 + 0x14;
    goto LAB_8017dfd0;
  case 0x11:
    DAT_80180d92 = DAT_80180d92 + -0x14;
    if (DAT_80180d92 == -0x14) {
      DAT_80180d92 = 0;
      iVar13 = 6;
      break;
    }
    goto LAB_8017dfd0;
  case 0x12:
    DAT_80180d8f = '\0';
    iVar13 = 6;
    break;
  case 0x13:
    iVar13 = FUN_8017fdbc(DAT_80180d78 ^ 1);
    uVar14 = 0;
    if (iVar13 != 0) {
      DAT_80180d94 = '\x01';
LAB_8017dff8:
      if (DAT_80180d94 == '\0') {
        func_0x80077adc(0x4050000,0);
      }
      goto LAB_8017e00c;
    }
    iVar13 = 0;
    break;
  case 0x14:
    if ((_DAT_800df918 & 0x1000) != 0) {
      uVar9 = uVar14 & 0xff;
      uVar14 = 0;
      if (uVar9 == 0) {
        func_0x80077adc(0x4050000,0);
        goto LAB_8017e090;
      }
      func_0x80077adc(0x4060000,0);
      iVar13 = 0;
    }
    unaff_s7 = 1;
    if ((_DAT_800df918 & 0x2000) != 0) {
      func_0x80077adc(0x4060000,0);
      iVar13 = 0;
    }
  }
switchD_8017d2d4_default:
LAB_8017dfd0:
  uVar9 = uVar14 & 0xff;
LAB_8017dfd4:
  FUN_8017e31c(iVar13,local_31,uVar9,unaff_s5);
  DAT_80180d96 = 0;
  func_0x8004cd88(1);
  goto LAB_8017cfcc;
}
