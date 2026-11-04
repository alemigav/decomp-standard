/* FUN_80058318
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80058318  body 0x80058318..0x800584d3  size 444 B
 * body sha256 bdc89b06fee7b2287bf0e7d64a96e0b435770606546a5e2b406edda7105f3243
 * provider record sha256 2010874e1bac96b204dc64b8873fe5838905642f770b132874299b2a7a8a49e9
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80057fc0::caseD_7(void)

{
  uint uVar1;
  uint *unaff_s0;
  undefined4 uStack00000018;
  short sStack0000001c;
  
  if (*(char *)((int)unaff_s0 + 0x206) == '\0') {
    *(short *)(unaff_s0 + 0x7d) = *(short *)(unaff_s0 + 0x7d) + 0x32;
    *(short *)((int)unaff_s0 + 0x2ae) = *(short *)((int)unaff_s0 + 0x2ae) + -0x32;
    if (*(short *)(unaff_s0 + 0x7d) < 1) goto LAB_80058374;
    *(undefined2 *)(unaff_s0 + 0x7d) = 0;
  }
  else {
    *(short *)(unaff_s0 + 0x7d) = *(short *)(unaff_s0 + 0x7d) + -0x32;
    *(short *)((int)unaff_s0 + 0x2ae) = *(short *)((int)unaff_s0 + 0x2ae) + -0x32;
    if (-1 < *(short *)(unaff_s0 + 0x7d)) goto LAB_80058374;
    *(undefined2 *)(unaff_s0 + 0x7d) = 0;
  }
  *(undefined2 *)((int)unaff_s0 + 0x2ae) = 0;
LAB_80058374:
  uStack00000018._0_2_ = *(short *)(unaff_s0 + 0x7d);
  FUN_8004276c(unaff_s0 + 5,&uStack00000018,&uStack00000018);
  uVar1 = unaff_s0[0x8d];
  DAT_8010dcb8 = (int)uStack00000018._0_2_ + *(int *)(uVar1 + 0x4c);
  DAT_8010dcbc = (int)uStack00000018._2_2_ + *(int *)(uVar1 + 0x50);
  DAT_8010dcc0 = (int)sStack0000001c + *(int *)(uVar1 + 0x54);
  FUN_800334c8();
  FUN_80089d54();
  FUN_80032b5c();
  if (9 < *(byte *)((int)unaff_s0 + 0x1e9)) {
    *unaff_s0 = *unaff_s0 & 0xfffffff7;
    FUN_800551e0();
    unaff_s0[1] = 0x1000000;
    DAT_800e110c = DAT_800e110c & 0xffffffbf;
    *(byte *)((int)unaff_s0 + 0x26f) = *(byte *)((int)unaff_s0 + 0x26f) & 0x7f;
    *unaff_s0 = *unaff_s0 & 0xfffffffb;
    *(uint *)(unaff_s0[0x82] + 0x14) = unaff_s0[0x8d] + 0x4c;
  }
  if ((*(uint *)unaff_s0[0x85] & 0x4000) != 0) {
    FUN_80077f30(0,((*(uint *)unaff_s0[0x85] & 0x2000) >> 0xd) * 3 + 4);
    DAT_800e112a = DAT_800e112a | 4;
  }
  return;
}
