/* FUN_800a5890
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5890  body 0x800a5890..0x800a58bb  size 44 B
 * body sha256 244f8799e8a5f1ac43828ac4be812f9fbd843ecc75b32aaffbd2d18e34118d8e
 * provider record sha256 004a9f9c86461d8c1be91e6d245f0deafe1842e3cff03401fdc3e4cd96ec736f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_800a5890(int param_1)

{
  return *(char *)(param_1 * 0x68 + _DAT_80143f0c) != '\0';
}
