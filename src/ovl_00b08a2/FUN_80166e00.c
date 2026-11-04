/* FUN_80166e00
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80166e00  body 0x80166e00..0x80166e97  size 152 B
 * body sha256 a17ae04c0c2359c55f464ea5a732746b82f87dd010f8838b3f68257edc8a6049
 * provider record sha256 3283bf9d475f099c0914ffb72787930e52da9aed1bc0affab27c1fba08307d2c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80166e00(int param_1)

{
  *(byte *)(_DAT_800e13f0 + 0x2bf) =
       *(byte *)(_DAT_800e13f0 + 0x2bf) & ~(byte)(2 << (*(byte *)(param_1 + 0x2b4) & 0x1f));
  if (*(char *)(param_1 + 0x2be) != '\0') {
    *(char *)(param_1 + 0x2be) = *(char *)(param_1 + 0x2be) + -1;
    *(byte *)(_DAT_800e13f0 + 0x2bf) =
         *(byte *)(_DAT_800e13f0 + 0x2bf) | (byte)(2 << (*(byte *)(param_1 + 0x2b4) & 0x1f));
    func_0x80052c6c(3,0x82,0);
    func_0x80052d10(0x19,0x82,0,3);
  }
  return;
}
