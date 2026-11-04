/* FUN_80166ed0
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80166ed0  body 0x80166ed0..0x80166f83  size 180 B
 * body sha256 d3176175002d81e4149e186d8e65b64cf5cf76d8edea2ca346b2d3abf6b306b6
 * provider record sha256 4bd59428d5773de3fbbb0fc8276dfbe93b4471c4df91de04dafc25fae9a73468
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80166ed0(int param_1,short param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = func_0x800667d4(param_1 + 0x28,(int)param_2,1 << (*(byte *)(param_1 + 0x1a2) & 0x1f),0x400
                         );
  if ((iVar1 != 0) && (piVar2 = (int *)&DAT_800e1068, _DAT_800e1068 != 0)) {
    do {
      if ((*piVar2 != *(int *)(param_1 + 0x2c4)) &&
         ((uint)(-*(int *)(param_1 + 0x2c) / 0x708) <= *(uint *)(*piVar2 + 0xc))) {
        return 1;
      }
      piVar2 = piVar2 + 1;
    } while (*piVar2 != 0);
  }
  return 0;
}
