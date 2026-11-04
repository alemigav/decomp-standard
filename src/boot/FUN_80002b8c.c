/* FUN_80002b8c
 * image   boot (boot), base 0x80000480
 * address 0x80002b8c  body 0x80002b8c..0x80002bb3  size 40 B
 * body sha256 a3faa7a086880bd5fdc47082f94180e825c579a503acd4831380e34214627718
 * provider record sha256 5c5e3b7075e5c2d21f3f602f0dcb2a8b14cedc2c998b9e14b3f673f29a29666c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80002b8c(undefined4 param_1,int param_2)

{
  (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),param_1);
  return;
}
