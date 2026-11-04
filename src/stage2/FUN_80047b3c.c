/* FUN_80047b3c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047b3c  body 0x80047b3c..0x80047b57  size 28 B
 * body sha256 b9d5909d64aa588f15d1a96ca391d21efe748979194a537755d4dfa8f645c62d
 * provider record sha256 f86d496f7416701af2ba647f4737d346e44f5211012f2868cc9998c2d877c327
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80047b3c(int param_1,short param_2)

{
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 3) = 0;
    return;
  }
  *(undefined1 *)(param_1 + 3) = 2;
  return;
}
