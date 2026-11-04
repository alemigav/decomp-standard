/* FUN_80053c78
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80053c78  body 0x80053c78..0x80053d37  size 192 B
 * body sha256 84eed0ca342ea5d2ae45beef6a77b77bb675ee10d3fcbb0509e2bbd9d7f3c12d
 * provider record sha256 46e59cf38af8f525c0aa0326cffd83ab7e7df95f204f81001b6135a6a208d9e7
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80053c78(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = DAT_8010d940;
  uVar2 = 0;
  iVar6 = 0x18a;
  iVar5 = 0x16c;
  iVar4 = 0x22;
  iVar3 = 4;
  do {
    FUN_80082474(iVar1 + iVar3,iVar1 + iVar4,0x1e);
    FUN_80082474(iVar1 + iVar5,iVar1 + iVar6,0x1e);
    iVar6 = iVar6 + 0x1e;
    iVar5 = iVar5 + 0x1e;
    iVar4 = iVar4 + 0x1e;
    uVar2 = uVar2 + 1;
    iVar3 = iVar3 + 0x1e;
  } while (uVar2 < 0xb);
  uVar2 = 0;
  iVar3 = iVar1;
  while( true ) {
    uVar2 = uVar2 + 1;
    *(undefined1 *)(iVar3 + 0x14e) = 0x20;
    *(undefined1 *)(iVar3 + 0x2b6) = 0;
    if (0x1d < uVar2) break;
    iVar3 = iVar1 + uVar2;
  }
  return;
}
