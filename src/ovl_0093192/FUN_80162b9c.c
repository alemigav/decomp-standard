/* FUN_80162b9c
 * image   ovl_0093192 (ovl), base 0x80161cf0
 * address 0x80162b9c  body 0x80162b9c..0x80162c6b  size 208 B
 * body sha256 43d3d1353012deefb61b73bedd7c5e4eed8e05139f3fd68de0f300819b2e48b9
 * provider record sha256 dd9024649a6b4e62d1f4285a8fb27e33c723f1be123f1575528882b0a27d4e4e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162b9c(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined2 local_10;
  short local_e;
  undefined2 local_c;
  
  iVar2 = *(int *)(param_1 + 0x234) + (param_2 & 0xff) * 0x178;
  iVar1 = (param_3 & 0x7f) * 6;
  local_10 = *(undefined2 *)(iVar2 + 0x4e);
  local_e = *(short *)(iVar2 + 0x52);
  if (((param_3 & 0x80) != 0) && (*(short *)(param_1 + 0x1a8) < *(short *)(param_1 + 0x25e))) {
    local_e = *(short *)(param_1 + 0x1a8) + 10;
  }
  local_c = *(undefined2 *)(iVar2 + 0x56);
  func_0x80037780((uint)(byte)(&DAT_80162d6c)[iVar1] << 0x18 |
                  (uint)(byte)(&DAT_80162d6d)[iVar1] << 0x10 |
                  (uint)*(ushort *)(&DAT_80162d70 + iVar1),
                  (int)(((int)*(short *)(param_1 + 0x66) + (uint)*(ushort *)(&DAT_80162d6e + iVar1))
                       * 0x10000) >> 0x10,0x800e9028,&local_10);
  return;
}
