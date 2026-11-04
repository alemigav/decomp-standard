/* FUN_80163d10
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80163d10  body 0x80163d10..0x80163da3  size 148 B
 * body sha256 9b031e2f07741c0676041d27b4a309e7602df7ec6a2b5cd7025db4c9f0a0141b
 * provider record sha256 e4f64454157ac883790de670f95bed3c6e808114b07589e3f9bb0cf55c10fedf
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163d10(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined2 *)((int)param_1 + 6) = 0x100;
  *(undefined2 *)(param_1 + 0x19) = 0;
  *param_1 = *param_1 | 4;
  FUN_801665a0(param_1,1);
  *(undefined2 *)(param_1 + 0x78) = 0x30f;
  *(undefined2 *)(param_1 + 0x79) = 0;
  func_0x80032b5c(param_1,0);
  *(undefined2 *)(param_1 + 0x1a) = 0xfc00;
  param_1[0x7a] = 0x8000000;
  func_0x80089d54(param_1,param_2,param_3,0x100);
  return;
}
