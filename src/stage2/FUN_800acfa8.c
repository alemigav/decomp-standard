/* FUN_800acfa8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800acfa8  body 0x800acfa8..0x800ad0bf  size 280 B
 * body sha256 8b8de3ef3f85e4818c8c2bcdb47a7f4cab251015663cb96d1158dbe383a2fc97
 * provider record sha256 1243080f34d78523ae839d0cf1100ec9b8c774df4de4e7fd5d68bb205eaa4958
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800acfa8(short param_1)

{
  int iVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  FUN_800a5678();
  iVar3 = _DAT_801529f0;
  iVar4 = 0;
  if (0 < _DAT_801529f0) {
    iVar1 = -0x7fead600;
    do {
      if (*(short *)(iVar1 + 4) == param_1) break;
      iVar4 = iVar4 + 1;
      iVar1 = iVar1 + 0xc;
    } while (iVar4 < _DAT_801529f0);
  }
  if (iVar4 != _DAT_801529f0) {
    sVar2 = *(short *)(iVar4 * 0xc + -0x7fead5f8) + -1;
    *(short *)(iVar4 * 0xc + -0x7fead5f8) = sVar2;
    iVar4 = iVar4 + 1;
    if (sVar2 == 0) {
      if (iVar4 < iVar3) {
        puVar5 = (undefined4 *)(iVar4 * 0xc + -0x7fead600);
        iVar3 = iVar4 * 0xc + -0xc;
        do {
          uVar6 = puVar5[1];
          uVar7 = puVar5[2];
          *(undefined4 *)(iVar3 + -0x7fead600) = *puVar5;
          *(undefined4 *)(&DAT_80152a04 + iVar3) = uVar6;
          *(undefined4 *)(iVar3 + -0x7fead5f8) = uVar7;
          puVar5 = puVar5 + 3;
          iVar4 = iVar4 + 1;
          iVar3 = iVar3 + 0xc;
        } while (iVar4 < _DAT_801529f0);
      }
      _DAT_801529f0 = _DAT_801529f0 + -1;
      FUN_800a56c0();
      return 1;
    }
  }
  FUN_800a56c0();
  return 0;
}
