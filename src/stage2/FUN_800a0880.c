/* FUN_800a0880
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a0880  body 0x800a0880..0x800a0bb7  size 824 B
 * body sha256 54b0411d55de4c7cb0c7c3341da9d4fea874cf5bb5ada89504d381c28482db82
 * provider record sha256 774fd25ba77a1fac5fc1b85332c4cc601ffeefd6e45f83880b268cb6ed585f6d
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800a0880(void)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  ushort *puVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  
  bVar1 = true;
  uVar14 = 0;
  iVar11 = 0;
  iVar12 = 0;
  iVar13 = 0;
  do {
    iVar3 = _DAT_80143c58 + iVar12;
    puVar6 = *(uint **)(iVar3 + 300);
    if (puVar6 != (uint *)0x0) {
      uVar14 = 1;
      while (iVar8 = _DAT_80143c58,
            *puVar6 <= (uint)(*(int *)(iVar3 + 0x134) + *(int *)(_DAT_80143c58 + 0x120))) {
        uVar10 = (uint)*(ushort *)(puVar6 + 2);
        if (uVar10 == 0xfffe) {
          if (*(char *)(_DAT_80143c58 + 0xfc5) != '\0') {
            *(undefined4 *)(iVar3 + 300) = 0;
            goto LAB_800a0b70;
          }
          *(uint *)(iVar3 + 300) =
               *(int *)(iVar3 + 0x128) + (uint)*(ushort *)((int)puVar6 + 10) * 0xc;
          uVar2 = *(undefined4 *)(*(int *)(iVar8 + 0x10c) + 0x14);
          *(undefined4 *)(iVar3 + 0x130) = 0;
          *(undefined4 *)(iVar3 + 0x134) = uVar2;
          if (bVar1) {
            bVar1 = false;
            FUN_800a0bb8(*(undefined4 *)(*(int *)(iVar8 + 0x10c) + 0x14));
            *(short *)(_DAT_80143c58 + 0xfc6) = *(short *)(_DAT_80143c58 + 0xfc6) + 1;
          }
        }
        else {
          if (uVar10 == 0xffff) {
            *(undefined4 *)(iVar3 + 300) = 0;
            goto LAB_800a0b70;
          }
          iVar7 = *(int *)(_DAT_80143c58 + 0x10c);
          iVar3 = *(int *)(uVar10 * 4 + *(int *)(iVar7 + 4) + iVar7);
          iVar9 = _DAT_80143c58 + iVar13;
          *(undefined4 *)(iVar9 + 0x56c) = 0;
          *(undefined4 *)(iVar9 + 0x568) = 0;
          *(undefined4 *)(iVar9 + 0x570) = 0;
          iVar3 = iVar3 + iVar7;
          *(int *)(iVar9 + 0x574) = iVar3 + 0xc;
          if (*(int *)(iVar3 + 4) == 0) {
            *(undefined4 *)(iVar9 + 0x578) = 0;
          }
          else {
            *(int *)(iVar9 + 0x578) = *(int *)(iVar3 + 4) + *(int *)(iVar8 + 0x10c);
          }
          iVar8 = _DAT_80143c58;
          iVar7 = _DAT_80143c58 + iVar13;
          *(undefined4 *)(iVar7 + 0x584) = 0;
          *(undefined2 *)(iVar7 + 0x580) = 0x2000;
          if (*(int *)(iVar3 + 8) == 0) {
            *(undefined4 *)(iVar7 + 0x57c) = 0;
          }
          else {
            *(int *)(iVar7 + 0x57c) = *(int *)(iVar3 + 8) + *(int *)(iVar8 + 0x10c);
          }
          iVar3 = _DAT_80143c58;
          iVar8 = _DAT_80143c58 + iVar13;
          *(undefined4 *)(iVar8 + 0x588) = 0;
          *(undefined2 *)(iVar8 + 0x582) = 0;
          *(undefined1 *)(iVar8 + 0x58c) =
               *(undefined1 *)
                (*(int *)(*(int *)(iVar3 + 0x10c) + 8) + *(int *)(iVar3 + 0x10c) + iVar11);
          *(undefined1 *)(_DAT_80143c58 + iVar13 + 0x58d) = *(undefined1 *)((int)puVar6 + 0xb);
          *(undefined1 *)(_DAT_80143c58 + iVar13 + 0x58e) = *(undefined1 *)((int)puVar6 + 10);
          *(char *)(_DAT_80143c58 + iVar13 + 0x58f) = (char)iVar11;
          if (*(byte *)(puVar6 + 1) != 0xff) {
            uVar10 = (uint)*(byte *)(_DAT_80143c58 + iVar13 + 0x58c);
            iVar3 = _DAT_80143c58 + (uint)*(byte *)(puVar6 + 1);
            if (uVar10 == 9) {
              uVar10 = (uint)*(byte *)(iVar3 + 0x8c);
              if (uVar10 != 0xff) {
                puVar5 = (ushort *)(uVar10 * 8 + *(int *)(_DAT_80143c58 + 0x88));
                *(uint *)(_DAT_80143c58 + 0xfa4) =
                     (uint)*puVar5 << 0x10 | (uint)*(byte *)(puVar5 + 1) << 8 |
                     (uint)*(byte *)((int)puVar5 + 3);
              }
            }
            else {
              uVar4 = (uint)*(byte *)(iVar3 + 8);
              if (uVar4 != 0xff) {
                puVar5 = (ushort *)(uVar4 * 8 + *(int *)(_DAT_80143c58 + 4));
                *(uint *)(_DAT_80143c58 + uVar10 * 4 + 0xf80) =
                     (uint)*puVar5 << 0x10 | (uint)*(byte *)(puVar5 + 1) << 8 |
                     (uint)*(byte *)((int)puVar5 + 3);
              }
            }
          }
          if (*(char *)((int)puVar6 + 5) != -1) {
            FUN_800ac614(7,*(undefined1 *)(_DAT_80143c58 + iVar13 + 0x58c),DAT_80143c53);
          }
          *(int *)(_DAT_80143c58 + iVar12 + 300) = *(int *)(_DAT_80143c58 + iVar12 + 300) + 0xc;
        }
        iVar3 = _DAT_80143c58 + iVar12;
        puVar6 = *(uint **)(iVar3 + 300);
      }
      iVar3 = _DAT_80143c58 + iVar12;
      uVar10 = *(int *)(iVar3 + 0x130) + *(int *)(_DAT_80143c58 + 0x118);
      *(uint *)(iVar3 + 0x130) = uVar10 & 0xffff;
      *(uint *)(iVar3 + 0x134) =
           *(int *)(iVar3 + 0x134) + (uVar10 >> 0x10) + *(int *)(iVar8 + 0x11c);
    }
LAB_800a0b70:
    iVar12 = iVar12 + 0x10;
    iVar11 = iVar11 + 1;
    iVar13 = iVar13 + 0x28;
    if (0x3f < iVar11) {
      return uVar14;
    }
  } while( true );
}
