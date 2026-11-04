/* FUN_80092994
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80092994  body 0x80092994..0x80092a17  size 132 B
 * body sha256 32e4ba53b7a0a4f7e0b6da3851656fc55774d7c884cd1b7f4b80464493bdb855
 * provider record sha256 19244ae372e206754021d6ccb70477d696d188f00ded1d7ba0a9b5e062028e4a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80092994(void)

{
  if ((DAT_800df90c & 0x4000) == 0) {
    if ((DAT_800df918 & 0x3000) != 0) {
      FUN_80077adc(0x4060000,0);
      DAT_8012bf99 = '\0';
    }
  }
  else {
    DAT_8012bfa4 = 1;
    DAT_8012bf99 = DAT_8012bf99 + '\x01';
    FUN_80077adc(0x4040000,0);
  }
  return;
}
