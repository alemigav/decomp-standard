/* FUN_800ad818
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ad818  body 0x800ad818..0x800ad997  size 384 B
 * body sha256 f1f4914f9f0573ad50f479a6fffa7cf576cc7f5a5dadb57da79ce5464e5966e7
 * provider record sha256 a6219109e42bdf383f26d30e3c7b3a759d1675839d79735a74b95747b635cc86
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800ad818(uint param_1)

{
  uint uVar1;
  uint uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  
  FUN_800a5678();
  uVar5 = (param_1 & 0xffff) >> 6;
  uVar1 = (uint)*(ushort *)(&DAT_80153610 + uVar5 * 4);
  if (uVar1 != 0) {
    uVar9 = (uint)*(ushort *)(&DAT_80153612 + uVar5 * 4);
    iVar8 = 0;
    if (uVar1 != 0) {
      uVar2 = uVar9;
      do {
        if ((uint)*(ushort *)(uVar2 * 8 + -0x7feac1ec) == (param_1 & 0xffff)) break;
        iVar8 = iVar8 + 1;
        uVar2 = uVar9 + iVar8;
      } while (iVar8 < (int)uVar1);
      if ((iVar8 < (int)(uint)*(ushort *)(&DAT_80153610 + uVar5 * 4)) &&
         (iVar4 = (uVar9 + iVar8) * 8, sVar3 = *(short *)(iVar4 + -0x7feac1ea) + -1,
         *(short *)(iVar4 + -0x7feac1ea) = sVar3, sVar3 == 0)) {
        iVar8 = uVar9 + iVar8 + 1;
        if (iVar8 < _DAT_80153600) {
          puVar6 = (undefined4 *)(iVar8 * 8 + -0x7feac1f0);
          iVar4 = iVar8 * 8 + -8;
          do {
            uVar10 = puVar6[1];
            *(undefined4 *)(iVar4 + -0x7feac1f0) = *puVar6;
            *(undefined4 *)(iVar4 + -0x7feac1ec) = uVar10;
            puVar6 = puVar6 + 2;
            iVar8 = iVar8 + 1;
            iVar4 = iVar4 + 8;
          } while (iVar8 < _DAT_80153600);
        }
        iVar8 = 0;
        puVar7 = &DAT_80153610;
        do {
          iVar8 = iVar8 + 1;
          if (uVar9 < *(ushort *)(puVar7 + 2)) {
            *(ushort *)(puVar7 + 2) = *(ushort *)(puVar7 + 2) - 1;
          }
          puVar7 = puVar7 + 4;
        } while (iVar8 < 0x200);
        _DAT_80153600 = _DAT_80153600 + -1;
        *(short *)(&DAT_80153610 + uVar5 * 4) = *(short *)(&DAT_80153610 + uVar5 * 4) + -1;
      }
    }
  }
  FUN_800a56c0();
  return 0;
}
