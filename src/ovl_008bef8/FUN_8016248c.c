/* FUN_8016248c
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x8016248c  body 0x8016248c..0x8016270f  size 644 B
 * body sha256 3c96e074d1e1154f130351204bc673b0fd7f69b8dccd118c81b190614e0ecbd4
 * provider record sha256 713280ea17cd539bc342258a9f56acc4dcfdb8ea1c3ed992d822645a934430f5
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016248c(int param_1)

{
  char cVar1;
  int iVar2;
  
  FUN_80162d84();
  if ((*(char *)(param_1 + 0x2b6) == '\0') && (*(int *)(param_1 + 0x28) < -0x45d5)) {
    *(undefined1 *)(param_1 + 0x2b6) = 1;
    *(undefined4 *)(param_1 + 4) = 0x1030000;
    *(undefined2 *)(param_1 + 0x2ba) = 0;
    *(short *)(param_1 + 0x2b8) = -0x45d5 - *(short *)(param_1 + 0x2a);
    return;
  }
  if (*(char *)(param_1 + 0x2b6) == '\x01') {
    if (-0x1c9b < *(int *)(param_1 + 0x30)) {
      *(undefined1 *)(param_1 + 0x2b6) = 2;
      *(undefined2 *)(param_1 + 0x2b8) = 0;
      *(undefined4 *)(param_1 + 4) = 0x1030000;
      *(short *)(param_1 + 0x2ba) = *(short *)(param_1 + 0x32) + 0x1c9b;
      return;
    }
    if (*(char *)(param_1 + 0x2c8) != '\0') {
      return;
    }
    iVar2 = func_0x800837ac(0x800e8d00,1);
    if ((iVar2 != 0) && (*(byte *)(param_1 + 0x2c2) < 2)) {
      *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 4;
      *(undefined2 *)(param_1 + 0x20c) = *(undefined2 *)(param_1 + 0x2a);
      *(short *)(param_1 + 0x20e) = *(short *)(param_1 + 0x2e) + -800;
      *(undefined2 *)(param_1 + 0x210) = _DAT_800e1c92;
    }
    if (((_DAT_800e1c90 - *(int *)(param_1 + 0x30)) + -9000 < -0x78) &&
       (*(char *)(param_1 + 0x2c2) == '\0')) {
      *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfb;
    }
    iVar2 = func_0x800837ac(0x800e8d00,0);
    if (iVar2 != 0) {
      if (0x18e < (_DAT_800e1c90 - *(int *)(param_1 + 0x30)) - 0x2199U) {
        return;
      }
      if (*(char *)(param_1 + 0x2c2) != '\0') {
        return;
      }
      *(undefined1 *)(param_1 + 0x2c2) = 1;
      if (*(char *)(param_1 + 5) == '\x02') {
        *(undefined4 *)(param_1 + 4) = 0x1010000;
        return;
      }
      return;
    }
  }
  cVar1 = *(char *)(param_1 + 0x2c2);
  if ((cVar1 == '\0') || (cVar1 == '\a')) {
    if (*(char *)(param_1 + 5) == '\x01') {
      if (*(char *)(param_1 + 0x2c8) != '\0') {
        *(undefined4 *)(param_1 + 4) = 0x1020000;
      }
      if (*(char *)(param_1 + 0x2d4) == '\0') {
        if ((*(ushort *)(param_1 + 0x2b4) & 0x20) == 0) {
          if (100 < *(uint *)(param_1 + 0x28c)) {
            *(undefined4 *)(param_1 + 4) = 0x1020000;
          }
        }
        else if (100 < *(uint *)(param_1 + 0x28c)) {
          *(undefined4 *)(param_1 + 4) = 0x1020000;
        }
      }
    }
    else if (*(char *)(param_1 + 0x2c8) == '\0') {
      if ((cVar1 != '\0') && (cVar1 != '\a')) {
        *(undefined4 *)(param_1 + 4) = 0x1010000;
      }
      if (*(uint *)(param_1 + 0x28c) < 0x5a) {
        *(undefined4 *)(param_1 + 4) = 0x1010000;
      }
      if (*(char *)(param_1 + 0x2d4) != '\0') {
        *(undefined4 *)(param_1 + 4) = 0x1010000;
      }
    }
  }
  return;
}
