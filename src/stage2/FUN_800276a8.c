/* FUN_800276a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800276a8  body 0x800276a8..0x80027873  size 460 B
 * body sha256 8cf86a750e17c7eb6c580159f056f43f92db5cf481122d1068ae2cdbfae2cf1b
 * provider record sha256 b896f10e8abfe62115cbbbc4d46eadc80e492cd8a9db657b698358e63134ad7f
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800276a8(void)

{
  byte bVar1;
  undefined *puVar2;
  ushort *puVar3;
  int iVar4;
  
  puVar3 = &DAT_800e9184;
  FUN_80043620();
  iVar4 = 4;
  puVar2 = &DAT_800e9190;
  do {
    if (-1 < (int)((uint)*puVar3 << 0x10)) {
      if (puVar2[-8] == '\x01') {
        bVar1 = (byte)((int)((uint)*puVar3 << 0x10) >> 0x17);
        puVar2[4] = puVar2[-7] & bVar1;
        puVar2[6] = puVar2[-5] & bVar1;
        puVar2[5] = puVar2[-6] & bVar1;
      }
      else {
        puVar2[6] = 0;
        puVar2[5] = 0;
        puVar2[4] = 0;
      }
      puVar2[7] = (char)(*puVar3 >> 7);
      *puVar3 = *puVar3 + *(short *)(puVar2 + -10);
      if ((puVar2[7] != '\0') && (DAT_800e923c != '\x05')) {
        DAT_800df8b8 = FUN_80046f98(DAT_800df8b8,puVar2);
      }
    }
    puVar2 = puVar2 + 0x2c;
    iVar4 = iVar4 + -1;
    puVar3 = puVar3 + 0x16;
  } while (0 < iVar4);
  if ((DAT_800e110c & 0x10) == 0) {
    if (0xf < DAT_800e923d) {
      DAT_800e923d = DAT_800e923d - 0x10;
    }
  }
  else if (DAT_800e923d < 0xf0) {
    DAT_800e923d = DAT_800e923d + 0x10;
  }
  DAT_800e90c3 = DAT_800e923d;
  DAT_800e90a3 = DAT_800e923d;
  if (((DAT_800e10ec & 0x4000) == 0) && (DAT_800e923d != 0)) {
    DAT_800df8b8 = FUN_80046f98(DAT_800df8b8,&DAT_800e909c);
    DAT_800df8b8 = FUN_80046f98(DAT_800df8b8,&DAT_800e90bc);
  }
  return;
}
