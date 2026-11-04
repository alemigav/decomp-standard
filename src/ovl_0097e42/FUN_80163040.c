/* FUN_80163040
 * image   ovl_0097e42 (ovl), base 0x80161cf0
 * address 0x80163040  body 0x80163040..0x801630c7  size 136 B
 * body sha256 9b7b62dc6e88c879b3d71e8f9023a2467beec7cc67b90d6425b67a89f5438bfc
 * provider record sha256 6c10f453b0a4657e17a484cf776d2f1e297719b99b55680e71512276e831a1f0
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163040(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 5) != -1) {
    FUN_80163638(param_1,*(char *)(param_1 + 5));
    *(undefined1 *)(param_1 + 5) = 0xff;
    FUN_80163020(param_1);
  }
  (*(code *)(&PTR_FUN_80163934)[*(byte *)(param_1 + 0x26e)])(param_1,param_2,param_3);
  return;
}
