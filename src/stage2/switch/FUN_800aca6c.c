/* FUN_800aca6c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aca6c  body 0x800aca6c..0x800acae3  size 120 B
 * body sha256 601972783a5aa49666ff11250d9f4ff4ad58159544eddbdab5f5de73f67bfbc0
 * provider record sha256 8f2660275f93009080a7b1fff9778903acd3b753c80f50f2909069fc31baf197
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x800acaa0) */
/* WARNING: Removing unreachable block (ram,0x800aca94) */
/* WARNING: Removing unreachable block (ram,0x800acaa8) */

undefined2
switchD_800aca3c::caseD_85(int param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

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
