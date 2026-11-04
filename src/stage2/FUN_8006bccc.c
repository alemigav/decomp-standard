/* FUN_8006bccc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006bccc  body 0x8006bccc..0x8006bd37  size 108 B
 * body sha256 b3a5d46bc42ec082a2125262b4a804b5dcb25dd2e65f0ffdddd6903c7933e0ab
 * provider record sha256 41e5c6f05dc020bce1bb5c54960545652ee932acdd0b81ed8e584ae4a9d781a6
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006bccc(int param_1)

{
  while (DAT_801127e0 + param_1 != 0) {
    osRecvMesg(0x80139fb0,&DAT_801127ec,1);
  }
  return;
}
