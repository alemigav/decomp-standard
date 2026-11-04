/* FUN_80164398
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80164398  body 0x80164398..0x801643d3  size 60 B
 * body sha256 af84503bd6b37c2f9c535d946fd87d34b249972f1fbd8a916e2caea22c439d4c
 * provider record sha256 cd6fae95c570e095062b35ce84a63f62c38af6b708e6ef88af98aebee6c9e258
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164398(int param_1)

{
  *(undefined2 *)(param_1 + 100) = 0;
  (*(code *)(&PTR_FUN_80166734)[*(byte *)(param_1 + 5) - 1])();
  return;
}
