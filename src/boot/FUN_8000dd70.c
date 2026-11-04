/* FUN_8000dd70
 * image   boot (boot), base 0x80000480
 * address 0x8000dd70  body 0x8000dd70..0x8000de2f  size 192 B
 * body sha256 c3f4e2b773ba017e3a2c83fd9bac0d0b0623118f79090bdd7458a4ae35059902
 * provider record sha256 ccd1f4bc3309afd33bd47be3c15bc21b01c40a77b1e965e30b6dffdb278a277f
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8000dd70(int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  
  uVar1 = 0xffffffff;
  if (*param_1 != 0) {
    uVar1 = FUN_800072e0();
    piVar3 = (int *)*param_1;
    if (piVar3 != _DAT_80012960) {
      uVar2 = piVar3[5] + param_1[5];
      piVar3[4] = piVar3[4] + param_1[4] + (uint)(uVar2 < (uint)param_1[5]);
      piVar3[5] = uVar2;
    }
    piVar3 = _DAT_80012960;
    *(int *)param_1[1] = *param_1;
    *(int *)(*param_1 + 4) = param_1[1];
    *param_1 = 0;
    param_1[1] = 0;
    if ((int *)*piVar3 == piVar3) {
      FUN_8000de30(0);
    }
    FUN_80007300(uVar1);
    uVar1 = 0;
  }
  return uVar1;
}
