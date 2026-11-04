/* FUN_8017d07c
 * image   ovl_007af7a (ovl), base 0x8017b410
 * address 0x8017d07c  body 0x8017d07c..0x8017d467  size 1004 B
 * body sha256 15cd84741339fb8fd26f9c3bb5b231a80c75bb609eebf3aff0c3ac281312dbe6
 * provider record sha256 29c4c9ffabc3525cd4c8e029e5b157d356d0156f400f22e3c7b6a55f00d99170
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017d07c(void)

{
  if ((_DAT_800df918 & 0x2000) == 0) {
    if ((_DAT_800df918 & 0x1000) == 0) {
      if (_DAT_800e10ec < 0) {
        if ((_DAT_800df90c & 0x1000) != 0) {
          DAT_8017e5ca = 0;
          DAT_8017e5d0 = 0x2c808080;
          if ((&DAT_8017e5c4)[DAT_8017e5cc] == 2) {
            (&DAT_8017df58)
            [((uint)(byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] +
             (uint)(byte)(&DAT_8017e5c4)[DAT_8017e5cc]) * 8] = 5;
            if ((&DAT_8017e5c4)[DAT_8017e5cc] != '\0') {
              func_0x80077adc(0x4040000,0);
            }
            (&DAT_8017e5c4)[DAT_8017e5cc] = 0;
          }
        }
        if ((_DAT_800df90c & 0x4000) != 0) {
          DAT_8017e5ca = 0;
          DAT_8017e5d0 = 0x2c808080;
          (&DAT_8017df58)
          [((uint)(byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] +
           (uint)(byte)(&DAT_8017e5c4)[DAT_8017e5cc]) * 8] = 5;
          if ((&DAT_8017e5c4)[DAT_8017e5cc] != '\x02') {
            func_0x80077adc(0x4040000,0);
          }
          (&DAT_8017e5c4)[DAT_8017e5cc] = 2;
        }
        if ((&DAT_8017e5c4)[DAT_8017e5cc] != 2) {
          if ((_DAT_800df90c & 0x8000) != 0) {
            DAT_8017e5ca = 0;
            DAT_8017e5d0 = 0x2c808080;
            (&DAT_8017df58)
            [((uint)(byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] +
             (uint)(byte)(&DAT_8017e5c4)[DAT_8017e5cc]) * 8] = 5;
            if ((&DAT_8017e5c4)[DAT_8017e5cc] != '\x01') {
              func_0x80077adc(0x4040000,0);
            }
            (&DAT_8017e5c4)[DAT_8017e5cc] = 1;
          }
          if ((_DAT_800df90c & 0x2000) != 0) {
            DAT_8017e5ca = 0;
            DAT_8017e5d0 = 0x2c808080;
            (&DAT_8017df58)
            [((uint)(byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] +
             (uint)(byte)(&DAT_8017e5c4)[DAT_8017e5cc]) * 8] = 5;
            if ((&DAT_8017e5c4)[DAT_8017e5cc] != '\0') {
              func_0x80077adc(0x4040000,0);
            }
            (&DAT_8017e5c4)[DAT_8017e5cc] = 0;
          }
        }
      }
    }
    else {
      func_0x80077adc(0x4060000,0);
      if ((&DAT_8017e5c4)[DAT_8017e5cc] == '\x01') {
        DAT_8017e5c9 = 2;
        DAT_8017e5bf = DAT_8017e5bf | 0x10;
      }
      else {
        DAT_8017e5c9 = 2;
        DAT_8017e5ca = 0;
        DAT_8017e5d0 = 0x2c808080;
        DAT_8017e5cd = 0;
        DAT_8017e5bf = DAT_8017e5bf | 8;
      }
    }
  }
  else {
    DAT_8017e5c9 = 2;
    DAT_8017e5ca = 0;
    DAT_8017e5d0 = 0x2c808080;
    DAT_8017e5cd = 0;
    DAT_8017e5bf = DAT_8017e5bf | 8;
    func_0x80077adc(0x4050000,0);
  }
  return;
}
