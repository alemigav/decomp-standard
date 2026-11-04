/* FUN_8000521c
 * image   boot (boot), base 0x80000480
 * address 0x8000521c  body 0x8000521c..0x800053f3  size 472 B
 * body sha256 75cb717da8ab84efd23c911bb906fc30fbd32f57d8e916c194bef3b2543928e3
 * provider record sha256 97a14428c489029faf2f11193d1c59ce2a6fd48dbdb858bc8fa805a1d645fb5a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_8000521c(undefined2 param_1,undefined4 *param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  ushort *puVar10;
  ushort *puVar11;
  int iVar12;
  
  FUN_800051b8(param_1);
  puVar7 = _DAT_800128ac;
  puVar8 = _DAT_800128ac + 1;
  puVar10 = (ushort *)(_DAT_800128ac + 2);
  *param_2 = CONCAT22(*(undefined2 *)((int)_DAT_800128ac + 2),*(undefined2 *)_DAT_800128ac);
  param_2[1] = CONCAT22(*(undefined2 *)((int)puVar7 + 6),*(undefined2 *)puVar8);
  puVar11 = (ushort *)((int)puVar7 + 10);
  uVar1 = *(ushort *)(param_2 + 1);
  iVar12 = *puVar10 - 1;
  puVar7 = param_2 + 2;
  while (iVar12 != -1) {
    uVar2 = *puVar11;
    puVar11 = puVar11 + 1;
    uVar9 = (uVar2 >> 0xc) + 1;
    if ((uVar2 & 0xfff) == 0) {
      iVar4 = (uVar9 * uVar1 >> 2) - 1;
      if (iVar4 == -1) {
        iVar12 = iVar12 + -1;
      }
      else {
        do {
          *puVar7 = 0;
          iVar4 = iVar4 + -1;
          puVar7 = puVar7 + 1;
        } while (iVar4 != -1);
        iVar12 = iVar12 + -1;
      }
    }
    else {
      puVar8 = (undefined4 *)((int)puVar7 + 7U & 0xfffffff8);
      iVar5 = FUN_80004cfc(uVar2 & 0xfff,puVar8,0,0);
      puVar3 = puVar7;
      iVar4 = iVar5 >> 2;
      if (puVar8 != puVar7) {
        while (iVar4 + -1 != -1) {
          uVar6 = *puVar8;
          puVar8 = puVar8 + 1;
          *puVar3 = uVar6;
          puVar3 = puVar3 + 1;
          iVar4 = iVar4 + -1;
        }
        puVar8 = puVar7;
      }
      puVar8 = puVar8 + (iVar5 >> 2);
      if (uVar9 < 2) {
        iVar12 = iVar12 + -1;
        puVar7 = puVar8;
      }
      else {
        iVar4 = ((uint)(uVar2 >> 0xc) * iVar5 >> 2) - 1;
        if (iVar4 == -1) {
          iVar12 = iVar12 + -1;
          puVar7 = puVar8;
        }
        else {
          do {
            uVar6 = *puVar7;
            puVar7 = puVar7 + 1;
            iVar4 = iVar4 + -1;
            *puVar8 = uVar6;
            puVar8 = puVar8 + 1;
          } while (iVar4 != -1);
          iVar12 = iVar12 + -1;
          puVar7 = puVar8;
        }
      }
    }
  }
  if (_DAT_800128ac < puVar7) {
    trap(0);
  }
  return puVar7;
}
