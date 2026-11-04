/* FUN_80058580
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80058580  body 0x80058580..0x800585f3  size 116 B
 * body sha256 40a9cace24e13ac0c93f80aea8e9356346449357720f4a356c4e0d911eecb34e
 * provider record sha256 6db8c82055821e46dc543d14bb3d0c7ab79a7f21e1a1876219b4c1f97acc837a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8005850c::caseD_1(void)

{
  ushort uVar1;
  ushort uVar2;
  int unaff_s0;
  
  FUN_80089d54();
  uVar1 = *(ushort *)(unaff_s0 + 0x66);
  if ((uVar1 & 0x200) == 0) {
    uVar2 = -(uVar1 >> 2 & 0xff);
  }
  else {
    uVar2 = uVar1 >> 2 & 0xff;
  }
  *(ushort *)(unaff_s0 + 0x66) = uVar1 + uVar2;
  if ((*(ushort *)(unaff_s0 + 0x66) & 0x3e0) == 0) {
    *(ushort *)(unaff_s0 + 0x66) = *(ushort *)(unaff_s0 + 0x66) & 0xff00;
    *(undefined1 *)(unaff_s0 + 7) = 2;
    if ((*(byte *)(unaff_s0 + 6) & 2) != 0) {
      *(undefined1 *)(unaff_s0 + 5) = 9;
      *(undefined1 *)(unaff_s0 + 7) = 0;
    }
  }
  return;
}
