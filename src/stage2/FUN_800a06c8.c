/* FUN_800a06c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a06c8  body 0x800a06c8..0x800a087f  size 440 B
 * body sha256 94f93929e4b9a5c7553679ef3df05a577dfe4e9c4887a7421c668c6628633472
 * provider record sha256 b267e117fb6bb701518dbd1e309cb06e3055523178f6bc42d053c08b75ec01dd
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a06c8(void)

{
  byte bVar1;
  bool bVar2;
  undefined1 uVar3;
  ushort *puVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  ushort uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar11 = 0;
  iVar10 = 0;
  do {
    if (*(int *)(_DAT_80143c58 + iVar10 + 0x57c) != 0) {
      bVar2 = false;
      do {
        puVar4 = *(ushort **)(_DAT_80143c58 + iVar10 + 0x57c);
        bVar1 = *(byte *)puVar4;
        uVar8 = (ushort)bVar1;
        if ((bVar1 == 0x80) && ((byte)*puVar4 == 0)) {
          *(undefined4 *)(_DAT_80143c58 + iVar10 + 0x57c) = 0;
LAB_800a0840:
          bVar2 = true;
        }
        else {
          if ((bVar1 & 0x80) == 0) {
            iVar9 = 1;
          }
          else {
            uVar8 = *puVar4 & 0x7fff;
            iVar9 = 2;
          }
          iVar7 = _DAT_80143c58 + iVar10;
          uVar6 = *(int *)(iVar7 + 0x588) + (int)(short)uVar8;
          if ((uint)(*(int *)(iVar7 + 0x56c) + *(int *)(_DAT_80143c58 + 0x120)) < uVar6)
          goto LAB_800a0840;
          *(uint *)(iVar7 + 0x588) = uVar6;
          pbVar5 = (byte *)(*(int *)(iVar7 + 0x57c) + iVar9);
          *(byte **)(iVar7 + 0x57c) = pbVar5;
          bVar1 = *pbVar5;
          if ((bVar1 & 0x80) == 0) {
            iVar9 = (int)(char)bVar1;
            pbVar5 = pbVar5 + 1;
          }
          else {
            iVar9 = (int)(((uint)pbVar5[1] | (bVar1 & 0x7f) << 8) << 0x11) >> 0x11;
            pbVar5 = pbVar5 + 2;
          }
          *(byte **)(iVar7 + 0x57c) = pbVar5;
          uVar3 = DAT_80143c53;
          iVar7 = _DAT_80143c58 + iVar10;
          uVar6 = (uint)*(ushort *)(iVar7 + 0x582) + iVar9;
          *(short *)(iVar7 + 0x582) = (short)uVar6;
          FUN_800ac614(1,*(undefined1 *)(iVar7 + 0x58c),uVar3,uVar6 >> 7 & 0xff);
          FUN_800ac614(0x21,*(undefined1 *)(_DAT_80143c58 + iVar10 + 0x58c),DAT_80143c53,
                       *(byte *)(_DAT_80143c58 + iVar10 + 0x583) & 0x7f);
        }
      } while (!bVar2);
    }
    iVar11 = iVar11 + 1;
    iVar10 = iVar10 + 0x28;
    if (0x3f < iVar11) {
      return;
    }
  } while( true );
}
