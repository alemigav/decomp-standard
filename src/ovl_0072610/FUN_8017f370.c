/* FUN_8017f370
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017f370  body 0x8017f370..0x8017f3b3  size 68 B
 * body sha256 3c2cf998b33a61e96091c2b506d756a4128606014ad60dafe48471b70d8900a4
 * provider record sha256 9e7692c7cfdf0edf506af47aecdd04688d336c47a78983a77ccd8defc179da2d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8017f370(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_8017bbcc();
  uVar2 = 1;
  if (iVar1 == 0) {
    iVar1 = FUN_8017bbcc();
    uVar2 = 0x11;
    if (iVar1 == 0) {
      DAT_80185780 = 1;
      uVar2 = 0x11;
    }
  }
  return uVar2;
}
