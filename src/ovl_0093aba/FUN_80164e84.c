/* FUN_80164e84
 * image   ovl_0093aba (ovl), base 0x80161cf0
 * address 0x80164e84  body 0x80164e84..0x80165077  size 500 B
 * body sha256 9706f8ebbc345b4d96255a15ccfcaf44f7446be4aceaf971ee175239e1942b76
 * provider record sha256 2a2039f6ae3c6ea37147395c08a2a93719f8b6c16aa9a6db136379d07de1eec5
 * callees 3 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164e84(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  bVar1 = *(byte *)(param_1 + 5);
  iVar7 = *(int *)(param_1 + 0x208);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        func_0x8003247c(param_1);
        *(undefined1 *)(iVar7 + 0xe) = 0;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined2 *)(param_1 + 0x1f2) = 0xffff;
    *(undefined1 *)(param_1 + 5) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x9000000;
    *(undefined2 *)(param_1 + 500) = 0;
    func_0x80089d54(param_1,param_2,param_3,0x100);
  }
  sVar2 = *(short *)(param_1 + 500) + 1;
  *(short *)(param_1 + 500) = sVar2;
  if (sVar2 == 0x1f) {
    iVar5 = 10;
    iVar6 = *(int *)(param_1 + 0x234);
    piVar4 = (int *)(iVar6 + 0x60);
    do {
      func_0x8004a5b4(iVar6 + 4,1);
      iVar6 = iVar6 + 0x178;
      iVar5 = iVar5 + -1;
      piVar4[-0x17] = piVar4[-0x17] | 2;
      *piVar4 = *piVar4 + -0x103010;
      piVar4 = piVar4 + 0x5e;
    } while (iVar5 != 0);
  }
  if (0x1e < *(short *)(param_1 + 500)) {
    iVar6 = *(int *)(param_1 + 0x234);
    iVar5 = 10;
    if (*(char *)(iVar6 + 99) != '\0') {
      piVar4 = (int *)(iVar6 + 0x60);
      do {
        iVar5 = iVar5 + -1;
        *piVar4 = *piVar4 + -0x10001;
        piVar4 = piVar4 + 0x5e;
      } while (iVar5 != 0);
      iVar6 = *(int *)(param_1 + 0x234);
    }
    iVar5 = 10;
    if ((*(uint *)(iVar6 + 0x60) & 0xff00) != 0) {
      piVar4 = (int *)(iVar6 + 0x60);
      do {
        iVar5 = iVar5 + -1;
        *piVar4 = *piVar4 + -0x100;
        piVar4 = piVar4 + 0x5e;
      } while (iVar5 != 0);
    }
  }
  if ((*(uint *)(*(int *)(param_1 + 0x234) + 0x60) & 0xffffff) == 0) {
    *(undefined1 *)(param_1 + 5) = 2;
  }
  uVar3 = *(uint *)(iVar7 + 0x18);
  if ((uVar3 & 0xff0000) != 0) {
    *(uint *)(iVar7 + 0x18) = uVar3 - 0x10000;
    uVar3 = *(uint *)(iVar7 + 0x18);
  }
  if ((uVar3 & 0xff000000) != 0) {
    *(uint *)(iVar7 + 0x18) = uVar3 + 0xfdfffe00;
  }
  *(undefined1 *)(iVar7 + 0x1b) = 1;
  return;
}
