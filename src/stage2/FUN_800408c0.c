/* FUN_800408c0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800408c0  body 0x800408c0..0x80040967  size 168 B
 * body sha256 721fc14f95456a00642f2fecde13396abcce17f182a24befec939f49fdc7bee1
 * provider record sha256 bf08f6ef684838a2bff498313e98991b726370c38c818240d3d3b7fcad95e8f2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800408c0(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xfff;
  if (uVar1 < 0x400) {
    return *(int *)(&DAT_800eec30 + (param_1 & 0x3ff) * 4);
  }
  if (uVar1 < 0x800) {
    return -*(int *)(&DAT_800eec30 + (0x400 - (param_1 & 0x3ff)) * 4);
  }
  if (uVar1 < 0xc00) {
    return -*(int *)(&DAT_800eec30 + (param_1 & 0x3ff) * 4);
  }
  return *(int *)(&DAT_800eec30 + (0x400 - (param_1 & 0x3ff)) * 4);
}
