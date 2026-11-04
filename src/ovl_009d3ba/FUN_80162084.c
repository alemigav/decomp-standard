/* FUN_80162084
 * image   ovl_009d3ba (ovl), base 0x80161cf0
 * address 0x80162084  body 0x80162084..0x801620bb  size 56 B
 * body sha256 84d00b5c61449aa80e1ddefe22b9f7c0351fbc59e6428780d3baf4272e3e57c0
 * provider record sha256 0eef92dedfae1c45f400d1561689656f393ab828029587df2f567cae15b837bb
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162084(int param_1)

{
  (*(code *)(&PTR_FUN_80163050)[*(ushort *)(param_1 + 0x1aa) & 1])();
  return;
}
