/* FUN_800a02f8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a02f8  body 0x800a02f8..0x800a0403  size 268 B
 * body sha256 0f45677e034f9a3f02d04e7daf5d9b086490f4e7bd111fc8196061a6e9405db9
 * provider record sha256 14bc2138a209ffc06e778712ea12e33734a00d021563c4e3815b794c374bdf32
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a02f8(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = 0;
  if (DAT_80136311 != '\0') {
    bVar1 = true;
    if (DAT_80136311 == '*') goto LAB_800a0374;
    uVar3 = FUN_800ab3cc();
    bVar1 = true;
    if ((uVar3 & 3) != 0) goto LAB_800a0374;
    uVar6 = FUN_800ab3cc();
    uVar6 = uVar6 & 0xffff;
    uVar6 = uVar6 + (uVar6 / 0x3f + (uVar6 - uVar6 / 0x3f >> 1) >> 5) * -0x3f & 0xffff;
  }
  bVar1 = uVar6 < 0x40;
LAB_800a0374:
  iVar2 = _DAT_80143c58;
  if (bVar1) {
    iVar4 = uVar6 * 0x28 + _DAT_80143c58;
    iVar5 = _DAT_80143c58 + 0xa00;
    do {
      if (((*(int *)(iVar4 + 0x574) != 0) || (*(int *)(iVar4 + 0x578) != 0)) ||
         (*(int *)(iVar4 + 0x57c) != 0)) {
        uVar6 = *(int *)(iVar4 + 0x568) + *(int *)(iVar2 + 0x118);
        *(uint *)(iVar4 + 0x568) = uVar6 & 0xffff;
        *(int *)(iVar4 + 0x56c) =
             *(int *)(iVar4 + 0x56c) + ((int)uVar6 >> 0x10) + *(int *)(iVar2 + 0x11c);
      }
      iVar4 = iVar4 + 0x28;
    } while (iVar4 < iVar5);
  }
  return;
}
