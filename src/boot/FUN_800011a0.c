/* FUN_800011a0
 * image   boot (boot), base 0x80000480
 * address 0x800011a0  body 0x800011a0..0x800013a7  size 520 B
 * body sha256 0ba932d836d22cf4c3d47e6a7641fce3b9f629bb612dd67899b153de9e92fbab
 * provider record sha256 4f89b322354df53783ac0073887653ee0869526bb860da06291a36bd4d2d55fc
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_800011a0(uint param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  byte *pbVar19;
  byte *pbVar20;
  byte *pbVar21;
  byte *pbVar22;
  byte *pbVar23;
  byte *pbVar24;
  byte *pbVar25;
  byte *pbVar26;
  byte *pbVar27;
  byte *pbVar28;
  byte *pbVar29;
  byte *pbVar30;
  byte *pbVar31;
  byte *pbVar32;
  byte *pbVar33;
  uint uVar34;
  
  uVar3 = param_1 & 0xffff;
  param_1 = param_1 >> 0x10;
  if (param_2 == (byte *)0x0) {
    uVar2 = 1;
  }
  else {
    uVar2 = param_1 << 0x10;
    if (param_3 != 0) {
      do {
        uVar2 = param_3;
        if (0x15b0 < param_3) {
          uVar2 = 0x15b0;
        }
        param_3 = param_3 - uVar2;
        for (; 0xf < (int)uVar2; uVar2 = uVar2 - 0x10) {
          bVar1 = *param_2;
          pbVar19 = param_2 + 1;
          pbVar20 = param_2 + 2;
          pbVar21 = param_2 + 3;
          pbVar22 = param_2 + 4;
          pbVar23 = param_2 + 5;
          pbVar24 = param_2 + 6;
          pbVar25 = param_2 + 7;
          pbVar26 = param_2 + 8;
          pbVar27 = param_2 + 9;
          pbVar28 = param_2 + 10;
          pbVar29 = param_2 + 0xb;
          pbVar30 = param_2 + 0xc;
          pbVar31 = param_2 + 0xd;
          pbVar32 = param_2 + 0xe;
          pbVar33 = param_2 + 0xf;
          param_2 = param_2 + 0x10;
          iVar4 = uVar3 + bVar1;
          iVar5 = iVar4 + (uint)*pbVar19;
          iVar6 = iVar5 + (uint)*pbVar20;
          iVar7 = iVar6 + (uint)*pbVar21;
          iVar8 = iVar7 + (uint)*pbVar22;
          iVar9 = iVar8 + (uint)*pbVar23;
          iVar10 = iVar9 + (uint)*pbVar24;
          iVar11 = iVar10 + (uint)*pbVar25;
          iVar12 = iVar11 + (uint)*pbVar26;
          iVar13 = iVar12 + (uint)*pbVar27;
          iVar14 = iVar13 + (uint)*pbVar28;
          iVar15 = iVar14 + (uint)*pbVar29;
          iVar16 = iVar15 + (uint)*pbVar30;
          iVar17 = iVar16 + (uint)*pbVar31;
          iVar18 = iVar17 + (uint)*pbVar32;
          uVar3 = iVar18 + (uint)*pbVar33;
          param_1 = param_1 + iVar4 + iVar5 + iVar6 + iVar7 + iVar8 + iVar9 + iVar10 + iVar11 +
                    iVar12 + iVar13 + iVar14 + iVar15 + iVar16 + iVar17 + iVar18 + uVar3;
        }
        uVar34 = (uint)((ulonglong)uVar3 * 0x80078071 >> 0x20);
        if (uVar2 != 0) {
          do {
            bVar1 = *param_2;
            param_2 = param_2 + 1;
            uVar2 = uVar2 - 1;
            uVar3 = uVar3 + bVar1;
            param_1 = param_1 + uVar3;
          } while (uVar2 != 0);
          uVar34 = (uint)((ulonglong)uVar3 * 0x80078071 >> 0x20);
        }
        uVar3 = uVar3 + (uVar34 >> 0xf) * -0xfff1;
        param_1 = param_1 % 0xfff1;
      } while (param_3 != 0);
      uVar2 = param_1 * 0x10000;
    }
    uVar2 = uVar2 | uVar3;
  }
  return uVar2;
}
