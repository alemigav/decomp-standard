/* FUN_8015fc08
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015fc08  body 0x8015fc08..0x8015fd07  size 256 B
 * body sha256 5a9cdd2095b43753b21c60091263e5772aad87b72929024a28e9ae1bba4a39b6
 * provider record sha256 3a741bbd586f1d1d15b9a557beb8527505c4a08d81425ffaa20a3452f667e00b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015fc08(void)

{
  int iVar1;
  
  if (DAT_80160c30 != 0) {
    DAT_80160c30 = DAT_80160c30 + -2;
  }
  iVar1 = DAT_80160c34 + -1;
  if (-1 < DAT_80160c34) {
    DAT_80160c32 = (short)((iVar1 * iVar1 * 0x2e) / 0x1e4) + -0x2e;
    DAT_80160c34 = iVar1;
  }
  DAT_801613e6 = DAT_80160c32 + 0x4c;
  DAT_8016140e = DAT_801613e6;
  DAT_80161436 = DAT_801613e6;
  _DAT_800df8b4 = func_0x80043988(_DAT_800df8b4,&DAT_801613e0,0,0);
  _DAT_800df8b4 = func_0x80043988(_DAT_800df8b4,&DAT_80161408,0,0);
  _DAT_800df8b4 = func_0x80043988(_DAT_800df8b4,&DAT_80161430,0,0);
  return;
}
