/* FUN_80162664
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80162664  body 0x80162664..0x801626df  size 124 B
 * body sha256 76efdd4c5e3cb69708abf4c0e7b2a4ca4729d996cc229223523f4e4a3e84110c
 * provider record sha256 e3dab872615dd274aa26ab5d3987cfc3d6f46f2a38f813751d1364da5428ca2b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162664(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8016984c)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_80169868)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
