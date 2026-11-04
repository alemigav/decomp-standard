/* FUN_8006ebec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006ebec  body 0x8006ebec..0x8006ec57  size 108 B
 * body sha256 49e90017d31d29f5b6959ed52e34d31f9a17cf56f46cd1975670794bc68e76b9
 * provider record sha256 7baf7f4e0e16f7c3a1e5d05f414aa3c8741807fd16f98fc91f25807722f60cbd
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006ebec(undefined4 param_1)

{
  DAT_800e9183 = 1;
  DAT_80114f35 = (undefined1)DAT_800e8cac;
  DAT_800e8cac = (short)param_1;
  if ((DAT_800e10ec & 0x2000000) == 0) {
    FUN_80083c14(param_1);
  }
  return;
}
