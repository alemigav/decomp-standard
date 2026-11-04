/* FUN_801623e8
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x801623e8  body 0x801623e8..0x80162483  size 156 B
 * body sha256 ff5ea803ebfb798eb1383cf0000c298a202c4f8ff47086544371b851527491a5
 * provider record sha256 ab07bd9580daf7e4bf84a92ca241f40098734d8bf2301077574d0d4d7b05aa94
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801623e8(int param_1,undefined4 param_2,undefined4 param_3)

{
  if ((*(ushort *)(param_1 + 0x2c2) & 6) == 4) {
    *(undefined4 *)(param_1 + 4) = 0x3000000;
  }
  else {
    (*(code *)(&PTR_FUN_80166f90)[*(byte *)(param_1 + 5)])(param_1);
    (*(code *)(&PTR_FUN_80166fa4)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  return;
}
