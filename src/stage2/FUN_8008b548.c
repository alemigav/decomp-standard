/* FUN_8008b548
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008b548  body 0x8008b548..0x8008b793  size 588 B
 * body sha256 1d97654609bd330b695d83d24855c8654c8a4be7e9d310861d3cf68b41526e30
 * provider record sha256 346687f0b13a4b4361d370c358efb7a80880f81baf84b30c72de0e4e93e6b573
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008b548(void)

{
  undefined *puVar1;
  
  FUN_8008b130();
  DAT_8012bfa8 = 0;
  DAT_8012bfc4 = 0;
  DAT_8012bfb3 = 0;
  DAT_8012f522 = 0;
  DAT_8012f523 = 0;
  DAT_8012bf98 = 0;
  DAT_8012bf99 = 0;
  DAT_8012bf9a = 0;
  DAT_8012bf9b = 0;
  DAT_8012bf9c = 0;
  DAT_8012bf9d = 0;
  DAT_8012bf9e = 0;
  DAT_8012bf9f = 0;
  if ((&DAT_800e8ec9)[(uint)DAT_8012bfa0 * 4] != '\0') {
    DAT_800e1320 = DAT_800e1320 | 1;
  }
  if ((DAT_800e8b3e & 1) == 0) {
    FUN_80083758(&DAT_800e8b58,0x1f);
  }
  else {
    FUN_80083780(&DAT_800e8b58,0x1f);
  }
  puVar1 = PTR_DAT_80130ce4;
  if ((DAT_800e110c & 0x40000000) == 0) {
    DAT_80130c06 = 0x5f;
  }
  else {
    DAT_80130c06 = 0x2c;
  }
  if ((int)DAT_800e110c < 0) {
    if ((DAT_800e110c & 0x42000000) == 0) {
      PTR_DAT_80130ce4[0x80] = 0x28;
      puVar1[0x81] = 0x78;
      puVar1[0x82] = 0x14;
      puVar1[0x83] = 0x12;
      *(undefined2 *)(puVar1 + 0x84) = 0x7b;
      *(undefined2 *)(puVar1 + 0x86) = 0x66;
      goto LAB_8008b760;
    }
    PTR_DAT_80130ce4[0x80] = 0x30;
    puVar1[0x81] = 0x48;
    puVar1[0x82] = 0x28;
    puVar1[0x83] = 0x21;
    *(undefined2 *)(puVar1 + 0x84) = 0x67;
    *(undefined2 *)(puVar1 + 0x86) = 0x67;
  }
  else if ((DAT_800e110c & 0x2000000) == 0) {
LAB_8008b760:
    puVar1[0xf] = 1;
    puVar1[0x1f] = 1;
    puVar1[0x2f] = 1;
    puVar1[0x9f] = 1;
    DAT_80130693 = 1;
    DAT_80130713 = 1;
    DAT_80130723 = 1;
    return;
  }
  if ((DAT_800e10ec & 0x200000) == 0) {
    FUN_80083758(&DAT_800e8dac,4);
    puVar1[0xf] = 0;
  }
  else {
    puVar1[0xf] = 0;
  }
  puVar1[0x1f] = 0;
  puVar1[0x2f] = 0;
  puVar1[0x9f] = 0;
  DAT_80130723 = 0;
  DAT_80130713 = 0;
  DAT_80130693 = 0;
  return;
}
