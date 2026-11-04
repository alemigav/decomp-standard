/* FUN_8003b238
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003b238  body 0x8003b238..0x8003b2a3  size 108 B
 * body sha256 1f21048063d5a21f28a2994674cce6b2637b8b3e01cd0805b2a51888eba9b0ce
 * provider record sha256 021dea1b4293e4fac47df6ed7a8422152579dab5ef1ab8fcdcf45622ca7e4e90
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003b238(void)

{
  FUN_80038a20(((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x96) / 100 | 0x30b0000,0,&DAT_800e9028,
               DAT_800ebb94 + 0x34);
  return;
}
