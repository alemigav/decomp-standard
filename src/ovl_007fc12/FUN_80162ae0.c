/* FUN_80162ae0
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80162ae0  body 0x80162ae0..0x80162b5b  size 124 B
 * body sha256 c43cf4a456a75ca27c22408c74908215bf24d9d961b8f5f1d417fccf1f5251f7
 * provider record sha256 853291f80862ed813056dbd3a51f13cc13b4bb37cb7777d19553583f04440c9f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162ae0(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8016e22c)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8016e238)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
