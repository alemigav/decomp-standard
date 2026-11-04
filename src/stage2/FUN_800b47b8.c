/* FUN_800b47b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b47b8  body 0x800b47b8..0x800b480b  size 84 B
 * body sha256 582b14793ff96ed16bb8de2d5a91ecfd4215375073ecd185e41e9a917b7d8762
 * provider record sha256 474b276b827bd664ee684622ac74ab5b26fcaeaf9d55f6c81ec09a0a6935fb6f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800b47b8(void)

{
  if (_DAT_80143fd4 == (code *)0x0) {
    osCreateMesgQueue(0x8015b010,0x8015b028,1);
    DAT_8015afc0 = 0;
    _DAT_80143fd4 = FUN_800b4540;
  }
  return;
}
