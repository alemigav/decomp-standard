/* FUN_8017b8f4
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017b8f4  body 0x8017b8f4..0x8017b98b  size 152 B
 * body sha256 ff8307845762f57bf6b2ab7d8fddf07467694ccc28ce38f466612d650bbd6f46
 * provider record sha256 264569a26b46087f0324905323ef88bdb5c4cbd5564435d3500bda2f806b2a65
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined1 FUN_8017b8f4(void)

{
  int *piVar1;
  undefined1 uVar2;
  int *piVar3;
  
  if (*DAT_80186c94 + 0x800U <= (uint)DAT_80186c94[2]) {
    do {
      FUN_8017b50c(DAT_80186c94[1],DAT_80186c94,0x800);
      piVar3 = DAT_80186c94;
      piVar1 = DAT_80186c94 + 6;
      DAT_80186c94[2] = DAT_80186c94[2] + -0x800;
      piVar3[6] = *piVar1 + -0x800;
    } while (*piVar3 + 0x800U <= (uint)piVar3[2]);
  }
  uVar2 = *(undefined1 *)DAT_80186c94[2];
  DAT_80186c94[2] = (int)((undefined1 *)DAT_80186c94[2] + 1);
  return uVar2;
}
