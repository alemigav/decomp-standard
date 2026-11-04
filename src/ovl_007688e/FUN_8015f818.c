/* FUN_8015f818
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015f818  body 0x8015f818..0x8015f9e3  size 460 B
 * body sha256 581a0b5e0728b4bafaa4a69f2a71a58bc0bc7329b1666857345d79581610dcd4
 * provider record sha256 88006fe634543810e46203975382a117e3d4743d0773685c6369c03d3c19991b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8015f8ec) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015f818(void)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = 0;
  do {
    iVar4 = 1;
    do {
      bVar1 = iVar4 == 0;
      iVar4 = iVar4 + 1;
    } while (bVar1);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 2);
  uVar5 = 0;
  iVar6 = 0x618;
  iVar4 = 0x27;
  do {
    iVar2 = iVar4 * 0x28;
    (&DAT_80160c3a)[iVar2] = 0x80;
    (&DAT_80160c39)[iVar2] = 0x80;
    (&DAT_80160c38)[iVar2] = -0x80;
    if (uVar5 == DAT_80160c22) {
      *(undefined2 *)((int)&DAT_80160c42 + (uint)DAT_800dfbe8 * 0x14 + iVar6) = 0;
      cVar3 = DAT_80160c23 + -0x80;
      (&DAT_80160c3a)[iVar2] = cVar3;
      (&DAT_80160c39)[iVar2] = cVar3;
      (&DAT_80160c38)[iVar2] = cVar3;
    }
    else {
      (&DAT_80160c42)[(uVar5 * 2 + 0x27) * 0x14 + (uint)DAT_800dfbe8 * 10] = 0x100;
    }
    _DAT_800df8b4 = func_0x80043988(_DAT_800df8b4,&DAT_80160c38 + iVar4 * 0x28,0,0);
    iVar6 = iVar6 + 0x50;
    uVar5 = uVar5 + 1;
    iVar4 = iVar4 + 2;
  } while (uVar5 < 2);
  return;
}
