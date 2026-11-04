/* FUN_80167360
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80167360  body 0x80167360..0x80167497  size 312 B
 * body sha256 e0376378b4b68d5e552895219c9df85e3b82f964be2439a2e18b384684a2666f
 * provider record sha256 3bf14859a6afdbd7f8862da02192d2316af2c301757e5513334a81bbca37b7db
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80167360(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x17d0 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0xee8,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1fa0 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x38,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1000 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x790,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1000 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x2668,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1000 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x17b8,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1000 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x1b0,0);
  return;
}
