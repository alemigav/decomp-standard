/* FUN_800b467c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b467c  body 0x800b467c..0x800b47b7  size 316 B
 * body sha256 3b75ef572ca0631f4a644fe2a96f24cd224f45920b2655532ee8b69ba0f85e6a
 * provider record sha256 281d19d111887a404fa2393299610b4eb50841fe9f7fbb29ebffaeba4594e4e8
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800b467c(undefined4 param_1,undefined4 param_2,int param_3)

{
  FUN_800a5678();
  if (_DAT_80143fd4 == (code *)0x0) {
    osCreateMesgQueue(0x8015b010,0x8015b028,1);
    DAT_8015afc0 = 0;
    _DAT_80143fd4 = FUN_800b4540;
  }
  if (DAT_8015afc0 < 4) {
    *(undefined4 *)((uint)DAT_8015afc0 * 0xc + -0x7fea5030) = param_1;
    *(undefined4 *)((uint)DAT_8015afc0 * 0xc + -0x7fea502c) = param_2;
    *(uint *)((uint)DAT_8015afc0 * 0xc + -0x7fea5028) = param_3 + 0xfU & 0xfffffff0;
    DAT_8015afc0 = DAT_8015afc0 + 1;
    func_0x80007320(param_1,param_3);
    FUN_800a56c0();
    osRecvMesg(0x8015b010,0,1);
    func_0x80011390();
  }
  else {
    FUN_800a56c0();
  }
  return;
}
