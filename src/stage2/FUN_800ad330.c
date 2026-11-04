/* FUN_800ad330
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ad330  body 0x800ad330..0x800ad457  size 296 B
 * body sha256 19ce233dd0fadbfbe969ff211abfe9fce80e61177bed42933c52f72236ed396d
 * provider record sha256 c45fa241b824d637cc91427f16092d3b778fe29009d6d51041a8f6816e2956aa
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800ad330(short *param_1,undefined4 param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  short *psVar5;
  ushort uVar6;
  ushort uVar7;
  
  iVar3 = 0;
  if (0 < _DAT_8014e16c) {
    puVar4 = (undefined4 *)&DAT_8014e170;
    do {
      if ((short *)*puVar4 == param_1) break;
      iVar3 = iVar3 + 1;
      puVar4 = puVar4 + 3;
    } while (iVar3 < _DAT_8014e16c);
  }
  uVar2 = 1;
  if (iVar3 == _DAT_8014e16c) {
    if (iVar3 < 8) {
      uVar7 = 0;
      sVar1 = *param_1;
      psVar5 = param_1;
      while (sVar1 != -1) {
        psVar5 = psVar5 + 0xe;
        uVar7 = uVar7 + 1;
        sVar1 = *psVar5;
      }
      FUN_800a5678();
      uVar6 = 0;
      iVar3 = _DAT_8014e16c * 0xc;
      *(short **)(&DAT_8014e170 + iVar3) = param_1;
      *(ushort *)(&DAT_8014e178 + iVar3) = uVar7;
      *(undefined4 *)(iVar3 + -0x7feb1e8c) = param_2;
      if (uVar7 != 0) {
        do {
          param_1[1] = 0;
          uVar6 = uVar6 + 1;
          param_1 = param_1 + 0xe;
        } while (uVar6 < uVar7);
      }
      _DAT_8014e16c = _DAT_8014e16c + 1;
      FUN_800a56c0();
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}
