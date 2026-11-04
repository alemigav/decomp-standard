/* FUN_800a597c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a597c  body 0x800a597c..0x800a59cf  size 84 B
 * body sha256 5ed88d172cabe1c6c49e2a1902ee7ca590c2c55a796ce4d2e7e38f5a6ac95606
 * provider record sha256 7d6e021d4f48ef3f9888bf27ecc0d80bb15d8c319ced5760093b4a8b266ce7b6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a597c(uint param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(_DAT_80143f0c + (param_1 & 0xffff) * 0x68);
  puVar1[0x5c] = 0;
  *(undefined4 *)(puVar1 + 0x50) = 0;
  *(undefined4 *)(puVar1 + 0x58) = 0;
  *(undefined4 *)(puVar1 + 0x4c) = 0;
  *(undefined4 *)(puVar1 + 0x54) = 0x3f800000;
  *puVar1 = 1;
  *(undefined2 *)(puVar1 + 0x48) = *(undefined2 *)(puVar1 + 0x20);
  return;
}
