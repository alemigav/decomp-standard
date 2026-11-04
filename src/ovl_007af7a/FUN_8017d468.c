/* FUN_8017d468
 * image   ovl_007af7a (ovl), base 0x8017b410
 * address 0x8017d468  body 0x8017d468..0x8017d5c3  size 348 B
 * body sha256 63dad4050bd4cf7b14194b137a6dcc9228767cd1deba192206157342d8f2318c
 * provider record sha256 6b2d37eb84f23b0b102b2ecf72fa9ba1bce618444392fca88a636dc431f97771
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017d468(void)

{
  uint uVar2;
  uint uVar1;
  
  if (DAT_8017e5cc == 1) {
    uVar2 = 0x12;
    do {
      uVar1 = uVar2 - 1;
      (&DAT_8017df58)[(uVar2 + 0x13) * 8] = 0;
      (&DAT_8017df58)[(uVar2 + 0x13) * 8] =
           (byte)(*(uint *)(&DAT_8017de2c + (uint)DAT_8017e5bd * 4) >> (uVar1 & 0x1f)) & 1;
      uVar2 = uVar1;
    } while (uVar1 != 0);
  }
  else if (DAT_8017e5cc < 2) {
    if (DAT_8017e5cc == 0) {
      DAT_8017df80 = 0x40;
      DAT_8017df88 = 0x40;
      DAT_8017df90 = 0x40;
      DAT_8017df98 = 0x40;
      (&DAT_8017df58)[(DAT_800e8b3e + 5) * 8] = 0x41;
      DAT_8017dfa0 = 0x40;
      DAT_8017dfa8 = 0x40;
      (&DAT_8017df58)[(DAT_800dfbe9 + 9) * 8] = 0x41;
    }
  }
  else if (DAT_8017e5cc == 2) {
    if (DAT_8017e5c6 == '\0') {
      if (DAT_800dfbe9 == 0) {
        DAT_8017e5c6 = '\0';
      }
      else {
        DAT_8017e5c6 = '\x04';
      }
    }
    FUN_8017d9a0();
  }
  return;
}
