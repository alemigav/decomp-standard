/* FUN_801631c8
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x801631c8  body 0x801631c8..0x80163263  size 156 B
 * body sha256 8ba1461fd1e90a2e2d7277acb235a6f4dfa6eb39da3a6b25258c0a39f766eeb4
 * provider record sha256 2bf2f7f105441ed8714ebfd66dd71f347ab0fffcf310079afb3693e31289bcbe
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801631c8(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(_DAT_800df92c + 0x2c) + _DAT_800e8cac * 0x28;
  if (DAT_800dfbe8 == '\0') {
    *(undefined1 *)(iVar2 + 10) = 0xaa;
    *(undefined1 *)(iVar2 + 0xb) = 0x46;
    uVar1 = 7000;
  }
  else {
    *(undefined1 *)(iVar2 + 10) = 200;
    *(undefined1 *)(iVar2 + 0xb) = 0x5f;
    uVar1 = 10000;
  }
  *(undefined1 *)(iVar2 + 0xc) = 0;
  *(undefined2 *)(iVar2 + 0x26) = uVar1;
  *(undefined1 *)(iVar2 + 3) = 0;
  *(undefined2 *)(iVar2 + 0x1c) = *(undefined2 *)(param_1 + 0x2a);
  *(short *)(iVar2 + 0x1e) = *(short *)(param_1 + 0x2e) + -0x1194;
  *(undefined2 *)(iVar2 + 0x20) = *(undefined2 *)(param_1 + 0x32);
  return;
}
