/* FUN_8009189c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009189c  body 0x8009189c..0x800919a7  size 268 B
 * body sha256 57a1f6f35880872047f62d17351f7c6096af7231bbf7b1bb123453039ef57ca4
 * provider record sha256 263a055951c26086e2a101432e4a4b546bf4863f932ffdd75474b34e09f56b49
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 switchD_8009177c::caseD_4(void)

{
  undefined4 uVar1;
  int iVar2;
  uint unaff_s0;
  
  uVar1 = 9;
  if (2 < unaff_s0) {
    if (unaff_s0 == 8) {
      uVar1 = 9;
    }
    else if (((DAT_800e110c & 0x40000000) == 0) || (unaff_s0 != 3)) {
      if (unaff_s0 == 5) {
        if ((DAT_800e110c & 0x40000000) == 0) {
          iVar2 = FUN_800837ac(&DAT_800e8ce0,0xbe);
          if (iVar2 != 0) {
            return 0x10;
          }
        }
        else {
          iVar2 = FUN_800837ac(&DAT_800e8ce0,0xbe);
          if (iVar2 != 0) {
            return 0xd;
          }
        }
        iVar2 = FUN_800837ac(&DAT_800e8ce0,99);
        if (iVar2 != 0) {
          return 0xc;
        }
      }
      uVar1 = 10;
      if ((5 < unaff_s0) && (uVar1 = 0xc, unaff_s0 != 9)) {
        uVar1 = 0xb;
      }
    }
    else {
      iVar2 = FUN_800837ac(&DAT_800e8ce0,0x62);
      uVar1 = 10;
      if (iVar2 == 0) {
        uVar1 = 0xb;
      }
    }
  }
  return uVar1;
}
