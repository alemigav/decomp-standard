/* FUN_800ad0c0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ad0c0  body 0x800ad0c0..0x800ad22f  size 368 B
 * body sha256 a646922d30b2bcaea18dfd7f461ea717545c3958a0bef6079f2e84ad8c343a70
 * provider record sha256 6fa41494c36dbc5bfb0e3c7997b9cdc0bb39f78b67b0f017470e0fcbc048b9e3
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800ad0c0(ushort param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  
  FUN_800a5678();
  iVar4 = 0;
  if (0 < _DAT_8014e1d0) {
    iVar1 = -0x7feb1e20;
    do {
      if (param_1 <= *(ushort *)(iVar1 + 4)) break;
      iVar4 = iVar4 + 1;
      iVar1 = iVar1 + 8;
    } while (iVar4 < _DAT_8014e1d0);
    iVar1 = iVar4 * 8;
    if (iVar4 < _DAT_8014e1d0) {
      if (*(ushort *)(&DAT_8014e1e4 + iVar1) == param_1) {
        FUN_800a56c0();
        *(short *)(iVar1 + -0x7feb1e1a) = *(short *)(iVar1 + -0x7feb1e1a) + 1;
        return 0;
      }
      iVar1 = _DAT_8014e1d0 + -1;
      if (0x7ff < _DAT_8014e1d0) goto LAB_800ad1dc;
      if (iVar4 <= iVar1) {
        puVar3 = (undefined4 *)(iVar1 * 8 + -0x7feb1e20);
        iVar2 = iVar1 * 8 + 8;
        do {
          uVar5 = puVar3[1];
          *(undefined4 *)(iVar2 + -0x7feb1e20) = *puVar3;
          *(undefined4 *)(&DAT_8014e1e4 + iVar2) = uVar5;
          puVar3 = puVar3 + -2;
          iVar1 = iVar1 + -1;
          iVar2 = iVar2 + -8;
        } while (iVar4 <= iVar1);
      }
      goto LAB_800ad1f0;
    }
  }
  if (0x7ff < _DAT_8014e1d0) {
LAB_800ad1dc:
    FUN_800a56c0();
    return 0;
  }
LAB_800ad1f0:
  _DAT_8014e1d0 = _DAT_8014e1d0 + 1;
  iVar4 = iVar4 * 8;
  *(ushort *)(&DAT_8014e1e4 + iVar4) = param_1;
  *(undefined4 *)(iVar4 + -0x7feb1e20) = param_2;
  *(undefined2 *)(iVar4 + -0x7feb1e1a) = 1;
  FUN_800a56c0();
  return 1;
}
