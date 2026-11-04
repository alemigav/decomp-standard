/* FUN_800aca4c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aca4c  body 0x800aca4c..0x800aca53  size 8 B
 * body sha256 328c3eeab55f0a734c8211dd0b837a8efbbc03c628214f5f5ac043d7a6731cb0
 * provider record sha256 3d567479732e7bd52425c295485ad618a063b54d2093195782310a1352fbf7ee
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x800acaa0) */
/* WARNING: Removing unreachable block (ram,0x800aca94) */
/* WARNING: Removing unreachable block (ram,0x800acaa8) */

undefined2
switchD_800aca3c::caseD_81(int param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  undefined2 uVar1;
  
  if (*(char *)(param_1 + 0x4a) == -1) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_800ac0c8(param_4,*(char *)(param_1 + 0x4a),*(undefined1 *)(param_1 + 0x4b));
  }
  return uVar1;
}
