/* FUN_800ae6b4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ae6b4  body 0x800ae6b4..0x800aebfb  size 1352 B
 * body sha256 b0bfd3540eb68318e009d2c20d340d2d77606fc992975bb458c7447e0babde59
 * provider record sha256 3d77fbce72ab5de9f73a0ad411e9823ee708ef99f706d44a7eb1d26e41d066e3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_800ae6b4(byte param_1,byte param_2,short param_3,char param_4)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  if (DAT_80147fa8 != '\0') {
    return 0xffffffff;
  }
  if (param_4 == '\0') {
    bVar2 = DAT_80158838;
    bVar1 = DAT_80147a59;
  }
  else {
    bVar2 = DAT_8015883c;
    bVar1 = DAT_80144440;
  }
  bVar3 = bVar1 <= bVar2;
  bVar4 = bVar1 < DAT_80147a58;
  iVar10 = 0;
  if (param_2 < bVar1) {
    uVar9 = (uint)_DAT_8015883a;
    uVar8 = 0xffffffff;
    if ((uVar9 != 0xffff) && (uVar9 <= param_1)) {
      while (uVar8 == 0xffffffff) {
        bVar2 = *(byte *)(uVar9 + 0x80158940);
        while (uVar6 = (uint)bVar2, uVar6 != 0xff) {
          iVar5 = uVar6 * 0x1a0;
          if ((((((&DAT_80144505)[iVar5] == '\0') && (*(short *)(iVar5 + -0x7febbafe) == param_3))
               && ((iVar10 = iVar10 + 1, !bVar3 || !bVar4 || ((&DAT_80144494)[iVar5] == param_4))))
              && ((*(uint *)(&DAT_8014446c + iVar5) & 2) == 0)) &&
             ((uVar8 == 0xffffffff ||
              (*(uint *)(&DAT_80144470 + iVar5) < *(uint *)(&DAT_80144470 + uVar8 * 0x1a0))))) {
            uVar8 = uVar6;
          }
          bVar2 = *(byte *)(uVar6 * 4 + -0x7fea77bf);
        }
        uVar9 = (uint)*(ushort *)(uVar9 * 4 + -0x7fea7bc8);
        if ((uVar9 == 0xffff) || (param_1 < uVar9)) break;
      }
    }
    if ((int)(uint)param_2 <= iVar10) goto LAB_800aeacc;
    for (; uVar9 != 0xffff; uVar9 = (uint)*(ushort *)(uVar9 * 4 + -0x7fea7bc8)) {
      if ((int)(uint)param_2 <= iVar10) goto LAB_800aeacc;
      bVar2 = *(byte *)(uVar9 + 0x80158940);
      while (uVar6 = (uint)bVar2, uVar6 != 0xff) {
        if (((&DAT_80144505)[uVar6 * 0x1a0] == '\0') &&
           (*(short *)(uVar6 * 0x1a0 + -0x7febbafe) == param_3)) {
          iVar10 = iVar10 + 1;
        }
        bVar2 = *(byte *)(uVar6 * 4 + -0x7fea77bf);
      }
    }
    if ((int)(uint)param_2 <= iVar10) goto LAB_800aeacc;
  }
  uVar8 = 0xffffffff;
  if ((DAT_80158a40 == 0xff) || (bVar3 && bVar4)) {
    uVar9 = (uint)_DAT_8015883a;
    if (param_1 < uVar9) {
      return 0xffffffff;
    }
    if (uVar9 != 0xffff) {
      do {
        if (uVar8 != 0xffffffff) goto LAB_800aea94;
        bVar2 = *(byte *)(uVar9 + 0x80158940);
        while (uVar6 = (uint)bVar2, uVar6 != 0xff) {
          iVar10 = uVar6 * 0x1a0;
          if (((&DAT_80144505)[iVar10] == '\0') &&
             ((((!bVar3 || !bVar4 || ((&DAT_80144494)[iVar10] == param_4)) &&
               ((*(uint *)(&DAT_8014446c + iVar10) & 2) == 0)) &&
              ((uVar8 == 0xffffffff ||
               (*(uint *)(&DAT_80144470 + iVar10) < *(uint *)(&DAT_80144470 + uVar8 * 0x1a0))))))) {
            uVar8 = uVar6;
          }
          bVar2 = *(byte *)(uVar6 * 4 + -0x7fea77bf);
        }
        uVar9 = (uint)*(ushort *)(uVar9 * 4 + -0x7fea7bc8);
      } while ((uVar9 != 0xffff) && (uVar9 <= param_1));
    }
    if (uVar8 == 0xffffffff) {
      return 0xffffffff;
    }
  }
  else {
    uVar8 = (uint)DAT_80158a40;
  }
LAB_800aea94:
  if (param_1 < (byte)(&DAT_80144476)[uVar8 * 0x1a0]) {
    return 0xffffffff;
  }
LAB_800aeacc:
  if (uVar8 == 0xffffffff) {
    return 0xffffffff;
  }
  iVar10 = uVar8 * 4;
  pbVar7 = &DAT_801588c0 + iVar10;
  if (*(short *)(iVar10 + -0x7fea773e) == 1) {
    if (*pbVar7 == 0xff) {
      DAT_80158a40 = *(byte *)(iVar10 + -0x7fea773f);
    }
    else {
      *(undefined1 *)((uint)*pbVar7 * 4 + -0x7fea773f) = *(undefined1 *)(iVar10 + -0x7fea773f);
    }
    if (*(byte *)(iVar10 + -0x7fea773f) != 0xff) {
      (&DAT_801588c0)[(uint)*(byte *)(iVar10 + -0x7fea773f) * 4] = *pbVar7;
    }
    if (uVar8 == DAT_80158839) {
      DAT_80158839 = *pbVar7;
      *(undefined2 *)(iVar10 + -0x7fea773e) = 0;
    }
    else {
      *(undefined2 *)(iVar10 + -0x7fea773e) = 0;
    }
  }
  else if ((&DAT_80144494)[uVar8 * 0x1a0] == '\0') {
    DAT_80158838 = DAT_80158838 - 1;
  }
  else {
    DAT_8015883c = DAT_8015883c - 1;
  }
  if (param_4 == '\0') {
    DAT_80158838 = DAT_80158838 + 1;
  }
  else {
    DAT_8015883c = DAT_8015883c + 1;
  }
  return uVar8;
}
