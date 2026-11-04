/* FUN_8016332c
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x8016332c  body 0x8016332c..0x801633bb  size 144 B
 * body sha256 2545778792117675911158f3350bdc49f00e9475cbdb8c72ab49a027553bd82e
 * provider record sha256 9ff3b6f125aafe1ad501457000475df5ddc86c2cb38f6cb7aa9b091927e41749
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016332c(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_LAB_8016684c)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_LAB_80166894)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  func_0x80036c44(param_1,*(undefined4 *)(param_1 + 0x2b4));
  *(undefined4 *)(param_1 + 0x2b4) = *(undefined4 *)(param_1 + 4);
  return;
}
