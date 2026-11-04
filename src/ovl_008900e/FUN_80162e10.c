/* FUN_80162e10
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80162e10  body 0x80162e10..0x80162f07  size 248 B
 * body sha256 ba467b61d06d62fc51cee441a39d96acd30c6ea2049cd59cc8ac14ab0572956f
 * provider record sha256 dff6b0975460ddcec0b271f7a378404665342e9815596a7824cc5fff22202e4d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162e10(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  switch(param_2) {
  case 0:
    uVar2 = *param_1 & 0xe3ffffff;
    uVar1 = 0x10000000;
    break;
  case 1:
    uVar2 = *param_1 & 0xe3ffffff;
    uVar1 = 0x18000000;
    break;
  case 2:
    uVar2 = *param_1 & 0xe3ffffff;
    uVar1 = 0x8000000;
    break;
  case 3:
    uVar2 = *param_1 & 0xe3ffffff;
    uVar1 = 0xc000000;
    break;
  case 4:
    if (_DAT_800e12da - 7 < 2) {
      uVar2 = *param_1 & 0xe3ffffff;
      uVar1 = 0xc000000;
    }
    else {
      uVar2 = *param_1 & 0xe3ffffff;
      uVar1 = 0x4000000;
    }
    break;
  case 5:
    *param_1 = *param_1 & 0xe3ffffff;
  default:
    return;
  }
  *param_1 = uVar2 | uVar1;
  return;
}
