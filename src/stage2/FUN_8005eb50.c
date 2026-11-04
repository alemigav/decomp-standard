/* FUN_8005eb50
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005eb50  body 0x8005eb50..0x8005eb97  size 72 B
 * body sha256 a3be2a490bd751106d8f2d1071b97e5a1272902546dd51171ba03c94c49a2f91
 * provider record sha256 dbd70d18dc43c9a3977681c29bc988362245c2847c6a57c92f4e243c445506b4
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005eb50(int param_1)

{
  if ((**(uint **)(param_1 + 0x214) & 0x100000) != 0) {
    FUN_80077adc(**(uint **)(param_1 + 0x214) & 0xf0000 | 0x1000001,param_1 + 0x28);
  }
  return;
}
