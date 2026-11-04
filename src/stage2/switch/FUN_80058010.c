/* FUN_80058010
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80058010  body 0x80058010..0x80058067  size 88 B
 * body sha256 3e224c4bb6372b53b4b25231fe6626b00b0287321c5f08dc0f602b505f5fab13
 * provider record sha256 8a4b1a3f2d411ee739a2ef64c78f6b3e278fc86f00a6e9b7fdf5ddc1ef19ad1b
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80057fc0::caseD_1(void)

{
  int iVar1;
  int unaff_s0;
  
  FUN_80032ef4();
  iVar1 = FUN_80032f64();
  if (iVar1 == 0) {
    *(undefined1 *)(unaff_s0 + 6) = 2;
    FUN_80032ef4();
  }
  FUN_80089d54();
  if ((**(uint **)(unaff_s0 + 0x214) & 0x4000) != 0) {
    FUN_80077f30(0,((**(uint **)(unaff_s0 + 0x214) & 0x2000) >> 0xd) * 3 + 4);
    DAT_800e112a = DAT_800e112a | 4;
  }
  return;
}
