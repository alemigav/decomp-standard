/* FUN_8016724c
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x8016724c  body 0x8016724c..0x801673b3  size 360 B
 * body sha256 14a30a85b0ce248fba17c8e89984a65b98ee8cace3b57ba5303d71f544284763
 * provider record sha256 561a912912420e11b09e76caccbcb9e329b9bd775c2ff49e12b56db1f23609b5
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016724c(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x3af8 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x328,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x2770 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x38,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1000 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x790,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1fa0 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x1640,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x17d0 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x1350,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1000 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0xee8,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x17d0 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x4a0,0);
  return;
}
