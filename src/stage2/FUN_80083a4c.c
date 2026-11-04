/* FUN_80083a4c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80083a4c  body 0x80083a4c..0x80083ac3  size 120 B
 * body sha256 18a1a37b3e4779b4b4bf3ef2798b737e9597d962de338e9e0aa9a25951f647db
 * provider record sha256 37785de43cba987de161f89b02893dbd26524e83ac3e420842b527d1ce44bac5
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80083a4c(int param_1)

{
  short local_10 [2];
  short local_c;
  
  local_c = 0;
  local_10[0] = (short)((int)((uint)*(ushort *)(param_1 + 300) * 0xb3) >> 7);
  FUN_800837d0((int)*(short *)(param_1 + 0x66),local_10,local_10);
  *(short *)(param_1 + 0x1f8) = *(short *)(param_1 + 0x2a) + local_10[0];
  *(short *)(param_1 + 0x1fc) = *(short *)(param_1 + 0x32) + local_c;
  return;
}
