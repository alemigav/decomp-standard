/* FUN_801623b0
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x801623b0  body 0x801623b0..0x801623e7  size 56 B
 * body sha256 e54b9ccf62b2eea22839661cc37003890ad6c7cda47740a4a548bfaeaf7e7791
 * provider record sha256 173fda872885a6df09ecd5ae810df89c5435d5164c2166255344682e725e42e0
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801623b0(int param_1)

{
  (*(code *)(&PTR_FUN_80166f8c)[*(ushort *)(param_1 + 0x1aa) & 0x3f])();
  return;
}
