/* FUN_800b44f4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b44f4  body 0x800b44f4..0x800b4533  size 64 B
 * body sha256 cadc1d76d8ea4b8b2f6389975250215b3d39a44652a3f3d900064e40aaad251e
 * provider record sha256 6edb57d6a54b4bfc3b27359ace80697a49c531fcb8c60100ba4918cdfa841e10
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800b44f4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_800b4818(param_2,param_1);
  osSendMesg(param_4,0,1);
  return;
}
