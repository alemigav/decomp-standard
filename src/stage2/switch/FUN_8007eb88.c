/* FUN_8007eb88
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007eb88  body 0x8007eb88..0x8007ec13  size 140 B
 * body sha256 da6b0ad6b6aff6468ff5d4f489df2f597e2081664efb3f50f419f73f71bd2c44
 * provider record sha256 71cc0767608fabd12f409b2fa5113b84c0c55e0b301fbbe4eaa2f6bc4d3e59cd
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007e960::caseD_4(void)

{
  char cVar1;
  uint *unaff_s1;
  
  *(undefined1 *)((int)unaff_s1 + 7) = 5;
  *(undefined1 *)(unaff_s1 + 0x7a) = 9;
  if (4 < (*(byte *)((int)unaff_s1 + 6) & 0xc)) {
    *(undefined1 *)(unaff_s1 + 0x7a) = 7;
  }
  *(undefined1 *)((int)unaff_s1 + 0x1e9) = 4;
  *(undefined1 *)((int)unaff_s1 + 0x1ea) = 7;
  *(byte *)((int)unaff_s1 + 0x26f) = *(byte *)((int)unaff_s1 + 0x26f) & 0x7f;
  unaff_s1[0xb] = (int)*(short *)((int)unaff_s1 + 0x25e);
  *unaff_s1 = *unaff_s1 & 0xfffffffb;
  FUN_80077f30(1);
  DAT_800e112a = DAT_800e112a | 4;
  *(char *)((int)unaff_s1 + 0x1a2) = -(char)((int)unaff_s1[0xb] / 0x708);
  cVar1 = FUN_80089d54();
  *(char *)((int)unaff_s1 + 7) = *(char *)((int)unaff_s1 + 7) + cVar1;
  return;
}
