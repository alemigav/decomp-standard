/* FUN_80165bd0
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80165bd0  body 0x80165bd0..0x80165c73  size 164 B
 * body sha256 0a6009d0d3756a5d9f1fb52963622f4ab8d7931cd5ee4f05aef4b7d54d10a6c1
 * provider record sha256 9175b2b43afd77ead56f3988143c84ae63847c71db4e91dbe434e302c4e81b3c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165bd0(int param_1,uint param_2,short param_3,short param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x234) + (param_2 & 0x3f) * 0x178;
  if ((param_2 & 0x40) == 0) {
    *(short *)(iVar1 + 0x58) = -param_3;
    *(short *)(iVar1 + 0x5a) = -param_4;
    func_0x80040e58(iVar1 + 0x58,iVar1 + 8);
  }
  if ((param_2 & 0x80) == 0) {
    *(short *)(iVar1 + 0x348) = param_3;
    *(short *)(iVar1 + 0x34a) = param_4;
    func_0x80040e58(iVar1 + 0x348,iVar1 + 0x2f8);
  }
  return;
}
