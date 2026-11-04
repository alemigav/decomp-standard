/* FUN_801669f8
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801669f8  body 0x801669f8..0x80166b03  size 268 B
 * body sha256 7ce92a08cce67233bc95f8d1cca10da484dfdc0fd3e6602b15ef69cb7e0fd508
 * provider record sha256 d85213b7912e38ebb3ca016a2cb09a24a1e42318d89480e5e080f5c3c8f67fdb
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801669f8(int param_1,uint param_2)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 auStack_38 [22];
  ushort local_22;
  ushort local_1a;
  
  iVar3 = *(int *)(param_1 + 0x234);
  func_0x80040e58(param_1 + 100,param_1 + 0x14);
  func_0x800424ec(param_1 + 0x14,iVar3 + 8,auStack_38);
  iVar3 = iVar3 + (param_2 & 0xff) * 0xbc0 + 0x5e0;
  if (((int)(uint)*(byte *)(param_1 + 700) >> ((param_2 & 7) << 2) & 1U) == 0) {
    func_0x800424ec(auStack_38,iVar3 + -0x170,auStack_38);
    func_0x800424ec(auStack_38,iVar3 + 8,auStack_38);
    iVar1 = (int)(((uint)local_22 - (uint)*(ushort *)(iVar3 + 0x4e)) * 0x10000) >> 0x10;
    iVar3 = (int)(((uint)local_1a - (uint)*(ushort *)(iVar3 + 0x56)) * 0x10000) >> 0x10;
    uVar2 = func_0x80040bb4(iVar1 * iVar1 + iVar3 * iVar3);
    *(undefined2 *)(param_1 + 0x1e0) = uVar2;
  }
  else {
    *(undefined2 *)(param_1 + 0x1e0) = 0;
  }
  return;
}
