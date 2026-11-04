/* FUN_8016552c
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x8016552c  body 0x8016552c..0x80165617  size 236 B
 * body sha256 86ee1bd100ccdcece5ff4649cc6ecbb60f48d9fb0505f716dee5da7b846830e4
 * provider record sha256 c05adc3a9450713de77899b7b1868a917b1c61a0ab8ae18cd69666e5bf639760
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016552c(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if ((*(byte *)(param_1 + 0x2bd) & 1) != 0) {
    uVar3 = 0;
    do {
      uVar3 = uVar3 + 1;
      uVar1 = func_0x80033604();
      FUN_801663a4(param_1,4,uVar1 & 7);
      uVar1 = func_0x80033604();
      FUN_801663a4(param_1,3,uVar1 & 7);
    } while (uVar3 < 4);
  }
  uVar3 = 0;
  do {
    FUN_801663a4(param_1,4,uVar3 + 0xc);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 4);
  uVar3 = 0;
  iVar2 = 0;
  do {
    uVar3 = uVar3 + 1;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + iVar2 + 0x60) = 0x3f3f3f;
    iVar2 = iVar2 + 0x178;
  } while (uVar3 < 0xd);
  FUN_801651c0(param_1,param_2,param_3);
  return;
}
