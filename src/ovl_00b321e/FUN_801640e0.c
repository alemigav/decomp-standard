/* FUN_801640e0
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801640e0  body 0x801640e0..0x8016428b  size 428 B
 * body sha256 d14e5bac085103345e047aa8e97a24b7b6e086d88c567d37d200ed3f9e7b2720
 * provider record sha256 410ef802f21d0a43879f920c3a38ec262d994b66c8c2b9451d11d2ba0292d0a7
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801640e0(int param_1)

{
  short sVar1;
  int iVar2;
  byte bVar4;
  ushort uVar3;
  bool bVar5;
  
  bVar4 = *(byte *)(param_1 + 7);
  if (bVar4 != 1) {
    if (1 < bVar4) {
      if (((bVar4 == 2) &&
          (sVar1 = *(short *)(param_1 + 500), *(short *)(param_1 + 500) = sVar1 + -1, sVar1 == 1))
         && (*(undefined4 *)(param_1 + 4) = 0x1010000, _DAT_800e1322 < 0)) {
        *(undefined4 *)(param_1 + 4) = 0x1090000;
      }
      goto LAB_80164274;
    }
    if (bVar4 != 0) goto LAB_80164274;
    bVar5 = false;
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined2 *)(param_1 + 500) = 0xf;
    *(undefined4 *)(param_1 + 0x1e8) = 0x3000700;
    iVar2 = *(int *)(param_1 + 0x28) - (int)*(short *)(param_1 + 0x2da);
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    if (iVar2 < 800) {
      iVar2 = *(int *)(param_1 + 0x30) - (int)*(short *)(param_1 + 0x2dc);
      if (iVar2 < 0) {
        iVar2 = -iVar2;
      }
      if (iVar2 < 800) {
        bVar5 = true;
      }
    }
    if (bVar5) {
      bVar4 = *(char *)(param_1 + 0x2de) + 1;
      *(byte *)(param_1 + 0x2de) = bVar4;
      if (2 < bVar4) {
        *(undefined4 *)(param_1 + 4) = 0x10c0000;
        return;
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x2de) = 0;
    }
  }
  *(undefined2 *)(param_1 + 0x1e0) = 0x4b;
  if ((**(uint **)(param_1 + 0x214) & 0x10000) == 0) {
    *(undefined2 *)(param_1 + 0x1e0) = 0x25;
  }
  func_0x80032b5c(param_1,0);
  sVar1 = *(short *)(param_1 + 500);
  *(short *)(param_1 + 500) = sVar1 + -1;
  if ((sVar1 == 1) || ((*(uint *)(param_1 + 0x1ac) & 1) != 0)) {
    *(undefined1 *)(param_1 + 7) = 2;
    *(undefined4 *)(param_1 + 0x1e8) = 0x700;
    uVar3 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar3 & 0xf) + 0xf;
  }
  func_0x80033648(param_1);
LAB_80164274:
  FUN_801623ac(param_1);
  return;
}
