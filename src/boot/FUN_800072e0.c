/* FUN_800072e0
 * image   boot (boot), base 0x80000480
 * address 0x800072e0  body 0x800072e0..0x800072ff  size 32 B
 * body sha256 fcdf87bb672c63f8439e2e373e984cfe957358fb2c1be0d3c95f02ff00098913
 * provider record sha256 764cfb65f8ad8edb21629e8d0eec43aede7e0583d073aa5e7b2b243e4fdef49d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_800072e0(void)

{
  setCopReg(0,Status,Status & 0xfffffffe);
  return Status & 1;
}
