/* FUN_80167c88
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80167c88  body 0x80167c88..0x80167ebb  size 564 B
 * body sha256 8eb12e149a7b132edfefcc7b6532bb3046b2155cb31083e5bfeb6b8acb820786
 * provider record sha256 6d3b183dc231b905d0b8b4564df05126efcf4fdf9dd078bce2f7c8423dcf639a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80167c88(int param_1)

{
  ushort uVar2;
  uint uVar1;
  int iVar3;
  short local_20;
  short local_1e;
  short local_1c;
  
  iVar3 = *(int *)(param_1 + 0x234);
  uVar2 = func_0x80033604();
  local_20 = 0x80 - (uVar2 & 0xff);
  uVar2 = func_0x80033604();
  local_1e = 0x80 - (uVar2 & 0xff);
  uVar2 = func_0x80033604();
  local_1c = 0x80 - (uVar2 & 0xff);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 8 + 0x13e8 | 0x6000000,(int)*(short *)(param_1 + 0x66),
                  iVar3 + 0x38,&local_20);
  iVar3 = *(int *)(param_1 + 0x234);
  uVar2 = func_0x80033604();
  local_20 = 0x80 - (uVar2 & 0xff);
  uVar2 = func_0x80033604();
  local_1e = 0x80 - (uVar2 & 0xff);
  uVar2 = func_0x80033604();
  local_1c = 0x80 - (uVar2 & 0xff);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 8 + 0x1000 | 0x6000000,(int)*(short *)(param_1 + 0x66),
                  iVar3 + 0x38,&local_20);
  iVar3 = *(int *)(param_1 + 0x234);
  uVar2 = func_0x80033604();
  local_20 = 0x80 - (uVar2 & 0xff);
  uVar2 = func_0x80033604();
  local_1e = 0x80 - (uVar2 & 0xff);
  uVar2 = func_0x80033604();
  local_1c = 0x80 - (uVar2 & 0xff);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 8 + 0x1000 | 0x6000000,(int)*(short *)(param_1 + 0x66),
                  iVar3 + 0x38,&local_20);
  iVar3 = *(int *)(param_1 + 0x234);
  uVar2 = func_0x80033604();
  local_20 = 0x80 - (uVar2 & 0xff);
  uVar2 = func_0x80033604();
  local_1e = 0x80 - (uVar2 & 0xff);
  uVar2 = func_0x80033604();
  local_1c = 0x80 - (uVar2 & 0xff);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 8 + 0xc18 | 0x6000000,(int)*(short *)(param_1 + 0x66),
                  iVar3 + 0x38,&local_20);
  iVar3 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) << 3 | 0x40c1000,(int)*(short *)(param_1 + 0x66),iVar3 + 0x38,0);
  iVar3 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 8 + 0xc18 | 0x6000000,(int)*(short *)(param_1 + 0x66),
                  iVar3 + 0xd70,&local_20);
  iVar3 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 8 + 0xc18 | 0x6000000,(int)*(short *)(param_1 + 0x66),
                  iVar3 + 0x4a0,&local_20);
  return;
}
