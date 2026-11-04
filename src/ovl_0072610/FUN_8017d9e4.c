/* FUN_8017d9e4
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017d9e4  body 0x8017d9e4..0x8017da9b  size 184 B
 * body sha256 51c1cdde0c4c4a2f1122ef6244b67a1af4381a344e54062d44e2e9a9aeab33a1
 * provider record sha256 9d55fb767a79a6db4b939fcd9be47395228e6a9661a97a00cf1a719b7b650aed
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017d9e4(void)

{
  int iVar1;
  
  iVar1 = FUN_8017bec8(2);
  *(int *)(DAT_80186c94 + 0x420) = iVar1 + 1;
  FUN_8017bec8(4);
  if (*(int *)(DAT_80186c94 + 0x420) == 2) {
    DAT_801857c4 = FUN_8017bec8(0xe);
    FUN_8017bbe8(1);
    DAT_801857c8 = FUN_8017bec8(0xe);
    DAT_801857cc = FUN_8017bec8(5);
    DAT_801857d0 = FUN_8017bec8(5);
    DAT_801857d4 = FUN_8017bec8(5);
    DAT_801857d8 = FUN_8017bec8(5);
  }
  return;
}
