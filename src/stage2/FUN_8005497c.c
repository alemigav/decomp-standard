/* FUN_8005497c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005497c  body 0x8005497c..0x80054a9b  size 288 B
 * body sha256 53bea7982a1575959336e16fcede94e6234452512b814afd95456304041ae85c
 * provider record sha256 735d1389d9e9dceff2eb0d8439d16fd2c3df40476f529b8fd50bf55e1e471795
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x800549b8) */
/* WARNING: Removing unreachable block (ram,0x800549c0) */
/* WARNING: Removing unreachable block (ram,0x80054a04) */
/* WARNING: Removing unreachable block (ram,0x80054a14) */
/* WARNING: Removing unreachable block (ram,0x80054a34) */
/* WARNING: Removing unreachable block (ram,0x80054a38) */
/* WARNING: Removing unreachable block (ram,0x80054a44) */

void FUN_8005497c(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint unaff_s3;
  
  iVar3 = DAT_8010d940;
  iVar1 = FUN_8005360c();
  iVar2 = DAT_800df934;
  if (iVar1 != 0) goto LAB_80054f24;
  if ((DAT_8010da24 != 0) && ((DAT_800df914 & 0x1000) != 0)) {
    DAT_8010da20 = 1;
  }
  if (DAT_8010da20 != 0) {
    DAT_80139bef = 0;
    DAT_80139bee = 0;
  }
  unaff_s3 = (uint)DAT_800e8609;
  switch(unaff_s3) {
  case 0:
    DAT_8010d940 = DAT_800df934;
    DAT_800df934 = DAT_800df934 + 0x5320;
    if ((DAT_800e110c & 0x200) == 0) {
      FUN_80054f98(DAT_800e10f0 >> 4,1);
    }
    else {
      FUN_80054f98(DAT_800e10f0 >> 4,0);
      FUN_800539a0(0,"Register your fingerprint.]",&DAT_8010da24);
    }
    DAT_8010da24 = 0;
    DAT_8010da20 = 0;
    iVar3 = iVar2;
    if ((DAT_800e110c & 0x200) == 0) {
      DAT_800e8609 = 1;
      goto FUN_80054b68;
    }
    DAT_800e8609 = 8;
    break;
  case 1:
FUN_80054b68:
    FUN_800539a0(1,"UMBRELLA \"RODEM\" SYSTEM]                      Ver 5.0]",&DAT_8010da24);
    if (DAT_8010da24 != 0) {
      DAT_800e8609 = 2;
    }
    break;
  case 2:
    DAT_80139bef = 0xc;
    FUN_800539a0(1,"Culture Experiment Room Staff Registry.]]",&DAT_8010da24);
    if ((DAT_8010da24 & DAT_8010da20) != 0) {
      DAT_800e8609 = 3;
    }
    break;
  case 3:
    DAT_80139bef = 2;
    FUN_800539a0(1,"Accessing[020.[020.[020.[020.[020.]]",&DAT_8010da24);
    if (DAT_8010da24 != 0) {
      DAT_800e8609 = 4;
    }
    break;
  case 4:
    DAT_80139bef = 3;
    FUN_800539a0(1,"Enter your user name.]>",&DAT_8010da24);
    if ((DAT_8010da24 & DAT_8010da20) != 0) {
      DAT_800e8609 = 5;
      DAT_800e860a = 1;
    }
    break;
  case 5:
    iVar2 = FUN_80052ffc(8,0);
    if (iVar2 != 0) {
      DAT_800e860a = 2;
      iVar2 = FUN_80082308(iVar3 + 0x2e4,"NEMESIS");
      if (iVar2 == 0) {
        DAT_800e8609 = 7;
        FUN_80053d38();
      }
      else {
        DAT_800e8609 = 6;
      }
    }
    break;
  case 6:
    DAT_80139bef = 4;
    FUN_800539a0(1,"|1This name is not in the]researcher data base.|0]",&DAT_8010da24);
    if ((DAT_8010da24 & DAT_8010da20) != 0) {
      DAT_800e8609 = 4;
    }
    break;
  case 7:
    DAT_80139bef = 6;
    FUN_800539a0(1,"Register your fingerprint.",&DAT_8010da24);
    if ((DAT_8010da24 & DAT_8010da20) != 0) {
      DAT_800e110c = DAT_800e110c | 0x200;
      FUN_80083758(&DAT_800e8ce0,0x5b);
      DAT_800e8609 = 0xc;
    }
    break;
  case 8:
    DAT_80139bef = 8;
    FUN_800539a0(1,"Please wait[025.[025.[025.[025.[025.]",&DAT_8010da24);
    if (DAT_8010da24 != 0) {
      DAT_800e8609 = 9;
    }
    break;
  case 9:
    DAT_80139bef = 9;
    FUN_800539a0(1,"Registration complete.]]",&DAT_8010da24);
    if ((DAT_8010da24 & DAT_8010da20) != 0) {
      DAT_800e8609 = 10;
    }
    break;
  case 10:
    DAT_80139bee = 10;
    DAT_80139bef = 0xb;
    FUN_800539a0(1,"Guest registration is valid]for 24 hours.]",&DAT_8010da24);
    if ((DAT_8010da24 & DAT_8010da20) != 0) {
      DAT_800e110c = DAT_800e110c & 0xfffffdff;
      FUN_800550ec(1);
      return;
    }
    break;
  case 0xb:
    FUN_800550ec(1);
    return;
  case 0xc:
    FUN_800550ec(0);
    return;
  }
  if (*(char *)(iVar3 + 0x2d9) == '\x01') {
    *(undefined1 *)(iVar3 + 0x2d9) = 0;
    DAT_800e8609 = 0xb;
  }
LAB_80054f24:
  if (((DAT_8010da20 & DAT_8010da24) != 0) || (unaff_s3 != DAT_800e8609)) {
    DAT_80139bef = 0;
    DAT_8010da24 = 0;
    DAT_8010da20 = 0;
    DAT_80139bee = 0;
  }
  FUN_80053d7c(1);
  FUN_80053eb8(0x16c);
  return;
}
