/* FUN_80096d90
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80096d90  body 0x80096d90..0x80096e73  size 228 B
 * body sha256 d46636ddd9225b5231a4a77bd810be75094c0251568116dad29603f8e4694795
 * provider record sha256 24def8875beafb35406fab59cada17ec0b9daed7e77df7fedaf6229f5d25059f
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80096d90(void)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  
  sVar2 = DAT_8012bfd2;
  sVar1 = DAT_8012bfd0;
  uVar3 = DAT_800c52dc + 0x3bb64U;
  if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
    uVar3 = DAT_800c52dc + 0x3c004U;
  }
  iVar6 = 0x11;
  psVar4 = (short *)&UNK_8013129c;
  iVar5 = uVar3 + 0x758;
  do {
    iVar6 = iVar6 + -1;
    FUN_800478b8(iVar5,psVar4[-2] + sVar1,psVar4[-1] + sVar2);
    DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar5,0,0);
    psVar4 = psVar4 + -2;
    iVar5 = iVar5 + 0x14;
  } while (iVar6 != 0);
  return;
}
