/* FUN_80163d90
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80163d90  body 0x80163d90..0x80163e07  size 120 B
 * body sha256 82fe8313910a3bb7cdff834a7817f638c6be8453d6691acf1d48d29239606463
 * provider record sha256 c5b1f3cfaf3ee89a5fc07530f523f27e4ccd794b26f4bbdc5f27372d00091462
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163d90(int param_1)

{
  int iVar1;
  
  iVar1 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0xc0);
  if ((iVar1 != 0) || ((*(ushort *)(param_1 + 0x2c6) & 2) == 0)) {
    FUN_80166294(param_1,0x15e);
    FUN_80165c68(param_1,4);
  }
  FUN_80165f80(param_1);
  return;
}
