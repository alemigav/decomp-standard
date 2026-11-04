/* FUN_8017bb20
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017bb20  body 0x8017bb20..0x8017bdaf  size 656 B
 * body sha256 0f335a9ca18de4242e581a161c0bac758b09f24e3d6483c6a0e9ae6d320ab538
 * provider record sha256 07ce08d409cb2a532f3a7ece08d793574a7ee2c49a5c40ee25e5ee6eebff9dda
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017bb20(void)

{
  short sVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  char cVar5;
  int unaff_s2;
  
  DAT_8017e704 = 0;
  DAT_8017e72e = 0;
  cVar3 = *(char *)(_DAT_800e1380 + 8);
  iVar4 = 0xe;
  if ((cVar3 == '4') && ((*(ushort *)(_DAT_800e1380 + 0x1aa) & 1) == 0)) {
    cVar3 = '3';
  }
  if (cVar3 == '9') {
    cVar3 = '.';
  }
  cVar5 = '\x0e';
  if (cVar3 != '$') {
    do {
      cVar5 = (char)iVar4;
      iVar2 = iVar4 << 0x18;
      iVar4 = iVar4 + -1;
      if (iVar2 < 1) break;
      cVar5 = (char)iVar4;
    } while ((&DAT_8017e6d4)[iVar4 * 0x1000000 >> 0x18] != cVar3);
  }
  iVar4 = cVar5 * 0x1c;
  DAT_8017e73c = (undefined4 *)(&DAT_8017e530 + iVar4);
  DAT_8017e728 = *DAT_8017e73c;
  DAT_8017e730 = *(undefined4 *)(&UNK_8017e534 + iVar4);
  DAT_8017e72c = _DAT_800e1196 & 0xfff;
  cVar3 = func_0x80033144(&DAT_800e1130,_DAT_800e1380);
  if (cVar3 == '\0') {
    sVar1 = *(short *)(&UNK_8017e540 + iVar4);
    DAT_8017e72e = *(undefined2 *)(&UNK_8017e53e + iVar4);
  }
  else {
    sVar1 = *(short *)(&UNK_8017e53c + iVar4);
    DAT_8017e72e = *(undefined2 *)(&UNK_8017e53a + iVar4);
  }
  DAT_8017e72c = DAT_8017e72c + sVar1;
  if (*(short *)(&UNK_8017e546 + iVar4) == 0) {
    if ((DAT_8017e734 & 1) != 0) {
      sVar1 = *(short *)(&UNK_8017e548 + iVar4);
      iVar2 = _DAT_800e13ec;
      goto LAB_8017bd20;
    }
    sVar1 = *(short *)(&UNK_8017e548 + iVar4);
    iVar2 = _DAT_800e1364;
  }
  else {
    if (*(short *)(&UNK_8017e546 + iVar4) != 1) goto LAB_8017bd40;
    sVar1 = *(short *)(&UNK_8017e548 + iVar4);
    iVar2 = _DAT_800e1380;
LAB_8017bd20:
    iVar2 = *(int *)(iVar2 + 0x234);
  }
  unaff_s2 = iVar2 + sVar1 * 0x178 + 0x38;
LAB_8017bd40:
  DAT_8017e710 = *(int *)(unaff_s2 + 0x18) + (int)*(short *)(&UNK_8017e542 + iVar4);
  DAT_8017e700 = *(undefined2 *)(&UNK_8017e538 + iVar4);
  DAT_8017e736 = 0;
  DAT_8017e718 = *(undefined4 *)(unaff_s2 + 0x14);
  DAT_8017e720 = *(undefined4 *)(unaff_s2 + 0x1c);
  DAT_8017e71c = *(int *)(unaff_s2 + 0x18) + -300;
  FUN_8017c234();
  FUN_8017be6c();
  FUN_8017c168();
  FUN_8017c664();
  return;
}
