/* FUN_80007590
 * image   boot (boot), base 0x80000480
 * address 0x80007590  body 0x80007590..0x80007a9b  size 1292 B
 * body sha256 b026c857be68ea8be115982e59481a7e55531489e261e968ca37e64100f39219
 * provider record sha256 6c59cfcb80b21cd887f31e460db2b0e5b327cbe8abe7369242cd0456eaf1d7a1
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80007590(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  
  uVar2 = _DAT_a5000508;
  iVar1 = _DAT_80016224;
  piVar5 = (int *)(_DAT_80016224 + 0x14);
  piVar6 = piVar5 + (uint)*(ushort *)(_DAT_80016224 + 0x1a) * 9 + 6;
  if ((_DAT_a4600010 & 1) != 0) {
    *piVar6 = 0x1d;
    _DAT_800128d0 = _DAT_800128d0 & 0xfffff7ff;
    FUN_80007b6c();
    return 1;
  }
  do {
  } while ((_DAT_a4600010 & 3) != 0);
  if ((_DAT_a5000508 & 0x2000000) != 0) {
    do {
    } while ((_DAT_a4600010 & 3) != 0);
    _DAT_a5000510 = *(uint *)(_DAT_80016224 + 0x24) | 0x1000000;
    *piVar6 = 0;
    return 0;
  }
  iVar4 = *piVar5;
  if (iVar4 == 2) {
    return 1;
  }
  if ((_DAT_a5000508 & 0x8000000) != 0) {
    do {
    } while ((_DAT_a4600010 & 3) != 0);
    *piVar6 = 0x16;
    FUN_80007b6c();
    _DAT_800128d0 = _DAT_800128d0 | 0x100401;
    _DAT_a4600010 = 2;
    return 1;
  }
  if (iVar4 == 1) {
    if ((_DAT_a5000508 & 0x40000000) != 0) {
      piVar6[1] = piVar6[1] + piVar6[3];
      iVar4 = _DAT_80016224;
      *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + 1;
      pi_dma_programmer(iVar4,1,0x5000400,piVar6[1],piVar6[3]);
      return 1;
    }
    iVar3 = 0x18;
    if (*(int *)(_DAT_80016224 + 0x1c) + 1 == (uint)*(ushort *)(_DAT_80016224 + 0x18) * 0x55) {
      _DAT_a4600010 = 2;
      *piVar6 = 0;
      _DAT_800128d0 = _DAT_800128d0 | 0x100401;
      FUN_80007b6c();
      return 1;
    }
  }
  else {
    iVar3 = 4;
    if (iVar4 == 0) {
      if (*(short *)(_DAT_80016224 + 0x18) == 3) {
        if (piVar6[4] + 0x11 < *(int *)(_DAT_80016224 + 0x1c)) {
          *piVar6 = 0;
          goto LAB_80007a78;
        }
        if ((_DAT_a5000508 & 0x40000000) == 0) {
          iVar3 = 0x17;
          goto LAB_80007a74;
        }
      }
      else {
        piVar6[1] = piVar6[1] + piVar6[3];
      }
      if (((_DAT_a5000510 & 0x600000) == 0x600000) || ((_DAT_a5000510 & 0x2000000) != 0)) {
        if ((uint)piVar6[4] < 4) {
          piVar6[piVar6[4] + 5] = *(int *)(iVar1 + 0x1c) + 1;
        }
        else {
          iVar3 = 0x17;
          if (*(short *)(iVar1 + 0x18) != 3) goto LAB_80007a74;
          if (0x52 < *(int *)(iVar1 + 0x1c)) {
            *piVar6 = 0x17;
            goto LAB_80007a78;
          }
        }
        piVar6[4] = piVar6[4] + 1;
      }
      if ((uVar2 & 0x10000000) != 0) {
        if (*(int *)(iVar1 + 0x1c) != 0x57) {
          *piVar6 = 0x18;
          FUN_80007a9c();
        }
        if (*(int *)(iVar1 + 0x18) == 0x20000) {
          *(undefined2 *)(iVar1 + 0x1a) = 1;
          *(undefined4 *)(iVar1 + 0x1c) = 0xffffffff;
          *(int *)(iVar1 + 0x54) = *(int *)(iVar1 + 0x54) - *(int *)(iVar1 + 0x5c);
          *piVar6 = 0x16;
        }
        else {
          _DAT_a4600010 = 2;
          *piVar5 = 2;
          *piVar6 = 0;
          _DAT_800128d0 = _DAT_800128d0 | 0x100401;
        }
        pi_dma_programmer(_DAT_80016224,0,0x5000000,piVar6[2],piVar6[3] << 2);
        return 1;
      }
      if ((*(int *)(iVar1 + 0x1c) == -1) && (*(int *)(iVar1 + 0x18) == 0x20001)) {
        if ((*(int *)(iVar1 + 0x3c) == 0) &&
           (piVar5 = *(int **)(iVar1 + 0x34),
           ((*piVar5 != 0 || piVar5[1] != 0) || piVar5[2] != 0) || piVar5[3] != 0)) {
          *(undefined4 *)(iVar1 + 0x2c) = 0x18;
          goto LAB_80007a78;
        }
        *(undefined4 *)(iVar1 + 0x2c) = 0;
        FUN_80007b6c();
      }
      iVar4 = *(int *)(iVar1 + 0x1c) + 1;
      *(int *)(iVar1 + 0x1c) = iVar4;
      if ((uVar2 & 0x40000000) == 0) {
        iVar3 = 0x18;
        if (0x54 < iVar4) {
          return 1;
        }
      }
      else {
        if (iVar4 < 0x55) {
          pi_dma_programmer(_DAT_80016224,0,0x5000400,piVar6[1],piVar6[3]);
          *piVar6 = 0;
          return 1;
        }
        iVar3 = 0x18;
      }
    }
  }
LAB_80007a74:
  *piVar6 = iVar3;
LAB_80007a78:
  FUN_80007a9c();
  return 1;
}
