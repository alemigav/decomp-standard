/* FUN_8017e150
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017e150  body 0x8017e150..0x8017e20b  size 188 B
 * body sha256 6535bb1087b587fc4c01d40da98b54f97b01e7687ef786ba75dde60b28bdd9a4
 * provider record sha256 27992068e883b401ac106bc2d38344ce8e57cddb461b66ed0287cca7f383d908
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017e150(void)

{
  if ((((_DAT_800e10ec & 0x100) == 0) && ((_DAT_800e110c & 0x10000000) != 0)) &&
     (*(char *)(_DAT_800e13ec + 4) == '\x03')) {
    DAT_8017e734 = 1;
  }
  func_0x800479c8(_DAT_800c52dc + 0x3b800,&DAT_8017e8e4,0x14cf,0);
  func_0x8003994c(0x200,0x200,0x100);
  FUN_8017e20c(0xc68);
  return;
}
