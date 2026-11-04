/* FUN_8000e658
 * image   boot (boot), base 0x80000480
 * address 0x8000e658  body 0x8000e658..0x8000e7cf  size 376 B
 * body sha256 ff4b4a38de75affcf7c91a61554fc1d7a2f855261fcb9f2894643f72b90424d9
 * provider record sha256 62197b78d667f8dec9c3a523c69d13b579f21023c339e7d4dbab6b0bb2c9ee7e
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8000e748) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000e658(int param_1)

{
  int iVar1;
  short *local_20 [2];
  
  local_20[0] = (short *)0x0;
  iVar1 = FUN_8000e7f0();
  _DAT_80017860 = *(short *)(iVar1 + 2);
  if (_DAT_80017860 == 0) {
    _DAT_80017860 = 1;
  }
  do {
    while( true ) {
      osRecvMesg(*(undefined4 *)(param_1 + 0xc),local_20,1);
      if (*local_20[0] == 0xd) break;
      if (*local_20[0] == 0xe) {
        FUN_8000df64();
      }
    }
    FUN_8000ecb0();
    _DAT_80017860 = _DAT_80017860 + -1;
    if (_DAT_80017860 == 0) {
      iVar1 = FUN_8000e7f0();
      if (*(int *)(iVar1 + 0x10) != 0) {
        osSendMesg(*(int *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14),0);
      }
      _DAT_80017860 = *(short *)(iVar1 + 2);
    }
    iVar1 = _DAT_80017820;
    _DAT_80017824 = _DAT_80017824 + 1;
    _DAT_80017820 = FUN_80007000();
    _DAT_8001782c = _DAT_8001782c + (_DAT_80017820 - iVar1);
    _DAT_80017828 = _DAT_80017828 + (uint)(_DAT_8001782c < (uint)(_DAT_80017820 - iVar1));
  } while( true );
}
