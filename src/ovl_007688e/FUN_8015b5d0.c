/* FUN_8015b5d0
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015b5d0  body 0x8015b5d0..0x8015b677  size 168 B
 * body sha256 9260885544a222e541ba601fe0a9d156d77c5f629c216e64c8c16607b1a9a5bf
 * provider record sha256 203ba4db18bc06ec5ae8ef12fda24790a1ec3da5e000abe3f42f9ef84a64f082
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8015b5d0(void)

{
  if (DAT_80160c1e != 1) {
    if (1 < DAT_80160c1e) {
      if (DAT_80160c1e == 2) {
        DAT_80160c1d = 1;
        DAT_80160c1e = 0;
      }
      goto LAB_8015b65c;
    }
    if (DAT_80160c1e != 0) goto LAB_8015b65c;
    func_0x800274e4(0,0);
    DAT_80160c30 = 0x36;
    DAT_80160c34 = 0x16;
    DAT_80160c32 = 0;
  }
  DAT_80160c1d = 1;
  DAT_80160c1e = 0;
LAB_8015b65c:
  FUN_8015fd54();
  return;
}
