/* FUN_80167ba4
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80167ba4  body 0x80167ba4..0x80167c87  size 228 B
 * body sha256 51f46b04df201ea91de78cbfed75da5b9afbf32a9e29ee997fb5156f3036ff46
 * provider record sha256 e4b816bab701de2a55ca646ca359a0332a947b0cb1697f8c34464c5ee1f9340e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80167ba4(int param_1)

{
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  
  local_10 = 0;
  local_e = 200;
  local_c = 0;
  func_0x80037780(0x5032710,(int)*(short *)(param_1 + 0x66),*(int *)(param_1 + 0x234) + 0x38,
                  &local_10);
  if ((*(uint *)(*(int *)(param_1 + 0x234) + 0x468) & 1) != 0) {
    func_0x80037780(0x50313e8,(int)*(short *)(param_1 + 0x66),*(int *)(param_1 + 0x234) + 0x4a0,
                    &local_10);
  }
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x60) = 0x404040;
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x1d8) = 0x484848;
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x350) = 0x707070;
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x7b8) = 0x707070;
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0xd98) = 0x505050;
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0xf10) = 0x484848;
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x1088) = 0x404040;
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x1200) = 0x505050;
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x1378) = 0x404040;
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x14f0) = 0x404040;
  return;
}
