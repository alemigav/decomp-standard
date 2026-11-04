/* FUN_801660e0
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801660e0  body 0x801660e0..0x8016617f  size 160 B
 * body sha256 6a799d5f3d9680dc0c8879de2ed585081fb692d859ef70de67ed7fae2498f33e
 * provider record sha256 929ca4576f4f8ca687f2c8de664f5f5bc900711a2f9ef1224be2dde4ffda30b9
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801660e0(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  FUN_80165b38();
  if ((*(byte *)(param_1 + 0x26e) < 3) || (*(char *)(param_1 + 5) == '\x10')) {
    *(undefined1 *)(param_1 + 699) = 6;
    uVar3 = 0;
    do {
      uVar3 = uVar3 + 1;
      uVar1 = func_0x80033604();
      FUN_80166980(param_1,uVar1 & 0xf,7);
    } while (uVar3 < 6);
    uVar3 = 0;
    iVar2 = 0;
    do {
      uVar3 = uVar3 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x234) + iVar2 + 0x60) = 0x202020;
      iVar2 = iVar2 + 0x178;
    } while (uVar3 < 0x11);
  }
  return;
}
