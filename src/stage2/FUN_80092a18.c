/* FUN_80092a18
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80092a18  body 0x80092a18..0x80092a77  size 96 B
 * body sha256 47fcb95e67226ac79f101e3b4a3871ca297f9f192d9562ca36439db7bbaa50a8
 * provider record sha256 223a511020c18cb990b2f29ba2532b39e8a25daf2cbc863ea59b99747e61515b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80092a18(void)

{
  uint uVar1;
  byte bVar3;
  uint uVar2;
  int iVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  
  switch(DAT_8012bf9a) {
  case 0:
    uVar1 = (uint)DAT_8012bfa4;
    if (DAT_800e10ec < 0) {
      if (((DAT_800df90c & 0x2000) != 0) && ((int)uVar1 < (int)(DAT_800e8b38 - 1))) {
        if ((&DAT_800e8eca)[uVar1 * 4] == '\x01') {
          DAT_8012bfa4 = DAT_8012bfa4 + 1;
        }
        DAT_8012bfa4 = DAT_8012bfa4 + 1;
      }
      if ((((DAT_800df90c & 0x8000) != 0) && (uVar2 = (uint)DAT_8012bfa4, uVar2 != 0)) &&
         (uVar2 != 10)) {
        if ((&DAT_800e8eca)[uVar2 * 4] == '\x02') {
          if (uVar2 == 1) {
            DAT_8012bfa4 = DAT_8012bfa4 + 1;
          }
          else {
            DAT_8012bfa4 = DAT_8012bfa4 - 1;
          }
        }
        DAT_8012bfa4 = DAT_8012bfa4 - 1;
      }
      bVar3 = DAT_8012bfa4;
      if ((DAT_800df90c & 0x4000) != 0) {
        bVar3 = DAT_8012bfa4 + 2;
        if (((int)(DAT_800e8b38 - 2) <= (int)(uint)DAT_8012bfa4) &&
           (bVar3 = DAT_8012bfa4, DAT_8012bfa4 == 10)) {
          bVar3 = 1;
        }
      }
      DAT_8012bfa4 = bVar3;
      if ((DAT_800df90c & 0x1000) != 0) {
        if ((DAT_8012bfa4 < 2) || (DAT_8012bfa4 == 10)) {
          uVar1 = 10;
          DAT_8012bf99 = DAT_8012bf99 + -1;
        }
        else {
          DAT_8012bfa4 = DAT_8012bfa4 - 2;
        }
      }
      if (uVar1 != DAT_8012bfa4) {
        FUN_80077adc(0x4040000,0);
      }
    }
    cVar5 = DAT_8012bfae;
    if ((DAT_800df918 & 0x1000) == 0) {
      if ((DAT_800df918 & 0x2000) == 0) {
        if (((DAT_800df918 & 0x4000) != 0) && (DAT_8012bfae == '\x01')) {
          FUN_80077adc(0x4050000,0);
          DAT_8012bf99 = cVar5;
        }
      }
      else {
        FUN_80077adc(0x4050000,0);
        DAT_8012bf99 = '\0';
      }
    }
    else {
      FUN_80077adc(0x4060000,0);
      DAT_8012bf9a = 1;
    }
    break;
  case 1:
    if (-1 < DAT_800e10ec) {
LAB_80092dd8:
      if ((DAT_800df918 & 0x2000) == 0) {
        if ((DAT_800df918 & 0x1000) != 0) {
          FUN_80077adc(0x4060000,0);
          DAT_8012bf9a = 4;
        }
      }
      else {
        FUN_80077adc(0x4050000,0);
        DAT_8012bf9a = 0;
      }
      break;
    }
    if ((DAT_800df90c & 0x1000) == 0) {
      if ((DAT_800df90c & 0x4000) == 0) {
        if ((DAT_800df90c & 4) == 0) {
          if ((DAT_800df90c & 8) == 0) goto LAB_80092dd8;
          FUN_80077adc(0x4060000,0);
          bVar3 = DAT_8012bfbc + 5;
        }
        else {
          FUN_80077adc(0x4060000,0);
          bVar3 = DAT_8012bfbc - 5;
        }
LAB_80092e7c:
        DAT_8012bfbc = bVar3 & 0x3f;
        uVar1 = DAT_800c52dc + 0x3bb64U;
        if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
          uVar1 = DAT_800c52dc + 0x3c004U;
        }
        FUN_8008ca0c(7,(uint)(byte)(&DAT_800e8ef4)[(DAT_8012bfbc - 1 & 0x3f) * 4],
                     uVar1 + (uint)(byte)(&DAT_800e8ef4)[(DAT_8012bfbc - 1 & 0x3f) * 4] * 0x4b0 +
                             0xa64);
        iVar6 = 0;
        iVar7 = 10;
        do {
          uVar1 = DAT_800c52dc + 0x3bb64U;
          if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
            uVar1 = DAT_800c52dc + 0x3c004U;
          }
          FUN_8008ca0c(iVar7,(uint)(byte)(&DAT_800e8ef4)[((uint)DAT_8012bfbc + iVar6 & 0x3f) * 4],
                       uVar1 + (uint)(byte)(&DAT_800e8ef4)[((uint)DAT_8012bfbc + iVar6 & 0x3f) * 4]
                               * 0x4b0 + 0xa64);
          iVar6 = iVar6 + 1;
          iVar7 = iVar7 + 3;
        } while (iVar6 < 5);
        goto LAB_80092f90;
      }
      FUN_80077adc(0x2140000,0);
      DAT_8012bf9a = 3;
      uVar1 = DAT_8012bfbc + 5;
    }
    else {
      FUN_80077adc(0x2140000,0);
      DAT_8012bf9a = 2;
      uVar1 = DAT_8012bfbc - 1;
    }
    uVar2 = DAT_800c52dc + 0x3bb64U;
    if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
      uVar2 = DAT_800c52dc + 0x3c004U;
    }
    FUN_8008ca0c(7,(uint)(byte)(&DAT_800e8ef4)[(uVar1 & 0x3f) * 4],
                 uVar2 + (uint)(byte)(&DAT_800e8ef4)[(uVar1 & 0x3f) * 4] * 0x4b0 + 0xa64);
    break;
  case 2:
    DAT_8012bfae = '\0';
    if (5 < DAT_8012bf9b) {
      if ((DAT_800df90c & 0x1000) == 0) {
        DAT_8012bf9a = 1;
      }
      else {
        DAT_8012bf9b = DAT_8012bf9b + 1;
        FUN_80077adc(0x2140000,0);
      }
      DAT_8012bfbd = '\0';
      DAT_8012bf9b = 0;
      bVar3 = DAT_8012bfbc - 1;
      goto LAB_80092e7c;
    }
    DAT_8012bfbd = DAT_8012bfbd + '\x03';
    DAT_8012bf9b = DAT_8012bf9b + 1;
LAB_80092f90:
    cVar5 = (&DAT_800e8ef4)[(DAT_8012bfbc - 1 & 0x3f) * 4];
    if (cVar5 == '\0') {
      cVar5 = 'd';
      iVar6 = (int)DAT_8012bfea;
      iVar7 = DAT_8012bfe8 + 7;
      iVar4 = DAT_8012bfbd + 9;
    }
    else {
      iVar6 = (int)DAT_8012bfea;
      iVar7 = DAT_8012bfe8 + 7;
      iVar4 = DAT_8012bfbd + 9;
    }
    goto LAB_800931b8;
  case 3:
    DAT_8012bfae = '\0';
    if (DAT_8012bf9b < 6) {
      DAT_8012bfbd = DAT_8012bfbd + -3;
      DAT_8012bf9b = DAT_8012bf9b + 1;
    }
    else {
      if ((DAT_800df90c & 0x4000) == 0) {
        DAT_8012bf9a = 1;
      }
      else {
        DAT_8012bf9b = DAT_8012bf9b + 1;
        FUN_80077adc(0x2140000,0);
      }
      DAT_8012bfbd = '\0';
      DAT_8012bf9b = 0;
      uVar2 = DAT_8012bfbc + 1 & 0x3f;
      DAT_8012bfbc = (byte)uVar2;
      uVar1 = DAT_800c52dc + 0x3bb64U;
      if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
        uVar1 = DAT_800c52dc + 0x3c004U;
      }
      FUN_8008ca0c(7,(uint)(byte)(&DAT_800e8ef4)[(uVar2 + 5 & 0x3f) * 4],
                   uVar1 + (uint)(byte)(&DAT_800e8ef4)[(uVar2 + 5 & 0x3f) * 4] * 0x4b0 + 0xa64);
      iVar6 = 0;
      iVar7 = 10;
      do {
        uVar1 = DAT_800c52dc + 0x3bb64U;
        if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
          uVar1 = DAT_800c52dc + 0x3c004U;
        }
        FUN_8008ca0c(iVar7,(uint)(byte)(&DAT_800e8ef4)[((uint)DAT_8012bfbc + iVar6 & 0x3f) * 4],
                     uVar1 + (uint)(byte)(&DAT_800e8ef4)[((uint)DAT_8012bfbc + iVar6 & 0x3f) * 4] *
                             0x4b0 + 0xa64);
        iVar6 = iVar6 + 1;
        iVar7 = iVar7 + 3;
      } while (iVar6 < 5);
    }
    cVar5 = (&DAT_800e8ef4)[(DAT_8012bfbc + 5 & 0x3f) * 4];
    if (cVar5 == '\0') {
      cVar5 = 'd';
    }
    iVar6 = (int)DAT_8012bfea;
    iVar7 = DAT_8012bfe8 + 7;
    iVar4 = DAT_8012bfbd + 0x81;
LAB_800931b8:
    FUN_8008c25c(iVar7,iVar6 + iVar4,6,cVar5);
    break;
  case 4:
    DAT_8012bfae = '\0';
    DAT_8012bf9a = 0;
    FUN_8009325c();
    break;
  case 5:
    if ((DAT_8010b294 & 0x80) == 0) {
      DAT_8012bf9a = 1;
      DAT_8012bfae = 0;
      return;
    }
    DAT_8012bfae = 0;
    return;
  }
  FUN_8008c25c(0x10,0xaf,6,(&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4]);
  return;
}
