/* FUN_801627a8
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x801627a8  body 0x801627a8..0x80162823  size 124 B
 * body sha256 ee49b75b6058a9e66013764a9f1c394558448920d165de760a794ea6556d4b9d
 * provider record sha256 45d86c4c4e87ad2d0a5a38aa2f85b71b38969e628975efa27b1b9a11d1770865
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801627a8(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_80168024)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_80168024)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
