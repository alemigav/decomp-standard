/* FUN_8006b8a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006b8a0  body 0x8006b8a0..0x8006b9bb  size 284 B
 * body sha256 8401f0639e4a8b0abb1c984514afc8feeaa36779c7b777679e4315d3d2c481c7
 * provider record sha256 6a550e3b9083a2321aa1b03631563ba4260c1d063f054609c749844150f09e8f
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8006b8b4) */
/* WARNING: Removing unreachable block (ram,0x8006b920) */
/* WARNING: Removing unreachable block (ram,0x8006b96c) */
/* WARNING: Removing unreachable block (ram,0x8006b934) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006b8a0(void)

{
  osStartThread(&DAT_80112da0);
  func_0x8000cdf0(&DAT_80112da0,0x1e);
  func_0x8000cdf0(&DAT_80112bf0,0x14);
  func_0x8000cdf0(&DAT_80112f50,0x15);
  func_0x8000cdf0(&DAT_80113100,0x15);
  return;
}
