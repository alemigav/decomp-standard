/* FUN_800004f0
 * image   boot (boot), base 0x80000480
 * address 0x800004f0  body 0x800004f0..0x800004ff  size 16 B
 * body sha256 48acddae6bcb4eb0c6a2e79601ebb4187abc6b85e7ccdd3585411563d123f2be
 * provider record sha256 e3251d9b17422335844c878224f0fd73356dcaa090f7d2c99b0ea47351cc2603
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800004f0(undefined4 param_1)

{
  setCopReg(0,WatchLo,param_1);
  setCopReg(0,WatchHi,0);
  return;
}
