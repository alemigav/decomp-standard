/* FUN_800ad458
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ad458  body 0x800ad458..0x800ad62b  size 468 B
 * body sha256 1855e061b553e370a417f48ec7694eb1fe10d976970f9cbb6d87da0b135e64a7
 * provider record sha256 0cedfb0eedfd43c3ef4fb78a61e012b4757ffc9a54a5089ca53e7880441a3841
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800ad458(short param_1)

{
  bool bVar1;
  bool bVar2;
  short sVar5;
  int *piVar3;
  int iVar4;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  short *psVar10;
  short *psVar11;
  int *piVar12;
  uint uVar13;
  
  bVar1 = false;
  uVar13 = 0;
  if (_DAT_8014e16c != 0) {
    piVar12 = (int *)&DAT_8014e170;
    do {
      psVar11 = (short *)*piVar12;
      sVar5 = *psVar11;
      bVar2 = false;
      if (sVar5 != -1) {
        psVar10 = psVar11 + 1;
        do {
          if (sVar5 == param_1) {
            sVar5 = *psVar10;
            *psVar10 = sVar5 + -1;
            bVar1 = true;
            if ((short)(sVar5 + -1) == 0) {
              FUN_800a5cec(psVar11 + 6,*(undefined4 *)(psVar10 + 1));
              bVar1 = true;
            }
          }
          if (*psVar10 != 0) {
            bVar2 = true;
          }
          psVar11 = psVar11 + 0xe;
          sVar5 = *psVar11;
          psVar10 = psVar10 + 0xe;
        } while (sVar5 != -1);
      }
      if (bVar1) {
        if (bVar2) {
          return 1;
        }
        uVar13 = 0;
        if ((int)_DAT_8014e16c < 1) goto LAB_800ad560;
        piVar3 = (int *)&DAT_8014e170;
        goto LAB_800ad540;
      }
      uVar13 = uVar13 + 1;
      piVar12 = piVar12 + 3;
    } while (uVar13 < _DAT_8014e16c);
  }
  return 0;
  while( true ) {
    uVar13 = uVar13 + 1;
    piVar3 = piVar3 + 3;
    if ((int)_DAT_8014e16c <= (int)uVar13) break;
LAB_800ad540:
    if (*piVar3 == *piVar12) break;
  }
LAB_800ad560:
  if (uVar13 != _DAT_8014e16c) {
    FUN_800a5678();
    iVar4 = uVar13 + 1;
    if (iVar4 < (int)_DAT_8014e16c) {
      puVar7 = (undefined4 *)(&DAT_8014e170 + iVar4 * 0xc);
      iVar6 = iVar4 * 0xc + -0xc;
      do {
        uVar8 = puVar7[1];
        uVar9 = puVar7[2];
        *(undefined4 *)(&DAT_8014e170 + iVar6) = *puVar7;
        *(undefined4 *)(iVar6 + -0x7feb1e8c) = uVar8;
        *(undefined4 *)(&DAT_8014e178 + iVar6) = uVar9;
        puVar7 = puVar7 + 3;
        iVar4 = iVar4 + 1;
        iVar6 = iVar6 + 0xc;
      } while (iVar4 < (int)_DAT_8014e16c);
    }
    _DAT_8014e16c = _DAT_8014e16c - 1;
    FUN_800a56c0();
  }
  return 1;
}
