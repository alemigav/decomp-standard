/* FUN_8004789c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004789c  body 0x8004789c..0x800478ab  size 16 B
 * body sha256 2809762fdba0e2de8a83e03fc34d57bcf214f77b3310d9d000cb5683e9612e67
 * provider record sha256 0744bdfa944feb71cda34093b7e2a168e9f7d06ab88a1f4a6239ed4c16223cfc
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004789c(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  *(undefined1 *)(param_1 + 4) = param_2;
  *(undefined1 *)(param_1 + 5) = param_3;
  *(undefined1 *)(param_1 + 6) = param_4;
  return;
}
