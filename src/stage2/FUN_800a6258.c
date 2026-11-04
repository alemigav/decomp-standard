/* FUN_800a6258
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a6258  body 0x800a6258..0x800a62b3  size 92 B
 * body sha256 9d2ddadd512b978b57f2ea48753d2b1166a61c826cf897a3e7f0a54ea8e5fb88
 * provider record sha256 d6de7dfcd34df0425cd1fbbbe85d40777e8d12023bbe12c49f633d39304097d3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
double FUN_800a6258(double param_1)

{
  uint uVar1;
  double dVar2;
  
  if (param_1 < 2147483648.0) {
    uVar1 = (uint)param_1;
  }
  else {
    uVar1 = (int)(param_1 - 2147483648.0) | 0x80000000;
  }
  dVar2 = (double)(int)uVar1;
  if ((int)uVar1 < 0) {
    dVar2 = dVar2 + 4294967296.0;
  }
  return dVar2;
}
