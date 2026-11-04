/* FUN_800725dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800725dc  body 0x800725dc..0x8007266f  size 148 B
 * body sha256 b5c32c628f5ebd4e7c75d16c4d9a01cf7bd999e63e01b0643d82f819d08057a4
 * provider record sha256 9cfba2c370b2801469e757764ba46243fcd9342153cc4fbea4d8e2cd11d328fc
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800725dc(int param_1)

{
  if (DAT_80114f3e == -1) {
    DAT_80114f3e = DAT_80119e73;
    DAT_80119e73 = (byte)(((uint)DAT_80119e73 * (uint)*(byte *)(*(int *)(param_1 + 0x1c) + 1)) / 100
                         );
  }
  else {
    DAT_80119e73 = DAT_80114f3e;
    DAT_80114f3e = 0xff;
  }
  FUN_800750b0(0);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 2;
  return 1;
}
