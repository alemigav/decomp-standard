/* FUN_800073d0
 * image   boot (boot), base 0x80000480
 * address 0x800073d0  body 0x800073d0..0x80007443  size 116 B
 * body sha256 17cc5e8b8c5acf2bb3eef00f2ca69e8ab42e1e0ce12c8872d62c94a9a182ce1f
 * provider record sha256 efbb58a9f4747598a7132fb0a31bdc35a0f572b74f22e3458ef58b1b30c0f61e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800073d0(uint param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  
  if (0 < (int)param_2) {
    if (0x3fff < param_2) {
      uVar2 = 0x80000000;
      do {
        cacheOp(0,uVar2);
        bVar1 = uVar2 < 0x80003fe0;
        uVar2 = uVar2 + 0x20;
      } while (bVar1);
      return;
    }
    if (param_1 < param_1 + param_2) {
      uVar2 = param_1 - (param_1 & 0x1f);
      do {
        cacheOp(0x10,uVar2);
        bVar1 = uVar2 < (param_1 + param_2) - 0x20;
        uVar2 = uVar2 + 0x20;
      } while (bVar1);
    }
  }
  return;
}
