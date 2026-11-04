/* FUN_8008d6fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008d6fc  body 0x8008d6fc..0x8008d8a3  size 424 B
 * body sha256 462372a5bd53cff0a162468358d6726bac28a8f0e5754db4c98f5ffd84bc412d
 * provider record sha256 0eeba3e2ed953aec242ad683faea3e6de0221c3e29b6965384ba760d21348f1d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008d6fc(void)

{
  byte bVar1;
  undefined4 uVar2;
  
  bVar1 = DAT_8012bfa6;
  DAT_8012bfae = '\x01';
  if (DAT_800e10ec < 0) {
    if (((DAT_800df90c & 0x2000) != 0) && (DAT_8012bfa6 < 3)) {
      DAT_8012bfa6 = DAT_8012bfa6 + 1;
    }
    if (((DAT_800df90c & 0x8000) != 0) && (DAT_8012bfa6 != 0)) {
      DAT_8012bfa6 = DAT_8012bfa6 - 1;
    }
    if (bVar1 != DAT_8012bfa6) {
      FUN_80077adc(0x4040000,0);
    }
  }
  if ((DAT_800df918 & 0x1000) != 0) {
    uVar2 = 0x4060000;
    if (DAT_8012bfa6 < 3) {
      DAT_8012bf99 = '\x05' - DAT_8012bfa6;
      DAT_8012bf9a = 0;
      DAT_8012bf9b = 0;
      DAT_8012bf9c = 0;
      DAT_8012bf9d = 0;
      DAT_8012bf9e = 0;
      DAT_8012bf9f = 0;
      DAT_8012bfa4 = 0;
    }
    else {
      if (DAT_8012bfa6 != 3) goto LAB_8008d830;
      DAT_8012bf99 = '\0';
      uVar2 = 0x4050000;
    }
    FUN_80077adc(uVar2,0);
  }
LAB_8008d830:
  if ((DAT_800df918 & 0x2000) != 0) {
    FUN_80077adc(0x4050000,0);
    DAT_8012bf99 = '\0';
  }
  if (((DAT_800df918 & 0x4000) != 0) && (DAT_8012bfae == '\x01')) {
    FUN_80077adc(0x4050000,0);
    DAT_8012bf99 = '\0';
  }
  return;
}
