/* FUN_8008e278
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008e278  body 0x8008e278..0x8008e30b  size 148 B
 * body sha256 425b6d1bc464b5e4d6d6179d54ee3702268acb94ef502c908200e37087c86543
 * provider record sha256 58dfacb5c32c6727db6420fd992caa933d975b9c46a0009384b20c6cc5dc0017
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008e278(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 unaff_s0;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  bVar1 = (&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4];
  bVar2 = (&DAT_800e8ec8)[(uint)DAT_8012bfa5 * 4];
  uVar8 = (uint)(byte)(&DAT_800e8ec9)[(uint)DAT_8012bfa4 * 4] +
          (uint)(byte)(&DAT_800e8ec9)[(uint)DAT_8012bfa5 * 4];
  DAT_8012bfae = 0;
  switch(DAT_8012bf9c) {
  case '\0':
    uVar8 = (uint)DAT_8012bfa5;
    if (DAT_800e10ec < 0) {
      if (((DAT_800df90c & 0x2000) != 0) && ((int)uVar8 < (int)(DAT_800e8b38 - 1))) {
        if ((&DAT_800e8eca)[uVar8 * 4] == '\x01') {
          DAT_8012bfa5 = DAT_8012bfa5 + 1;
        }
        DAT_8012bfa5 = DAT_8012bfa5 + 1;
      }
      if ((((DAT_800df90c & 0x8000) != 0) && (uVar9 = (uint)DAT_8012bfa5, uVar9 != 0)) &&
         (uVar9 != 10)) {
        if ((&DAT_800e8eca)[uVar9 * 4] == '\x02') {
          if (uVar9 == 1) {
            DAT_8012bfa5 = DAT_8012bfa5 + 1;
          }
          else {
            DAT_8012bfa5 = DAT_8012bfa5 - 1;
          }
        }
        DAT_8012bfa5 = DAT_8012bfa5 - 1;
      }
      bVar1 = DAT_8012bfa5;
      if ((DAT_800df90c & 0x4000) != 0) {
        bVar1 = DAT_8012bfa5 + 2;
        if (((int)(DAT_800e8b38 - 2) <= (int)(uint)DAT_8012bfa5) &&
           (bVar1 = DAT_8012bfa5, DAT_8012bfa5 == 10)) {
          bVar1 = 1;
        }
      }
      DAT_8012bfa5 = bVar1;
      if (((DAT_800df90c & 0x1000) != 0) && (DAT_8012bfa5 != 10)) {
        if (DAT_8012bfa5 < 2) {
          DAT_8012bfa5 = 10;
        }
        else {
          DAT_8012bfa5 = DAT_8012bfa5 - 2;
        }
      }
      if (uVar8 != DAT_8012bfa5) {
        FUN_80077adc(0x4040000,0);
      }
    }
    if ((DAT_800df918 & 0x1000) == 0) {
      if ((DAT_800df918 & 0x2000) != 0) {
        FUN_80077adc(0x4050000,0);
        DAT_8012bf9a = 1;
        DAT_8012bf9b = 0;
        DAT_8012bf9c = '\0';
      }
    }
    else {
      DAT_8012bf9c = FUN_8008c414();
      uVar7 = 0x4070000;
      if (DAT_8012bf9c != '\0') {
        uVar7 = 0x4060000;
      }
      FUN_80077adc(uVar7,0);
    }
    FUN_800965e4((&DAT_800e8eca)[(uint)DAT_8012bfa5 * 4]);
    FUN_8008c25c(0x10,0xaf,2,(&DAT_800e8ec8)[(uint)DAT_8012bfa5 * 4]);
    break;
  case '\x01':
    if (9 < DAT_8012bf9d) {
      if (DAT_8012bf9e != '\0') {
        DAT_8012bfa4 = DAT_8012bfa5;
      }
      DAT_8012bf9c = DAT_8012bf9c + '\x01';
      DAT_8012bf9d = 0;
      DAT_8012bf9e = 0;
      DAT_8012bfae = 0;
      DAT_8012bfb4 = 0;
      DAT_8012bfb5 = 0;
      DAT_8012bfb6 = 0;
      DAT_8012bfb7 = 0;
      DAT_8012bfb8 = 0;
      DAT_8012bfb9 = 0;
      DAT_8012bfba = 0;
      DAT_8012bfbb = 0;
      return;
    }
    DAT_8012bfb6 = DAT_8012bfb6 + DAT_8012bfb4;
    DAT_8012bfb7 = DAT_8012bfb7 + DAT_8012bfb5;
    DAT_8012bfba = DAT_8012bfba + DAT_8012bfb8;
    DAT_8012bfbb = DAT_8012bfbb + DAT_8012bfb9;
    DAT_8012bf9d = DAT_8012bf9d + 1;
    goto LAB_8008f074;
  case '\x02':
    DAT_8012bf9d = DAT_8012bf9d + 1;
    if (DAT_8012bf9d < 4) {
LAB_8008e6d8:
      if (DAT_8012bf9e == '\0') {
        return;
      }
    }
    else {
      uVar8 = FUN_8008c4b8(0);
      if (uVar8 < 9) {
        iVar5 = FUN_8008c4b8(1);
        uVar9 = uVar8 + 1;
        if ((int)uVar8 < (int)((uint)DAT_800e8b38 - iVar5)) {
          iVar10 = (int)uVar9 / 2 + 1 + uVar8;
          FUN_8008cb48(iVar10,(int)uVar8 / 2 + uVar8);
          iVar6 = uVar8 * 4;
          iVar5 = uVar9 * 4;
          (&DAT_800e8ec8)[iVar6] = (&DAT_800e8ec8)[iVar5];
          (&DAT_800e8ec9)[iVar6] = (&DAT_800e8ec9)[iVar5];
          (&DAT_800e8eca)[iVar6] = (&DAT_800e8eca)[iVar5];
          DAT_8012bf9d = 0;
          if (DAT_8012bfa0 == uVar9) {
            DAT_8012bfa0 = (byte)uVar8;
          }
          FUN_8008cc1c(iVar10);
          FUN_8008c314(uVar9,0,0,0);
          goto LAB_8008e6d8;
        }
      }
    }
    DAT_8012bf9a = 4;
    DAT_8012bf9e = '\0';
    DAT_8012bf9d = 0;
    DAT_8012bf9c = '\0';
    DAT_8012bf9b = 0;
    break;
  case '\x03':
    DAT_8012bf9d = DAT_8012bf9d + 1;
    if (DAT_8012bf9d == 1) {
      FUN_8004ac04(0xaf0010,0xe400,2,0);
    }
    else if ((DAT_8010b294 & 0x80) == 0) {
      DAT_8012bf9d = 0;
      DAT_8012bf9c = '\0';
      DAT_8012bf9b = 0;
      DAT_8012bf9a = 0;
    }
    break;
  case '\x04':
    func_0x80004cfc(0x14d6,DAT_800c52dc + 0x44800,0,"MIX ITP");
    FUN_8008c970((uint)(DAT_8012bfa4 >> 1) + (uint)DAT_8012bfa4,
                 DAT_800c52dc + (uint)DAT_8012bfbf * 0x4b0 + 0x44800);
    (&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4] = DAT_8012bfbe;
    (&DAT_800e8ec9)[(uint)DAT_8012bfa4 * 4] = (&DAT_8012ffa8)[(uint)DAT_8012bfbe * 8];
    if (DAT_8012bfa4 == DAT_8012bfa0) {
      DAT_8012bfa2 = DAT_8012bfbe;
    }
    if (DAT_8012bfa5 == DAT_8012bfa0) {
      DAT_8012bfa0 = DAT_8012bfa4;
      DAT_8012bfa2 = DAT_8012bfbe;
    }
    FUN_8008c314(DAT_8012bfa5,0,0,0);
    FUN_8008cc1c((uint)(DAT_8012bfa5 >> 1) + (uint)DAT_8012bfa5);
    uVar7 = 0;
    goto LAB_8008ed78;
  case '\x05':
    if ((((&DAT_800e8ec9)[(uint)DAT_8012bfa4 * 4] == (&DAT_8012ffa8)[(uint)bVar1 * 8]) &&
        ((byte)(&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4] < 0x14)) ||
       (((&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4] == '\x0f' &&
        ((&DAT_800e8ec9)[(uint)DAT_8012bfa4 * 4] == -1)))) goto LAB_8008e9f4;
    if ((byte)(&DAT_8012ffa8)[(uint)bVar1 * 8] < uVar8) {
      FUN_8008c33c(DAT_8012bfa4);
      (&DAT_800e8ec9)[(uint)DAT_8012bfa5 * 4] = (char)uVar8 - (&DAT_8012ffa8)[(uint)bVar1 * 8];
    }
    else {
      FUN_8008c33c(DAT_8012bfa4,uVar8);
      FUN_8008c314(DAT_8012bfa5,0,0,0);
      FUN_8008cc1c((uint)(DAT_8012bfa5 >> 1) + (uint)DAT_8012bfa5);
    }
    uVar7 = 0;
    goto LAB_8008ed78;
  case '\x06':
    if ((((&DAT_800e8ec9)[(uint)DAT_8012bfa5 * 4] != (&DAT_8012ffa8)[(uint)bVar2 * 8]) ||
        (0x13 < (byte)(&DAT_800e8ec8)[(uint)DAT_8012bfa5 * 4])) &&
       (((&DAT_800e8ec8)[(uint)DAT_8012bfa5 * 4] != '\x0f' ||
        ((&DAT_800e8ec9)[(uint)DAT_8012bfa5 * 4] != -1)))) {
      if ((byte)(&DAT_8012ffa8)[(uint)bVar2 * 8] < uVar8) {
        FUN_8008c33c(DAT_8012bfa5);
        (&DAT_800e8ec9)[(uint)DAT_8012bfa4 * 4] = (char)uVar8 - (&DAT_8012ffa8)[(uint)bVar2 * 8];
      }
      else {
        FUN_8008c33c(DAT_8012bfa5,uVar8);
        FUN_8008c314(DAT_8012bfa4,0,0,0);
        FUN_8008cc1c((uint)(DAT_8012bfa4 >> 1) + (uint)DAT_8012bfa4);
      }
      DAT_8012bf9c = 1;
      DAT_8012bf9d = 0;
      DAT_8012bf9e = 1;
      FUN_8008d160();
      return;
    }
LAB_8008e9f4:
    DAT_8012bf9c = '\x03';
    DAT_8012bf9d = 0;
    break;
  case '\a':
    func_0x80004cfc(0x14d6,DAT_800c52dc + 0x44800,0,"MIX ITP");
    cVar3 = (&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4];
    (&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4] = (&DAT_800e8ec8)[(uint)DAT_8012bfa5 * 4] + -0xf;
    if ((uint)DAT_8012bfa0 == (uint)DAT_8012bfa4) {
      DAT_8012bfa2 = (&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4];
    }
    (&DAT_800e8ec8)[(uint)DAT_8012bfa5 * 4] = cVar3 + '\x0f';
    uVar4 = (&DAT_800e8ec9)[(uint)DAT_8012bfa4 * 4];
    (&DAT_800e8ec9)[(uint)DAT_8012bfa4 * 4] = (&DAT_800e8ec9)[(uint)DAT_8012bfa5 * 4];
    (&DAT_800e8ec9)[(uint)DAT_8012bfa5 * 4] = uVar4;
    uVar8 = (uint)DAT_8012bfa5;
    if ((&DAT_800e8ec9)[uVar8 * 4] == '\0') {
      FUN_8008c314(uVar8,0,0,0);
      FUN_8008cc1c((uint)(DAT_8012bfa5 >> 1) + (uint)DAT_8012bfa5);
    }
    else {
      FUN_8008c970((DAT_8012bfa5 >> 1) + uVar8,DAT_800c52dc + (uint)DAT_8012bfbf * 0x4b0 + 0x44800);
    }
    uVar7 = 0;
    goto LAB_8008ed78;
  case '\b':
    func_0x80004cfc(0x14d6,DAT_800c52dc + 0x44800,0,"MIX ITP");
    FUN_8008c970((uint)(DAT_8012bfa4 >> 1) + (uint)DAT_8012bfa4,
                 DAT_800c52dc + (uint)DAT_8012bfbf * 0x4b0 + 0x44800);
    cVar3 = (&DAT_800e8ec8)[(uint)DAT_8012bfa5 * 4];
    (&DAT_800e8ec8)[(uint)DAT_8012bfa5 * 4] = (&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4] + -0xf;
    if ((uint)DAT_8012bfa0 == (uint)DAT_8012bfa5) {
      DAT_8012bfa2 = (&DAT_800e8ec8)[(uint)DAT_8012bfa5 * 4];
    }
    (&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4] = cVar3 + '\x0f';
    uVar4 = (&DAT_800e8ec9)[(uint)DAT_8012bfa4 * 4];
    (&DAT_800e8ec9)[(uint)DAT_8012bfa4 * 4] = (&DAT_800e8ec9)[(uint)DAT_8012bfa5 * 4];
    (&DAT_800e8ec9)[(uint)DAT_8012bfa5 * 4] = uVar4;
    uVar8 = (uint)DAT_8012bfa4;
    if ((&DAT_800e8ec9)[uVar8 * 4] == '\0') {
      FUN_8008c314(uVar8,0,0,0);
      FUN_8008cc1c((uint)(DAT_8012bfa4 >> 1) + (uint)DAT_8012bfa4);
    }
    else {
      FUN_8008c970((DAT_8012bfa4 >> 1) + uVar8,DAT_800c52dc + (uint)DAT_8012bfbf * 0x4b0 + 0x44800);
    }
    uVar7 = 1;
LAB_8008ed78:
    DAT_8012bf9c = '\x01';
    DAT_8012bf9e = '\0';
    DAT_8012bf9d = 0;
    FUN_8008d160(uVar7);
    break;
  case '\t':
    func_0x80004cfc(0x14d6,DAT_800c52dc + 0x44800,0,"MIX ITP");
    if ((&DAT_800e8ec8)[(uint)DAT_8012bfa5 * 4] == '$') {
      unaff_s0 = 0x19;
    }
    if ((&DAT_800e8ec8)[(uint)DAT_8012bfa5 * 4] == '%') {
      unaff_s0 = 0x1a;
    }
    iVar5 = (uint)DAT_8012bfa4 * 4;
    if (6 < (byte)(&DAT_800e8ec9)[iVar5]) {
      (&DAT_800e8ec9)[iVar5] = (&DAT_800e8ec9)[iVar5] - 6;
      (&DAT_800e8ec8)[(uint)DAT_8012bfa5 * 4] = unaff_s0;
      (&DAT_800e8ec9)[(uint)DAT_8012bfa5 * 4] = 6;
      bVar1 = DAT_8012bfa5;
      goto LAB_8008efac;
    }
    (&DAT_800e8ec8)[iVar5] = unaff_s0;
    FUN_8008c970((uint)(DAT_8012bfa4 >> 1) + (uint)DAT_8012bfa4,
                 DAT_800c52dc + (uint)DAT_8012bfbf * 0x4b0 + 0x44800);
    FUN_8008c314(DAT_8012bfa5,0,0,0);
    bVar1 = DAT_8012bfa5;
LAB_8008ef68:
    FUN_8008cc1c((uint)(bVar1 >> 1) + (uint)bVar1);
    goto LAB_8008efdc;
  case '\n':
    func_0x80004cfc(0x14d6,DAT_800c52dc + 0x44800,0,"MIX ITP");
    if ((&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4] == '$') {
      unaff_s0 = 0x19;
    }
    if ((&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4] == '%') {
      unaff_s0 = 0x1a;
    }
    iVar5 = (uint)DAT_8012bfa5 * 4;
    if ((byte)(&DAT_800e8ec9)[iVar5] < 7) {
      (&DAT_800e8ec8)[iVar5] = unaff_s0;
      FUN_8008c970((uint)(DAT_8012bfa5 >> 1) + (uint)DAT_8012bfa5,
                   DAT_800c52dc + (uint)DAT_8012bfbf * 0x4b0 + 0x44800);
      FUN_8008c314(DAT_8012bfa4,0,0,0);
      bVar1 = DAT_8012bfa4;
      goto LAB_8008ef68;
    }
    (&DAT_800e8ec9)[iVar5] = (&DAT_800e8ec9)[iVar5] - 6;
    (&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4] = unaff_s0;
    (&DAT_800e8ec9)[(uint)DAT_8012bfa4 * 4] = 6;
    bVar1 = DAT_8012bfa4;
LAB_8008efac:
    FUN_8008c970((uint)(bVar1 >> 1) + (uint)bVar1,
                 DAT_800c52dc + (uint)DAT_8012bfbf * 0x4b0 + 0x44800);
LAB_8008efdc:
    FUN_8008d160(0);
    DAT_8012bf9c = '\x01';
    DAT_8012bf9e = '\0';
    DAT_8012bf9d = 0;
    break;
  case '\v':
    if (DAT_8012bf9d == 0) {
      FUN_8004ac04(0xaf0010,0xe400,0xb,0);
      DAT_8012bf9d = DAT_8012bf9d + 1;
    }
    else if ((DAT_8010b294 & 0x80) == 0) {
      if ((DAT_8010b294 & 1) == 0) {
        DAT_8012bf9c = '\x04';
      }
      else {
        DAT_8012bf9e = '\0';
        DAT_8012bf9d = 0;
        DAT_8012bf9c = '\0';
      }
    }
LAB_8008f074:
    FUN_800965e4((&DAT_800e8eca)[(uint)DAT_8012bfa5 * 4]);
  }
  return;
}
