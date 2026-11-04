/* FUN_800796c4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800796c4  body 0x800796c4..0x80079703  size 64 B
 * body sha256 9fad354a74e3ad3e6a205c605a4113c51733a8f2ffae777be84bd7e00b155de7
 * provider record sha256 bb72a69ce54311e9a0cbc14e5c883d89e91a39ac94d718628583ce4a733ff9da
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800796c4(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_800837ac(&DAT_800e8ce0,0xff);
  if (iVar1 != 0) {
    FUN_800351e8(param_1);
  }
  return;
}
