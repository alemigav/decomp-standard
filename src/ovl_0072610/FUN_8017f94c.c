/* FUN_8017f94c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017f94c  body 0x8017f94c..0x8017f9eb  size 160 B
 * body sha256 e6b311a04a3ca8e898d2fabe9fadc065315744ac13df02495023e35468d8fcd4
 * provider record sha256 0b2bdb3d544ff53bb9c0231dc8a6a4450424dd07648bd978faee4c77370086a1
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8017f94c(void)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  
  iVar1 = FUN_8017bbb0(5);
  if (iVar1 < 0x1f) {
    puVar2 = &DAT_80184e6c;
  }
  else {
    iVar1 = FUN_8017bbb0(9);
    iVar1 = iVar1 + -0x1f0;
    puVar2 = &DAT_80184eac;
  }
  uVar3 = (uint)(char)puVar2[iVar1 * 2];
  FUN_8017bbe8((int)(char)(puVar2 + iVar1 * 2)[1]);
  iVar1 = 0;
  if ((uVar3 != 0) && (iVar1 = FUN_8017bec8(uVar3), (iVar1 >> (uVar3 - 1 & 0x1f) & 1U) == 0)) {
    iVar1 = (iVar1 + 1) - (1 << (uVar3 & 0x1f));
  }
  return iVar1;
}
