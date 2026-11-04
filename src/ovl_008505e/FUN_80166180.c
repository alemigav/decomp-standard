/* FUN_80166180
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80166180  body 0x80166180..0x8016620f  size 144 B
 * body sha256 98d88d5659557e8e25a225d0cad1a0548a310862aed568f3c7c98b86a94a7d82
 * provider record sha256 d4298312dea85abb16cbdfc9669b5aa810306ca1b3f3c94554275531257ced2f
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166180(int param_1)

{
  int iVar1;
  uint uVar2;
  
  FUN_80165b38();
  uVar2 = 0;
  if (*(byte *)(param_1 + 0x26e) < 3) {
    iVar1 = 0;
    do {
      uVar2 = uVar2 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x234) + iVar1 + 0x60) = 0x3f2f;
      iVar1 = iVar1 + 0x178;
    } while (uVar2 < 0x11);
    *(undefined1 *)(param_1 + 699) = 2;
    uVar2 = func_0x80033604();
    FUN_80166980(param_1,uVar2 & 7,9);
    uVar2 = func_0x80033604();
    FUN_80166980(param_1,uVar2 & 7 | 8,10);
  }
  return;
}
