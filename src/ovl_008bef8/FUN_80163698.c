/* FUN_80163698
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80163698  body 0x80163698..0x80163763  size 204 B
 * body sha256 c2406bfff390dbcdc0841f43be68486454b93c564786f828378b0e611e240375
 * provider record sha256 bdbebdf02f64349b745c2c5b861f7fa8209cc9682b597ac8b43f1e3b9be23c58
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80163698(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1 - param_2;
  if (param_2 == 0) {
    return param_3;
  }
  iVar1 = param_3 * (iVar2 + 1) * (iVar2 + 1);
  param_1 = param_1 * param_1;
  if (param_1 == 0) {
    trap(0x1c00);
  }
  if ((param_1 == -1) && (iVar1 == -0x80000000)) {
    trap(0x1800);
  }
  iVar2 = param_3 * iVar2 * iVar2;
  if (param_1 == 0) {
    trap(0x1c00);
  }
  if ((param_1 == -1) && (iVar2 == -0x80000000)) {
    trap(0x1800);
  }
  return iVar1 / param_1 - iVar2 / param_1;
}
