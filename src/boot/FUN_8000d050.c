/* FUN_8000d050
 * image   boot (boot), base 0x80000480
 * address 0x8000d050  body 0x8000d050..0x8000d1ef  size 416 B
 * body sha256 2b4776f612913d8fba5786bf37c532ae40f12e753ee558dc8dfb2fd65bf8100c
 * provider record sha256 05bb7cb7d82c6a42d48e7e5bddeb7b6bb5aa186a27aa141768975783b7600ebb
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8000d1cc) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float FUN_8000d050(float param_1)

{
  uint uVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  uVar1 = (int)param_1 >> 0x16 & 0x1ff;
  if (uVar1 < 0xff) {
    dVar4 = (double)param_1;
    if (0xe5 < uVar1) {
      dVar2 = dVar4 * dVar4;
      param_1 = (float)(dVar4 + dVar4 * dVar2 *
                                (((_DAT_80011c60 * dVar2 + _DAT_80011c58) * dVar2 + _DAT_80011c50) *
                                 dVar2 + _DAT_80011c48));
    }
  }
  else if (uVar1 < 0x136) {
    dVar4 = (double)param_1 * _DAT_80011c68;
    if (0.0 <= dVar4) {
      dVar4 = dVar4 + _DAT_80011c88;
    }
    else {
      dVar4 = dVar4 - _DAT_80011c90;
    }
    dVar2 = (double)(int)dVar4;
    dVar2 = ((double)param_1 - dVar2 * _DAT_80011c70) - dVar2 * _DAT_80011c78;
    dVar3 = dVar2 * dVar2;
    dVar2 = dVar2 + dVar2 * dVar3 *
                    (((_DAT_80011c60 * dVar3 + _DAT_80011c58) * dVar3 + _DAT_80011c50) * dVar3 +
                    _DAT_80011c48);
    if (((int)dVar4 & 1U) == 0) {
      param_1 = (float)dVar2;
    }
    else {
      param_1 = -(float)dVar2;
    }
  }
  else {
    param_1 = _DAT_80011c80;
  }
  return param_1;
}
