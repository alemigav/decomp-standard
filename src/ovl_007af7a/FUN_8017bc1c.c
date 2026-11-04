/* FUN_8017bc1c
 * image   ovl_007af7a (ovl), base 0x8017b410
 * address 0x8017bc1c  body 0x8017bc1c..0x8017bf9b  size 696 B
 * body sha256 a60bed89000b19f8de07bcb44e6c1d4b3670d0abadd1ed4f4e830be8978e7223
 * provider record sha256 523abd178dffc917adac4a76fdc62ae3461472827b65e729fe790c2fef4e648c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017bc1c(void)

{
  undefined4 uVar1;
  
  entry();
  if ((_DAT_800df918 & 0x2000) != 0) {
    uVar1 = 0x4050000;
    DAT_8017e5c9 = 2;
    DAT_8017e5bf = DAT_8017e5bf | 4;
LAB_8017bf80:
    func_0x80077adc(uVar1,0);
    return;
  }
  if ((_DAT_800df918 & 0x1000) == 0) {
    if (-1 < _DAT_800e10ec) {
      return;
    }
    if ((_DAT_800df90c & 0x1000) != 0) {
      DAT_8017e5ca = 0;
      DAT_8017e5d0 = 0x2c808080;
      (&DAT_8017df58)
      [((uint)(byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] +
       (uint)(byte)(&DAT_8017e5c4)[DAT_8017e5cc]) * 8] = 5;
      (&DAT_8017e5c4)[DAT_8017e5cc] = (&DAT_8017e5c4)[DAT_8017e5cc] + -1;
      if ((&DAT_8017e5c4)[DAT_8017e5cc] == -1) {
        (&DAT_8017e5c4)[DAT_8017e5cc] = '\0';
      }
      else {
        func_0x80077adc(0x4040000,0);
      }
    }
    if ((_DAT_800df90c & 0x4000) == 0) {
      return;
    }
    DAT_8017e5ca = 0;
    DAT_8017e5d0 = 0x2c808080;
    (&DAT_8017df58)
    [((uint)(byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] +
     (uint)(byte)(&DAT_8017e5c4)[DAT_8017e5cc]) * 8] = 5;
    (&DAT_8017e5c4)[DAT_8017e5cc] = (&DAT_8017e5c4)[DAT_8017e5cc] + '\x01';
    if ((&DAT_8017e5c4)[DAT_8017e5cc] == '\x05') {
      (&DAT_8017e5c4)[DAT_8017e5cc] = '\x04';
      return;
    }
    uVar1 = 0x4040000;
    goto LAB_8017bf80;
  }
  if ((&DAT_8017e5c4)[DAT_8017e5cc] == '\x04') {
    uVar1 = 0x4050000;
    DAT_8017e5c9 = 2;
    DAT_8017e5bf = DAT_8017e5bf | 4;
    goto LAB_8017bf80;
  }
  DAT_8017e5c9 = 2;
  DAT_8017e5bf = DAT_8017e5bf | 8;
  func_0x80077adc(0x4060000,0);
  DAT_8017e5ca = 0;
  DAT_8017e5d0 = 0x2c808080;
  DAT_8017e5cd = (&DAT_8017e5c4)[DAT_8017e5cc] + 1;
  switch(DAT_8017e5cd) {
  default:
    goto LAB_8017bf88;
  case 1:
    DAT_8017e5bd = DAT_800e8b3e;
    DAT_8017e5c5 = DAT_800e8b3e;
    DAT_8017e5ca = 0;
    DAT_8017e5d0 = 0x2c808080;
    return;
  case 2:
    DAT_8017e5c1 = 1;
    DAT_8017e5c3 = 0;
    FUN_8017dc48(0,DAT_80119e74,DAT_8017e5cd);
    FUN_8017dc48(3,DAT_80119e73,DAT_8017e5cd);
    if (DAT_800dfbe9 != '\0') {
      (&DAT_8017e5c4)[DAT_8017e5cd] = 4;
      return;
    }
    break;
  case 3:
  case 4:
  }
  (&DAT_8017e5c4)[DAT_8017e5cd] = 0;
LAB_8017bf88:
  return;
}
