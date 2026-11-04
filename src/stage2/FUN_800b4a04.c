/* FUN_800b4a04
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b4a04  body 0x800b4a04..0x800b4d2f  size 812 B
 * body sha256 c6d3342a2f5430a1094e5a1a158ef3ceec59b73184afa430ca5d384848343b14
 * provider record sha256 f615cd0126a037ca3cc27a974eddaf228d852a0f67795d1657668da10827bb40
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800b4a04(int param_1)

{
  int iVar1;
  short sVar3;
  uint uVar2;
  uint uVar4;
  uint uVar5;
  
  uVar5 = (uint)*(byte *)(param_1 + 0x11de);
  if (*(char *)(param_1 + 0x11dc) != '\0') {
    iVar1 = osRecvMesg(param_1 + 0x11ac,0,0);
    if (-1 < iVar1) {
      iVar1 = *(int *)(param_1 + 0x11d0);
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x11c8) = 0x60;
        *(undefined2 *)(param_1 + 0x11a0) = *(undefined2 *)(param_1 + 0x1a4);
        *(short *)(param_1 + 0x11a2) = (short)*(undefined4 *)(param_1 + 0x1a4);
        *(uint *)(param_1 + 0x11a4) = *(uint *)(param_1 + 0x1a8) & 0xffffff;
        iVar1 = *(int *)(param_1 + 0x11d0);
      }
      *(int *)(param_1 + 0x11d0) = iVar1 + 0x400;
      if (*(uint *)(param_1 + 0x11a4) < 0x101) {
        *(undefined4 *)(param_1 + 0x11a4) = 0;
      }
      else {
        *(uint *)(param_1 + 0x11a4) = *(uint *)(param_1 + 0x11a4) - 0x100;
      }
      *(undefined1 *)(param_1 + 0x11dc) = 0;
    }
    if (*(char *)(param_1 + 0x11dc) != '\0') goto LAB_800b4b38;
  }
  if (((*(byte *)(param_1 + 0x11dd) - 1 < 2) || (*(byte *)(param_1 + 0x11dd) == 3)) &&
     ((uint)(*(int *)(param_1 + 0x11d0) - *(int *)(param_1 + 0x11cc)) < 0xc01)) {
    if (*(int *)(param_1 + 0x11d0) == 0) {
      iVar1 = 0x400;
    }
    else {
      iVar1 = 0x400;
      if (*(uint *)(param_1 + 0x11a4) < 0x101) {
        iVar1 = *(uint *)(param_1 + 0x11a4) << 2;
      }
    }
    if (0 < iVar1) {
      *(undefined1 *)(param_1 + 0x11dc) = 1;
      (**(code **)(param_1 + 400))
                (*(int *)(param_1 + 0x194) + *(uint *)(param_1 + 0x11d0),
                 param_1 + (*(uint *)(param_1 + 0x11d0) & 0xff8) + 0x1a0,iVar1,param_1 + 0x11ac);
    }
  }
LAB_800b4b38:
  if ((uint)(*(int *)(param_1 + 0x11d8) - *(int *)(param_1 + 0x11d4)) <
      *(int *)(param_1 + 0x19c) - 0xa0U) {
    do {
      if ((((*(char *)(param_1 + 0x11dd) != '\x01') && (*(short *)(param_1 + 0x11a0) == 0)) ||
          (((*(int *)(param_1 + 0x11d0) == 0 || (*(int *)(param_1 + 0x11a4) != 0)) &&
           ((uint)(*(int *)(param_1 + 0x11d0) - *(int *)(param_1 + 0x11cc)) < 0x25)))) ||
         ((int)uVar5 < 1)) break;
      if (*(uint *)(param_1 + 0x19c) == 0) {
        trap(0x1c00);
      }
      FUN_800b53f4(param_1,*(int *)(param_1 + 0x198) +
                           (*(uint *)(param_1 + 0x11d8) % *(uint *)(param_1 + 0x19c) >> 2) * 8);
      sVar3 = *(short *)(param_1 + 0x11a0) + -1;
      *(short *)(param_1 + 0x11a0) = sVar3;
      *(uint *)(param_1 + 0x11cc) = *(uint *)(param_1 + 0x11c8) >> 3 & 0xfffffffc;
      *(int *)(param_1 + 0x11d8) = *(int *)(param_1 + 0x11d8) + 0xa0;
      if (sVar3 == 0) {
        *(undefined4 *)(param_1 + 0x11a8) = *(undefined4 *)(param_1 + 0x19c);
      }
      uVar5 = uVar5 - 1;
    } while ((uint)(*(int *)(param_1 + 0x11d8) - *(int *)(param_1 + 0x11d4)) <
             *(int *)(param_1 + 0x19c) - 0xa0U);
  }
  if ((*(byte *)(param_1 + 0x11dd) - 3 < 2) && (*(short *)(param_1 + 0x11a0) == 0)) {
    uVar2 = *(uint *)(param_1 + 0x11d8);
    uVar4 = *(uint *)(param_1 + 0x19c);
    if (uVar2 - *(int *)(param_1 + 0x11d4) < uVar4 - 0xa0 && 0 < (int)uVar5) {
      do {
        if (uVar4 == 0) {
          trap(0x1c00);
        }
        uVar5 = uVar5 - 1;
        func_0x80006650(*(int *)(param_1 + 0x198) + (uVar2 % uVar4 >> 2) * 8,0x140);
        uVar4 = *(uint *)(param_1 + 0x19c);
        uVar2 = *(int *)(param_1 + 0x11d8) + 0xa0;
        *(uint *)(param_1 + 0x11d8) = uVar2;
      } while (uVar2 - *(int *)(param_1 + 0x11d4) < uVar4 - 0xa0 && 0 < (int)uVar5);
    }
  }
  if ((*(char *)(param_1 + 0x11dd) == '\x01') &&
     (*(int *)(param_1 + 0x19c) - 0x140U <=
      (uint)(*(int *)(param_1 + 0x11d8) - *(int *)(param_1 + 0x11d4)))) {
    *(undefined1 *)(param_1 + 0x11dd) = 2;
  }
  return;
}
