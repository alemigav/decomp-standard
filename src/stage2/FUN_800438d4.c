/* FUN_800438d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800438d4  body 0x800438d4..0x8004392f  size 92 B
 * body sha256 ea4fcbb8fd715ee073f9fca7fc62d38ebdda5902b9e39b7a9f7a48c533d42922
 * provider record sha256 883221e0bfed4d84d8d76178f5a0ac1a7c9c6af85006c53a4593b3d80171ab44
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800438d4(undefined4 param_1,int param_2,int param_3)

{
  DAT_800efd94 = 0xffffffff;
  DAT_800efd9c = 0;
  for (; param_2 != param_3; param_2 = param_2 + 0x10) {
    param_1 = FUN_80043930(param_1,param_2);
  }
  return param_1;
}
