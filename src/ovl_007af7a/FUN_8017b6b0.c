/* FUN_8017b6b0
 * image   ovl_007af7a (ovl), base 0x8017b410
 * address 0x8017b6b0  body 0x8017b6b0..0x8017b89b  size 492 B
 * body sha256 7835e02803dcbc77913b250c4406529e3d9f1d172ea202a49fd162693f2d8d41
 * provider record sha256 77534ffeb63de59c9562c26a16d46512ef941189699e45f6ab2014c9e1915747
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017b6b0(void)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar1 = func_0x8002767c(0);
  if (iVar1 == 0) {
    return;
  }
  (&DAT_8017df58)
  [((uint)(byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] + (uint)(byte)(&DAT_8017e5c4)[DAT_8017e5cc])
   * 8] = 5;
  if ((DAT_8017e5bf & 8) == 0) {
    func_0x800274f8(0x200,0,7,1);
    func_0x800275c0(0,0x7fff,1,0);
    DAT_8017e5c9 = 4;
    return;
  }
  func_0x800274f8(0x200,0xfffff400,7,1);
  if (DAT_8017e5cd != '\x03') {
    if (((DAT_8017e5cc != 3) && (DAT_8017e5cd != '\x01')) && (DAT_8017e5cc != 1)) {
      local_10 = 0x3000;
      local_c = 0x40018f00;
      func_0x800275c0(0,0x7fff,0xffff,&local_10);
      DAT_8017e5c9 = 0;
      DAT_8017e5cc = DAT_8017e5cd;
      return;
    }
    if ((DAT_8017e5cd != '\x03') && (DAT_8017e5cd != '\x01')) {
      func_0x800274e4(4,1);
      DAT_8017e5c9 = 0;
      DAT_8017e5bf = DAT_8017e5bf & 0xfe;
      goto LAB_8017b800;
    }
  }
  func_0x800274e4(4,1);
  DAT_8017e5bf = DAT_8017e5bf | 1;
  func_0x800274e4(3,0);
  DAT_8017e5bc = DAT_8017e5cd == '\x03';
  DAT_8017e5c9 = 5;
LAB_8017b800:
  func_0x800275c0(0,0x7fff,0xffff,0);
  DAT_8017e5cc = DAT_8017e5cd;
  return;
}
