/* FUN_8017b5cc
 * image   ovl_007af7a (ovl), base 0x8017b410
 * address 0x8017b5cc  body 0x8017b5cc..0x8017b6af  size 228 B
 * body sha256 f6b1cf4454678ce61b2e87bf01e8b32ab8b1680a09e74bad203ff6056d7e307a
 * provider record sha256 09757e4e0041a5836438463b1834f454af787c53d91822e8e2e31cbe6ef9fc23
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017b5cc(void)

{
  undefined4 *puVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  func_0x8006c070(0);
  if ((DAT_8017e5bf & 8) == 0) {
    func_0x800274f8(0x200,0x1800,7,1);
  }
  else {
    func_0x800274f8(0x200,0xc00,7,1);
    if ((((DAT_8017e5cd != '\x03') && (DAT_8017e5cc != '\x03')) && (DAT_8017e5cd != '\x01')) &&
       (DAT_8017e5cc != '\x01')) {
      puVar1 = &local_10;
      local_10 = 0x3000;
      local_c = 0x40018f00;
      goto LAB_8017b674;
    }
  }
  puVar1 = (undefined4 *)0x0;
LAB_8017b674:
  func_0x800275c0(0,0,0xffff,puVar1);
  if (DAT_8017e5c2 != '\0') {
    DAT_8017e5c9 = 3;
  }
  DAT_8017e5c2 = DAT_8017e5c2 == '\0';
  return;
}
