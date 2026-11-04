/* FUN_8017c31c
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017c31c  body 0x8017c31c..0x8017c4ef  size 468 B
 * body sha256 f352b103d05ea02e984ebb93a47a7a34cb7f2393511b3a54030c93f0a8271f17
 * provider record sha256 6c739a0f5e917302f29eebac0a14b27ec2481d0615df05d7c462e4ed53cbd2be
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017c31c(void)

{
  int iVar1;
  
  iVar1 = *(int *)(_DAT_800df92c + 0x2c) + _DAT_800e8cac * 0x28;
  if ((_DAT_800e10ec & 0x100) != 0) {
    if (DAT_8017e704 - 6 < 4) {
      *(undefined1 *)(iVar1 + 10) = 0xff;
      *(undefined1 *)(iVar1 + 0xb) = 0;
      *(undefined1 *)(iVar1 + 0xc) = 0;
      *(undefined2 *)(iVar1 + 0x26) = 20000;
    }
    else if ((DAT_8017e704 - 10 & 0xffff) < 0xb) {
      *(char *)(iVar1 + 10) = *(char *)(iVar1 + 10) + -0xc;
      *(char *)(iVar1 + 0xb) = *(char *)(iVar1 + 0xb) + '\r';
      *(char *)(iVar1 + 0xc) = *(char *)(iVar1 + 0xc) + '\r';
      *(short *)(iVar1 + 0x26) = *(short *)(iVar1 + 0x26) + -0x4b0;
    }
  }
  if (DAT_8017e704 == 0) {
    if (((_DAT_800e10ec & 0x100) != 0) && (DAT_8017e735 == '\0')) {
      FUN_8017e20c(0xc68);
      DAT_8017e735 = '\x01';
    }
    FUN_8017c8a0();
  }
  DAT_8017e900 = func_0x80025b0c();
  func_0x80026980(0);
  FUN_8017c8f0();
  FUN_8017c664();
  DAT_8017e704 = DAT_8017e704 + 1;
  if (DAT_8017e704 == 0xaa) {
    DAT_8017e700 = 10;
    DAT_8017e736 = 2;
    DAT_8017e72e = 0x10;
    DAT_8017e704 = 0;
    DAT_8017e702 = DAT_8017e702 + 1;
  }
  *(undefined2 *)(DAT_8017e8e0 + 0x10f56) = 1;
  *(undefined1 *)(iVar1 + 4) = 0x3c;
  *(undefined1 *)(iVar1 + 5) = 0x3c;
  *(undefined1 *)(iVar1 + 6) = 0x3c;
  return;
}
