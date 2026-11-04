/* FUN_80043398
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80043398  body 0x80043398..0x8004341b  size 132 B
 * body sha256 223c730d22ef3d91a5c989622352089c335d3cdf5ea867af7daa5216862320ba
 * provider record sha256 aa34a07e507769471830db1574e0af73f2bfa297f2bd7cd628e23530b7a649c5
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80043398(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_80040bb4((_DAT_80139a70 - DAT_801315d0) * (_DAT_80139a70 - DAT_801315d0) +
                       (_DAT_80139a72 - DAT_801315d4) * (_DAT_80139a72 - DAT_801315d4) +
                       (_DAT_80139a74 - DAT_801315d8) * (_DAT_80139a74 - DAT_801315d8));
  *param_1 = uVar1;
  return;
}
