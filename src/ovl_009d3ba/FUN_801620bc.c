/* FUN_801620bc
 * image   ovl_009d3ba (ovl), base 0x80161cf0
 * address 0x801620bc  body 0x801620bc..0x80162137  size 124 B
 * body sha256 f8567f1d64e01e0d7551fb0e306866e7a1ec4acd5aae350f7e8c54d20a80e949
 * provider record sha256 810f1772464bbe0dea24b2ef0b7a73fcb094cfff06311421c8ed7fd735916504
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801620bc(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_80163058)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_80163078)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
