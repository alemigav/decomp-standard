/* FUN_8016a87c
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016a87c  body 0x8016a87c..0x8016a8bf  size 68 B
 * body sha256 f452e77f7b279faa09e63bfb7454b8bc52923c04987d1c84f707d4fa6179a752
 * provider record sha256 3fc48bb6b42916057188837df4631b252cc9bcbd536cc807e24b6a9a1f5b79cd
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
ushort FUN_8016a87c(int param_1,ushort param_2)

{
  ushort uVar1;
  
  uVar1 = (~param_2 & 1) * 0x400;
  if (((uVar1 - *(short *)(param_1 + 0x66)) + 0x400 & 0xfff) < 0x800) {
    return uVar1;
  }
  return uVar1 | 0x800;
}
