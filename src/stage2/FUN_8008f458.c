/* FUN_8008f458
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008f458  body 0x8008f458..0x8009052f  size 160 B
 * body sha256 4cdbd7805b55f484cefcf2ff8220dc1fd2fa0626d6d4f99138b6e87deebd5176
 * provider record sha256 2d228f0f32d0664fcda6b4b515a1e466ad60ee0ecb02ece58fee98769fd62b97
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8008f894) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8008f458(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  byte bVar7;
  ushort uVar6;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  bool bVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  int iVar14;
  int iVar15;
  
  bVar7 = DAT_8012bfaa;
  DAT_8012bfae = 0;
  switch(DAT_8012bf9a) {
  case '\0':
    FUN_8006c070(0);
    iVar14 = 4;
    iVar15 = 0x28;
    FUN_80085398(DAT_800c52dc + 0x44800,DAT_800c52dc + 0x53e18,0);
    uVar5 = DAT_800c52dc + 0x44807U & 0xfffffff8;
    _DAT_8013a384 = uVar5;
    iVar10 = func_0x80004cfc(0x1f5e,uVar5,0,"FILEM");
    _DAT_8013a384 = _DAT_8013a384 + iVar10 + 7 & 0xfffffff8;
    FUN_800824b8(uVar5);
    puVar12 = (undefined4 *)&DAT_8012f948;
    puVar13 = &DAT_8012dfe4;
    iVar10 = 0x2a80;
    do {
      uVar2 = _DAT_8013a384;
      iVar15 = iVar15 + -10;
      puVar12 = puVar12 + -1;
      iVar14 = iVar14 + -1;
      *(undefined4 *)(&DAT_8012b62c + iVar10) = 0xffffffff;
      *(uint *)(&UNK_8012b614 + iVar10) = uVar5;
      *(undefined2 *)(&UNK_8012b5b6 + iVar10) = 0xc00;
      *(undefined4 **)(&UNK_8012b5c0 + iVar10) = &DAT_800e9028;
      *(undefined4 *)(&UNK_8012b578 + iVar10) = 0;
      *(undefined2 *)(&UNK_8012b584 + iVar10) = 0;
      *(undefined4 *)(&UNK_8012b57c + iVar10) = 0;
      *(undefined2 *)(&UNK_8012b586 + iVar10) = 0;
      *(undefined4 *)(&UNK_8012b580 + iVar10) = 0;
      *(undefined2 *)(&UNK_8012b588 + iVar10) = 0;
      *(undefined2 *)(&UNK_8012b5b4 + iVar10) = 0;
      *(undefined2 *)(&UNK_8012b5b8 + iVar10) = 0;
      *(undefined4 *)(&UNK_8012b5bc + iVar10) = 0x808080;
      *(undefined4 *)(&UNK_8012b564 + iVar10) = 0x10000000;
      *(undefined4 *)(&UNK_8012b568 + iVar10) = 0;
      *(undefined4 *)(&UNK_8012b56c + iVar10) = 0x10000000;
      *(undefined4 *)(&DAT_8012b570 + iVar10) = 0;
      *(undefined4 *)(&UNK_8012b574 + iVar10) = 0x10000000;
      *(undefined4 *)(&UNK_8012b578 + iVar10) = 0;
      *(undefined4 *)(&UNK_8012b57c + iVar10) = 0;
      *(undefined4 *)(&UNK_8012b580 + iVar10) = 0;
      _DAT_8013a384 =
           FUN_800874d4(uVar2,&UNK_8012b608 + iVar10,&DAT_8012b60c + iVar10,*puVar12,
                        &UNK_8012b5c8 + iVar10);
      iVar8 = 8;
      if (iVar14 == 3) {
        iVar8 = 0x10;
      }
      do {
        iVar8 = iVar8 + -1;
        iVar3 = (iVar15 + iVar8) * 0x110;
        *(undefined4 *)(&UNK_8012c1dc + iVar3) = 0xffffffff;
        *(undefined4 *)(&UNK_8012c128 + iVar3) = 0;
        *(undefined2 *)(&UNK_8012c134 + iVar3) = 0;
        *(undefined2 *)(&UNK_8012c164 + iVar3) = 0;
        *(undefined4 *)(&UNK_8012c12c + iVar3) = 0;
        *(undefined2 *)(&UNK_8012c136 + iVar3) = 0;
        *(undefined2 *)(&UNK_8012c166 + iVar3) = 0;
        *(undefined4 *)(&UNK_8012c130 + iVar3) = 0;
        *(undefined2 *)(&UNK_8012c138 + iVar3) = 0;
        *(undefined2 *)(&UNK_8012c168 + iVar3) = 0;
        *(undefined4 **)(&UNK_8012c170 + iVar3) = puVar13;
        *(undefined4 *)(&UNK_8012c16c + iVar3) = 0x808080;
        *(undefined4 *)(&UNK_8012c114 + iVar3) = 0x10000000;
        *(undefined4 *)(&UNK_8012c118 + iVar3) = 0;
        *(undefined4 *)(&UNK_8012c11c + iVar3) = 0x10000000;
        *(undefined4 *)(&UNK_8012c120 + iVar3) = 0;
        *(undefined4 *)(&UNK_8012c124 + iVar3) = 0x10000000;
        *(undefined4 *)(&UNK_8012c128 + iVar3) = 0;
        *(undefined4 *)(&UNK_8012c12c + iVar3) = 0;
        *(undefined4 *)(&UNK_8012c130 + iVar3) = 0;
      } while (iVar8 != 0);
      puVar13 = puVar13 + -0x2a8;
      iVar10 = iVar10 + -0xaa0;
    } while (iVar14 != 0);
    DAT_8012f930 = _DAT_8013a384;
    iVar10 = func_0x80004cfc(0x1f5a,_DAT_8013a384,0,&DAT_800b9fd8);
    _DAT_8013a384 = _DAT_8013a384 + iVar10 + 7 & 0xfffffff8;
    FUN_800824b8(DAT_8012f930);
    **(undefined1 **)(*(int *)(*(int *)(DAT_8012f930 + 8) + 4) + 8) = 0xb0;
    *(undefined1 *)(*(int *)(*(int *)(*(int *)(DAT_8012f930 + 8) + 4) + 8) + 1) = 200;
    *(undefined1 *)(*(int *)(*(int *)(*(int *)(DAT_8012f930 + 8) + 4) + 8) + 2) = 0x78;
    *(undefined1 *)(*(int *)(*(int *)(*(int *)(DAT_8012f930 + 8) + 4) + 8) + 3) = 0;
    DAT_8012f934 = _DAT_8013a384;
    iVar10 = func_0x80004cfc(0x1f5a,_DAT_8013a384,0,&DAT_800b9fd8);
    _DAT_8013a384 = _DAT_8013a384 + iVar10 + 7 & 0xfffffff8;
    FUN_800824b8(DAT_8012f934);
    **(undefined1 **)(*(int *)(*(int *)(DAT_8012f934 + 8) + 4) + 8) = 0;
    *(undefined1 *)(*(int *)(*(int *)(*(int *)(DAT_8012f934 + 8) + 4) + 8) + 1) = 0;
    *(undefined1 *)(*(int *)(*(int *)(*(int *)(DAT_8012f934 + 8) + 4) + 8) + 2) = 0;
    *(undefined1 *)(*(int *)(*(int *)(*(int *)(DAT_8012f934 + 8) + 4) + 8) + 3) = 0;
    FUN_80096e74(1);
    FUN_80098a04(_DAT_8013a384);
    DAT_8012bfa9 = 0;
    DAT_8012bfe6 = 0x11e;
                    /* WARNING: Read-only address (ram,0x8012bfc8) is written */
    DAT_8012bfc8 = 0x400;
    DAT_8012bfaa = 0;
                    /* WARNING: Read-only address (ram,0x8012bfc6) is written */
    DAT_8012bfc6 = 0;
    if (DAT_800e8ff4 == -1) {
      FUN_80090584(0);
    }
    else {
      DAT_8012bfaa = 0;
    }
    FUN_80082d10(&DAT_8012fa70,&DAT_8012fa7c);
    DAT_8012bf9a = '\x01';
    DAT_8012bf9b = 0;
  case '\x01':
    bVar11 = 0xb < DAT_8012bf9b;
    DAT_8012bf9b = DAT_8012bf9b + 1;
    if (bVar11) {
      DAT_8012bf9a = '\x03';
      DAT_8012bf9b = 0;
    }
    DAT_8012bfd2 = DAT_8012bfd2 + (DAT_8012bf9b + 1) * 2;
    DAT_8012bfe6 = DAT_8012bfe6 + (DAT_8012bf9b + 2) * -2;
    DAT_8012bfd8 = DAT_8012bfd8 + -6;
    goto LAB_8008fc8c;
  case '\x02':
    if (0xb < DAT_8012bf9b) {
      DAT_8012bf99 = 6;
      DAT_8012bf9a = '\0';
    }
    DAT_8012bfd2 = DAT_8012bfd2 + -0xe;
    DAT_8012bfd8 = DAT_8012bfd8 + 6;
    DAT_8012bfe6 = DAT_8012bfe6 + 0xd;
    DAT_8012bf9b = DAT_8012bf9b + 1;
    FUN_80098b08();
    FUN_80098f10();
    if (0xc < DAT_8012bf9b) {
      DAT_8012bf9b = 0;
      FUN_800828ac(&DAT_8012fa70,&DAT_8012fa7c);
    }
    goto LAB_800904f8;
  case '\x03':
    FUN_8006c070(1);
    if (DAT_800e10ec < 0) {
      if ((DAT_800df90c & 0x8000) != 0) {
        DAT_8012bf9a = '\x04';
        FUN_80077adc(0x40a0000,0);
      }
      if ((DAT_800df90c & 0x2000) != 0) {
        DAT_8012bf9a = '\x05';
        FUN_80077adc(0x40a0000,0);
      }
    }
    if ((DAT_800df918 & 0x1000) == 0) {
LAB_8008faf4:
      if ((DAT_800df918 & 0x2000) == 0) goto LAB_8008fc8c;
      DAT_8012bf9a = '\x02';
      uVar9 = 0x4050000;
    }
    else if (((char)DAT_8012bfa9 == 3) ||
            (uVar9 = 0x4060000, (&DAT_800e8ff4)[(char)DAT_8012bfa9 * 8] == -1)) {
      if (((DAT_800df918 & 0x1000) == 0) ||
         ((DAT_8012bfa9 != 3 || (uVar9 = 0x4060000, DAT_800e901b == 0xff)))) goto LAB_8008faf4;
      DAT_8012bfab = 0;
      DAT_8012bf9a = '\x06';
    }
    else {
      DAT_8012bfab = 0;
      DAT_8012bf9a = '\x06';
    }
LAB_8008fb18:
    FUN_80077adc(uVar9,0);
    goto LAB_8008fc8c;
  case '\x04':
  case '\x05':
    bVar7 = DAT_8012bf9b + 1;
    if (DAT_8012bf9b < 10) {
      if (DAT_8012bf9a == '\x04') {
        DAT_8012bfc8 = (ushort)bVar7 * -0x10;
      }
      else {
        DAT_8012bfc8 = (ushort)bVar7 * 0x10;
      }
                    /* WARNING: Read-only address (ram,0x8012bfc8) is written */
      DAT_8012bf9b = bVar7;
    }
    else {
      if (DAT_8012bf9a == '\x04') {
        DAT_8012bfa9 = DAT_8012bfa9 - 1;
        if ((int)((uint)DAT_8012bfa9 << 0x18) < 0) {
          DAT_8012bfa9 = 3;
        }
      }
      else {
        DAT_8012bfa9 = DAT_8012bfa9 + 1;
        if ('\x03' < (char)DAT_8012bfa9) {
          DAT_8012bfa9 = 0;
        }
      }
      if ((char)DAT_8012bfa9 == 3) {
        bVar1 = DAT_800e901b;
      }
      else {
        bVar1 = (&DAT_800e8ff4)[(char)DAT_8012bfa9 * 8];
      }
      if (bVar1 == 0xff) {
        DAT_8012bf9b = bVar7;
        FUN_80090584(0);
      }
      else {
        DAT_8012bfaa = 0;
      }
                    /* WARNING: Read-only address (ram,0x8012bfc8) is written */
      DAT_8012bfc8 = 0x400;
                    /* WARNING: Read-only address (ram,0x8012bfca) is written */
      _UNK_8012bfca = 0;
      DAT_8012bf9a = '\x03';
      DAT_8012bf9b = 0;
      DAT_8012bf9c = 0;
      if ((DAT_800df90c & 0x8000) != 0) {
        DAT_8012bf9a = '\x04';
        FUN_80077adc(0x40a0000,0);
      }
      if ((DAT_800df90c & 0x2000) != 0) {
        DAT_8012bf9a = '\x05';
        uVar9 = 0x40a0000;
        goto LAB_8008fb18;
      }
    }
LAB_8008fc8c:
    FUN_80098b08();
    break;
  case '\x06':
    if (DAT_8012bf9b < 0xb) {
      DAT_8012bfc6 = (ushort)(byte)(DAT_8012bf9b + 1) * 4 + 0x14;
      DAT_8012bf9b = DAT_8012bf9b + 1;
                    /* WARNING: Read-only address (ram,0x8012bfc6) is written */
    }
    else {
      DAT_8012bf9a = '\b';
      DAT_8012bf9b = 0;
    }
    break;
  case '\a':
    if (DAT_8012bf9b < 0xb) {
      DAT_8012bfc6 = -((ushort)(byte)(DAT_8012bf9b + 1) * 4 + 0x14);
      DAT_8012bf9b = DAT_8012bf9b + 1;
                    /* WARNING: Read-only address (ram,0x8012bfc6) is written */
    }
    else {
      DAT_8012bf9a = '\x03';
      DAT_8012bf9b = 0;
    }
    break;
  case '\b':
  case '\t':
    bVar11 = 10 < DAT_8012bf9b;
    DAT_8012bf9b = DAT_8012bf9b + 1;
    if (bVar11) {
      bVar11 = DAT_8012bf9a == '\b';
      DAT_8012bf9a = '\a';
      if (bVar11) {
        DAT_8012bf9a = '\n';
      }
      DAT_8012bf9b = 0;
    }
    break;
  case '\n':
    if (DAT_800e10ec < 0) {
      if ((DAT_800df90c & 0x1000) != 0) {
        FUN_80090584(1);
      }
      if ((DAT_800df90c & 0x4000) != 0) {
        FUN_80090584(0);
      }
      if (bVar7 != DAT_8012bfaa) {
        FUN_80077adc(0x4040000,0);
      }
    }
    if ((DAT_800df918 & 0x1000) == 0) {
LAB_8008fee8:
      if ((DAT_800df918 & 0x2000) != 0) {
        DAT_8012bf9a = '\t';
        uVar9 = 0x4050000;
        goto LAB_8008ff08;
      }
    }
    else {
      if (((char)DAT_8012bfa9 == 3) ||
         ((&DAT_800e8ff4)[(char)DAT_8012bfa9 * 8 + (int)(char)DAT_8012bfaa] == -1)) {
        if (((DAT_800df918 & 0x1000) != 0) && (DAT_8012bfa9 == 3)) {
          bVar11 = false;
          if ((DAT_800e901b != 0xff) && ((int)(char)DAT_8012bfaa < (int)(uint)DAT_800e901b)) {
            bVar11 = true;
          }
          if (bVar11) {
            DAT_8012bf9a = '\v';
            DAT_8012bfab = 0;
            DAT_8012fe04 = 1;
            FUN_800946f0();
            FUN_80098c08(_DAT_8013a384);
            uVar9 = 0x4060000;
            goto LAB_8008ff08;
          }
        }
        goto LAB_8008fee8;
      }
      DAT_8012bf9a = '\v';
      DAT_8012bfab = 0;
      DAT_8012fe04 = 0;
      FUN_800946f0();
      FUN_80098c08(_DAT_8013a384);
      uVar9 = 0x4060000;
LAB_8008ff08:
      FUN_80077adc(uVar9,0);
    }
    if ((char)DAT_8012bfa9 == 3) {
      iVar10 = (int)((uint)DAT_8012bfaa << 0x18) >> 0x18;
      uVar5 = iVar10 - ((int)((uint)DAT_8012bfaa << 0x18) >> 0x1f) >> 1;
      if ((iVar10 + uVar5 * -2 & 0xff) == 0) {
        uVar5 = (uint)((byte)(&DAT_800e9013)[uVar5 & 0xff] >> 4);
      }
      else {
        uVar5 = (byte)(&DAT_800e9013)[uVar5 & 0xff] & 0xf;
      }
      iVar10 = uVar5 + 0x81;
    }
    else {
      iVar10 = (byte)(&DAT_800e8ff4)[(char)DAT_8012bfa9 * 8 + (int)(char)DAT_8012bfaa] + 0x68;
    }
    FUN_8008c25c(0x10,0xcb,2,iVar10);
    break;
  case '\v':
    if (0xd < DAT_8012bf9b) {
      DAT_8012bf9a = '\x10';
      DAT_8012bf9b = 0;
      DAT_8012bff4 = 0x138;
      FUN_80077adc(0x4080000,0);
      FUN_800274e4(4,1);
      goto LAB_800904f8;
    }
    DAT_8012bfe6 = DAT_8012bfe6 + 0x16;
    DAT_8012bfde = DAT_8012bfde + -0x13;
    DAT_8012bfd4 = DAT_8012bfd4 + -0x16;
    DAT_8012bfd2 = DAT_8012bfd2 + 0x15;
    DAT_8012bfcc = DAT_8012bfcc + 0x15;
    DAT_8012bf9b = DAT_8012bf9b + 1;
    goto LAB_80090128;
  case '\f':
    goto LAB_80090070;
  case '\r':
    if ((char)DAT_8012bfa9 == 3) {
      iVar10 = (int)((uint)DAT_8012bfaa << 0x18) >> 0x18;
      uVar5 = iVar10 - ((int)((uint)DAT_8012bfaa << 0x18) >> 0x1f) >> 1;
      if ((iVar10 + uVar5 * -2 & 0xff) == 0) {
        uVar5 = (uint)((byte)(&DAT_800e9013)[uVar5 & 0xff] >> 4);
      }
      else {
        uVar5 = (byte)(&DAT_800e9013)[uVar5 & 0xff] & 0xf;
      }
      puVar4 = (ushort *)(&DAT_80130334 + uVar5 * 4);
    }
    else {
      puVar4 = (ushort *)
               (&DAT_801302d0 +
               (uint)(byte)(&DAT_800e8ff4)[(char)DAT_8012bfa9 * 8 + (int)(char)DAT_8012bfaa] * 4);
    }
    if (DAT_8012bfc1 == '\0') {
      if (0x32 < DAT_8012bfc0) {
        DAT_8012bfc1 = '\x01';
      }
      DAT_8012bfc0 = DAT_8012bfc0 + 4;
    }
    else {
      if (DAT_8012bfc0 < 10) {
        DAT_8012bfc1 = '\0';
      }
      DAT_8012bfc0 = DAT_8012bfc0 - 4;
    }
    if ((DAT_800df918 & 0x2000) != 0) {
      DAT_8012bf9a = '\f';
      FUN_80077adc(0x4050000,0);
      goto LAB_80090070;
    }
    if ((-1 < DAT_800e10ec) || ((DAT_800df90c & 0xa000) == 0)) goto LAB_800904f0;
    if ((DAT_800df90c & 0x2000) == 0) {
LAB_800902e0:
      if (((DAT_800df90c & 0x8000) == 0) || (DAT_8012bfab == 0)) goto LAB_800904f0;
      DAT_8012bf9a = '\x11';
      DAT_8012bfab = DAT_8012bfab - 1;
    }
    else {
      if (*puVar4 <= (ushort)DAT_8012bfab) {
        DAT_8012bf9a = '\x0e';
        FUN_80077adc(0x4040000,0);
        goto LAB_800902e0;
      }
      DAT_8012bf9a = '\x0f';
      DAT_8012bfab = DAT_8012bfab + 1;
    }
    FUN_80077adc(0x4080000,0);
    goto LAB_800904f0;
  case '\x0e':
    if ((DAT_800df918 & 0x3000) == 0) {
      if ((-1 < DAT_800e10ec) || ((DAT_800df90c & 0x8000) == 0)) goto LAB_800904f0;
      DAT_8012bf9a = '\r';
      goto LAB_800903ac;
    }
    DAT_800e1124 = 0x917;
    FUN_800824b0(DAT_800c52dc + 0x44800);
    DAT_8012bf9a = '\f';
    FUN_80077adc(0x4060000,0);
    goto LAB_80090070;
  case '\x0f':
  case '\x10':
    bVar7 = DAT_8012bf9b + 1;
    if (DAT_8012bf9b < 0xb) {
      if (DAT_8012bf9a == '\x0f') {
        bVar7 = (&DAT_8012f948)[bVar7];
      }
      else {
        bVar7 = (&UNK_8012f953)[-(uint)bVar7];
      }
      uVar6 = -(ushort)bVar7;
LAB_800904ec:
      DAT_8012bf9b = DAT_8012bf9b + 1;
      DAT_8012bff4 = DAT_8012bff4 + uVar6;
      goto LAB_800904f0;
    }
    if (DAT_8012bf9a == '\x0f') {
      DAT_8012bf9b = bVar7;
      FUN_800946f0();
      DAT_8012bff4 = 0x138;
      DAT_8012bf9a = '\x10';
    }
    else {
      DAT_8012bf9a = '\r';
    }
    DAT_8012bf9b = 0;
    goto LAB_800903ac;
  case '\x11':
  case '\x12':
    bVar7 = DAT_8012bf9b + 1;
    if (DAT_8012bf9b < 0xb) {
      if (DAT_8012bf9a == '\x11') {
        bVar7 = (&DAT_8012f948)[bVar7];
      }
      else {
        bVar7 = (&UNK_8012f953)[-(uint)bVar7];
      }
      uVar6 = (ushort)bVar7;
      goto LAB_800904ec;
    }
    if (DAT_8012bf9a == '\x11') {
      DAT_8012bf9b = bVar7;
      FUN_800946f0();
      DAT_8012bff4 = -0x106;
      DAT_8012bf9a = '\x12';
    }
    else {
      DAT_8012bf9a = '\r';
    }
    DAT_8012bf9b = 0;
LAB_800903ac:
    DAT_8012bfc1 = '\0';
    DAT_8012bfc0 = 4;
LAB_800904f0:
    FUN_80095280();
  default:
    goto LAB_800904f8;
  }
LAB_8008fc94:
  FUN_80098f10();
LAB_800904f8:
  FUN_80096f68(1);
  return;
LAB_80090070:
  if (DAT_8012bf9b < 0xd) {
    DAT_8012bfe6 = DAT_8012bfe6 + -0x16;
    DAT_8012bfde = DAT_8012bfde + 0x13;
    DAT_8012bfd4 = DAT_8012bfd4 + 0x16;
    DAT_8012bfd2 = DAT_8012bfd2 + -0x15;
    DAT_8012bfcc = DAT_8012bfcc + -0x15;
    DAT_8012bf9b = DAT_8012bf9b + 1;
LAB_80090128:
  }
  else {
    DAT_8012bf9b = DAT_8012bf9b + 1;
    FUN_800274e4(4,0xd);
    DAT_8012bf9a = '\n';
    DAT_8012bf9b = 0;
    DAT_8012bfe6 = DAT_8012bfe6 + -0x16;
    DAT_8012bfd4 = DAT_8012bfd4 + 0x16;
    DAT_8012bfde = DAT_8012bfde + 0x13;
    DAT_8012bfcc = DAT_8012bfcc + -0x15;
    DAT_8012bfd2 = DAT_8012bfd2 + -0x15;
    FUN_80098a04(_DAT_8013a384);
  }
  goto LAB_8008fc94;
}
