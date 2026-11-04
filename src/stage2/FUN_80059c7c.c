/* FUN_80059c7c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059c7c  body 0x80059c7c..0x80059ceb  size 112 B
 * body sha256 f80c3e485bdaffd70e23b28e2d75d9ef398e9e29f3f015175ef802ecf4e079b3
 * provider record sha256 6368d82ca5b733dc0329d213edf996dcc2971d3932b53df046d607cbcc097fa0
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80059c7c(uint *param_1)

{
  DAT_800e110c = DAT_800e110c | 0x40;
  *param_1 = *param_1 & 0xfffffffb;
  (**(code **)(&DAT_800df948 + (*(byte *)(param_1[0x94] + 8) - 0x10) * 4))
            (param_1,param_1[0x89],param_1[0x8a]);
  return;
}
