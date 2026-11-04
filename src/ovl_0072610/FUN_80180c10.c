/* FUN_80180c10
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80180c10  body 0x80180c10..0x80180ccf  size 192 B
 * body sha256 2eeb4937b733ae5043483db346b29230b8d3b200d65c9d4092628102f8706691
 * provider record sha256 8eab3858281ee4ed278ea86079221d25f8c3b2a5ec469a9f46c757ffe2c17bc9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_80180c10(void)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  func_0x8004d030(_DAT_8010b6d0);
  piVar5 = (int *)*DAT_80185498;
  uVar8 = piVar5[3];
  uVar7 = piVar5[2];
  uVar6 = 0;
  while( true ) {
    uVar1 = 0;
    if ((uVar8 != uVar7) && (uVar1 = uVar8 - uVar7, uVar8 <= uVar7)) {
      uVar1 = *piVar5 - (uVar7 - uVar8);
    }
    iVar3 = 0;
    if (uVar6 <= uVar1) {
      uVar4 = piVar5[3];
      uVar1 = uVar6 + 1;
      if (uVar4 < uVar1) {
        iVar3 = *piVar5 - (uVar1 - uVar4);
      }
      else {
        iVar3 = uVar4 - uVar1;
      }
      iVar3 = piVar5[1] + iVar3 * 4;
    }
    if (iVar3 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(ushort *)(iVar3 + 2) & 0x1000;
    }
    if (uVar2 == 0) break;
    uVar6 = uVar6 + 1;
  }
  return uVar6;
}
