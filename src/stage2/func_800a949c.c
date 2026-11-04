/* func_800a949c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a949c  body 0x800a949c..0x800a953f  size 164 B
 * body sha256 a80b5a73a1e13539a219705e1500988de50f4ab8df6b54dab8b11e52b186aec0
 * provider record sha256 f8842f22cc03cf717714d7ef3c9fb0d89e73c38500539af20a1b5c9ce0e4042c
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void func_800a949c(int param_1,uint param_2,uint param_3,uint param_4,byte param_5)

{
  if ((DAT_80136310 != '\0') && (param_1 != -1)) {
    FUN_800a5678();
    FUN_800a5a60(param_1,(param_2 & 0xff) << 0x10,(param_3 & 0xff) << 0x10,(param_4 & 0xff) << 0x10,
                 (uint)param_5 << 0x10);
    FUN_800a56c0();
  }
  return;
}
