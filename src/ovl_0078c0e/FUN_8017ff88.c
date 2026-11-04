/* FUN_8017ff88
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017ff88  body 0x8017ff88..0x8018001f  size 152 B
 * body sha256 a6b95a77c8b51e808780a9188d3224db68e3ae7f40fe42ce4c9b9679debb851d
 * provider record sha256 56adfc559d33d2ce1eb66d3b1c049d8dfb6d29a591703a3a21936b6818fdb4b7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8017ff88(int param_1)

{
  DAT_80180adc = 5;
  DAT_80180ae4 = param_1 >> 4;
  DAT_80180ae0 = &DAT_80180ae4;
  DAT_80180ae8 = &DAT_80180ad8;
  DAT_80180aec = &DAT_80181f94;
  if (DAT_80180ae4 == 0) {
    DAT_80180ad8 = 0;
  }
  else {
    if (_DAT_80131f10 != 0) {
      func_0x800879a0(&DAT_80180adc);
      return 1;
    }
    DAT_80180ad8 = 10;
  }
  osSendMesg(&DAT_80181f94,0,0);
  return 1;
}
