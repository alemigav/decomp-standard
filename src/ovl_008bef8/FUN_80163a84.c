/* FUN_80163a84
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80163a84  body 0x80163a84..0x80163b33  size 176 B
 * body sha256 4ae31f9c29c942606eb63c6e4302a634591baa1e99f41a3274c4e1bbf1364596
 * provider record sha256 8bf6b35a60e41fd9b5741a95854e0c6c615c82c3d94e91f07f42bc69fae7a307
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163a84(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(short *)(param_1 + 0x2ce) == 0) {
    func_0x80077d18(5,param_1);
  }
  FUN_80165364(param_1);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x298);
  if (*(char *)(param_1 + 4) == '\x01') {
    (*(code *)(&PTR_LAB_801660d0)[*(byte *)(param_1 + 5)])(param_1);
    (*(code *)(&PTR_FUN_801660f0)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  return;
}
