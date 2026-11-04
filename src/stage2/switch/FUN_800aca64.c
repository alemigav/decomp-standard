/* FUN_800aca64
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aca64  body 0x800aca64..0x800aca6b  size 8 B
 * body sha256 b8e727d1a82d65259de1b2ac519122c0b8ad2229cb343c933ae45618abc2fb68
 * provider record sha256 0ecdf9dbb67fce31f6195f71e2e65718b221e142f14f4e42c47c4059b749146a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x800acaa0) */
/* WARNING: Removing unreachable block (ram,0x800aca94) */
/* WARNING: Removing unreachable block (ram,0x800acaa8) */

undefined2
switchD_800aca3c::caseD_84(int param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

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
