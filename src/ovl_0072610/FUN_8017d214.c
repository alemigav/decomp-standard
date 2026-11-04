/* FUN_8017d214
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017d214  body 0x8017d214..0x8017d25b  size 72 B
 * body sha256 3ed58092ab1140dd3dd97b76500560ee67896e8c13456fe037bd93f2bfccee8c
 * provider record sha256 ffe2805659ac3252062e669078a4e90a799e3bc65e1871bada62bda9a0f06ac1
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017d214(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(DAT_80186c94 + 0x10) & 7;
  do {
    FUN_8017bbe8(uVar2);
    iVar1 = FUN_8017bbb0(0x18);
    uVar2 = 8;
  } while (iVar1 != 1);
  return;
}
