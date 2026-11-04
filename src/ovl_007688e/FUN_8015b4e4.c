/* FUN_8015b4e4
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015b4e4  body 0x8015b4e4..0x8015b5cf  size 236 B
 * body sha256 dd86040c3f9f40b8703462eb84ac8d38ccf057b2d5e0e0d07b0f4a681b35cbdf
 * provider record sha256 a2e10ec6105e603e28e388c7b1faa52b702156bb852c07e108ec81eedec77c2d
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015b4e4(void)

{
  int iVar1;
  
  DAT_80160c2c = DAT_80160c2c + DAT_80160c2e;
  func_0x800274f8(0x200,0,7,1);
  func_0x800275c0(0,(int)DAT_80160c2c,0,0);
  iVar1 = func_0x8002767c(0);
  if (iVar1 != 0) {
    DAT_80160c2e = 0;
    DAT_80160c2c = -1;
  }
  if ((_DAT_800df90e & 0x9ff) == 0) {
    iVar1 = func_0x8002767c(0);
    if (iVar1 == 0) goto LAB_8015b5b8;
    if ((_DAT_800df90e & 0x9ff) != 0) goto LAB_8015b58c;
  }
  else {
LAB_8015b58c:
    func_0x80077adc(0x4060000,0);
  }
  DAT_80160c2e = -0x1000;
  DAT_80160c2a = 0;
  DAT_80160c1d = 1;
  DAT_80160c1e = 0;
  DAT_80160c1f = 0;
LAB_8015b5b8:
  FUN_8015fbb8();
  return;
}
