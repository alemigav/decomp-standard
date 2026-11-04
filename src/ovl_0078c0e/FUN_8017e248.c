/* FUN_8017e248
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017e248  body 0x8017e248..0x8017e31b  size 212 B
 * body sha256 e4dce23e16b5e8bd3cf7ecfa3ef92a7bb83278325f873a578cde744879f7fb5c
 * provider record sha256 6c7f9780c4a28d6d88c58ef61ba56a8279a176fa988111df1bb3dce11a4e327b
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017e248(int param_1)

{
  int iVar1;
  
  func_0x80027650(3);
  func_0x800274f8(0x200,0x1800,7,1);
  while (iVar1 = func_0x8002767c(0), iVar1 == 0) {
    func_0x8004cd88(1);
  }
  func_0x80026910(DAT_80181fac);
  func_0x800274f8(0x200,0,7,1);
  func_0x800275c0(0,0x7fff,0xffff,0);
  func_0x8004cd88(1);
  if ((param_1 == 0) && ((_DAT_800e10ec & 0x200000) == 0)) {
    DAT_800e9182 = 2;
    DAT_800e9183 = 2;
  }
  return;
}
