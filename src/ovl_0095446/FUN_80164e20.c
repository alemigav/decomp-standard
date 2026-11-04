/* FUN_80164e20
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80164e20  body 0x80164e20..0x80164eff  size 224 B
 * body sha256 5992f50678627a6353cf6ccbeeabd5125aea53da75a70132d6b5b8d179763be6
 * provider record sha256 7f91cd28b039dd074cffaef6be8ad99c4728a6870db4ac294c4b3152fa44ffb4
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164e20(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x17d0 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x328,0);
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
                  iVar2 + 0x17b8,0);
  return;
}
