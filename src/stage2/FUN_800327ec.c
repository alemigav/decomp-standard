/* FUN_800327ec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800327ec  body 0x800327ec..0x8003287b  size 144 B
 * body sha256 54bfb87f3ad4ea1c41a313c2de524b17c27740e1e6b88827f673b56ad766ee1d
 * provider record sha256 8ca7c7fd7446813811a96733d4b1690b0277164e410f8863d5fa849077ccaf52
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800327ec(undefined4 *param_1,int param_2)

{
  undefined1 auStack_68 [20];
  undefined4 local_54;
  
  if (param_1[1] != 0) {
    if (param_1[1] != param_1[3] - param_1[2]) {
      inflate_init(auStack_68,DAT_8010b6f8);
      inflate(auStack_68,*param_1,*(undefined4 *)(param_2 + 8),param_1[1]);
      inflate_free(auStack_68,2);
      return local_54;
    }
    FUN_800888ec(*param_1);
  }
  return 0;
}
