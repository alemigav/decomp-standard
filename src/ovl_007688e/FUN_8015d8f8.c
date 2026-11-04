/* FUN_8015d8f8
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015d8f8  body 0x8015d8f8..0x8015daaf  size 440 B
 * body sha256 a76a4a3d01280ccad38d30ad742f47c9974fae4ffca0814ec764a936fcc0dbb0
 * provider record sha256 d8e8ee14985faca1e759c2d1d0a27f96150dbb3ed4f98427aaf3bec087878d5f
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015d8f8(void)

{
  int iVar1;
  
  func_0x800275c0(3,0x7c00,0,0);
  if (DAT_80160c1e == 1) {
    DAT_80160c27 = DAT_80160c27 + '\x01';
    FUN_8015f9e4(DAT_80160c27,0x80,0);
    if (-1 < DAT_80160c27) goto LAB_8015da4c;
    DAT_80160c27 = -0x80;
    DAT_80160c2e = -0x100;
    DAT_80160c2c = 0x5a00;
  }
  else {
    if (1 < DAT_80160c1e) {
      if (DAT_80160c1e == 2) {
        FUN_8015f9e4(0x80,0x80,0);
        DAT_80160c2c = DAT_80160c2c + DAT_80160c2e;
        func_0x800275c0(3,(int)DAT_80160c2c,0,0);
        iVar1 = func_0x8002767c(3);
        if (iVar1 != 0) {
          func_0x80077adc(0x4060000,0);
          DAT_80160c2e = 0;
          DAT_80160c2c = -1;
          DAT_80160c1d = '\x01';
        }
      }
      goto LAB_8015da4c;
    }
    if (DAT_80160c1e != 0) goto LAB_8015da4c;
    DAT_80160c26 = DAT_80160c26 + '\x02';
    FUN_8015f9e4(0,DAT_80160c26,0);
    if (-1 < DAT_80160c26) goto LAB_8015da4c;
    DAT_80160c26 = -0x80;
  }
  DAT_80160c1e = DAT_80160c1e + 1;
LAB_8015da4c:
  if ((_DAT_800df90e & 0x9ff) != 0) {
    func_0x80077adc(0x4060000,0);
    DAT_80160c2e = -0x1000;
    DAT_80160c1d = DAT_80160c1d + '\x01';
    if (DAT_80160c2c == 0) {
      DAT_80160c2c = 0x5a00;
    }
  }
  return;
}
