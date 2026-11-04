/* func_800a23cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a23cc  body 0x800a23cc..0x800a2423  size 88 B
 * body sha256 659aed8c5994d16b9b6a5cd2b46d0e2d2f2fec73ba68976063e07d181fdfc08f
 * provider record sha256 68dd699df0c4b8a2e3d96d58272bf7babf816c52c69d14ae020ea835f135daef
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void func_800a23cc(undefined4 param_1,undefined4 param_2)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a15d0(param_1,param_2,0);
    FUN_800a56c0();
  }
  return;
}
