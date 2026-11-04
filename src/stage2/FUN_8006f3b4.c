/* FUN_8006f3b4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006f3b4  body 0x8006f3b4..0x8006f447  size 148 B
 * body sha256 2af39fe2e94f76bc8af21bad1ad44e48263febcf69d532d499bc6df9dadfc6eb
 * provider record sha256 db9deecb686d67711f6cca40cee3803e8e216f440932f77570a00cf4492b3062
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006f3b4(int param_1)

{
  byte *pbVar1;
  
  DAT_801152cc = (byte *)(&DAT_800dfb60)[*(byte *)(*(int *)(param_1 + 0x1c) + 1)];
  pbVar1 = DAT_801152cc + 0x14;
  if ((DAT_801152cc[1] & 0x80) == 0) {
    pbVar1 = DAT_801152cc + 0xc;
  }
  (*(code *)(&PTR_LAB_80115290)[*DAT_801152cc])(pbVar1);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 2;
  return 1;
}
