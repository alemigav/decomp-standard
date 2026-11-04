/* FUN_800acd1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800acd1c  body 0x800acd1c..0x800ace1b  size 256 B
 * body sha256 cf5450b78adc137299bcc157cd0d1ed43c31c7ae4e5b2a7e0f984b61ce27176e
 * provider record sha256 05938b0122797494b6d928edcdcce5eefabb6977290d772f26c75ad7b86f930e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800acd1c(short param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  
  FUN_800a5678();
  iVar3 = _DAT_801521e0;
  iVar4 = 0;
  if (0 < _DAT_801521e0) {
    iVar2 = -0x7feade10;
    do {
      if (*(short *)(iVar2 + 4) == param_1) break;
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 8;
    } while (iVar4 < _DAT_801521e0);
  }
  if (iVar4 != _DAT_801521e0) {
    sVar1 = *(short *)(iVar4 * 8 + -0x7feade0a) + -1;
    *(short *)(iVar4 * 8 + -0x7feade0a) = sVar1;
    iVar4 = iVar4 + 1;
    if (sVar1 == 0) {
      if (iVar4 < iVar3) {
        puVar5 = (undefined4 *)(iVar4 * 8 + -0x7feade10);
        iVar3 = iVar4 * 8 + -8;
        do {
          uVar6 = puVar5[1];
          *(undefined4 *)(iVar3 + -0x7feade10) = *puVar5;
          *(undefined4 *)(&DAT_801521f4 + iVar3) = uVar6;
          puVar5 = puVar5 + 2;
          iVar4 = iVar4 + 1;
          iVar3 = iVar3 + 8;
        } while (iVar4 < _DAT_801521e0);
      }
      _DAT_801521e0 = _DAT_801521e0 + -1;
      FUN_800a56c0();
      return 1;
    }
  }
  FUN_800a56c0();
  return 0;
}
