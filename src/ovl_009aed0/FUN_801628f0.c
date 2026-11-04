/* FUN_801628f0
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x801628f0  body 0x801628f0..0x801629c3  size 212 B
 * body sha256 c7444aacc9297b1f04edeb31f5e8895cb32d66d85b1e54a7bbc791330ac6f5b6
 * provider record sha256 4a7e32c457ea095bb5bd29dd67b3a67c6f413de0a83e199fd5b23305c8b710ae
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801628f0(int param_1,int param_2,int param_3,uint param_4,short param_5,int param_6,
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
