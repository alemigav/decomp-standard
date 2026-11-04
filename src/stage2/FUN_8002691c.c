/* FUN_8002691c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002691c  body 0x8002691c..0x8002697f  size 100 B
 * body sha256 3a3b910048d1e3cfcd17cc9d5db519481c0ecae90467a348762cf9b90f1d45d2
 * provider record sha256 2495cdc2756463983a914434011053c31ab594d113bb4c9b8756bef9530c3371
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002691c(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  DAT_801127f8 = (float)((param_1 - param_3) - param_4) / 320.0;
  DAT_801127fc = (float)((param_2 - param_5) - param_6) / 240.0;
  return;
}
