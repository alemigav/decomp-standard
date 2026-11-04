/* FUN_800aca44
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aca44  body 0x800aca44..0x800aca4b  size 8 B
 * body sha256 71bdb42019d5a3323a07398ffa9b363083a260c82112f7d76ed42e81009353de
 * provider record sha256 a1556b6d317e1207ad7b4c0e7dbf2445350c6b672499178e55fd65c724a2b933
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x800acaa0) */
/* WARNING: Removing unreachable block (ram,0x800aca94) */
/* WARNING: Removing unreachable block (ram,0x800acaa8) */

undefined2
switchD_800aca3c::caseD_80(int param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

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
