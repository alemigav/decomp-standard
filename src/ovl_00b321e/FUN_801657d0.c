/* FUN_801657d0
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801657d0  body 0x801657d0..0x8016588f  size 192 B
 * body sha256 f4cafd1e5920cd906ee22943e886d3cba54b66ea09e5394e1d7b463639ad6b7a
 * provider record sha256 4cdde0f383592beb2a8515b71ea76fb35aba16e6f7885e3eac5ba748a61e855a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801657d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    FUN_80166270(param_1,2,0xb);
    *(undefined1 *)(param_1 + 0x2cf) = 0x2d;
    uVar2 = 0;
    iVar1 = 0;
    do {
      uVar2 = uVar2 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x234) + iVar1 + 0x60) = 0x3f3f4f;
      iVar1 = iVar1 + 0x178;
    } while (uVar2 < 0xd);
    FUN_801651c0(param_1,param_2,param_3);
  }
  else {
    (*(code *)(&PTR_FUN_80166830)[*(byte *)(param_1 + 6)])(param_1,param_2,param_3);
  }
  return;
}
