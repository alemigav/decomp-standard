/* FUN_8017e0cc
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017e0cc  body 0x8017e0cc..0x8017e247  size 380 B
 * body sha256 c6fa134daf36d09019accd5682b387d10c7589fe021295f5c29d921f4da26011
 * provider record sha256 42915223a907db6476be014f43c6d630103f95e402c0a2c9733d349c660edbdd
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017e0cc(void)

{
  int iVar1;
  short sVar2;
  
  func_0x800274f8(0x103,0,7,1);
  func_0x800275c0(3,0,0,0);
  func_0x80082498(&DAT_80180d78,0x45d);
  DAT_800e9182 = 2;
  func_0x800274e4(0,1);
  func_0x800274f8(0x200,0xffffe800,7,1);
  while (iVar1 = func_0x8002767c(0), iVar1 == 0) {
    func_0x8004cd88(1);
  }
  FUN_8017b580(0x21);
  FUN_8017b580(0x21);
  DAT_80180d90 = 0;
  sVar2 = FUN_8017b580(0x21);
  DAT_80180d9c = (short)((0x68 - sVar2) / 2) + -4;
  DAT_80180d9e = 0x32;
  sVar2 = FUN_8017b580(0x21);
  DAT_80180d8d = 0;
  DAT_80180da0 = sVar2 + 0xe2;
  DAT_80180da2 = 0x6a;
  DAT_80180d8e = 0;
  DAT_80180d92 = 0;
  DAT_80180d8f = 0;
  func_0x8004cd88(2);
  return;
}
