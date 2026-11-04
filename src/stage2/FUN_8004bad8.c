/* FUN_8004bad8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004bad8  body 0x8004bad8..0x8004bbf3  size 284 B
 * body sha256 f4dff07241677440c1efc8aa76be3b671e96fe7f0e592eae23358ded3002bbe2
 * provider record sha256 1914afa305cbe754639c5c8ba76cc83aca2a10c65e414ee1876203e04654cbb3
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined * FUN_8004bad8(uint param_1)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  if ((param_1 & 0xff) < 100) {
    uVar3 = (uint)(byte)(&DAT_8012ffa9)[(param_1 & 0xff) * 8];
  }
  if ((DAT_800e10ec & 0x40) == 0) {
    if ((uVar3 == 0) || (iVar1 = FUN_800837ac(&DAT_800e8d78,uVar3), iVar1 == 0)) {
      uVar3 = param_1 & 0xff;
    }
    else {
      uVar3 = uVar3 + 0x91;
    }
    uVar3 = (uint)*(ushort *)(&DAT_800fab98 + uVar3 * 2);
    puVar2 = &UNK_800fa69c;
  }
  else if ((uVar3 == 0) || (iVar1 = FUN_800837ac(&DAT_800e8d78,uVar3), iVar1 == 0)) {
    uVar3 = (uint)*(ushort *)(&DAT_800fb3f8 + (param_1 & 0xff) * 2);
    puVar2 = &UNK_800facb0;
  }
  else {
    uVar3 = (uint)*(ushort *)(&DAT_800fb3f8 + (uVar3 + 0x91) * 2);
    puVar2 = &UNK_800facb0;
  }
  return puVar2 + uVar3;
}
