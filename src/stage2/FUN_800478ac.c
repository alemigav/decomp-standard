/* FUN_800478ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800478ac  body 0x800478ac..0x800478b7  size 12 B
 * body sha256 e35941533922404b8943e83d94c5b4e8f4ca161897181954618b931dfd6504ce
 * provider record sha256 a482f2ae27ffcf74f43c1c927a250d0706b2edf6a4620a75ad4a703922bf3009
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800478ac(int param_1,undefined1 param_2,undefined1 param_3)

{
  *(undefined1 *)(param_1 + 8) = param_2;
  *(undefined1 *)(param_1 + 9) = param_3;
  return;
}
