/* FUN_80168b3c
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80168b3c  body 0x80168b3c..0x80168cb3  size 376 B
 * body sha256 108943ea97258a71fc3cff7bc00cfaa26638323ed398292d2d555057b25585fb
 * provider record sha256 cd68354b72d470a03024bd891c25ff6fb606e0098a0c5a89de86efded29f58cb
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80168b3c(int param_1,int param_2)

{
  byte bVar1;
  short sVar2;
  undefined2 uVar3;
  
  bVar1 = *(byte *)(param_1 + 5);
  if (bVar1 == 1) {
LAB_80168b88:
    *(short *)(*(int *)(param_2 + 0x120) + 0xc) =
         *(short *)(*(int *)(param_2 + 0x120) + 0xc) - *(short *)(param_1 + 500);
    *(short *)(*(int *)(param_2 + 0x120) + 0x10) =
         *(short *)(*(int *)(param_2 + 0x120) + 0x10) + *(short *)(param_1 + 500);
    if (*(short *)(*(int *)(param_2 + 0x120) + 0x10) < 0x625) {
      sVar2 = *(short *)(param_1 + 500) + 0x40;
      *(short *)(param_1 + 500) = sVar2;
      if (0x180 < sVar2) {
        *(undefined2 *)(param_1 + 500) = 0x180;
      }
      goto LAB_80168ca0;
    }
    sVar2 = *(short *)(param_1 + 500) + -0x40;
    *(short *)(param_1 + 500) = sVar2;
    if (0xbf < sVar2) goto LAB_80168ca0;
    *(undefined1 *)(param_1 + 5) = 2;
    uVar3 = 0xc0;
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 != 0) goto LAB_80168ca0;
      *(undefined2 *)(param_1 + 500) = 0x200;
      *(undefined1 *)(param_1 + 5) = 1;
      goto LAB_80168b88;
    }
    if (bVar1 != 2) goto LAB_80168ca0;
    *(short *)(*(int *)(param_2 + 0x120) + 0xc) =
         *(short *)(*(int *)(param_2 + 0x120) + 0xc) + *(short *)(param_1 + 500);
    *(short *)(*(int *)(param_2 + 0x120) + 0x10) =
         *(short *)(*(int *)(param_2 + 0x120) + 0x10) - *(short *)(param_1 + 500);
    if (*(short *)(*(int *)(param_2 + 0x120) + 0x10) < 0x200) {
      sVar2 = *(short *)(param_1 + 500) + -0x30;
      *(short *)(param_1 + 500) = sVar2;
      uVar3 = 0x100;
      if (0x8f < sVar2) goto LAB_80168ca0;
      *(undefined1 *)(param_1 + 5) = 1;
    }
    else {
      sVar2 = *(short *)(param_1 + 500) + 0x30;
      *(short *)(param_1 + 500) = sVar2;
      uVar3 = 0x100;
      if (sVar2 < 0x101) goto LAB_80168ca0;
    }
  }
  *(undefined2 *)(param_1 + 500) = uVar3;
LAB_80168ca0:
  func_0x80066288(param_1);
  return;
}
