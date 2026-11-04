/* func_80161cf0
 * image   ovl_009d3ba (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80161dbf  size 208 B
 * body sha256 c36affd35ba91aa5b0abd4a4f96f939e87d7b1da1f44dd5bbdfb5fb948199bc6
 * provider record sha256 8c8f6a9df0d325e11c0f728d76d0d8e4e3607aafaf599285345277a66b07ea2b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  int in_a0;
  
  func_0x800653d0(in_a0,&DAT_800e1158,0,0);
  if ((_DAT_800e1110 & 0x20000000) == 0) {
    if ((_DAT_800e1128 != 0) && ((*(ushort *)(in_a0 + 0x1aa) & 0x10) != 0)) {
      _DAT_800e1128 = _DAT_800e1128 + -1;
    }
    if ((DAT_80163130 != '\0') && ((*(ushort *)(in_a0 + 0x1aa) & 0x10) != 0)) {
      DAT_80163130 = DAT_80163130 + -1;
    }
    (*(code *)(&PTR_FUN_80163030)[*(byte *)(in_a0 + 4)])();
    func_0x8004db5c();
  }
  return;
}
