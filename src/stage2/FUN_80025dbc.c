/* FUN_80025dbc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80025dbc  body 0x80025dbc..0x80025e6b  size 176 B
 * body sha256 e3ccd23dbc9632e1abbaceed519354dd783f5c61b4e27895f820ad4c4d6f063e
 * provider record sha256 2ef52ada0956b5048c1a2dac689cb8c12fdc67e09a978bcefadf769e7af823fe
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80025dbc(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  
  uVar9 = DAT_800c7670;
  uVar8 = DAT_800c766c;
  uVar7 = DAT_800c7668;
  uVar6 = DAT_800c7664;
  uVar5 = DAT_800c7660;
  uVar4 = DAT_800c765c;
  uVar3 = DAT_800c7658;
  uVar2 = DAT_800c7654;
  uVar1 = DAT_800c764c;
  iVar10 = DAT_800c7640 * 0x28;
  *(undefined4 *)(&DAT_800c4f84 + iVar10) = DAT_800c7650;
  *(undefined4 *)(&DAT_800c4f88 + iVar10) = uVar2;
  *(undefined4 *)(&DAT_800c4f8c + iVar10) = uVar3;
  *(undefined4 *)(&DAT_800c4f90 + iVar10) = uVar4;
  *(undefined4 *)(&DAT_800c4f94 + iVar10) = uVar5;
  *(undefined4 *)(&DAT_800c4f98 + iVar10) = uVar6;
  *(undefined4 *)(&DAT_800c4f9c + iVar10) = uVar7;
  *(undefined4 *)(&DAT_800c4fa0 + iVar10) = uVar8;
  *(undefined4 *)(&DAT_800c4fa4 + iVar10) = uVar9;
  *(undefined4 *)(&DAT_800c4f80 + iVar10) = uVar1;
  FUN_80025d80();
  return;
}
