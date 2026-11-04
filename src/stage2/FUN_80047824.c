/* FUN_80047824
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047824  body 0x80047824..0x80047853  size 48 B
 * body sha256 6e0020ae917751c4271428386497cf9959878d817a3cecfed7f94ee571b8bbe1
 * provider record sha256 3793bbe006c55714b7c5417470d6856772a3c99b76ce2abc1a27af52b6a6653a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80047824(int param_1,char param_2,char param_3,char param_4,char param_5)

{
  *(char *)(param_1 + 0x10) = param_2;
  *(char *)(param_1 + 8) = param_2;
  *(char *)(param_1 + 0x20) = param_2 + param_4;
  *(char *)(param_1 + 0x18) = param_2 + param_4;
  *(char *)(param_1 + 0x19) = param_3;
  *(char *)(param_1 + 9) = param_3;
  *(char *)(param_1 + 0x21) = param_3 + param_5;
  *(char *)(param_1 + 0x11) = param_3 + param_5;
  return;
}
