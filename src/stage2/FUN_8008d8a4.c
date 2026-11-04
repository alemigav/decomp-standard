/* FUN_8008d8a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008d8a4  body 0x8008d8a4..0x8008d8ef  size 76 B
 * body sha256 43d672fd1ad399e1b022f571725bbf9a99be9511f7e1b3565851cbe650c6bffd
 * provider record sha256 3ba27448e2754557ce6f99df6a32736b133f407b814f747c0fd2211acc80e08b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008d8a4(void)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  switch(DAT_8012bf9a) {
  case 0:
    DAT_8012bfae = '\x01';
    uVar6 = (uint)DAT_8012bfa4;
    if (DAT_800e10ec < 0) {
      if (((DAT_800df90c & 0x2000) != 0) && ((int)uVar6 < (int)(DAT_800e8b38 - 1))) {
        if ((&DAT_800e8eca)[uVar6 * 4] == '\x01') {
          DAT_8012bfa4 = DAT_8012bfa4 + 1;
        }
        DAT_8012bfa4 = DAT_8012bfa4 + 1;
      }
      if ((((DAT_800df90c & 0x8000) != 0) && (uVar4 = (uint)DAT_8012bfa4, uVar4 != 0)) &&
         (uVar4 != 10)) {
        if ((&DAT_800e8eca)[uVar4 * 4] == '\x02') {
          if (uVar4 == 1) {
            DAT_8012bfa4 = DAT_8012bfa4 + 1;
          }
          else {
            DAT_8012bfa4 = DAT_8012bfa4 - 1;
          }
        }
        DAT_8012bfa4 = DAT_8012bfa4 - 1;
      }
      bVar2 = DAT_8012bfa4;
      if ((DAT_800df90c & 0x4000) != 0) {
        bVar2 = DAT_8012bfa4 + 2;
        if (((int)(DAT_800e8b38 - 2) <= (int)(uint)DAT_8012bfa4) &&
           (bVar2 = DAT_8012bfa4, DAT_8012bfa4 == 10)) {
          bVar2 = 1;
        }
      }
      DAT_8012bfa4 = bVar2;
      if ((DAT_800df90c & 0x1000) == 0) {
LAB_8008da84:
        if (uVar6 != DAT_8012bfa4) {
          FUN_80077adc(0x4040000,0);
        }
        goto LAB_8008da9c;
      }
      if (DAT_8012bfa4 != 10) {
        if (DAT_8012bfa4 < 2) {
          DAT_8012bfa4 = 10;
        }
        else {
          DAT_8012bfa4 = DAT_8012bfa4 - 2;
        }
        goto LAB_8008da84;
      }
      DAT_8012bf99 = 2;
      FUN_80077adc(0x4050000,0);
    }
    else {
LAB_8008da9c:
      if (((DAT_800df918 & 0x1000) == 0) || ((&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4] == '\0')) {
        if ((DAT_800df918 & 0x2000) == 0) {
          if (((DAT_800df918 & 0x4000) != 0) && (DAT_8012bfae == '\x01')) {
            FUN_80077adc(0x4050000,0);
            DAT_8012bf99 = 0;
          }
        }
        else {
          FUN_80077adc(0x4050000,0);
          DAT_8012bf99 = 2;
        }
      }
      else {
        DAT_8013a380 = '\0';
        if ((byte)(&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4] < 0x14) {
          uVar5 = 1;
          if ((&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4] != 4) goto LAB_8008db30;
          iVar3 = FUN_800837ac(&DAT_800e8ce0,0x7e);
          FUN_80097364((uint)(iVar3 != 0) << 1 | 1,1);
          DAT_8013a380 = '\x01';
        }
        else {
          uVar5 = 0;
LAB_8008db30:
          FUN_80097364(uVar5,0);
        }
        FUN_80077adc(0x4060000,0);
        DAT_8012bf9a = 3;
        DAT_8012bf9b = 0;
        DAT_8012bfe0 = DAT_8012bfe0 + 0x41;
      }
    }
    FUN_8008c25c(0x10,0xaf,2,(&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4]);
    goto LAB_8008debc;
  case 1:
    DAT_8012bfae = '\x01';
    if (DAT_800e10ec < 0) {
      if (DAT_8013a380 == '\0') {
        if (((DAT_800df90c & 0x4000) != 0) &&
           (bVar1 = DAT_8012bfa7 == 1, DAT_8012bfa7 = DAT_8012bfa7 - 1, bVar1)) {
          DAT_8012bfa7 = 3;
        }
        if (((DAT_800df90c & 0x1000) != 0) &&
           (bVar1 = DAT_8012bfa7 == 3, DAT_8012bfa7 = DAT_8012bfa7 + 1, bVar1)) {
          DAT_8012bfa7 = 1;
        }
      }
      else {
        if (((DAT_800df90c & 0x4000) != 0) &&
           (bVar1 = DAT_8012bfa7 == 0, DAT_8012bfa7 = DAT_8012bfa7 - 1, bVar1)) {
          DAT_8012bfa7 = 3;
        }
        if (((DAT_800df90c & 0x1000) != 0) &&
           (bVar1 = DAT_8012bfa7 == 3, DAT_8012bfa7 = DAT_8012bfa7 + 1, bVar1)) {
          DAT_8012bfa7 = 0;
        }
      }
      if ((DAT_800df90c & 0x5000) != 0) {
        FUN_80077adc(0x4040000,0);
      }
    }
    uVar5 = 0x4060000;
    if ((DAT_800df918 & 0x1000) == 0) {
      uVar5 = 0x4050000;
      if ((DAT_800df918 & 0x2000) == 0) break;
      DAT_8012bf9a = 4;
      DAT_8012bf9b = 0;
    }
    else {
      DAT_8012bf9a = 2;
      DAT_8012bf9c = 0;
      DAT_8012bf9b = DAT_8012bfa7;
      DAT_8012bfa5 = DAT_8012bfa4;
    }
    FUN_80077adc(uVar5,0);
    break;
  case 2:
    FUN_80097578(DAT_8013a380);
    if (DAT_8012bf9b == 1) {
      FUN_8008e278();
    }
    else if (DAT_8012bf9b < 2) {
      if (DAT_8012bf9b == 0) {
        iVar3 = FUN_800837ac(&DAT_800e8ce0,0x7e);
        if (iVar3 == 0) {
          FUN_80083758(&DAT_800e8ce0,0x7e);
          uVar6 = 2;
        }
        else {
          FUN_80083780(&DAT_800e8ce0,0x7e);
          uVar6 = 0;
        }
        FUN_80097364(uVar6 | 1,1);
        DAT_8012bfa7 = 0;
        DAT_8012bf9a = 1;
        DAT_8012bf9b = 0;
      }
    }
    else if (DAT_8012bf9b == 2) {
      FUN_8008f0a8();
    }
    else if (DAT_8012bf9b == 3) {
      FUN_8008def4();
    }
    goto LAB_8008debc;
  case 3:
    bVar1 = 3 < DAT_8012bf9b;
    DAT_8012bf9b = DAT_8012bf9b + 1;
    if (bVar1) {
      DAT_8012bf9a = 1;
      DAT_8012bf9b = 0;
    }
    DAT_8012bfe0 = DAT_8012bfe0 + -0xd;
    break;
  case 4:
    bVar1 = 3 < DAT_8012bf9b;
    DAT_8012bf9b = DAT_8012bf9b + 1;
    if (bVar1) {
      DAT_8012bf9a = 0;
      DAT_8012bf9b = 0;
    }
    DAT_8012bfe0 = DAT_8012bfe0 + 0xd;
    break;
  default:
    goto LAB_8008debc;
  }
  FUN_80097578(DAT_8013a380);
LAB_8008debc:
  FUN_800962fc((&DAT_800e8eca)[(uint)DAT_8012bfa4 * 4]);
  return;
}
