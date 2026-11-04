/* FUN_80005e84
 * image   boot (boot), base 0x80000480
 * address 0x80005e84  body 0x80005e84..0x80005ee7  size 100 B
 * body sha256 33f8b0be5e0d21ee73d6604e488868355594726b11f245575b459d01037f19fb
 * provider record sha256 f758cd752714afcfbe0778b60343d38883de8d8c03d364177d6da8f42fb3f5fd
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_80005e84(short param_1,uint param_2)

{
  if (param_1 != -1) {
    _DAT_800128ac = _DAT_800c52d8 + 0xaf800;
    param_2 = FUN_80005438();
    if (_DAT_800128ac < param_2) {
      trap(0);
    }
  }
  return param_2;
}
