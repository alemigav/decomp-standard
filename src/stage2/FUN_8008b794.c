/* FUN_8008b794
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008b794  body 0x8008b794..0x8008bb0f  size 892 B
 * body sha256 bd5ee1048ba2deafb9c62101aed4d62715cd4aaa231425a8ba9cc7818242351a
 * provider record sha256 8dfa2d7fe741a3c6558915a270aa1e3591c5ded92d33528d6711586a9097d8de
 * callees 24 direct (24 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8008b794(void)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  undefined *puVar4;
  uint uVar5;
  
  FUN_8004ce90(0);
  DAT_8010bfa8 = DAT_8010bfa8 << 1 | 1;
  _DAT_8013a370 = FUN_80025b0c();
  FUN_80026980(0);
  FUN_800274e4(4,0xd);
  FUN_80052bbc(0xf01c,0xa06);
  FUN_800428e0(0xd0);
  DAT_800e9182 = 0;
  FUN_8008b130();
  if (DAT_800e110c < 0) {
    PTR_DAT_80130ce4 = &DAT_801307d4;
  }
  else {
    PTR_DAT_80130ce4 = &DAT_80130724;
  }
  if (DAT_8012bfb3 != '\0') {
    uVar5 = 10;
    FUN_8008d2e4(DAT_800c52dc + 0x3b800);
    puVar4 = &UNK_800c76d4;
    do {
      uVar5 = uVar5 - 1;
      if (puVar4[0x2181a] == '\x02') {
        uVar3 = (byte)puVar4[0x21818] + 0x56;
      }
      else {
        uVar3 = (uint)(byte)puVar4[0x21818];
      }
      FUN_8008c970((uVar5 >> 1) + uVar5,DAT_800c52dc + uVar3 * 0x4b0 + 0x3b800);
      puVar4 = puVar4 + -4;
    } while (uVar5 != 0);
    DAT_8012bfb3 = '\0';
  }
  iVar1 = FUN_800837ac(&DAT_800e8d48,0x3f);
  if (iVar1 != 0) {
    DAT_800e8b38 = 10;
  }
  if ((-1 < DAT_800e110c) && (iVar1 = FUN_800837ac(&DAT_800e8cc0,0xa2), iVar1 != 0)) {
    DAT_800e8ef0 = 0x2f;
  }
  uVar5 = 1;
  puVar4 = &UNK_8012ffb0;
  do {
    iVar1 = FUN_800837ac(&DAT_800e8b58,uVar5);
    if (iVar1 == 0) {
      bVar2 = puVar4[2] & 0xef;
    }
    else {
      bVar2 = puVar4[2] | 0x10;
    }
    puVar4[2] = bVar2;
    uVar5 = uVar5 + 1;
    puVar4 = puVar4 + 8;
  } while (uVar5 < 0x14);
  DAT_8012f528 = (undefined1)DAT_800e8cac;
  DAT_8012f52c = *(undefined4 *)(DAT_800df92c + 0x2c);
  DAT_800e8cac = 0;
  *(undefined **)(DAT_800df92c + 0x2c) = &DAT_8012be50;
  FUN_80097764();
  FUN_80095b90();
  FUN_80097b68();
  FUN_80098088();
  FUN_80096794();
  FUN_800961dc();
  FUN_800964c0();
  FUN_80097068();
  FUN_80097f14();
  FUN_80096c8c();
  DAT_8012bf98 = 0;
  DAT_8012bf99 = 0;
  DAT_8012bf9a = 0;
  DAT_8012bf9b = 0;
  DAT_8012bf9c = 0;
  DAT_8012bf9d = 0;
  DAT_8012bf9e = 0;
  DAT_8012bf9f = 0;
  DAT_8012bfa4 = 0;
  DAT_8012bfa5 = 0;
  if (DAT_8012f523 == '\0') {
    DAT_8012bfa1 = DAT_8012bfa0;
    DAT_8012bfa3 = DAT_8012bfa2;
  }
  else {
    DAT_8012bfa1 = 0x80;
    DAT_8012bfa3 = 0;
    DAT_8012f523 = '\0';
    DAT_8012bfa0 = DAT_8012f524;
    DAT_8012bfa2 = DAT_8012f525;
  }
  DAT_8012bfae = 1;
  DAT_8012bfd8 = 0;
  DAT_8012bfda = 0;
  FUN_8008ccbc(0);
  FUN_8008c568();
  do {
    FUN_80043620();
    (*(code *)(&PTR_FUN_8012be14)[(uint)DAT_8012bfa8 * 3 + (uint)DAT_8012bf98])();
    FUN_8004cd88(1);
  } while( true );
}
