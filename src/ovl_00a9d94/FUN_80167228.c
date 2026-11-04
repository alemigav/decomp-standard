/* FUN_80167228
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80167228  body 0x80167228..0x8016735f  size 312 B
 * body sha256 4996456f4e62d161ff1a0c1b6d465ce0a89b9123751330d0c43a572a9d110e8e
 * provider record sha256 5b47f2a6debf0d817a0ec3778ff6ae54ae0fbc4fd9fb9e0fa4c0be3b5aa11b14
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80167228(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x17d0 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0xee8,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1fa0 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x38,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1000 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x790,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1000 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x1b0,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1000 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x1640,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1000 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x11d8,0);
  return;
}
