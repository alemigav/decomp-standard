/* FUN_80167ae4
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80167ae4  body 0x80167ae4..0x80167b17  size 52 B
 * body sha256 4e174a62ee8c91adac192b6354f3757f9ec1e2ad3617c23ae8e3acf4109aa13f
 * provider record sha256 f39cacefa646a066a6a0a9e9ba554357dadbb3816c75cb9db123acbf732e1cc6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80167ae4(int param_1)

{
  (**(code **)(&DAT_801682d8 + (uint)*(byte *)(param_1 + 5) * 4))();
  return;
}
