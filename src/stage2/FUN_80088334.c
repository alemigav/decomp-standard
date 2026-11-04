/* FUN_80088334
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80088334  body 0x80088334..0x8008836b  size 56 B
 * body sha256 3111bbf7104bdfd6f642ff644a625cd08596b54829a86106918cdd37274f45dd
 * provider record sha256 b95ac0b84998a1fa4ccd5e695aab9cfa86aefe10ba600bdc175cd31f58c9c3de
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80088334(int param_1)

{
  *(undefined4 *)(&DAT_8012a040 + param_1 * 8) = 4;
  *(int *)(&UNK_8012a044 + param_1 * 8) = param_1;
  FUN_800879a0();
  return;
}
