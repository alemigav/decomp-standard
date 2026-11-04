/* FUN_8016490c
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x8016490c  body 0x8016490c..0x801649ab  size 160 B
 * body sha256 8bf3f3fd40885215cfa99a85f354e7772b65d68c9c0b74e85c9fb287953da681
 * provider record sha256 8a4d63680623516299f74804c36319365463adcc7a13c8d84fe53668742d0844
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016490c(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 6) == '\0') {
    FUN_80166270(param_1,0,7);
    FUN_80164684(param_1,param_2,param_3);
  }
  else {
    (*(code *)(&PTR_FUN_801667a8)[*(byte *)(param_1 + 6)])(param_1,param_2,param_3);
    func_0x80089d54(param_1,param_2,param_3,0x100);
  }
  return;
}
