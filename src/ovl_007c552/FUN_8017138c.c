/* FUN_8017138c
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x8017138c  body 0x8017138c..0x801713af  size 36 B
 * body sha256 96db574f4db4f627f0ab5948a1b3384eff48ed582cd8eec67827c3053233c30f
 * provider record sha256 fd7130c0034dcf3408f3ac923f8866500341dfd62b1582ae485dce10a6160057
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017138c(undefined4 *param_1)

{
  undefined2 *puVar1;
  uint uVar2;
  
  puVar1 = (undefined2 *)*param_1;
  uVar2 = 0;
  do {
    *puVar1 = 0;
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (uVar2 < 0x140);
  *param_1 = puVar1;
  return;
}
