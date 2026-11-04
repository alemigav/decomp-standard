/* FUN_80162c2c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80162c2c  body 0x80162c2c..0x80162d9b  size 368 B
 * body sha256 58680182f4917d66de66f5454b1c6869174f80ddaa79caf54694291aa2f1c6e0
 * provider record sha256 04515a9fae69dd620e73ce3ba12738d899046e46d9982f147cc6a07421055c2e
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80162c2c(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar3;
  int iVar2;
  undefined4 uVar4;
  
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        if (bVar1 == 3) {
          return 1;
        }
        return 0;
      }
      iVar2 = func_0x80089d54(param_1,param_2,param_3,0x400);
      if (iVar2 == 0) {
        return 0;
      }
      *(undefined1 *)(param_1 + 7) = 3;
      return 0;
    }
    if (bVar1 != 0) {
      return 0;
    }
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0xa000300;
  }
  func_0x80089d54(param_1,param_2,param_3,0x400);
  if ((**(uint **)(param_1 + 0x214) & 0x10000) == 0) {
    return 0;
  }
  *(undefined1 *)(param_1 + 7) = 2;
  func_0x80077d18(3,param_1);
  if (*(byte *)(param_1 + 0x2be) < 2) {
    FUN_801671ec(param_1,*(byte *)(param_1 + 0x2be) + 8,
                 (int)(((uint)*(ushort *)(param_1 + 0x66) + (uint)*(ushort *)(param_1 + 0x2b6)) *
                      0x10000) >> 0x10);
    return 0;
  }
  if (*(char *)(param_1 + 0x2d3) == '\0') {
    uVar4 = 0x89;
    if (2999 < *(uint *)(param_1 + 0x28c)) {
      uVar4 = 0x88;
    }
  }
  else {
    uVar4 = 0x89;
    if (2999 < (*(uint *)(param_1 + 0x290) & 0x3fffffff)) {
      uVar4 = 0x88;
    }
  }
  sVar3 = FUN_801645e8(param_1);
  FUN_801671ec(param_1,uVar4,(int)sVar3);
  return 0;
}
