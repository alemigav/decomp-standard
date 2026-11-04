/* FUN_80167498
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80167498  body 0x80167498..0x80167627  size 400 B
 * body sha256 d4ec1bbe8a24de2ea54e41cfe5955580cd7ac3b481a11053c82030f8a2fed05e
 * provider record sha256 e7ab4eaf859eb543136a05ff8d34222bbd2d617bef3e6f3ce14d53c47dbe291c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80167498(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x17d0 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0xee8,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1bb8 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x38,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1000 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x1640,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1000 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x790,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1000 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x328,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x830 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x38,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x448 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x1640,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x448 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x618,0);
  return;
}
