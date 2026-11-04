/* FUN_800b4818
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b4818  body 0x800b4818..0x800b4927  size 272 B
 * body sha256 6a4a69795e9dc5a89859d70fbbb863e3095708b89b7c15b278898d0d4e2f548c
 * provider record sha256 3d22930e8f9bfc2fac061495f36343ca56edf2952ee518d4d4346d1075d419f7
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800b4818(undefined4 param_1,undefined4 param_2,int param_3)

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
  }
  FUN_800a56c0();
  return;
}
