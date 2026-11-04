/* FUN_8000e800
 * image   boot (boot), base 0x80000480
 * address 0x8000e800  body 0x8000e800..0x8000e853  size 84 B
 * body sha256 5c7c41faecc5382215f614d0abd6f6399ba5c501ac92cd522709718a092ec478
 * provider record sha256 f92976e12595742d93a2ce7faf204a5e01f23b3d499dde32885e8cc2b0ed4a4a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8000e800(uint param_1)

{
  uint uVar1;
  
  if (param_1 + 0x80000000 < 0x20000000) {
    uVar1 = param_1 & 0x1fffffff;
  }
  else {
    uVar1 = param_1 & 0x1fffffff;
    if (0x1fffffff < param_1 + 0x60000000) {
      uVar1 = FUN_8000e860();
    }
  }
  return uVar1;
}
