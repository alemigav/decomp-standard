/* FUN_80164d40
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80164d40  body 0x80164d40..0x80164e1f  size 224 B
 * body sha256 80b31ea3a22fa9ebd7c5912b3472c1df4df9ef910be5c094112226c5694d60ab
 * provider record sha256 2279c665222e8b40f6b5ccbcc48e85f8eb4b897d94152e86884c6c3b61d5be2a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164d40(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1fa0 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x328,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1fa0 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x38,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x17d0 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x790,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x17d0 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x17b8,0);
  return;
}
