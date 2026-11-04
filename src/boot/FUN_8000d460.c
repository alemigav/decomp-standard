/* FUN_8000d460
 * image   boot (boot), base 0x80000480
 * address 0x8000d460  body 0x8000d460..0x8000d66b  size 524 B
 * body sha256 f6ae6fe06f2bcc341f8be3501644607f0c042b26adf32aa10e7f40de60294c5d
 * provider record sha256 cca05cab2ecede4987d0fecc6d1351bfdd81391c43273286f9870e010a143a5e
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000d460(int param_1)

{
  int iVar1;
  
  FUN_8000d6a0(param_1,0x800177e0,0x40);
  if (_DAT_800177f0 != 0) {
    _DAT_800177f0 = FUN_8000e800();
  }
  if (_DAT_800177f8 != 0) {
    _DAT_800177f8 = FUN_8000e800();
  }
  if (_DAT_80017800 != 0) {
    _DAT_80017800 = FUN_8000e800();
  }
  if (_DAT_80017808 != 0) {
    _DAT_80017808 = FUN_8000e800();
  }
  if (_DAT_8001780c != 0) {
    _DAT_8001780c = FUN_8000e800();
  }
  if (_DAT_80017810 != 0) {
    _DAT_80017810 = FUN_8000e800();
  }
  if (_DAT_80017818 != 0) {
    _DAT_80017818 = FUN_8000e800();
  }
  if ((_DAT_800177e4 & 1) != 0) {
    _DAT_800177f8 = _DAT_80017818;
    _DAT_800177fc = _DAT_8001781c;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffffe;
    if ((_DAT_800177e4 & 4) != 0) {
      _DAT_800177f0 = *(int *)(*(int *)(param_1 + 0x38) + 0xbfcU | 0xa0000000);
    }
  }
  FUN_8000efa0(0x800177e0,0x40);
  FUN_8000db10(0x2b00);
  do {
    iVar1 = FUN_8000dae0(0x4001000);
  } while (iVar1 == -1);
  do {
    iVar1 = FUN_8000d9e0(1,0x4000fc0,0x800177e0,0x40);
  } while (iVar1 == -1);
  do {
    iVar1 = FUN_8000d9c0(1);
  } while (iVar1 != 0);
  do {
    iVar1 = FUN_8000d9e0(1,0x4001000,_DAT_800177e8,_DAT_800177ec);
  } while (iVar1 == -1);
  return;
}
