/* FUN_8017e31c
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017e31c  body 0x8017e31c..0x8017f14f  size 3636 B
 * body sha256 96eea0f2a6d49a66e16e10ebfe046d7a38bf8045aa8cda2c0f03237c71c5154c
 * provider record sha256 299f1665f717440f0d4f793c9b243dac7389ee1ef09737987a48d6a39ecf8ea6
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017e31c(int param_1,int param_2,uint param_3,int param_4)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  short sVar4;
  short sVar5;
  char cVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  char local_80 [72];
  undefined1 auStack_38 [4];
  char local_34;
  char local_33;
  char local_32;
  char local_31;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined2 local_2a;
  
  bVar2 = false;
  switch(param_1) {
  default:
    goto switchD_8017e37c_caseD_0;
  case 1:
    sVar5 = FUN_8017b4c8(0xf);
    func_0x8004c21c((int)sVar5,0x60,&DAT_801804b3,0x4002);
    sVar5 = FUN_8017b4c8(0xf);
    func_0x8004c21c((int)sVar5,0x78," KJ:P",0x4002);
    sVar5 = FUN_8017b4c8(0xf);
    iVar8 = sVar5 + -0x10;
    iVar9 = param_3 * 0x18 + 0x60;
    break;
  case 2:
    if (param_2 == 0) {
      sVar5 = FUN_8017b4c8(5);
      func_0x8004c21c((int)sVar5,0x40,&DAT_8018042c,0x4002);
      sVar5 = FUN_8017b4c8(3);
      uVar1 = 0;
    }
    else {
      sVar5 = FUN_8017b4c8(6);
      func_0x8004c21c((int)sVar5,0x40,&DAT_80180441,0x4002);
      sVar5 = FUN_8017b4c8(3);
      uVar1 = 0xd;
    }
    func_0x8004c21c((int)sVar5,0x90,&DAT_801803f0 + uVar1,0x4002);
    sVar5 = FUN_8017b4c8(3);
    func_0x8004c21c((int)sVar5,0x60,"/=RA@",0x4002);
    sVar5 = FUN_8017b4c8(3);
    func_0x8004c21c((int)sVar5,0x78,"/=RA@",0x4002);
    sVar5 = FUN_8017b4c8(3);
    iVar8 = sVar5 + -0x10;
    iVar9 = param_3 * 0x18 + 0x60;
    break;
  case 3:
    if (param_4 != 4) {
      if (DAT_80180d78 == '\0') {
        sVar5 = FUN_8017b4c8(2);
        uVar1 = 0x1a;
      }
      else {
        sVar5 = FUN_8017b4c8(3);
        uVar1 = 0x27;
      }
      func_0x8004c21c((int)sVar5,0x14,&DAT_801803f0 + uVar1,0x4002);
    }
    sVar5 = FUN_8017b4c8(param_4 + 0x14);
    func_0x8004c21c((int)sVar5,0x60,&DAT_801803f0 + (ushort)(&DAT_801806dc)[param_4 + 0x14],0x4012);
    goto switchD_8017e37c_caseD_0;
  case 0xc:
    if (DAT_80180d78 == '\0') {
      sVar5 = FUN_8017b4c8(2);
      uVar1 = 0x1a;
    }
    else {
      sVar5 = FUN_8017b4c8(3);
      uVar1 = 0x27;
    }
    func_0x8004c21c((int)sVar5,0x14,&DAT_801803f0 + uVar1,0x4002);
    sVar5 = FUN_8017b4c8(0xb);
    func_0x8004c21c((int)sVar5,0x40,"\"KNI=PPEJC",0x4012);
    sVar5 = FUN_8017b4c8(0xd);
    func_0x8004c21c((int)sVar5,0x60,"\"KNI=P",0x4002);
    sVar5 = FUN_8017b4c8(0xd);
    func_0x8004c21c((int)sVar5,0x78,&DAT_8018049a,0x4002);
    sVar5 = FUN_8017b4c8(0xd);
    iVar8 = sVar5 + -0x10;
    iVar9 = param_3 * 0x18 + 0x60;
    break;
  case 0xf:
    sVar5 = FUN_8017b4c8(8);
    func_0x8004c21c((int)sVar5,0xb2,&DAT_8018045b,0x4012);
    func_0x8004c21c(0x8b,0xc4,&DAT_80180467,0x4002);
    func_0x8004c21c(0x8b,0xd6,&DAT_8018046c,0x4002);
    FUN_8017f150(0x7b,param_3 * 0x12 + 0xc4);
    sVar5 = FUN_8017b580(0x21);
    func_0x8004a7c8((0x68 - sVar5) / 2 + -7,(uint)DAT_80180d97 * 0x14 + 0x38,3,0,&DAT_8018025c,0);
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xe:
  case 0x10:
  case 0x11:
    local_34 = (char)((int)((uint)DAT_80180d90 << 0x10) >> 0x11) + (char)DAT_80180d90 * '\x03';
    local_30 = DAT_80180d9c;
    local_2e = DAT_80180d9e;
    local_2c = DAT_80180da0;
    local_2a = DAT_80180da2;
    local_33 = local_34;
    local_32 = local_34;
    local_31 = local_34;
    _DAT_800df8b4 = func_0x80046f98(_DAT_800df8b4,auStack_38);
    uVar12 = 0;
    if (DAT_80180d92 != 0) goto LAB_8017e620;
    while (uVar12 < 5) {
LAB_8017e620:
      while( true ) {
        iVar8 = 0;
        if (param_1 == 0x11) {
          uVar11 = (uVar12 + DAT_80180d8d) - 1;
        }
        else {
          uVar11 = uVar12 + DAT_80180d8d;
        }
        if (uVar11 < 9) {
          local_80[0] = '\0';
        }
        else {
          local_80[0] = (char)((uVar11 + 1) / 10) + '\f';
        }
        local_80[2] = 0xfe;
        local_80[1] = (char)((uVar11 + 1) % 10) + '\f';
        sVar5 = FUN_8017b580(0x21);
        iVar9 = uVar12 * 0x14 + 0x38;
        func_0x8004c21c((0x68 - sVar5) / 2 + 2,DAT_80180d92 + iVar9,local_80,0x4002);
        local_80[0] = '\x01';
        local_80[1] = 0xfe;
        sVar5 = FUN_8017b580(0x21);
        func_0x8004c21c((0x68 - sVar5) / 2 + 0x19,DAT_80180d92 + iVar9,local_80,2);
        iVar9 = uVar11 * 0x80;
        if ((byte)(&DAT_80180d7c)[uVar11] < 0xf) {
          if ((*(uint *)(&DAT_80181780 + iVar9) & 0x40000000) == 0) {
            if (((&DAT_80181776)[iVar9] & 1) == 0) {
              iVar8 = 4;
              iVar3 = 0x1d9;
            }
            else {
              iVar3 = 0x1e2;
              iVar8 = 2;
            }
          }
          else if (((&DAT_80181776)[iVar9] & 1) == 0) {
            iVar3 = 0x1eb;
            iVar8 = 4;
          }
          else {
            iVar3 = 500;
            iVar8 = 2;
          }
          func_0x80082474(local_80,&DAT_801803f0 + iVar3,0xe);
          if ((*(uint *)(&DAT_80181780 + iVar9) & 0x4000000) != 0) {
            iVar8 = 0;
          }
          cVar6 = (&DAT_80181776)[iVar9];
          if (cVar6 == '\f') {
            iVar8 = 3;
            func_0x80082474(local_80,&DAT_801805ed,0xe);
            cVar6 = (&DAT_80181776)[iVar9];
          }
          if (cVar6 == '\r') {
            iVar8 = 0;
            func_0x80082474(local_80,&DAT_801805f6,0xe);
          }
          pcVar7 = local_80;
          uVar11 = 0;
          cVar6 = local_80[0];
          while (cVar6 != -2) {
            pcVar7 = pcVar7 + 1;
            uVar11 = uVar11 + 1;
            cVar6 = *pcVar7;
          }
          uVar10 = uVar11 & 0xff;
          func_0x80082474(local_80 + uVar10,&DAT_801805ff,4);
          local_80[uVar10 + 1] =
               local_80[uVar10 + 1] + (char)(*(ushort *)(&DAT_8018178c + iVar9) / 10);
          local_80[uVar10 + 2] =
               local_80[uVar10 + 2] +
               (char)*(ushort *)(&DAT_8018178c + iVar9) +
               (char)(*(ushort *)(&DAT_8018178c + iVar9) / 10) * -10;
          func_0x80082474(local_80 + uVar10 + 4,
                          &DAT_801803f0 +
                          (ushort)(&DAT_801806dc)[(byte)(&DAT_80181777)[iVar9] + 0x25],0x18);
          if ((param_1 == 9) && (uVar12 == param_3)) {
            bVar2 = false;
            if (DAT_80180d7a == '\x01') {
              bVar2 = local_80[DAT_80180d7b + 1] == -2;
            }
            if (DAT_80180d7b < 0) {
              local_80[0] = -2;
            }
            else {
              if ((byte)(local_80[DAT_80180d7b] + 0x12U) < 3) {
                DAT_80180d7b = DAT_80180d7b + '\x01';
              }
              if ((uint)DAT_80181fb0 != (int)DAT_80180d7b) {
                if (local_80[DAT_80180d7b] == '\0') {
                  func_0x80077adc(0x2240000,0);
                  DAT_80180d7a = '\n';
                }
                else {
                  func_0x80077adc(0x2220000,0);
                }
              }
              local_80[DAT_80180d7b + 1] = -2;
            }
            if ((int)(uVar11 & 0xff) <= (int)DAT_80180d7b) {
              sVar5 = FUN_8017b580(0x21);
              sVar4 = FUN_8017b580(0x21);
              func_0x8004c21c((0x68 - sVar5) / 2 + sVar4 + 0x25,
                              (int)DAT_80180d92 + uVar12 * 0x14 + 0x38,local_80 + (uVar11 & 0xff),
                              0x4002);
            }
            if (bVar2) {
              DAT_80180d7b = -2;
            }
          }
          else {
            sVar5 = FUN_8017b580(0x21);
            sVar4 = FUN_8017b580(0x21);
            func_0x8004c21c((0x68 - sVar5) / 2 + sVar4 + 0x25,
                            (int)DAT_80180d92 + uVar12 * 0x14 + 0x38,local_80 + (uVar11 & 0xff),
                            0x4002);
          }
          local_80[uVar11 & 0xff] = -2;
        }
        else {
          if (DAT_80180d98 == 0x1e000) {
            iVar8 = 3;
          }
          func_0x80082474(local_80,&DAT_801804d4,0xf);
        }
        sVar5 = FUN_8017b580(0x21);
        func_0x8004c21c((0x68 - sVar5) / 2 + 0x25,(int)DAT_80180d92 + uVar12 * 0x14 + 0x38,local_80,
                        iVar8 << 4 | 0x4002);
        uVar12 = uVar12 + 1;
        if (DAT_80180d92 == 0) break;
        if (5 < uVar12) goto LAB_8017ebb8;
      }
    }
LAB_8017ebb8:
    if (DAT_80180d78 == '\0') {
      sVar5 = FUN_8017b4c8(2);
      uVar1 = 0x1a;
    }
    else {
      sVar5 = FUN_8017b4c8(3);
      uVar1 = 0x27;
    }
    func_0x8004c21c((int)sVar5,0x14,&DAT_801803f0 + uVar1,0x4002);
    if ((1 < param_1 - 0xeU) && (param_1 != 9)) {
      sVar5 = FUN_8017b580(0x21);
      FUN_8017f150((0x68 - sVar5) / 2 + -7,param_3 * 0x14 + 0x38);
    }
    if ((param_1 == 0xe) && (((param_4 - 2U < 2 || (param_4 == 7)) || (param_4 == 8)))) {
      sVar5 = FUN_8017b580(0x21);
      func_0x8004a7c8((0x68 - sVar5) / 2 + -7,(uint)DAT_80180d97 * 0x14 + 0x38,3,0,&DAT_8018025c,0);
    }
    bVar2 = true;
    if (param_1 != 9) {
      local_80[0] = -2;
      local_80[1] = 0xfe;
      DAT_80180d8e = DAT_80180d8e + 1;
      if (0x1f < DAT_80180d8e) {
        DAT_80180d8e = 0;
      }
      if ((DAT_80180d8e < 0x10) || (DAT_80180d92 != 0)) {
        if (DAT_80180d8d != 0) {
          local_80[0] = -100;
          func_0x8004c21c(0x99,0x24,local_80,2);
        }
        if (DAT_80180d8d < 10) {
          local_80[0] = '\v';
          func_0x8004c21c(0x99,0x9c,local_80,2);
        }
      }
    }
    goto switchD_8017e37c_caseD_0;
  case 0x14:
    sVar5 = FUN_8017b4c8(0x12);
    func_0x8004c21c((int)sVar5,0x40,&DAT_801804dd,0x4012);
    sVar5 = FUN_8017b4c8(0x12);
    func_0x8004c21c((int)sVar5,0x54,"SEPDKQP",0x4012);
    sVar5 = FUN_8017b4c8(10);
    func_0x8004c21c((int)sVar5,0x74,&DAT_80180467,0x4002);
    sVar5 = FUN_8017b4c8(10);
    func_0x8004c21c((int)sVar5,0x8c,&DAT_8018046c,0x4002);
    sVar5 = FUN_8017b4c8(10);
    iVar8 = sVar5 + -0x10;
    iVar9 = param_3 * 0x18 + 0x74;
  }
  FUN_8017f150(iVar8,iVar9);
switchD_8017e37c_caseD_0:
  if (bVar2) {
    DAT_80180d90 = DAT_80180d90 + 3;
    if (0x1e < (short)DAT_80180d90) {
      DAT_80180d90 = 0x1e;
    }
  }
  else {
    DAT_80180d90 = 0;
  }
  DAT_80181fb0 = DAT_80180d7b;
  func_0x800275c0(3,(int)(short)DAT_80180d90 << 7,0,&DAT_80180d9c);
  return;
}
