/* FUN_800a0518
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a0518  body 0x800a0518..0x800a06c7  size 432 B
 * body sha256 0ee6ad556ab89cb8a28885ce0c3c9db8fabf5b7639a0c2d9153bea61a215b95d
 * provider record sha256 35ffe583f88e5de905075d19c2b376179290fe13b8447606b1b894d71b4ef9aa
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a0518(void)

{
  byte bVar1;
  bool bVar2;
  undefined1 uVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar10 = 0;
  iVar9 = 0;
  do {
    if (*(int *)(_DAT_80143c58 + iVar9 + 0x578) != 0) {
      bVar2 = false;
      do {
        pbVar4 = *(byte **)(_DAT_80143c58 + iVar9 + 0x578);
        bVar1 = *pbVar4;
        uVar5 = (uint)bVar1;
        uVar7 = (uint)pbVar4[1];
        if ((uVar5 == 0x80) && (uVar7 == 0)) {
          *(undefined4 *)(_DAT_80143c58 + iVar9 + 0x578) = 0;
LAB_800a0688:
          bVar2 = true;
        }
        else {
          if ((bVar1 & 0x80) == 0) {
            iVar8 = 1;
          }
          else {
            uVar5 = uVar7 | (uVar5 & 0x7f) << 8;
            iVar8 = 2;
          }
          iVar6 = _DAT_80143c58 + iVar9;
          uVar5 = uVar5 + *(int *)(iVar6 + 0x584);
          if ((uint)(*(int *)(iVar6 + 0x56c) + *(int *)(_DAT_80143c58 + 0x120)) < uVar5)
          goto LAB_800a0688;
          *(uint *)(iVar6 + 0x584) = uVar5;
          pbVar4 = (byte *)(*(int *)(iVar6 + 0x578) + iVar8);
          *(byte **)(iVar6 + 0x578) = pbVar4;
          bVar1 = *pbVar4;
          if ((bVar1 & 0x80) == 0) {
            iVar8 = (int)((uint)bVar1 << 0x19) >> 0x19;
            pbVar4 = pbVar4 + 1;
          }
          else {
            iVar8 = (int)(((uint)pbVar4[1] | (bVar1 & 0x7f) << 8) << 0x11) >> 0x11;
            pbVar4 = pbVar4 + 2;
          }
          *(byte **)(iVar6 + 0x578) = pbVar4;
          uVar3 = DAT_80143c53;
          iVar6 = _DAT_80143c58 + iVar9;
          uVar5 = (uint)*(ushort *)(iVar6 + 0x580) + iVar8;
          *(short *)(iVar6 + 0x580) = (short)uVar5;
          FUN_800ac614(0x80,*(undefined1 *)(iVar6 + 0x58c),uVar3,uVar5 >> 7 & 0xff);
          FUN_800ac614(0x81,*(undefined1 *)(_DAT_80143c58 + iVar9 + 0x58c),DAT_80143c53,
                       *(byte *)(_DAT_80143c58 + iVar9 + 0x581) & 0x7f);
        }
      } while (!bVar2);
    }
    iVar10 = iVar10 + 1;
    iVar9 = iVar9 + 0x28;
    if (0x3f < iVar10) {
      return;
    }
  } while( true );
}
