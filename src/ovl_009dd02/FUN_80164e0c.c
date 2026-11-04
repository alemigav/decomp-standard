/* FUN_80164e0c
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80164e0c  body 0x80164e0c..0x80164e87  size 124 B
 * body sha256 1effb11b7619bc159d73b418dcd496864cfc499e38a785c5509ee054ca5a8861
 * provider record sha256 966cb074e434d43634e9ad4de1d977e585e09e158cf875f66084f2ff7f90f433
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164e0c(int param_1)

{
  (*(code *)(&PTR_FUN_801672f0)[*(byte *)(param_1 + 5) - 1])();
  FUN_80166a44(param_1);
  FUN_80166584(param_1);
  func_0x800347b0(param_1,(int)(((uint)*(ushort *)(param_1 + 0x66) +
                                (uint)*(byte *)(param_1 + 0x2cd) * 0x800) * 0x10000) >> 0x10);
  FUN_80166978(param_1);
  return;
}
