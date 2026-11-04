/* FUN_8017b9bc
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017b9bc  body 0x8017b9bc..0x8017b9eb  size 48 B
 * body sha256 fe0c277b215f6526a539bb7690698e63fd34efd197ac45610526c864f34fa871
 * provider record sha256 9303668db11c4db722786b617ce050af9ad3a2eb01d9fdda1f95ab64ff83610d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8017b9bc(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_8017b98c();
  uVar2 = FUN_8017b98c();
  return iVar1 << 0x10 | uVar2;
}
