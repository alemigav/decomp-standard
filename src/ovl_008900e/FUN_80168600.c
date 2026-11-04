/* FUN_80168600
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80168600  body 0x80168600..0x80168653  size 84 B
 * body sha256 ab5b46a11cf56bb2a6ba839c0da75d9a59028f4dfeff252494fd1e1d68500d31
 * provider record sha256 55f377a51d799297258a384b2ece68acf78354de5178a395008dfd2639d3d3f7
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80168600(int param_1,int param_2,int param_3,uint param_4,short param_5,int param_6,
                 undefined4 param_7)

{
  func_0x80037780(param_2 << 0x18 | param_3 << 0x10 | param_4,(int)param_5,
                  *(int *)(param_1 + 0x234) + param_6 * 0x178 + 0x38,param_7);
  return;
}
