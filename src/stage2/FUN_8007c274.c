/* FUN_8007c274
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007c274  body 0x8007c274..0x8007c2ef  size 124 B
 * body sha256 8b7597c4942bd3f2ebe64b588661f60699454f9b20f1c56c4fc5713ab21fdad9
 * provider record sha256 ff21a3e719532a23ce51ab616daf1bd9c3b436d928a201d6f3d9b476629ce4ae
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007c274(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b1e8)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
