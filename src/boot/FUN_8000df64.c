/* FUN_8000df64
 * image   boot (boot), base 0x80000480
 * address 0x8000df64  body 0x8000df64..0x8000e09f  size 316 B
 * body sha256 fe9a738bc132e8dbe3cdd9abb498186c1db18f6c2ac429989d79fa0b512164e0
 * provider record sha256 5b73c0ccdd940d2822687475223a6000b3a80631c4adb9ac7cceb96a4916af99
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000df64(void)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  if ((int *)*_DAT_80012960 != _DAT_80012960) {
    while (piVar3 = (int *)*_DAT_80012960, piVar3 != _DAT_80012960) {
      iVar1 = FUN_80007000();
      uVar2 = iVar1 - _DAT_80017830;
      _DAT_80017830 = iVar1;
      if ((piVar3[4] != 0) || (uVar2 < (uint)piVar3[5])) {
        piVar3[4] = piVar3[4] - (uint)((uint)piVar3[5] < uVar2);
        piVar3[5] = piVar3[5] - uVar2;
        FUN_8000e0a0();
        return;
      }
      *(int *)piVar3[1] = *piVar3;
      *(int *)(*piVar3 + 4) = piVar3[1];
      *piVar3 = 0;
      piVar3[1] = 0;
      if (piVar3[6] != 0) {
        osSendMesg(piVar3[6],piVar3[7],0);
      }
      if ((piVar3[2] != 0) || (piVar3[3] != 0)) {
        piVar3[4] = piVar3[2];
        piVar3[5] = piVar3[3];
        FUN_8000e100();
      }
    }
    FUN_8000de30(0);
    _DAT_80017830 = 0;
  }
  return;
}
