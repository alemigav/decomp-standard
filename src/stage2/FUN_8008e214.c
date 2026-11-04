/* FUN_8008e214
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008e214  body 0x8008e214..0x8008e277  size 100 B
 * body sha256 6c2e2a09f068118ee7af8975162bdde7f62351e93fb596c6318fbe8fbea5f09e
 * provider record sha256 4d953bdbff9fb0ce16869e8d87983f03725131beabefd1d21e5260c91d62e7ca
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008e214(undefined4 param_1,int param_2)

{
  short sVar1;
  int unaff_s0;
  
  if (*(char *)(unaff_s0 + 0x62) == '\0') {
    *(undefined1 *)(unaff_s0 + 4) = 2;
    *(ushort *)(param_2 + 0x19c70) = *(ushort *)(param_2 + 0x19c70) & 0xefff;
    sVar1 = *(short *)(param_2 + 0x19c72) + *(short *)(unaff_s0 + 0x3588);
    *(short *)(param_2 + 0x19c72) = sVar1;
    if (*(short *)(param_2 + 0x19c7e) <= sVar1) {
      *(undefined2 *)(param_2 + 0x19c72) = *(undefined2 *)(param_2 + 0x19c7e);
    }
  }
  return;
}
