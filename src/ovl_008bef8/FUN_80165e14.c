/* FUN_80165e14
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80165e14  body 0x80165e14..0x80165ee7  size 212 B
 * body sha256 69c64dd2c22faf0f8fe78e51de7c9abd470c247c093d6e1a344fddffbe26c8d6
 * provider record sha256 63da2d7ade65214868dfa48b345dceb96be34b893e7ff49f149fa511c1969e44
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165e14(int param_1,int param_2,int param_3,uint param_4,short param_5,int param_6,
                 undefined4 param_7)

{
  int iVar1;
  short local_20;
  short local_1e;
  short local_1c;
  
  iVar1 = *(int *)(param_1 + 0x234) + param_6 * 0x178;
  func_0x8004276c(iVar1 + 0x38,param_7,&local_20);
  local_20 = local_20 + *(short *)(iVar1 + 0x4e);
  local_1e = local_1e + *(short *)(iVar1 + 0x52);
  local_1c = local_1c + *(short *)(iVar1 + 0x56);
  func_0x80037780(param_2 << 0x18 | param_3 << 0x10 | param_4,(int)param_5,0x800e9028,&local_20);
  return;
}
