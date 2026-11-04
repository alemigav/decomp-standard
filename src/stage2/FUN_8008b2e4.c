/* FUN_8008b2e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008b2e4  body 0x8008b2e4..0x8008b547  size 612 B
 * body sha256 c2b26b8657c6b6d56025ab25120fc09558d1c0cedba5a19bee2ce629b4841de9
 * provider record sha256 d102deae41f9d30545b0b7ca317c57f3a6241de08e1ee8e80d20d2e3605903cd
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008b2e4(void)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0xb;
  iVar4 = 0;
  if ((int)DAT_800e110c < 0) {
    iVar4 = 0xb;
  }
  if (DAT_800e1138 == '\f') {
    iVar4 = 0x16;
  }
  if (DAT_800e1138 == '\r') {
    iVar4 = 0x21;
  }
  puVar2 = &DAT_800e8ef4;
  do {
    iVar3 = iVar3 + -1;
    iVar1 = (iVar3 + iVar4) * 3;
    puVar2[-4] = (&UNK_8012bd90)[iVar1];
    puVar2[-3] = (&UNK_8012bd91)[iVar1];
    puVar2[-2] = (&UNK_8012bd92)[iVar1];
    puVar2 = puVar2 + -4;
  } while (iVar3 != 0);
  iVar3 = 0x40;
  DAT_8012bfa2 = (&UNK_8012bd90)[iVar4 * 3];
  DAT_8012bfa0 = 0;
  puVar2 = &DAT_800e8ff4;
  do {
    iVar3 = iVar3 + -1;
    puVar2[-4] = 0;
    puVar2[-3] = 0;
    puVar2[-2] = 0;
    puVar2 = puVar2 + -4;
  } while (iVar3 != 0);
  DAT_800e8b38 = 8;
  DAT_800e8b58 = 0;
  FUN_80083758(&DAT_800e8b58,0x12);
  FUN_80083780(&DAT_800e8ce0,0x7e);
  iVar3 = 0x18;
  do {
    iVar4 = iVar3 + -1;
    (&UNK_800e8ff3)[iVar3] = 0xff;
    iVar3 = iVar4;
  } while (iVar4 != 0);
  if (DAT_80160c18 == '\0') {
    iVar3 = 8;
    do {
      iVar4 = iVar3 + -1;
      (&DAT_800e9012)[iVar3] = 0;
      iVar3 = iVar4;
    } while (iVar4 != 0);
    DAT_800e901b = 0xff;
  }
  if ((DAT_800e110c & 0x4000000) != 0) {
    if (((DAT_800e10ec & 0x200000) == 0) && ((DAT_800e110c & 0x40000000) == 0)) {
      if ((int)DAT_800e110c < 0) {
        DAT_800e8ff4 = 0x18;
      }
      else {
        DAT_800e8ff4 = 0x17;
      }
    }
    DAT_800e8ed4 = 0x14;
    DAT_800e8ed5 = 0x78;
    DAT_800e8ed6 = 0;
    DAT_800e8ef8 = 0x23;
    DAT_800e8ef9 = 1;
    DAT_800e8efa = 0;
    DAT_800e8efc = 0x23;
    DAT_800e8efd = 1;
    DAT_800e8efe = 0;
    DAT_800e8f00 = 0x23;
    DAT_800e8f01 = 1;
    DAT_800e8f02 = 0;
  }
  return;
}
