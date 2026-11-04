/* FUN_80162f08
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80162f08  body 0x80162f08..0x80162f57  size 80 B
 * body sha256 5d517b22807d00cfffbf6435ab9f93fb02a7a75e6e251ae4253e6c34f86414f6
 * provider record sha256 1ee997c1f1cf699143148bd8d27a331ded7f95df5b4e84ec58284e613b32fc03
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162f08(int param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0x234);
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      uVar2 = uVar2 + 1;
      *(uint *)(iVar1 + 0x60) =
           *(uint *)(iVar1 + 0x60) & 0xff000000 | param_5 << 0x10 | param_4 << 8 | param_3;
      iVar1 = iVar1 + 0x178;
    } while (uVar2 < param_2);
  }
  return;
}
