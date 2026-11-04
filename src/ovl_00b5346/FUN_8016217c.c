/* FUN_8016217c
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x8016217c  body 0x8016217c..0x801621f7  size 124 B
 * body sha256 92ab024ef5aaf27a0461e6ed2f79ac050be5e6c1bf8f550746f8eeb0445f6d01
 * provider record sha256 54db4fd38b77352f8f2db7ac6bcd897c876903f6d347271b5dc96aa52b3fa28e
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016217c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = func_0x800837ac(0x800e8d00,0x1f);
  if (iVar1 == 0) {
    if (*(char *)(param_1 + 6) == '\0') {
      FUN_801621f8(param_1,param_2,param_3);
    }
    else {
      FUN_80162408(param_1,param_2,param_3);
    }
  }
  return;
}
