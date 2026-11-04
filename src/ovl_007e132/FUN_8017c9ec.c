/* FUN_8017c9ec
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017c9ec  body 0x8017c9ec..0x8017cceb  size 768 B
 * body sha256 85bd0480d625395ec3820ddbd9a0537511102678ba832665931fd290724718e9
 * provider record sha256 e60176bcb69deb5d4d7b2c85797ce8ce031433ed7b73985473e5f78c76ed3364
 * callees 3 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017c9ec(void)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  short sVar5;
  int iVar4;
  int iVar6;
  short sVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  short sVar13;
  short sVar14;
  short local_52;
  short local_4a;
  short sStack_3a;
  
  local_4a = 0;
  do {
    sVar14 = 0;
    local_52 = 0;
    puVar11 = (undefined4 *)(DAT_8017e8e0 + local_4a * 0x3400 + 8);
    do {
      sVar13 = 0;
      iVar12 = 0;
      puVar9 = puVar11 + 0xc;
      iVar10 = (int)local_52;
      sStack_3a = local_52 * 0xb;
      do {
        sVar5 = (short)iVar12;
        if (local_4a != 0) {
          iVar4 = (int)sVar5;
          iVar8 = iVar10 * 8 + iVar4 * 0x88;
          iVar1 = DAT_8017e8e0 + iVar8;
          *(short *)(iVar1 + 0x6808) = sVar5 * 0x1e;
          *(short *)(iVar1 + 0x680c) = sStack_3a;
          iVar1 = func_0x800408c0(iVar4 << 0xc);
          iVar8 = DAT_8017e8e0 + iVar8;
          iVar6 = (uint)*(ushort *)(iVar8 + 0x680c) + (iVar1 >> 9);
          iVar1 = (iVar4 * -0x1e + 0xf0) * 0x10000 >> 0x10;
          iVar2 = (0x58 - iVar6) * 0x10000 >> 0x10;
          *(short *)(iVar8 + 0x680c) = (short)iVar6;
          *(undefined2 *)(iVar8 + 0x680a) = 0x212;
          uVar3 = func_0x80040bb4(iVar1 * iVar1 + iVar2 * iVar2);
          *(undefined2 *)(DAT_8017e8e0 + iVar10 * 2 + iVar4 * 0x22 + 0x7110) = uVar3;
        }
        if ((iVar10 != 0x10) && (sVar5 != 0x10)) {
          sVar7 = 0x10;
          *puVar9 = &DAT_8017e8e4;
          *(undefined2 *)((int)puVar9 + -0x1a) = 0xb5;
          *(undefined2 *)((int)puVar9 + -0x26) = 0;
          *puVar11 = 0x20202002;
          if (sVar5 == 0xf) {
            sVar7 = 0xf;
          }
          sVar5 = 4;
          if (iVar10 == 0xf) {
            sVar5 = 3;
          }
          func_0x80047914(puVar11,sVar13,sVar14,sVar7 + sVar13,sVar14,sVar13,sVar5 + sVar14,
                          sVar7 + sVar13,sVar5 + sVar14);
          puVar9 = puVar9 + 0xd;
          puVar11 = puVar11 + 0xd;
          sVar13 = sVar13 + 0x10;
        }
        iVar1 = DAT_8017e8e0;
        iVar12 = iVar12 + 1;
      } while (iVar12 * 0x10000 >> 0x10 < 0x11);
      local_52 = local_52 + 1;
      sVar14 = sVar14 + 4;
    } while (local_52 < 0x11);
    local_4a = local_4a + 1;
  } while (local_4a < 2);
  uVar3 = 0x16;
  *(undefined2 *)(DAT_8017e8e0 + 2) = 0;
  *(undefined2 *)(iVar1 + 0x10f56) = 0;
  *(undefined1 *)(iVar1 + 4) = 0xf;
  *(undefined1 *)(DAT_8017e8e0 + 5) = 1;
  if ((_DAT_800e10ec & 0x100) != 0) {
    uVar3 = 0x34;
  }
  *(undefined2 *)(DAT_8017e8e0 + 0x10f54) = uVar3;
  return;
}
