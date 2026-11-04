/* FUN_8007e4b4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e4b4  body 0x8007e4b4..0x8007e587  size 212 B
 * body sha256 5b44aa2f3c91a593bfcabbbf90e8b28a07607c5977f91d60473c49d1b3e39a30
 * provider record sha256 d66696152657dea203558cb0fd2b09108a25dfcec3bf2df8156482b375e041bc
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007e304::caseD_5(void)

{
  int iVar1;
  uint *unaff_s0;
  
  FUN_800334c8();
  iVar1 = FUN_80089d54();
  if (iVar1 != 0) {
    *unaff_s0 = *unaff_s0 & 0xfffffff7;
    *(byte *)((int)unaff_s0 + 0x26f) = *(byte *)((int)unaff_s0 + 0x26f) & 0x7f;
    FUN_80083758(&DAT_800e8d00,*(undefined1 *)((int)unaff_s0 + 0x267));
    *(undefined1 *)((int)unaff_s0 + 5) = 6;
    *(undefined1 *)((int)unaff_s0 + 6) = 0;
  }
  FUN_80032bd8();
  if ((*(uint *)unaff_s0[0x85] & 0x4000) != 0) {
    FUN_80077f30(1,((*(uint *)unaff_s0[0x85] & 0x2000) >> 0xd) * 3 + 4);
    DAT_800e112a = DAT_800e112a | 4;
  }
  return;
}
