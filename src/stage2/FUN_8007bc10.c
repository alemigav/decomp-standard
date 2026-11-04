/* FUN_8007bc10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007bc10  body 0x8007bc10..0x8007bc93  size 132 B
 * body sha256 a95cacba0f055ea6028ed1e361269c543d4d0cd283c952e27faa9975a3d474dc
 * provider record sha256 76a123d0ab560d8d493792fc80edb771d2ffe5676003f278b7f4e68d9e99b73b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007bc10(int param_1)

{
  byte bVar1;
  
  if ((*(ushort *)(param_1 + 0xe) & 0x8000) == 0) {
    *(undefined1 *)(param_1 + 0x2bf) = 0;
  }
  else {
    bVar1 = *(char *)(param_1 + 0x2bf) + 1U & 0x7f;
    *(byte *)(param_1 + 0x2bf) = bVar1;
    if (0x3c < bVar1) {
      *(byte *)(param_1 + 0x2bf) = bVar1 | 0x80;
    }
  }
  if (*(char *)(param_1 + 0x2c6) != '\0') {
    *(char *)(param_1 + 0x2c6) = *(char *)(param_1 + 0x2c6) + -1;
  }
  if ((*(char *)(param_1 + 8) == 'E') || (*(char *)(param_1 + 8) == 'O')) {
    FUN_8007efe8();
  }
  else {
    FUN_8007bc9c();
  }
  return;
}
