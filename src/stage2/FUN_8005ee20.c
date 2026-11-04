/* FUN_8005ee20
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005ee20  body 0x8005ee20..0x8005ef07  size 232 B
 * body sha256 49f1881833e17600b1a3040869fadbd45d7712c04023f64ea0c6c4775ccef319
 * provider record sha256 af895bc3b5e29bd112cea74b2146473fdb0b39e7b2791af2b101cf9ecbf2234c
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005ee20(int param_1)

{
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  if ((uint)*(byte *)(param_1 + 0x1e9) % 3 == 1) {
    local_18 = 0x96;
    local_16 = 0x4b0;
    local_14 = 0;
    FUN_80037780(0x31d1200,(int)DAT_800e1196,*(int *)(param_1 + 0x234) + 0x1060,&local_18);
    DAT_80131781 = 1;
  }
  if (*(char *)(param_1 + 0x1e9) == '\x01') {
    FUN_80077adc(0x1000001,*(int *)(param_1 + 0x234) + 0x1044);
    FUN_8005d700(param_1);
  }
  if (*(char *)(param_1 + 0x1e9) == '\v') {
    FUN_80077adc(0x10b0001,*(int *)(param_1 + 0x234) + 0x1044);
  }
  return;
}
