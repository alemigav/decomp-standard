/* FUN_80030edc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80030edc  body 0x80030edc..0x80030f17  size 60 B
 * body sha256 966c88ae1aef7ce5c60f3b7636d991d8a2b16d3c14ae3fb151dcbe09112ddc88
 * provider record sha256 fa7e43afb6950d08a39e5ad93c577c896b75f020fa84776b7b6e50ebd2a593d6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80030edc(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1 + -1 + param_2;
  if (param_2 == 0) {
    trap(0x1c00);
  }
  if ((param_2 == -1) && (iVar1 == -0x80000000)) {
    trap(0x1800);
  }
  return iVar1 - iVar1 % param_2;
}
