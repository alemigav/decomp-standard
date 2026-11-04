/* FUN_80164e84
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80164e84  body 0x80164e84..0x80164f13  size 144 B
 * body sha256 fca44857684c1691c58680c3827fea49f4866061261f111f5de6320712299e27
 * provider record sha256 602f3401c1c97a7ce4d35fa3bf2d4e44793a362589d06a273ccc5d8a179857c5
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164e84(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 6) == '\0') {
    FUN_80164684();
    *(undefined1 *)(param_1 + 0x2cf) = 0x14;
  }
  else {
    (*(code *)(&PTR_FUN_801667a8)[*(byte *)(param_1 + 6)])(param_1,param_2,param_3);
    func_0x80089d54(param_1,param_2,param_3,0x100);
  }
  return;
}
