/* FUN_8017c020
 * image   ovl_007af7a (ovl), base 0x8017b410
 * address 0x8017c020  body 0x8017c020..0x8017c47f  size 1120 B
 * body sha256 71c8de404116ce11d927a107669b67d526eeb008e77710f8e0682ba7c85038e0
 * provider record sha256 ef83b016433bc741a47256126f2853ac11c0d5ebc7339d2cc16baa504d6d6c82
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017c020(void)

{
  if ((_DAT_800df918 & 0x2000) == 0) {
    if (((_DAT_800df918 & 0x1000) == 0) || ((&DAT_8017e5c4)[DAT_8017e5cc] != '\x04')) {
      entry();
      if (_DAT_800e10ec < 0) {
        if ((_DAT_800df90c & 0x1000) != 0) {
          DAT_8017e5ca = 0;
          DAT_8017e5d0 = 0x2c808080;
          if ((&DAT_8017e5c4)[DAT_8017e5cc] == '\x04') {
            func_0x80077adc(0x4040000,0);
          }
          (&DAT_8017e5c4)[DAT_8017e5cc] = DAT_8017e5bd;
        }
        if ((_DAT_800df90c & 0x4000) != 0) {
          DAT_8017e5ca = 0;
          DAT_8017e5d0 = 0x2c808080;
          if ((&DAT_8017e5c4)[DAT_8017e5cc] != '\x04') {
            func_0x80077adc(0x4040000,0);
          }
          (&DAT_8017e5c4)[DAT_8017e5cc] = 4;
        }
        if (((_DAT_800df90c & 0x8000) != 0) && ((&DAT_8017e5c4)[DAT_8017e5cc] != '\x04')) {
          DAT_8017e5ca = 0;
          DAT_8017e5d0 = 0x2c808080;
          func_0x80077adc(0x4040000,0);
          DAT_8017e5bd = DAT_8017e5bd - 1;
          if (DAT_8017e5bd == 0xff) {
            DAT_8017e5bd = 3;
          }
          (&DAT_8017e5c4)[DAT_8017e5cc] = DAT_8017e5bd;
        }
        if (((_DAT_800df90c & 0x2000) != 0) && ((&DAT_8017e5c4)[DAT_8017e5cc] != '\x04')) {
          DAT_8017e5ca = 0;
          DAT_8017e5d0 = 0x2c808080;
          func_0x80077adc(0x4040000,0);
          DAT_8017e5bd = DAT_8017e5bd + 1;
          if (DAT_8017e5bd == 4) {
            DAT_8017e5bd = 0;
          }
          (&DAT_8017e5c4)[DAT_8017e5cc] = DAT_8017e5bd;
        }
      }
      if (((_DAT_800df90c & 0x8000) != 0) && ((&DAT_8017e5c4)[DAT_8017e5cc] != '\x04')) {
        DAT_8017e512 = 0x20;
        DAT_8017e486 = 0x20;
        DAT_8017e3fa = 0x20;
        DAT_8017e36e = 0x20;
      }
      if (((_DAT_800df90c & 0x2000) != 0) && ((&DAT_8017e5c4)[DAT_8017e5cc] != '\x04')) {
        DAT_8017e526 = 0x20;
        DAT_8017e49a = 0x20;
        DAT_8017e40e = 0x20;
        DAT_8017e382 = 0x20;
      }
      FUN_8017bf9c();
    }
    else {
      if ((DAT_8017e5bd & 1) == 0) {
        _DAT_800e8b58 = _DAT_800e8b58 | 1;
      }
      else {
        _DAT_800e8b58 = _DAT_800e8b58 & 0xfffffffe;
      }
      DAT_8017e5c9 = 2;
      DAT_8017e5ca = 0;
      DAT_8017e5d0 = 0x2c808080;
      DAT_8017e5cd = 0;
      DAT_8017e5bf = DAT_8017e5bf | 8;
      DAT_800e8b3e = DAT_8017e5bd;
      DAT_800e923e = DAT_8017e5bd;
      func_0x80077adc(0x4050000,0);
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
