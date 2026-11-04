/* FUN_8015dab0
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015dab0  body 0x8015dab0..0x8015de0b  size 860 B
 * body sha256 1d777acea975bda8d374ff250d609dedc8b8f0c10df3b1f10aaef503604289fc
 * provider record sha256 50a1376547fdbc84a1905fe53de32332c067975e0d9b57c1eeef5ff1dcfba4a7
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015dab0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_80160c2c = DAT_80160c2c + DAT_80160c2e;
  func_0x800275c0(3,(int)DAT_80160c2c,0,0);
  iVar1 = func_0x8002767c(3);
  if (iVar1 != 0) {
    DAT_80160c2e = 0;
    DAT_80160c2c = -1;
  }
  if (((_DAT_800df918 & 0x1000) != 0) || ((_DAT_800df908 & 0x800) != 0)) {
    iVar1 = func_0x8002767c(3);
    if (iVar1 != 0) {
      if (DAT_80160c22 == '\0') {
        DAT_80160c1c = 2;
        DAT_80160c1d = 3;
        _DAT_800e10ec = _DAT_800e10ec | 0x20000;
        func_0x80077adc(0x4000000,0);
        func_0x800274f8(0x100,0xfffff800,7,1);
        while (iVar1 = func_0x8002767c(0), iVar1 == 0) {
          FUN_8015f9e4(0x80,0x80,1);
          FUN_8015f818();
          func_0x8004cd88(1);
        }
        uVar2 = 0x80;
      }
      else {
        DAT_80160c1c = 1;
        DAT_800e9012 = 0;
        func_0x80077adc(0x4050000,0);
        uVar2 = 0x1800;
        _DAT_800e10ec = _DAT_800e10ec & 0xfffffff6;
      }
      func_0x800274f8(0x200,uVar2,7,1);
      func_0x800275c0(0,0x200,0x1085,0);
      while (iVar1 = func_0x8002767c(0), iVar1 == 0) {
        FUN_8015f9e4(0x80,0x80,1);
        FUN_8015f818();
        func_0x8004cd88(1);
      }
      func_0x800274f8(0x200,0,7,1);
      func_0x800275c0(0,0x7fff,0xffff,0);
      func_0x8004cd88(1);
      if (DAT_80160c22 != '\0') {
        func_0x8007608c(0x11,0);
      }
      FUN_8015b26c();
      return;
    }
    DAT_80160c2e = -0x1000;
  }
  DAT_80160c23 = DAT_80160c23 + DAT_80160c24;
  if (0x2f < (byte)(DAT_80160c23 - 1U)) {
    DAT_80160c24 = -DAT_80160c24;
  }
  if (((_DAT_800df90e & 0x1000) != 0) && (DAT_80160c22 == '\x01')) {
    func_0x80077adc(0x4040000,0);
    DAT_80160c22 = '\0';
  }
  if (((_DAT_800df90e & 0x4000) != 0) && (DAT_80160c22 == '\0')) {
    func_0x80077adc(0x4040000,0);
    DAT_80160c22 = '\x01';
  }
  DAT_80160c26 = DAT_80160c26 + 0x10;
  if ((int)((uint)DAT_80160c26 << 0x18) < 0) {
    DAT_80160c26 = 0x80;
  }
  DAT_80160c27 = DAT_80160c27 + 0x10;
  if ((int)((uint)DAT_80160c27 << 0x18) < 0) {
    DAT_80160c27 = 0x80;
  }
  FUN_8015f9e4(DAT_80160c27,DAT_80160c26,0);
  FUN_8015f818();
  return;
}
