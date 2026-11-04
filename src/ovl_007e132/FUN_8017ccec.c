/* FUN_8017ccec
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017ccec  body 0x8017ccec..0x8017cee7  size 508 B
 * body sha256 9d5679c155929f3af19f075ce50dd7e3f7c16a6cf42d1574af681327ea8b6b00
 * provider record sha256 a8f5fab03131336e2b0250df7becb54b3e7159fb155a7291666e8ceaff9427f8
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017ccec(void)

{
  short sVar2;
  int iVar1;
  short sVar3;
  int iVar4;
  undefined2 *puVar5;
  short sVar6;
  undefined4 *puVar7;
  int iVar8;
  short sVar9;
  int iVar10;
  
  iVar4 = 0;
  do {
    iVar1 = 0;
    do {
      sVar9 = 0x40;
      iVar10 = 0;
      puVar7 = (undefined4 *)(DAT_8017e8e0 + (short)iVar4 * 0x3400 + 0x7354 + (short)iVar1 * 0x1a00)
      ;
      do {
        sVar6 = 0;
        iVar8 = 0;
        puVar5 = (undefined2 *)((int)puVar7 + 10);
        do {
          sVar3 = 0x20;
          puVar5[6] = 0x95;
          *(undefined **)(puVar5 + 0x13) = &DAT_8017e8e4;
          *puVar5 = 0;
          *puVar7 = 2;
          if ((short)iVar8 == 7) {
            sVar3 = 0x1f;
          }
          sVar2 = 8;
          if ((short)iVar10 == 0xf) {
            sVar2 = 7;
          }
          func_0x80047914(puVar7,sVar6,sVar9,sVar3 + sVar6,sVar9,sVar6,sVar2 + sVar9,sVar3 + sVar6,
                          sVar2 + sVar9);
          puVar5 = puVar5 + 0x1a;
          puVar7 = puVar7 + 0xd;
          iVar8 = iVar8 + 1;
          sVar6 = sVar6 + 0x20;
        } while (iVar8 * 0x10000 >> 0x10 < 8);
        iVar10 = iVar10 + 1;
        sVar9 = sVar9 + 8;
      } while (iVar10 * 0x10000 >> 0x10 < 0x10);
      iVar1 = iVar1 + 1;
    } while (iVar1 * 0x10000 >> 0x10 < 2);
    iVar4 = iVar4 + 1;
  } while (iVar4 * 0x10000 >> 0x10 < 3);
  return;
}
