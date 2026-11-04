/* FUN_800540f0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800540f0  body 0x800540f0..0x8005420f  size 288 B
 * body sha256 dd8b9981aa85a874905abc8a222e0e6b1105ce054f9782042e901ef001f4c752
 * provider record sha256 32b7fb2d4cbafcb0228e92f96bc3fa038406a528603bdc503d062e4074fc078b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800540f0(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint unaff_s3;
  
  iVar4 = DAT_8010d940;
  iVar1 = FUN_8005360c();
  iVar3 = DAT_800df934;
  if (iVar1 != 0) goto LAB_80054908;
  if (DAT_8010da1c == '\0') {
    if ((DAT_8010da18 != 0) && ((DAT_800df914 & 0x1000) != 0)) {
      DAT_8010da14 = 1;
    }
  }
  else if ((DAT_8010da1c == '\x01') && (DAT_8010da18 != 0)) {
    if ((DAT_800df90e & 0xf0) != 0) {
      DAT_8010da14 = 1;
    }
    if ((DAT_800df90e & 0xf) != 0) {
      DAT_8010da14 = 1;
    }
  }
  if (DAT_8010da14 != 0) {
    _DAT_80139be8 = (undefined *)0x0;
    _DAT_80139be4 = (undefined *)0x0;
  }
  unaff_s3 = (uint)DAT_800e8609;
  switch(unaff_s3) {
  case 0:
    DAT_8010d940 = DAT_800df934;
    DAT_800df934 = DAT_800df934 + 0x5320;
    FUN_80054f98(DAT_800e10f0 >> 4,1);
    DAT_80139be0 = FUN_8008c51c(0x35);
    if ((int)((uint)DAT_80139be0 << 0x18) < 0) {
      DAT_80139be0 = FUN_8008c51c(0x35);
    }
    DAT_8010da18 = 0;
    DAT_8010da14 = 0;
    DAT_800e8609 = 1;
    iVar4 = iVar3;
  case 1:
    _DAT_80139be8 = &DAT_8010d960;
    FUN_800539a0(1,"DOOR LOCK SERVICE]------------------------------",&DAT_8010da18);
    if ((DAT_8010da18 & DAT_8010da14) != 0) {
      DAT_800e8609 = 2;
    }
    break;
  case 2:
    iVar3 = FUN_800837ac(&DAT_800e8ce0,0x46);
    if (iVar3 != 0) {
      _DAT_80139be4 = &DAT_8010d972;
      _DAT_80139be8 = &DAT_8010d97c;
      FUN_800539a0(1,"Hall side doors:      |2RELEASED|0]",&DAT_8010da18);
      uVar2 = DAT_8010da18 & DAT_8010da14;
      goto joined_r0x800547f8;
    }
    _DAT_80139be4 = &DAT_8010d993;
    _DAT_80139be8 = &DAT_8010d99d;
    FUN_800539a0(1,"Hall side doors:      |2LOCKED|0]",&DAT_8010da18);
    if ((DAT_8010da18 & DAT_8010da14) != 0) {
      DAT_800e8609 = 3;
    }
    break;
  case 3:
    _DAT_80139be4 = &DAT_8010d9b3;
    _DAT_80139be8 = &DAT_8010d9c2;
    FUN_800539a0(1,"]The doors can be unlocked]by a |2CARD KEY|0.]",&DAT_8010da18);
    if ((DAT_8010da18 & DAT_8010da14) != 0) {
      iVar3 = FUN_800837ac(&DAT_800e8ce0,0x46);
      if (iVar3 != 0) goto LAB_800548c0;
      DAT_800e8609 = 4;
    }
    break;
  case 4:
    iVar3 = FUN_8008c51c(0x35);
    if (-1 < iVar3) {
      DAT_8010b297 = 0x35;
      FUN_8004ac04(0,0x100,7,0xff000000);
    }
    DAT_800e8609 = 5;
    break;
  case 5:
    if ((DAT_8010b294 & 0x80) == 0) {
      iVar3 = FUN_8008c51c(0x35);
      if (iVar3 < 0) {
        DAT_800e8609 = 0xb;
        FUN_800539a0(0,&DAT_800b8cdc,&DAT_8010da18);
      }
      else {
        if ((DAT_8010b294 & 1) != 0) {
          FUN_800539a0(0,&DAT_800b8cdc,&DAT_8010da18);
          FUN_80053d38();
          goto LAB_800548c0;
        }
        FUN_80083758(&DAT_800e8ce0,0x46);
        iVar3 = FUN_8008c51c(0x35);
        iVar3 = iVar3 * 4;
        (&DAT_800e8ec8)[iVar3] = 0;
        (&DAT_800e8ec9)[iVar3] = 0;
        (&DAT_800e8eca)[iVar3] = 0;
        FUN_8008c568();
        DAT_800e8609 = 6;
      }
    }
    break;
  case 6:
    _DAT_80139be8 = &DAT_8010d9d6;
    FUN_800539a0(1,"]Checking up ID CARD[025.[025.[025.[025.",&DAT_8010da18);
    if (DAT_8010da18 != 0) {
      DAT_800e8609 = 7;
    }
    break;
  case 7:
    iVar3 = (int)DAT_800e8cac;
    if (((DAT_800e110c & 0x40000000) == 0) || (iVar1 = FUN_800837ac(&DAT_800e8ec0,0x11), iVar1 == 0)
       ) {
      FUN_80027148(9);
      iVar1 = 0;
      do {
        FUN_8004cd88(1);
        iVar1 = iVar1 + 1;
      } while (iVar1 < 0x3c);
      FUN_80077adc(0x2120000,0);
      iVar1 = 0;
      do {
        FUN_8004cd88(1);
        iVar1 = iVar1 + 1;
      } while (iVar1 < 0x3c);
    }
    FUN_80027148(2);
    iVar1 = 0;
    do {
      FUN_8004cd88(1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x3c);
    FUN_80077adc(0x2120000,0);
    iVar1 = 0;
    do {
      FUN_8004cd88(1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x3c);
    if ((DAT_800e110c & 0x40000000) != 0) {
      FUN_80027148(0xc);
      iVar1 = 0;
      do {
        FUN_8004cd88(1);
        iVar1 = iVar1 + 1;
      } while (iVar1 < 0x3c);
      FUN_80077adc(0x2120000,0);
      iVar1 = 0;
      do {
        FUN_8004cd88(1);
        iVar1 = iVar1 + 1;
      } while (iVar1 < 0x3c);
    }
    FUN_80027148(iVar3);
    DAT_800e8609 = 8;
    break;
  case 8:
    _DAT_80139be8 = &DAT_8010d9eb;
    FUN_800539a0(1,"]OK!]Hall side doors lock released.",&DAT_8010da18);
    uVar2 = DAT_8010da18 & DAT_8010da14;
joined_r0x800547f8:
    if (uVar2 != 0) {
LAB_800548c0:
      DAT_800e8609 = 0xb;
    }
    break;
  case 9:
    _DAT_80139be8 = &DAT_8010d960;
    FUN_800539a0(1,"press any key]>",&DAT_8010da18);
    DAT_8010da1c = '\x01';
    if ((DAT_8010da18 & DAT_8010da14) != 0) {
      FUN_80053d38();
      DAT_800e8609 = 0xb;
      DAT_8010da1c = '\0';
    }
    break;
  case 10:
    iVar3 = FUN_80052ffc(0,2);
    if (iVar3 != 0) {
      FUN_80053d38();
      DAT_800e860a = 2;
      goto LAB_800548c0;
    }
    break;
  case 0xb:
    FUN_800550ec(1);
    return;
  }
  if (*(char *)(iVar4 + 0x2d9) == '\x01') {
    *(undefined1 *)(iVar4 + 0x2d9) = 0;
    DAT_800e8609 = 0xb;
  }
LAB_80054908:
  if (((DAT_8010da14 & DAT_8010da18) != 0) || (unaff_s3 != DAT_800e8609)) {
    _DAT_80139be8 = (undefined *)0x0;
    DAT_8010da18 = 0;
    DAT_8010da14 = 0;
    _DAT_80139be4 = (undefined *)0x0;
  }
  FUN_80053d7c(1);
  FUN_80053eb8(0x16c);
  return;
}
