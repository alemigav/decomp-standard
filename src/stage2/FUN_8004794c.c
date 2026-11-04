/* FUN_8004794c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004794c  body 0x8004794c..0x80047983  size 56 B
 * body sha256 0c3f9b0d48b1aff6c239174d34a35bbd5d3a03c87353861c63aae6f3e52e5028
 * provider record sha256 fd44b2152aaf1d9342d6f8aba1678168dae45d002c0585ae5ae9d9123da682db
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004794c(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                 undefined1 param_9)

{
  *(undefined1 *)(param_1 + 8) = param_2;
  *(undefined1 *)(param_1 + 9) = param_3;
  *(undefined1 *)(param_1 + 0x10) = param_4;
  *(undefined1 *)(param_1 + 0x11) = param_5;
  *(undefined1 *)(param_1 + 0x18) = param_6;
  *(undefined1 *)(param_1 + 0x19) = param_7;
  *(undefined1 *)(param_1 + 0x20) = param_8;
  *(undefined1 *)(param_1 + 0x21) = param_9;
  return;
}
