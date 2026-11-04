/* FUN_800b03cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b03cc  body 0x800b03cc..0x800b185b  size 5264 B
 * body sha256 5297ad67637f173453fa7509e723ff6b70ae91d1df6780f913a70ddcdb6b9df9
 * provider record sha256 0aaf7132f5f74fe1b55b04bbdf9f5baf15dd18ac64a742cb581becf97e4a694f
 * callees 32 direct (32 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800b03cc(int *param_1)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  char cVar7;
  byte *pbVar4;
  int iVar5;
  ushort *puVar6;
  undefined1 uVar8;
  uint uVar9;
  uint uVar10;
  undefined2 uVar11;
  uint uVar12;
  uint uVar13;
  int *piVar14;
  undefined1 *puVar15;
  byte bVar17;
  uint uVar16;
  undefined4 uVar18;
  ushort local_38;
  ushort local_36;
  ushort local_34;
  ushort local_32;
  uint local_30;
  uint local_2c;
  
  uVar9 = param_1[9];
  if ((uVar9 & 3) != 0) {
    if ((uVar9 & 1) != 0) {
      param_1[9] = uVar9 & 0xfffffffe;
      FUN_800a5acc(*(undefined1 *)((int)param_1 + 99));
    }
    if ((param_1[9] & 0x40U) != 0) {
      param_1[9] = 0;
      FUN_800aebfc(param_1);
      return;
    }
    FUN_800ac7cc(param_1);
    *(undefined1 *)((int)param_1 + 0x4a) = *(undefined1 *)(param_1 + 0x15);
    *(undefined1 *)((int)param_1 + 0x4b) = *(undefined1 *)((int)param_1 + 0x55);
    *(undefined1 *)((int)param_1 + 0x2f) = *(undefined1 *)((int)param_1 + 0x56);
    param_1[0xe] = (uint)*(byte *)((int)param_1 + 0x53) << 0x10;
    iVar3 = (uint)*(byte *)((int)param_1 + 0x52) << 0x10;
    param_1[0xc] = iVar3;
    param_1[0xd] = iVar3;
    cVar7 = FUN_800ac6e4(*(undefined1 *)(param_1 + 0x15),*(undefined1 *)((int)param_1 + 0x4b));
    if (cVar7 == -1) {
      *(undefined1 *)((int)param_1 + 0xc1) = *(undefined1 *)((int)param_1 + 0x4f);
    }
    else {
      *(char *)((int)param_1 + 0xc1) = cVar7;
    }
    FUN_800ac69c(*(undefined1 *)((int)param_1 + 0x4a),*(undefined1 *)((int)param_1 + 0x4b),
                 *(undefined1 *)((int)param_1 + 0x4f));
    if ((param_1[0x18] != -1) && (*(char *)((int)param_1 + 0x4a) != -1)) {
      if (*(char *)((int)param_1 + 0x4b) == -1) {
        pbVar4 = (byte *)(*(byte *)((int)param_1 + 99) + 0x80158a80);
      }
      else {
        pbVar4 = (byte *)((uint)*(byte *)((int)param_1 + 0x4a) +
                          (uint)*(byte *)((int)param_1 + 0x4b) * 0x10 + -0x7fea7560);
      }
      *pbVar4 = *(byte *)((int)param_1 + 99);
    }
    bVar17 = 0;
    param_1[0x17] = 0x4000ac44;
    param_1[0x24] = 500;
    *(undefined1 *)((int)param_1 + 0x6a) = 2;
    *(undefined1 *)((int)param_1 + 0x6b) = 2;
    *(undefined1 *)((int)param_1 + 0x99) = 0x80;
    param_1[0x23] = 0;
    *(undefined1 *)(param_1 + 0x26) = 0;
    *(undefined1 *)((int)param_1 + 0x9a) = 0;
    *(undefined2 *)(param_1 + 0x1a) = 0;
    *(undefined1 *)(param_1 + 0x12) = 0;
    *(undefined1 *)((int)param_1 + 0x49) = 0;
    param_1[0x10] = 0;
    param_1[0x11] = 0;
    param_1[0x5b] = 0;
    *(undefined2 *)(param_1 + 0x5c) = 0;
    param_1[0x5e] = 0;
    *(undefined2 *)(param_1 + 0x5f) = 0;
    param_1[7] = 0;
    param_1[8] = 0;
    *(undefined2 *)(param_1 + 0x2e) = 0x2000;
    *(undefined2 *)((int)param_1 + 0xc2) = 0;
    *(undefined1 *)((int)param_1 + 0xbe) = *(undefined1 *)((int)param_1 + 0xbf);
    param_1[9] = param_1[9] & 8;
    uVar9 = 0;
    do {
      *(undefined2 *)((int)param_1 + uVar9 * 2 + 0x180) = 0;
      bVar17 = bVar17 + 1;
      uVar9 = (uint)bVar17;
    } while (bVar17 < 0x10);
    param_1[0x28] = 0;
    param_1[0x29] = 0;
  }
  if (((param_1[8] != 0) && ((param_1[9] & 0x40000000U) == 0)) && ((param_1[9] & 8U) != 0)) {
    iVar3 = param_1[7];
    param_1[1] = param_1[8];
    param_1[0x27] = 0;
    param_1[8] = 0;
    param_1[7] = 0;
    *param_1 = iVar3;
  }
  if (param_1[0x27] != 0) {
    uVar9 = param_1[9];
    param_1[0x29] = param_1[0x29] + _DAT_80147848;
    if ((((uVar9 & 4) != 0) && ((uVar9 & 0x40000000) == 0)) && ((uVar9 & 8) != 0)) {
      param_1[9] = uVar9 & 0xfffffffb;
      param_1[0x27] = 0;
      param_1[0x28] = param_1[0x29];
    }
    if (((param_1[9] & 0x100000U) != 0) &&
       (cVar7 = FUN_800a5890(*(undefined1 *)((int)param_1 + 99)), cVar7 == '\0')) {
      param_1[0x27] = 0;
      param_1[9] = param_1[9] & 0xffefffff;
      param_1[0x28] = param_1[0x29];
    }
    uVar9 = param_1[0x27];
    if (uVar9 == 0xffffffff) {
      return;
    }
    if ((uint)param_1[0x29] < uVar9) {
      return;
    }
    param_1[0x28] = uVar9;
    param_1[0x27] = 0;
    return;
  }
  DAT_80158a78 = 1;
LAB_800b0630:
  _DAT_80158a70 = *(uint *)param_1[1];
  _DAT_80158a74 = *(uint *)(param_1[1] + 4);
  param_1[1] = param_1[1] + 8;
  cVar7 = DAT_80158a77;
  uVar8 = (undefined1)(_DAT_80158a70 >> 0x10);
  switch(_DAT_80158a70 & 0x7f) {
  case 0:
    goto switchD_800b0678_caseD_0;
  case 1:
    if ((_DAT_80158a70 >> 8 & 0xff) != 0) {
      cVar7 = '\0';
      if (param_1[2] != 0) {
        *param_1 = param_1[2];
        param_1[1] = param_1[3];
        break;
      }
    }
    goto switchD_800b0678_caseD_0;
  case 2:
    if ((uint)*(ushort *)(param_1 + 0x14) < (_DAT_80158a70 >> 8 & 0xff)) goto LAB_800b094c;
    iVar3 = FUN_800ad998(_DAT_80158a70 >> 0x10);
    cVar7 = '\0';
    if (iVar3 != 0) {
      *param_1 = iVar3;
      param_1[1] = iVar3 + (_DAT_80158a74 & 0xffff) * 8;
    }
    break;
  case 3:
    if ((uint)*(ushort *)(param_1 + 0xc) < (_DAT_80158a70 >> 8 & 0xff)) goto LAB_800b094c;
    iVar3 = FUN_800ad998(_DAT_80158a70 >> 0x10);
    cVar7 = '\0';
    if (iVar3 != 0) {
      *param_1 = iVar3;
      param_1[1] = iVar3 + (_DAT_80158a74 & 0xffff) * 8;
    }
    break;
  case 4:
    goto LAB_800b0ef4;
  case 5:
    cVar7 = FUN_800af34c(param_1,&DAT_80158a70);
    break;
  case 6:
    iVar3 = FUN_800ad998(_DAT_80158a70);
    cVar7 = '\0';
    if (iVar3 == 0) goto switchD_800b0678_caseD_0;
    iVar5 = *param_1;
    *param_1 = iVar3;
    param_1[2] = iVar5;
    param_1[3] = param_1[1];
    param_1[1] = iVar3 + (_DAT_80158a74 & 0xffff) * 8;
    break;
  case 7:
    _DAT_80158a76 = CONCAT11(1,cVar7);
    goto LAB_800b0ef4;
  case 8:
    cVar7 = FUN_800af484(param_1,&DAT_80158a70);
    break;
  case 9:
    uVar16 = 0;
    uVar1 = *(ushort *)((int)param_1 + 0x4e);
    uVar9 = _DAT_80158a70 >> 8;
    uVar10 = _DAT_80158a70 & 0xffff0000;
    uVar13 = (uint)DAT_80147a58;
    if (uVar13 == 0) goto LAB_800b094c;
    puVar15 = &DAT_80144448;
    do {
      uVar12 = *(uint *)(puVar15 + 0x60);
      if (((uVar12 == (((uint)uVar1 + (uVar9 & 0xff)) * 0x100 | uVar10 | uVar16)) &&
          (uVar12 != 0xffffffff)) &&
         (iVar3 = (uVar12 & 0xff) * 0x1a0, *(uint *)(&DAT_801444a8 + iVar3) == uVar12)) {
        *(uint *)(&DAT_8014446c + iVar3) = *(uint *)(&DAT_8014446c + iVar3) | 8;
      }
      uVar16 = uVar16 + 1;
      puVar15 = puVar15 + 0x1a0;
    } while (uVar16 < uVar13);
    cVar7 = '\0';
    break;
  case 10:
    if (*(char *)((int)param_1 + 0x4a) == -1) goto LAB_800b094c;
    uVar9 = FUN_800ac928(param_1);
    cVar7 = '\0';
    if ((_DAT_80158a70 >> 8 & 0xff) <= (uVar9 >> 7 & 0xff)) {
      iVar3 = FUN_800ad998(_DAT_80158a70 >> 0x10);
      cVar7 = '\0';
      if (iVar3 != 0) {
        *param_1 = iVar3;
        param_1[1] = iVar3 + (_DAT_80158a74 & 0xffff) * 8;
      }
    }
    break;
  case 0xb:
    iVar3 = ((int)(((uint)*(ushort *)(param_1 + 0x14) * 0x10000 - (_DAT_80158a70 & 0xff0000)) *
                  ((int)(_DAT_80158a70 << 0x10) >> 0x18)) >> 7) + (_DAT_80158a70 >> 0x18) * 0x10000;
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    else if (0x7f0000 < iVar3) {
      param_1[0xe] = 0x7f0000;
      goto LAB_800b094c;
    }
    param_1[0xe] = iVar3;
    goto LAB_800b094c;
  case 0xc:
    if (((DAT_80136311 == '\0') || (DAT_80136311 == '*')) ||
       (DAT_80136b4a = DAT_80136b4a ^ 1, DAT_80136b4a != 0)) {
      puVar6 = (ushort *)FUN_800adef4(_DAT_80158a70 >> 8 & 0xffff);
      cVar7 = '\0';
      if (puVar6 == (ushort *)0x0) break;
      local_38 = *puVar6 >> 8 | *puVar6 << 8;
      local_36 = puVar6[1] >> 8 | puVar6[1] << 8;
      local_34 = puVar6[2] >> 8 | puVar6[2] << 8;
      local_32 = puVar6[3] >> 8 | puVar6[3] << 8;
      FUN_800a591c(*(undefined1 *)((int)param_1 + 99),&local_38);
      param_1[9] = param_1[9] | 0x200;
    }
    goto LAB_800b094c;
  case 0xd:
    if (DAT_80158a76 == '\0') {
      iVar3 = param_1[0xc];
    }
    else {
      iVar3 = param_1[0xd];
    }
    param_1[0xc] = iVar3 * (_DAT_80158a70 >> 8 & 0xff) >> 7;
    uVar9 = param_1[0xc] + (_DAT_80158a70 >> 0x10 & 0xff) * 0x10000;
    param_1[0xc] = uVar9;
    if (0x7f0000 < uVar9) {
      param_1[0xc] = 0x7f0000;
    }
    uVar9 = param_1[0xc];
    if (CONCAT11(DAT_80158a70,DAT_80158a77) == 0) {
      param_1[0xc] = uVar9;
    }
    else {
      iVar3 = FUN_800adef4();
      uVar13 = uVar9 >> 0x10;
      if (iVar3 != 0) {
        if (uVar13 < 0x7f) {
          uVar10 = (uint)*(byte *)(uVar13 + iVar3);
          uVar9 = uVar10 * 0x10000 + (((byte *)(uVar13 + iVar3))[1] - uVar10) * (uVar9 & 0xffff);
        }
        else {
          uVar9 = (uint)*(byte *)(iVar3 + uVar13) << 0x10;
        }
      }
      param_1[0xc] = uVar9;
    }
    goto LAB_800b094c;
  case 0xe:
    param_1[9] = param_1[9] | 0x10000;
    uVar9 = _DAT_80158a70 >> 0x10;
    param_1[0x2a] = uVar9;
    FUN_800ab504(param_1 + 0x2a);
    uVar13 = DAT_80158a77 * 0x10000;
    iVar3 = (_DAT_80158a70 >> 8 & 0xff) * 0x10000;
    param_1[0xe] = iVar3;
    param_1[0x2b] = uVar13 + iVar3;
    if (param_1[0x2a] == 0) {
      param_1[0xf] = uVar13;
    }
    else {
      if (uVar9 == 0) {
        trap(0x1c00);
      }
      param_1[0xf] = uVar13 / uVar9;
    }
    goto LAB_800b094c;
  case 0xf:
    iVar3 = param_1[0xc];
    goto LAB_800b0bf8;
  case 0x10:
    cVar7 = FUN_800af700(param_1,&DAT_80158a70);
    break;
  case 0x11:
    FUN_800a58c4(*(undefined1 *)((int)param_1 + 99),1);
    cVar7 = '\0';
    break;
  case 0x12:
    cVar7 = '\0';
    param_1[9] = param_1[9] | 0x80;
    break;
  case 0x13:
    uVar9 = FUN_800ab3cc();
    cVar7 = '\0';
    if ((_DAT_80158a70 >> 8 & 0xff) <= (uVar9 & 0xff)) {
      iVar3 = FUN_800ad998(_DAT_80158a70 >> 0x10);
      cVar7 = '\0';
      if (iVar3 != 0) {
        *param_1 = iVar3;
        param_1[1] = iVar3 + (_DAT_80158a74 & 0xffff) * 8;
      }
    }
    break;
  case 0x14:
    iVar3 = 0;
LAB_800b0bf8:
    cVar7 = FUN_800afbfc(param_1,&DAT_80158a70,iVar3);
    break;
  default:
    cVar7 = '\0';
    break;
  case 0x17:
    cVar7 = FUN_800afd80(param_1,&DAT_80158a70);
    break;
  case 0x18:
    cVar7 = FUN_800af5c4(param_1,&DAT_80158a70);
    break;
  case 0x19:
    *(ushort *)(param_1 + 0x14) = (ushort)(_DAT_80158a70 >> 8) & 0x7f;
    *(char *)(param_1 + 0x30) = (char)(_DAT_80158a70 >> 0x10);
    if (param_1[0x18] == -1) {
LAB_800b0cc0:
      bVar2 = false;
    }
    else {
      bVar2 = false;
      if (*(char *)((int)param_1 + 0x4a) != -1) {
        uVar9 = (uint)*(byte *)((int)param_1 + 99);
        if (*(char *)((int)param_1 + 0x4b) == -1) {
          bVar2 = false;
          if (*(byte *)(uVar9 + 0x80158a80) == uVar9) {
            bVar2 = true;
          }
        }
        else {
          bVar2 = true;
          if (*(byte *)((uint)*(byte *)((int)param_1 + 0x4a) +
                        (uint)*(byte *)((int)param_1 + 0x4b) * 0x10 + -0x7fea7560) != uVar9)
          goto LAB_800b0cc0;
        }
      }
    }
    if (bVar2) {
      FUN_800ac69c(*(undefined1 *)((int)param_1 + 0x4a),*(undefined1 *)((int)param_1 + 0x4b),
                   *(undefined1 *)((int)param_1 + 0x51));
    }
    _DAT_80158a70 = 4;
    goto LAB_800b0ef4;
  case 0x1a:
    uVar9 = (uint)*(byte *)((int)param_1 + 0xc1) + ((int)(_DAT_80158a70 << 0x10) >> 0x18);
    *(short *)(param_1 + 0x14) = (short)uVar9;
    if ((int)(uVar9 * 0x10000) < 0) {
      uVar11 = 0;
LAB_800b0d38:
      *(undefined2 *)(param_1 + 0x14) = uVar11;
    }
    else {
      if (0x7f < (uVar9 & 0xffff)) {
        uVar11 = 0x7f;
        goto LAB_800b0d38;
      }
      *(short *)(param_1 + 0x14) = (short)uVar9;
    }
    *(char *)(param_1 + 0x30) = (char)(_DAT_80158a70 >> 0x10);
    if (*(char *)((int)param_1 + 0x4a) != -1) {
      FUN_800ac69c(*(char *)((int)param_1 + 0x4a),*(undefined1 *)((int)param_1 + 0x4b),
                   *(undefined1 *)((int)param_1 + 0x51));
    }
    _DAT_80158a70 = 4;
    goto LAB_800b0ef4;
  case 0x1b:
    *(undefined1 *)(param_1 + 0x26) = uVar8;
    local_30 = _DAT_80158a74 >> 0x10;
    if ((_DAT_80158a74 >> 8 & 1) == 0) {
      FUN_800ab514(&local_30,param_1);
    }
    else {
      FUN_800ab504(&local_30);
    }
    param_1[0x24] = local_30;
    if (DAT_80158a72 == '\0') {
      param_1[9] = param_1[9] & 0xfffff7ffU | 0x1000;
      if (*(char *)((int)param_1 + 0x4a) == -1) goto LAB_800b094c;
      FUN_800ac734(*(char *)((int)param_1 + 0x4a),*(undefined1 *)((int)param_1 + 0x4b),0);
      cVar7 = '\0';
    }
    else {
      if (DAT_80158a72 == '\x01') {
        if ((param_1[9] & 0x800U) == 0) {
          FUN_800a851c(param_1);
        }
        param_1[9] = param_1[9] | 0x1800;
        goto LAB_800b094c;
      }
      cVar7 = '\0';
    }
    break;
  case 0x1c:
    cVar7 = FUN_800af888(param_1,&DAT_80158a70);
    break;
  case 0x1d:
    param_1[0x10] = 0;
    uVar8 = (undefined1)(_DAT_80158a70 >> 8);
    *(undefined1 *)(param_1 + 0x12) = uVar8;
    *(undefined1 *)(param_1 + 0x2c) = uVar8;
    iVar3 = (int)(short)_DAT_80158a70;
    if (iVar3 < 0) {
      iVar3 = FUN_800a5d10(-iVar3);
      iVar3 = -iVar3;
    }
    else {
      iVar3 = FUN_800a5d10(iVar3);
    }
    param_1[0x1f] = iVar3 << 0x10;
    goto LAB_800b0ef0;
  case 0x1e:
    param_1[0x11] = 0;
    uVar8 = (undefined1)(_DAT_80158a70 >> 8);
    *(undefined1 *)((int)param_1 + 0x49) = uVar8;
    *(undefined1 *)((int)param_1 + 0xb1) = uVar8;
    iVar3 = (int)(short)_DAT_80158a70;
    if (iVar3 < 0) {
      iVar3 = FUN_800a5d10(-iVar3);
      iVar3 = -iVar3;
    }
    else {
      iVar3 = FUN_800a5d10(iVar3);
    }
    param_1[0x20] = iVar3 << 0x10;
LAB_800b0ef0:
    _DAT_80158a70 = 0;
LAB_800b0ef4:
    cVar7 = FUN_800af1b0(param_1,&DAT_80158a70);
    break;
  case 0x1f:
    cVar7 = FUN_800af9cc(param_1,&DAT_80158a70);
    break;
  case 0x28:
    iVar3 = FUN_800ad998(_DAT_80158a70);
    cVar7 = '\0';
    if (iVar3 != 0) {
      param_1[7] = iVar3;
      param_1[8] = iVar3 + (_DAT_80158a74 & 0xffff) * 8;
    }
    break;
  case 0x29:
    cVar7 = '\0';
    param_1[8] = 0;
    param_1[7] = 0;
    break;
  case 0x30:
    iVar3 = ((uint)param_1[10] >> 0xf) + (int)(short)_DAT_80158a70;
    if (-1 < iVar3) {
      if (iVar3 < 0x10000) {
        iVar3 = iVar3 * 0x8000;
      }
      else {
        iVar3 = 0x7fff8000;
      }
      goto LAB_800b10e0;
    }
    param_1[10] = 0;
    goto LAB_800b094c;
  case 0x31:
    cVar7 = '\0';
    param_1[10] = (uint)_DAT_80158a70 << 0xf;
    break;
  case 0x32:
    cVar7 = '\0';
    *(ushort *)((_DAT_80158a70 >> 7 & 0x1fe) + 0x80147fb0) = _DAT_80158a70 & 0xff;
    break;
  case 0x33:
    *(undefined1 *)((int)param_1 + 0x6a) = uVar8;
    cVar7 = '\0';
    *(char *)((int)param_1 + 0x6b) = (char)(_DAT_80158a70 >> 8);
    break;
  case 0x34:
    *(char *)((int)param_1 + 0x99) = (char)(_DAT_80158a70 >> 8);
    cVar7 = '\0';
    *(char *)((int)param_1 + 0x9a) = (char)(_DAT_80158a70 >> 0x10);
    break;
  case 0x35:
    cVar7 = '\0';
    param_1[9] = param_1[9] | 0x40000;
    break;
  case 0x36:
    uVar9 = _DAT_80158a70 >> 8;
    goto LAB_800b1070;
  case 0x37:
    uVar9 = (uint)*(byte *)((int)param_1 + 0x2e) + (uint)_DAT_80158a70;
    iVar3 = (int)(uVar9 * 0x10000) >> 0x10;
    if (iVar3 < 0) {
      uVar9 = 0;
    }
    else if (0xff < iVar3) {
      uVar9 = 0xff;
    }
LAB_800b1070:
    FUN_800ae4d8(param_1,uVar9 & 0xff);
    cVar7 = '\0';
    break;
  case 0x38:
    if (_DAT_80158a74 == 0) {
      *(undefined2 *)(param_1 + 0xb) = 0;
    }
    else {
      if (_DAT_80158a74 == 0) {
        trap(0x1c00);
      }
      *(short *)(param_1 + 0xb) = (short)(((uint)param_1[10] >> 8) / _DAT_80158a74);
    }
    goto LAB_800b094c;
  case 0x39:
    uVar9 = (uint)_DAT_80158a70 + ((uint)*(ushort *)(param_1 + 0xc) * (_DAT_80158a74 & 0xffff) >> 7)
    ;
    iVar3 = 0x75300000;
    if (uVar9 < 0xea61) {
      iVar3 = uVar9 * 0x8000;
    }
LAB_800b10e0:
    param_1[10] = iVar3;
    goto LAB_800b094c;
  case 0x40:
    if (((param_1[9] & 0x200000U) == 0) || (cVar7 == '\0')) {
      param_1[9] = param_1[9] | 0x200000;
      *(undefined1 *)(param_1 + 0x35) = 0;
    }
    bVar17 = *(byte *)(param_1 + 0x35);
    if (bVar17 < 4) {
      *(byte *)(param_1 + 0x35) = bVar17 + 1;
      uVar8 = FUN_800ac9a8(DAT_80158a72);
      piVar14 = param_1 + bVar17 + 0x31;
      *(undefined1 *)piVar14 = uVar8;
      *(char *)((int)piVar14 + 1) = cVar7;
      cVar7 = (char)(_DAT_80158a70 >> 0x18);
      *(short *)((int)piVar14 + 2) =
           ((short)(((int)(short)_DAT_80158a70 << 8) / 100) + ((short)cVar7 >> 0xf)) -
           ((short)cVar7 >> 0xf);
    }
    goto LAB_800b094c;
  case 0x41:
    if (((param_1[9] & 0x400000U) == 0) || (cVar7 == '\0')) {
      param_1[9] = param_1[9] | 0x400000;
      *(undefined1 *)((int)param_1 + 0xe6) = 0;
    }
    bVar17 = *(byte *)((int)param_1 + 0xe6);
    if (bVar17 < 4) {
      *(byte *)((int)param_1 + 0xe6) = bVar17 + 1;
      uVar8 = FUN_800ac9a8(DAT_80158a72);
      puVar15 = (undefined1 *)((int)param_1 + (uint)bVar17 * 4 + 0xd6);
      *puVar15 = uVar8;
      puVar15[1] = cVar7;
      cVar7 = (char)(_DAT_80158a70 >> 0x18);
      *(short *)(puVar15 + 2) =
           ((short)(((int)(short)_DAT_80158a70 << 8) / 100) + ((short)cVar7 >> 0xf)) -
           ((short)cVar7 >> 0xf);
    }
    goto LAB_800b094c;
  case 0x42:
    if (((param_1[9] & 0x800000U) == 0) || (cVar7 == '\0')) {
      param_1[9] = param_1[9] | 0x800000;
      *(undefined1 *)((int)param_1 + 0x10a) = 0;
    }
    bVar17 = *(byte *)((int)param_1 + 0x10a);
    if (bVar17 < 4) {
      *(byte *)((int)param_1 + 0x10a) = bVar17 + 1;
      uVar8 = FUN_800ac9a8(DAT_80158a72);
      puVar15 = (undefined1 *)((int)param_1 + (uint)bVar17 * 4 + 0xfa);
      *puVar15 = uVar8;
      puVar15[1] = cVar7;
      cVar7 = (char)(_DAT_80158a70 >> 0x18);
      *(short *)(puVar15 + 2) =
           ((short)(((int)(short)_DAT_80158a70 << 8) / 100) + ((short)cVar7 >> 0xf)) -
           ((short)cVar7 >> 0xf);
    }
    goto LAB_800b094c;
  case 0x43:
    if (((param_1[9] & 0x1000000U) == 0) || (cVar7 == '\0')) {
      param_1[9] = param_1[9] | 0x1000000;
      *(undefined1 *)((int)param_1 + 0x12e) = 0;
    }
    bVar17 = *(byte *)((int)param_1 + 0x12e);
    if (bVar17 < 4) {
      *(byte *)((int)param_1 + 0x12e) = bVar17 + 1;
      uVar8 = FUN_800ac9a8(DAT_80158a72);
      puVar15 = (undefined1 *)((int)param_1 + (uint)bVar17 * 4 + 0x11e);
      *puVar15 = uVar8;
      puVar15[1] = cVar7;
      cVar7 = (char)(_DAT_80158a70 >> 0x18);
      *(short *)(puVar15 + 2) =
           ((short)(((int)(short)_DAT_80158a70 << 8) / 100) + ((short)cVar7 >> 0xf)) -
           ((short)cVar7 >> 0xf);
    }
    goto LAB_800b094c;
  case 0x44:
    if (((param_1[9] & 0x8000000U) == 0) || (cVar7 == '\0')) {
      param_1[9] = param_1[9] | 0x8000000;
      *(undefined1 *)(param_1 + 0x50) = 0;
    }
    bVar17 = *(byte *)(param_1 + 0x50);
    if (bVar17 < 4) {
      *(byte *)(param_1 + 0x50) = bVar17 + 1;
      uVar8 = FUN_800ac9a8(DAT_80158a72);
      piVar14 = param_1 + bVar17 + 0x4c;
      *(undefined1 *)piVar14 = uVar8;
      *(char *)((int)piVar14 + 1) = cVar7;
      cVar7 = (char)(_DAT_80158a70 >> 0x18);
      *(short *)((int)piVar14 + 2) =
           ((short)(((int)(short)_DAT_80158a70 << 8) / 100) + ((short)cVar7 >> 0xf)) -
           ((short)cVar7 >> 0xf);
    }
    goto LAB_800b094c;
  case 0x45:
    if (((param_1[9] & 0x4000000U) == 0) || (cVar7 == '\0')) {
      param_1[9] = param_1[9] | 0x4000000;
      *(undefined1 *)((int)param_1 + 0x152) = 0;
    }
    bVar17 = *(byte *)((int)param_1 + 0x152);
    if (bVar17 < 4) {
      *(byte *)((int)param_1 + 0x152) = bVar17 + 1;
      uVar8 = FUN_800ac9a8(DAT_80158a72);
      puVar15 = (undefined1 *)((int)param_1 + (uint)bVar17 * 4 + 0x142);
      *puVar15 = uVar8;
      puVar15[1] = cVar7;
      cVar7 = (char)(_DAT_80158a70 >> 0x18);
      *(short *)(puVar15 + 2) =
           ((short)(((int)(short)_DAT_80158a70 << 8) / 100) + ((short)cVar7 >> 0xf)) -
           ((short)cVar7 >> 0xf);
    }
    goto LAB_800b094c;
  case 0x46:
    if (((param_1[9] & 0x2000000U) == 0) || (cVar7 == '\0')) {
      param_1[9] = param_1[9] | 0x2000000;
      *(undefined1 *)(param_1 + 0x59) = 0;
    }
    bVar17 = *(byte *)(param_1 + 0x59);
    if (bVar17 < 4) {
      *(byte *)(param_1 + 0x59) = bVar17 + 1;
      uVar8 = FUN_800ac9a8(DAT_80158a72);
      piVar14 = param_1 + bVar17 + 0x55;
      *(undefined1 *)piVar14 = uVar8;
      *(char *)((int)piVar14 + 1) = cVar7;
      cVar7 = (char)(_DAT_80158a70 >> 0x18);
      *(short *)((int)piVar14 + 2) =
           ((short)(((int)(short)_DAT_80158a70 << 8) / 100) + ((short)cVar7 >> 0xf)) -
           ((short)cVar7 >> 0xf);
    }
    goto LAB_800b094c;
  case 0x47:
    if (((param_1[9] & 0x10000000U) == 0) || (cVar7 == '\0')) {
      param_1[9] = param_1[9] | 0x10000000;
      *(undefined1 *)(param_1 + 0x3e) = 0;
    }
    bVar17 = *(byte *)(param_1 + 0x3e);
    if (bVar17 < 4) {
      *(byte *)(param_1 + 0x3e) = bVar17 + 1;
      uVar8 = FUN_800ac9a8(DAT_80158a72);
      piVar14 = param_1 + bVar17 + 0x3a;
      *(undefined1 *)piVar14 = uVar8;
      *(char *)((int)piVar14 + 1) = cVar7;
      cVar7 = (char)(_DAT_80158a70 >> 0x18);
      *(short *)((int)piVar14 + 2) =
           ((short)(((int)(short)_DAT_80158a70 << 8) / 100) + ((short)cVar7 >> 0xf)) -
           ((short)cVar7 >> 0xf);
    }
    goto LAB_800b094c;
  case 0x48:
    if (((param_1[9] & 0x20000000U) == 0) || (cVar7 == '\0')) {
      param_1[9] = param_1[9] | 0x20000000;
      *(undefined1 *)(param_1 + 0x47) = 0;
    }
    bVar17 = *(byte *)(param_1 + 0x47);
    if (bVar17 < 4) {
      *(byte *)(param_1 + 0x47) = bVar17 + 1;
      uVar8 = FUN_800ac9a8(DAT_80158a72);
      piVar14 = param_1 + bVar17 + 0x43;
      *(undefined1 *)piVar14 = uVar8;
      *(char *)((int)piVar14 + 1) = cVar7;
      cVar7 = (char)(_DAT_80158a70 >> 0x18);
      *(short *)((int)piVar14 + 2) =
           ((short)(((int)(short)_DAT_80158a70 << 8) / 100) + ((short)cVar7 >> 0xf)) -
           ((short)cVar7 >> 0xf);
    }
LAB_800b094c:
    cVar7 = '\0';
    break;
  case 0x50:
    uVar9 = _DAT_80158a70 >> 8;
    local_2c = _DAT_80158a70 >> 0x10;
    FUN_800ab504(&local_2c);
    uVar9 = uVar9 & 0xff;
    if (param_1[uVar9 * 3 + 0x5b] != 0) {
      param_1[uVar9 * 3 + 0x5a] = 0;
    }
    cVar7 = '\0';
    param_1[uVar9 * 3 + 0x5b] = local_2c;
    break;
  case 0x60:
    uVar18 = 0;
    goto LAB_800b168c;
  case 0x61:
    uVar18 = 1;
    goto LAB_800b168c;
  case 0x62:
    uVar18 = 2;
    goto LAB_800b168c;
  case 99:
    uVar18 = 3;
    goto LAB_800b168c;
  case 100:
    uVar18 = 4;
LAB_800b168c:
    cVar7 = FUN_800affdc(param_1,&DAT_80158a70,uVar18);
    break;
  case 0x65:
    if ((_DAT_80158a70 >> 8 & 0xff) == 0) {
      uVar9 = _DAT_80158a70 >> 0x10 & 0x1f;
      if (uVar9 < 0x10) {
        *(short *)((int)param_1 + uVar9 * 2 + 0x180) = _DAT_80158a76;
      }
      else {
        *(short *)((uVar9 - 0x10) * 2 + -0x7feb8050) = _DAT_80158a76;
      }
      goto LAB_800b094c;
    }
    FUN_800acae4(param_1,_DAT_80158a70 >> 0x10 & 0xff,(int)_DAT_80158a76);
    cVar7 = '\0';
    break;
  case 0x70:
    uVar18 = 0;
    goto LAB_800b1728;
  case 0x71:
    uVar18 = 1;
LAB_800b1728:
    cVar7 = FUN_800b0254(param_1,&DAT_80158a70,uVar18);
  }
LAB_800b1740:
  if ((cVar7 != '\0') || (DAT_80158a78 = DAT_80158a78 + 1, 0x20 < DAT_80158a78)) {
    param_1[0x29] = param_1[0x29] + _DAT_80147848;
    return;
  }
  goto LAB_800b0630;
switchD_800b0678_caseD_0:
  FUN_800ae1a0(param_1);
  FUN_800aebfc(param_1);
  cVar7 = '\x01';
  goto LAB_800b1740;
}
