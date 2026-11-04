/* FUN_8017d524
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017d524  body 0x8017d524..0x8017d61b  size 248 B
 * body sha256 135e6b14c13aba48043b05d8063fd3701b79a4e5e5307e466552e4ce91e01e62
 * provider record sha256 e29e40d4dc53074a7302a800d99fb47c6f948311900bdd2495918c803b8128b6
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8017d524(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)(DAT_80186c94 + 0x41c) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0;
    if (0xaf0 < DAT_80185748) {
      uVar3 = FUN_8017bec8(3);
    }
  }
  if (*(int *)(DAT_80186c94 + 0x420) == 1) {
    uVar1 = FUN_8017bec8(7);
    *(undefined4 *)(DAT_80186c94 + 0x430) = uVar1;
  }
  iVar2 = FUN_8017bec8(5);
  if (*(int *)(DAT_80186c94 + 0x41c) != 0) {
    if (*(int *)(DAT_80186c94 + 0x424) != 0) {
      *(uint *)(DAT_80186c94 + 0x434) = (uint)(byte)(&DAT_80185560)[iVar2];
      goto LAB_8017d5dc;
    }
    iVar2 = iVar2 << 1;
  }
  *(int *)(DAT_80186c94 + 0x434) = iVar2;
LAB_8017d5dc:
  iVar2 = FUN_8017bec8(1);
  if (iVar2 != 0) {
    FUN_8017bec8(1);
    FUN_8017bbe8(7);
    FUN_8017dd78();
  }
  return uVar3;
}
