/* FUN_8017f9ec
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017f9ec  body 0x8017f9ec..0x8017fa8b  size 160 B
 * body sha256 5d6c41af0a1ba520860da05a9c131656cfba242bbcc70a99e2ec2d8e2997a0f4
 * provider record sha256 24286c2b6f024413e45385ed9bdd930c2d8deb23ac1fdf23d6d82452562c75b2
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8017f9ec(void)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  
  iVar1 = FUN_8017bbb0(5);
  if (iVar1 < 0x1f) {
    puVar2 = &DAT_80184ecc;
  }
  else {
    iVar1 = FUN_8017bbb0(10);
    iVar1 = iVar1 + -0x3e0;
    puVar2 = &DAT_80184f0c;
  }
  uVar3 = (uint)(char)puVar2[iVar1 * 2];
  FUN_8017bbe8((int)(char)(puVar2 + iVar1 * 2)[1]);
  iVar1 = 0;
  if ((uVar3 != 0) && (iVar1 = FUN_8017bec8(uVar3), (iVar1 >> (uVar3 - 1 & 0x1f) & 1U) == 0)) {
    iVar1 = (iVar1 + 1) - (1 << (uVar3 & 0x1f));
  }
  return iVar1;
}
