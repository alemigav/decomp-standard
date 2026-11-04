/* FUN_801671cc
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x801671cc  body 0x801671cc..0x8016721b  size 80 B
 * body sha256 9d7301da338e65727579ff2e5352dc0372195a76b4e7464bf1ecfe9c1a076315
 * provider record sha256 bc6abfdcc52eb67a0a879e40a374262e9a95cb0b71c8105dbd76fadefffdc4a6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_801671cc(char param_1)

{
  DAT_80167d6a = DAT_80167d6a + param_1;
  if ('\b' < DAT_80167d6a) {
    DAT_80167d6a = 8;
    return 1;
  }
  if (DAT_80167d6a < -8) {
    DAT_80167d6a = 0xf8;
    return 0xffffffff;
  }
  return 0;
}
