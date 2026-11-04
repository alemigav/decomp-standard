/* FUN_8017c168
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017c168  body 0x8017c168..0x8017c233  size 204 B
 * body sha256 a85e8859e434ba42ce7ce8b8a6e66392f105aafaec4ea856314f31bd67cc5b8d
 * provider record sha256 b98b13f6bbf3fe5b47c7a196b264eec7ba7df0ad118bd82f299b9af4850b6ad6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017c168(void)

{
  undefined2 uVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  
  iVar2 = _DAT_800e1364;
  iVar4 = *(int *)(_DAT_800df92c + 0x2c) + _DAT_800e8cac * 0x28;
  *(short *)(iVar4 + 0x1c) = DAT_8017e718._2_2_ + 500;
  *(short *)(iVar4 + 0x1e) = DAT_8017e71c._2_2_ + 3000;
  sVar3 = DAT_8017e720._2_2_;
  *(undefined1 *)(iVar4 + 10) = 0x84;
  *(undefined1 *)(iVar4 + 0xb) = 0x84;
  *(undefined1 *)(iVar4 + 0xc) = 0x84;
  *(undefined2 *)(iVar4 + 0x26) = 8000;
  *(short *)(iVar4 + 0x20) = sVar3 + 500;
  *(undefined2 *)(iVar4 + 0x10) = *(undefined2 *)(iVar2 + 0x4e);
  *(short *)(iVar4 + 0x12) = *(short *)(iVar2 + 0x52) + -300;
  uVar1 = *(undefined2 *)(iVar2 + 0x56);
  *(undefined1 *)(iVar4 + 4) = 0x78;
  *(undefined1 *)(iVar4 + 5) = 0x78;
  *(undefined1 *)(iVar4 + 6) = 0x78;
  *(undefined2 *)(iVar4 + 0x22) = 4000;
  *(undefined1 *)(iVar4 + 1) = 0;
  *(undefined1 *)(iVar4 + 7) = 0;
  *(undefined1 *)(iVar4 + 8) = 0;
  *(undefined1 *)(iVar4 + 9) = 0;
  *(undefined2 *)(iVar4 + 0x14) = uVar1;
  return;
}
