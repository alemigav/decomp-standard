/* FUN_80162b1c
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x80162b1c  body 0x80162b1c..0x80162c7b  size 352 B
 * body sha256 069371e12a27d5b2fea01e36b7d9062cf2dfe805ef2df51cfbcab7ab6ea0e6fa
 * provider record sha256 8b1141cbe5fe7448bf2b93346ba09792c3c51838cab91cf680dc489bdcfec506
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162b1c(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x208);
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0;
    func_0x80089d54();
    FUN_80162e00(param_1,0,(&DAT_80163087)[*(byte *)(param_1 + 5)]);
    func_0x800341dc(iVar4,0xaf4faf00);
    if (*(char *)(param_1 + 0x2c0) != '\0') {
      func_0x80035b84(param_1);
    }
    *(undefined2 *)(param_1 + 500) = 0x1000;
    uVar3 = 0;
    iVar4 = 0;
    do {
      uVar3 = uVar3 + 1;
      puVar1 = (uint *)(*(int *)(param_1 + 0x234) + iVar4);
      *(undefined2 *)(puVar1 + 0x49) = 0x1000;
      *(undefined2 *)((int)puVar1 + 0x126) = 0x1000;
      *(undefined2 *)(puVar1 + 0x4a) = 0x1000;
      puVar1[0x4c] = 0x400000;
      puVar1[0x4d] = 0x10101000;
      *puVar1 = *puVar1 | 0x480;
      iVar4 = iVar4 + 0x178;
    } while (uVar3 < 3);
  }
  else {
    uVar3 = 0;
    iVar2 = 0;
    do {
      uVar3 = uVar3 + 1;
      *(undefined2 *)(*(int *)(param_1 + 0x234) + iVar2 + 0x126) = *(undefined2 *)(param_1 + 500);
      iVar2 = iVar2 + 0x178;
    } while (uVar3 < 3);
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + -0x200;
    *(short *)(iVar4 + 6) = *(short *)(iVar4 + 6) + 0x20;
    *(short *)(iVar4 + 4) = *(short *)(iVar4 + 4) + 0x10;
    if (*(short *)(param_1 + 500) < 0x100) {
      *(undefined2 *)(param_1 + 500) = 0x1000;
      *(uint *)(param_1 + 4) = (uint)*(byte *)(param_1 + 5) * 0x10000 + 0x7000000;
    }
  }
  return;
}
