/* FUN_8017c664
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017c664  body 0x8017c664..0x8017c89f  size 572 B
 * body sha256 4356764ee9b949c77dcb9aa690bdc3622ac3954cadb4b9283cd14635ee5b227e
 * provider record sha256 4fbf14b23e78832df3a2c3b76a5160bf7fb3afaada3824cb94ebbdbcabf9f1cf
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017c664(void)

{
  short sVar1;
  int iVar2;
  int unaff_s1;
  
  DAT_8017e728 = DAT_8017e728 - DAT_8017e730;
  if (*(short *)(DAT_8017e73c + 0x16) == 0) {
    if ((DAT_8017e734 & 1) != 0) {
      sVar1 = *(short *)(DAT_8017e73c + 0x18);
      iVar2 = _DAT_800e13ec;
      goto LAB_8017c730;
    }
    sVar1 = *(short *)(DAT_8017e73c + 0x18);
    iVar2 = _DAT_800e1364;
  }
  else {
    if (*(short *)(DAT_8017e73c + 0x16) != 1) goto LAB_8017c74c;
    sVar1 = *(short *)(DAT_8017e73c + 0x18);
    iVar2 = _DAT_800e1380;
LAB_8017c730:
    iVar2 = *(int *)(iVar2 + 0x234);
  }
  unaff_s1 = iVar2 + sVar1 * 0x178 + 0x38;
LAB_8017c74c:
  DAT_8017e710 = DAT_8017e710 - DAT_8017e700;
  DAT_8017e700 = DAT_8017e700 + DAT_8017e736;
  iVar2 = func_0x800408c0((int)(short)DAT_8017e72c);
  DAT_8017e70c = *(int *)(unaff_s1 + 0x14) + (DAT_8017e728 * iVar2 >> 0xc);
  iVar2 = func_0x80040968((int)(short)DAT_8017e72c);
  DAT_8017e72c = DAT_8017e72c - DAT_8017e72e & 0xfff;
  DAT_8017e714 = *(int *)(unaff_s1 + 0x1c) - (DAT_8017e728 * iVar2 >> 0xc);
  DAT_8017e718 = DAT_8017e718 + (*(int *)(unaff_s1 + 0x14) - DAT_8017e718) / 0x1e;
  DAT_8017e720 = DAT_8017e720 + (*(int *)(unaff_s1 + 0x1c) - DAT_8017e720) / 0x1e;
  DAT_8017e71c = DAT_8017e71c + (*(int *)(unaff_s1 + 0x18) - (DAT_8017e71c + 300)) / 5;
  func_0x800828ac(&DAT_8017e70c,&DAT_8017e718);
  func_0x800428e0(0xd0);
  func_0x80042d60(0x800e9134);
  func_0x80042dac(0x800e9134);
  return;
}
